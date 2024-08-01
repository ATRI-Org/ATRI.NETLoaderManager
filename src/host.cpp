#define EXTERN __declspec(dllexport)
#include "plugin.h"
#include "vector"
#include "Windows.h"
#include <endstone/permissions/permissible.h>
wchar_t *charToWchar(const char *str)
{
    size_t len = strlen(str) + 1;
    wchar_t *wstr = new wchar_t[len];
    size_t converted = 0;
    mbstowcs_s(&converted, wstr, len, str, _TRUNCATE);
    return wstr;
}
extern "C" {
EXTERN void *RegisterPluginVoid(char *describe, char *version, char *pluginname, char *website, char *emil,
                                char *author, ENALBLECALL load, ENALBLECALL enable, ENALBLECALL disable)
{
    DotnetPlugin *ptr = new DotnetPlugin();
    ptr->buildPlugin(load, enable, disable, describe, version, pluginname, website, emil, author);
    return ptr;
}
EXTERN const wchar_t *plugin_getname(endstone::Plugin *plugin)
{
    return charToWchar(plugin->getName().c_str());
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
  EXTERN void recalculatePermissions(endstone::Permissible *ptr, endstone::PermissionAttachment *attachment)
  {
      ptr->removeAttachment(*attachment);
  }
  EXTERN void testlogger(endstone::Plugin *plugin, const char * data)
  {
    plugin->getLogger().error(data);
}
  EXTERN void setOp(bool num, endstone::Permissible* ptr) {
      ptr->setOp(num);
  }
  EXTERN void *getLogger(endstone::Plugin *plugin)
  {
      return &(plugin->getLogger());  
  }
  EXTERN void logger_info(endstone::Logger* logger,const char* text) {
     logger->info(text);
  }
  EXTERN void logger_error(endstone::Logger *logger,const char* text)
  {
     logger->error(text); 
  }
  EXTERN void logger_warn(endstone::Logger *logger, const char *text)
  {
      logger->warning(text);
  }
  EXTERN void logger_trace(endstone::Logger *logger, const char *text)
  {
      logger->trace(text);
      
  }
  EXTERN void logger_critical(endstone::Logger *logger, const char *text)
  {
      logger->critical(text);
  }
  EXTERN void logger_debug(endstone::Logger *logger, const char *text)
  {
      logger->debug(text);
      
  }
  EXTERN void *plugin_getserver(endstone::Plugin *plugin)
  {
      return &(plugin->getServer());
  }
  
  EXTERN const wchar_t *plugin_getdataflor(endstone::Plugin *plugin)
  {
      
      
      return charToWchar(plugin->getName().c_str());
  }
  EXTERN void *plugin_getcommand(endstone::Plugin *plugin, const char *name)
  {
      return (plugin->getCommand(name));
  }
  
  }
