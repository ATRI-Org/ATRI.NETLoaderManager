#define EXTERN __declspec(dllexport)
#include "plugin.h"
#include "vector"
#include <endstone/permissions/permissible.h>
extern "C" {
EXTERN void *RegisterPluginVoid(char *describe, char *version, char *pluginname, char *website, char *emil,
                                char *author, ENALBLECALL load, ENALBLECALL enable, ENALBLECALL disable)
{
    DotnetPlugin *ptr = new DotnetPlugin();
    ptr->buildPlugin(load, enable, disable, describe, version, pluginname, website, emil, author);
    return ptr;
}
EXTERN void cout(char* text) {
    if (text == 0) {
     return;
    }
   std::cout << text << std::endl;
}
  EXTERN void AddIntoArray(void* array, void* ptr) 
  {
     auto ptra = (std::vector<DotnetPlugin *>*)array;
     ptra->push_back((DotnetPlugin*)ptr);
  }
  EXTERN void* NewArray() {
      return new std::vector<DotnetPlugin *>();
  }

  EXTERN bool isOp(endstone::Permissible* ptr)
  {
      return ptr->isOp();
  }
  EXTERN bool hasPermission(char* name,endstone::Permissible* ptr) {
      return ptr->hasPermission(name);
   }
  EXTERN bool isPermissionSet(char *name, endstone::Permissible* ptr) {
      return ptr->isPermissionSet(name);
  }
  EXTERN void recalculatePermissions(endstone::Permissible *ptr, PermissionAttachment *attachment) {
      ptr->removeAttachment(*attachment);
  }
  EXTERN void setOp(bool num, endstone::Permissible* ptr) {
      ptr->setOp(num);
  }
  EXTERN void* getLogger(Plugin* plugin) {
      return &(plugin->getLogger());  
  }
  EXTERN void logger_info(endstone::Logger* logger,char* text) {
     logger->info(text);
  }
  EXTERN void logger_error(endstone::Logger* logger,char* text) {
     logger->error(text); 
  }
  EXTERN void logger_warn(endstone::Logger *logger, char* text) {
      logger->warning(text);
  }
  EXTERN void logger_trace(endstone::Logger *logger, char *text) {
      logger->trace(text);
      
  }
  EXTERN void logger_critical(endstone::Logger *logger, char *text)
  {
      logger->critical(text);
  }
  EXTERN void logger_debug(endstone::Logger *logger, char *text) {
      logger->debug(text);
      
  }
  EXTERN void* plugin_getserver(Plugin* plugin) {
      return &(plugin->getServer());
  }
  EXTERN const char* plugin_getname(Plugin* plugin) {
      return (plugin->getName().c_str());
      
  }
  EXTERN const char* plugin_getdataflor(Plugin* plugin) {
      return (plugin->getDataFolder().string().c_str());
  }
  EXTERN void* plugin_getcommand(Plugin* plugin,char* name) {
      return (plugin->getCommand(name));
  }
  }
