#include <assert.h>
#include <chrono>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include <vector>
#include <nethost.h>
#include <coreclr_delegates.h>
#include <hostfxr.h>
#include <Windows.h>
#define STR(s)        L##s
#define CH(c)         L##c
#define DIR_SEPARATOR L'\\'
#define string_compare wcscmp
using string_t = std::basic_string<char_t>;
namespace {
hostfxr_initialize_for_dotnet_command_line_fn init_for_cmd_line_fptr;
hostfxr_initialize_for_runtime_config_fn init_for_config_fptr;
hostfxr_get_runtime_delegate_fn get_delegate_fptr;
hostfxr_run_app_fn run_app_fptr;
hostfxr_close_fn close_fptr;
bool load_hostfxr(const char_t *app);
load_assembly_and_get_function_pointer_fn get_dotnet_load_assembly(const char_t *assembly);

int run_component_example(const string_t &root_path);
int run_app_example(const string_t &root_path);
} 

int LoadMain()
{
    char_t host_path[MAX_PATH];
    auto size = ::GetFullPathNameW(L"bedrock_server.exe", sizeof(host_path) / sizeof(char_t), host_path, nullptr);
    assert(size != 0);
    string_t root_path = host_path;
    auto pos = root_path.find_last_of(DIR_SEPARATOR);
    assert(pos != string_t::npos);
    root_path = root_path.substr(0, pos + 1);
    return run_component_example(root_path);
}

namespace {
int run_component_example(const string_t &root_path)
{
   
    if (!load_hostfxr(nullptr)) {
        assert(false && "Failure: load_hostfxr()");
        return EXIT_FAILURE;
    }

    const string_t config_path = root_path + STR("plugins\\plugins_dotnet\\runtime\\netloader.runtimeconfig.json");
    load_assembly_and_get_function_pointer_fn load_assembly_and_get_function_pointer = nullptr;
    load_assembly_and_get_function_pointer = get_dotnet_load_assembly(config_path.c_str());
    assert(load_assembly_and_get_function_pointer != nullptr && "Failure: get_dotnet_load_assembly()");
    const string_t dotnetlib_path = root_path + STR("plugins\\plugins_dotnet\\runtime\\netloader.dll");
    const char_t *dotnet_type = STR("Netmain.Pmain, netloader");
    const char_t *dotnet_type_method = STR("PluginMain");
    component_entry_point_fn PluginMain = nullptr;
    int rc = load_assembly_and_get_function_pointer(dotnetlib_path.c_str(), dotnet_type, dotnet_type_method,
                                                    nullptr, nullptr, (void **)&PluginMain);
    assert(rc == 0 && PluginMain != nullptr && "Failure: load_assembly_and_get_function_pointer()");
    struct lib_args {
        const char_t *message;
        int number;
    };
        lib_args args{STR("Loaded!"), 1};
        PluginMain(&args, sizeof(args));
    return EXIT_SUCCESS;
}}
namespace {
void *load_library(const char_t *);
void *get_export(void *, const char *);
void *load_library(const char_t *path)
{
    HMODULE h = ::LoadLibraryW(path);
    assert(h != nullptr);
    return (void *)h;
}
void *get_export(void *h, const char *name)
{
    void *f = ::GetProcAddress((HMODULE)h, name);
    assert(f != nullptr);
    return f;
}

bool load_hostfxr(const char_t *assembly_path)
{
    get_hostfxr_parameters params{sizeof(get_hostfxr_parameters), assembly_path, nullptr};
    // Pre-allocate a large buffer for the path to hostfxr
    char_t buffer[MAX_PATH];
    size_t buffer_size = sizeof(buffer) / sizeof(char_t);
    int rc = get_hostfxr_path(buffer, &buffer_size, &params);
    if (rc != 0) {
        return false;
    }
    void *lib = load_library(buffer);
    init_for_cmd_line_fptr =
        (hostfxr_initialize_for_dotnet_command_line_fn)get_export(lib, "hostfxr_initialize_for_dotnet_command_line");
    init_for_config_fptr =
        (hostfxr_initialize_for_runtime_config_fn)get_export(lib, "hostfxr_initialize_for_runtime_config");
    get_delegate_fptr = (hostfxr_get_runtime_delegate_fn)get_export(lib, "hostfxr_get_runtime_delegate");
    run_app_fptr = (hostfxr_run_app_fn)get_export(lib, "hostfxr_run_app");
    close_fptr = (hostfxr_close_fn)get_export(lib, "hostfxr_close");

    return (init_for_config_fptr && get_delegate_fptr && close_fptr);
}
// </SnippetLoadHostFxr>

// <SnippetInitialize>
// Load and initialize .NET Core and get desired function pointer for scenario
load_assembly_and_get_function_pointer_fn get_dotnet_load_assembly(const char_t *config_path)
{
    // Load .NET Core
    void *load_assembly_and_get_function_pointer = nullptr;
    hostfxr_handle cxt = nullptr;
    int rc = init_for_config_fptr(config_path, nullptr, &cxt);
    if (rc != 0 || cxt == nullptr) {
        std::cerr << "Init failed: " << std::hex << std::showbase << rc << std::endl;
        close_fptr(cxt);
        return nullptr;
    }

    // Get the load assembly function pointer
    rc = get_delegate_fptr(cxt, hdt_load_assembly_and_get_function_pointer, &load_assembly_and_get_function_pointer);
    if (rc != 0 || load_assembly_and_get_function_pointer == nullptr) {
        std::cerr << "Get delegate failed: " << std::hex << std::showbase << rc << std::endl;
    }

    close_fptr(cxt);
    return (load_assembly_and_get_function_pointer_fn)load_assembly_and_get_function_pointer;
}
} 
