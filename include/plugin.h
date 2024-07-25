// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.
#include "endstone/plugin/plugin_loader.h"
#include "endstone/plugin/plugin_manager.h"
#include "endstone/server.h"
#include "endstone/color_format.h"
#include "endstone/command/plugin_command.h"
#include <memory>
#include <vector>
#include "endstone/plugin/plugin_manager.h"
#include "endstone/plugin/plugin.h"
#include "iostream"
#include <filesystem>
#include "endstone/detail/plugin/plugin_manager.h"
#include "coreclr_delegates.h";
using string_t = std::basic_string<char_t>;
using namespace endstone;
namespace fs = std::filesystem;
std::string LoadMain();
class DotnetPluginLoader : public PluginLoader {
public:
    using PluginLoader::PluginLoader;
    
    std::vector<Plugin*> loadPlugins(const std::string &directory) override
    {
        try {
            std::string folderPath = "plugins\\plugins_dotnet\\"; 
            std::string extension = ".dll";
            
            std::cout << LoadMain() << std::endl;
            //delete text;
            return {};
        }
        catch (std::exception &e) {
            return {};
        }
    }
};
class DotnetLoader : public endstone::Plugin {
public:
    void onLoad() override
    {
        
        auto& server =  getServer();
        server.getPluginManager().registerLoader(std::make_unique<DotnetPluginLoader>(server));
        server.getPluginManager().loadPlugins("./plugins/plugins_dotnet/");
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
// class DotnetPlugin : public Plugin {
// public:
//     using Plugin::Plugin;
//
//     [[nodiscard]] const PluginDescription &getDescription() const override
//     {
//         PluginDescriptionBuilderImpl impl;
//         return nullptr;
//     }
//     void onLoad() override
//     {
//
//     }
//
//     void onEnable() override
//     {
//
//     }
//
//     void onDisable() override
//     {
//
//     }
//
//     bool onCommand(CommandSender &sender, const Command &command, const std::vector<std::string> &args) override
//     {
//         if (auto *player = sender.asPlayer(); player) {
//
//         }
//         if (auto *console = sender.asConsole(); console) {
//
//         }
//
//     }
// };
