// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.
#include "plugin.h"
#include <thread>
#include <chrono>
#include "endstone/logger.h"

class DotnetLoader : public endstone::Plugin {
public:
    void onLoad() override
    {
        auto &server = getServer();
        server.getPluginManager().registerLoader(std::make_unique<DotnetPluginLoader>(server));
        server.getPluginManager().loadPlugins("./plugins/plugins_dotnet/.empty");
        getLogger().info("init dotnet plugins");
    }

    void onEnable() override 
    {
      
    } 

    void onDisable() override
    {
        getLogger().info("onDisable is called");
    }
};
ENDSTONE_PLUGIN("dotnet_loader","0.0.1", DotnetLoader)
{
    description = "A dotnet loader for endstone [dotnet 9.0]";
    website = "http://netloader.axio.fun";
    authors = {"ATRI-ORG"};
}
std::vector<Plugin *> DotnetPluginLoader::loadPlugins(const std::string &directory)
{
        auto ptr = (std::vector<DotnetPlugin*>*)LoadMain();
       if (ptr == 0) {
            return {};
       }
        std::vector<Plugin *> des;
         for each (auto var in *ptr) {
            des.push_back(var);
            // initPlugin(*var, getServer().getLogger(), std::filesystem::path(directory));
         }
        delete ptr;
        return des;
}
void DotnetPlugin::buildPlugin(ENALBLECALL load, ENALBLECALL enable, ENALBLECALL disable, char *describe, char *version,
                               char *pluginname, char *website, char *emil, char *author)
{
        load_ = load;
        enable_ = enable;
        disable_ = disable;
        impl.authors = {author};
        impl.description = describe;
        impl.website = website;
        version_ = version;
        name_ = pluginname;
        PluginDescription * des_= new PluginDescription(name_,version);
        *(des_) = impl.build(name_,version);
        des = des_;
}
[[nodiscard]]  const PluginDescription &DotnetPlugin::getDescription() const
{
    return *des;
}
void DotnetPlugin::onEnable() {
    enable_();
}
void DotnetPlugin::onLoad() {
    load_();
}
bool DotnetPlugin::onCommand(CommandSender &sender, const Command &command, const std::vector<std::string> &args)
{
    if (auto *player = sender.asPlayer(); player) {
     
    }
    if (auto *console = sender.asConsole(); console) {
    }
    return true;
}
void DotnetPlugin::onDisable() {
    disable_();
}
