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
        // string ת char*
        const  char *pCStrKey = pKey.c_str();
        // ��һ�ε��÷���ת������ַ������ȣ�����ȷ��Ϊwchar_t*���ٶ����ڴ�ռ�
        int pSize = MultiByteToWideChar(CP_OEMCP, 0, pCStrKey, strlen(pCStrKey) + 1, NULL, 0);
        wchar_t *pWCStrKey = new wchar_t[pSize];
        // �ڶ��ε��ý����ֽ��ַ���ת����˫�ֽ��ַ���
        MultiByteToWideChar(CP_OEMCP, 0, pCStrKey, strlen(pCStrKey) + 1, pWCStrKey, pSize);
        return pWCStrKey;
    }
    char *wide_Char_To_Multi_Byte(wchar_t *pWCStrKey)
    {
        // ��һ�ε���ȷ��ת�����ֽ��ַ����ĳ��ȣ����ڿ��ٿռ�
        int pSize = WideCharToMultiByte(CP_OEMCP, 0, pWCStrKey, wcslen(pWCStrKey), NULL, 0, NULL, NULL);
        char *pCStrKey = new char[pSize + 1];
        // �ڶ��ε��ý�˫�ֽ��ַ���ת���ɵ��ֽ��ַ���
        WideCharToMultiByte(CP_OEMCP, 0, pWCStrKey, wcslen(pWCStrKey), pCStrKey, pSize, NULL, NULL);
        pCStrKey[pSize] = '\0';
        return pCStrKey;

        // �����Ҫת����string��ֱ�Ӹ�ֵ����
        // string pKey = pCStrKey;
    }

};
