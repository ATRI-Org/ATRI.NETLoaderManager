#define EXTERN __declspec(dllexport)
#include "plugin.h"
#include "vector"
extern "C" {
EXTERN void* RegisterPluginVoid(char *describe, char *version, char *pluginname, char *website, char *emil, char *author,
                               ENALBLECALL load, ENALBLECALL enable, ENALBLECALL disable)
  {
    DotnetPlugin *ptr = new DotnetPlugin();
    ptr->buildPlugin(load,enable,disable,describe,version,pluginname,website,emil,author);
    return ptr;
  }
  EXTERN void AddIntoArray(void* array, void* ptr) 
  {
     auto ptra = (std::vector<DotnetPlugin *>*)array;
     ptra->push_back((DotnetPlugin*)ptr);
  }
  EXTERN void* NewArray() {
      return new std::vector<DotnetPlugin *>();
  }
  }
