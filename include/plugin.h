// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.

#include "endstone/color_format.h"
#include "endstone/command/plugin_command.h"
#include "endstone/event/server/server_command_event.h"
#include "endstone/event/server/server_load_event.h"
#include "endstone/plugin/plugin.h"
#include <memory>
#include <vector>
#include "Windows.h"
#include "filesystem"
#include "iostream"
class DotnetLoader : public endstone::Plugin {
public:
    void onLoad() override
    {
        getLogger().info("init dotnet plugins");
        int LoadMain();
        LoadMain();
    }

    void onEnable() override
    {
      
    }

    void onDisable() override
    {
        getLogger().info("onDisable is called");
    }
    wchar_t *multi_Byte_To_Wide_Char(const std::string &pKey)
    {
        // string 转 char*
        const  char *pCStrKey = pKey.c_str();
        // 第一次调用返回转换后的字符串长度，用于确认为wchar_t*开辟多大的内存空间
        int pSize = MultiByteToWideChar(CP_OEMCP, 0, pCStrKey, strlen(pCStrKey) + 1, NULL, 0);
        wchar_t *pWCStrKey = new wchar_t[pSize];
        // 第二次调用将单字节字符串转换成双字节字符串
        MultiByteToWideChar(CP_OEMCP, 0, pCStrKey, strlen(pCStrKey) + 1, pWCStrKey, pSize);
        return pWCStrKey;
    }
    char *wide_Char_To_Multi_Byte(wchar_t *pWCStrKey)
    {
        // 第一次调用确认转换后单字节字符串的长度，用于开辟空间
        int pSize = WideCharToMultiByte(CP_OEMCP, 0, pWCStrKey, wcslen(pWCStrKey), NULL, 0, NULL, NULL);
        char *pCStrKey = new char[pSize + 1];
        // 第二次调用将双字节字符串转换成单字节字符串
        WideCharToMultiByte(CP_OEMCP, 0, pWCStrKey, wcslen(pWCStrKey), pCStrKey, pSize, NULL, NULL);
        pCStrKey[pSize] = '\0';
        return pCStrKey;

        // 如果想要转换成string，直接赋值即可
        // string pKey = pCStrKey;
    }

};
