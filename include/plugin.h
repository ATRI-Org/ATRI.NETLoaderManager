// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.
#pragma once
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
#include "endstone/detail/plugin/plugin_description_builder.h"
typedef void(__stdcall *CALLBACK_)(void);
#define ENALBLECALL CALLBACK_
using string_t = std::basic_string<char_t>;
using namespace endstone;
namespace fs = std::filesystem;

class DotnetPluginLoader : public PluginLoader {
public:
    using PluginLoader::PluginLoader;
    std::vector<Plugin*> loadPlugins(const std::string &directory) override;
};

 class DotnetPlugin : public Plugin {
 public:
     
     using Plugin::Plugin;
     endstone::detail::PluginDescriptionBuilder impl;
     PluginDescription *des;
     char *name_;
     char *version_;
     ENALBLECALL load_;
     ENALBLECALL enable_;
     ENALBLECALL disable_;
     void buildPlugin(ENALBLECALL load, ENALBLECALL enable, ENALBLECALL disable, char *describe, char *version,
                      char *pluginname, char *website, char *emil, char *author);
     [[nodiscard]] const PluginDescription &getDescription() const override;
     void onLoad() override;
     void onEnable() override;
     void onDisable() override;
     bool onCommand(CommandSender &sender, const Command &command, const std::vector<std::string> &args) override;
 };
 DotnetPlugin *LoadMain();