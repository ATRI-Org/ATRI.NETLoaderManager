#define EXTERN __declspec(dllexport)
#include "plugin.h"
extern "C" {
EXTERN void* RegisterPluginVoid(char *describe, char *version, char *pluginname, char *website, char *emil, char *author,
                               ENALBLECALL load, ENALBLECALL enable, ENALBLECALL disable)
  {
    DotnetPlugin *ptr = new DotnetPlugin();
    ptr->buildPlugin(load,enable,disable,describe,version,pluginname,website,emil,author);
    return ptr;
  }
}
