

# NETLoader for endstone

![Header](https://capsule-render.vercel.app/api?type=Waving&color=timeGradient&height=200&animation=fadeIn&section=header&text=NetLoader&fontSize=70)

## 目录

- [创建你的.net插件](#创建你的.net插件)
  - [开发前的配置要求](#开发前的配置要求)
  - [安装步骤](#安装步骤)
- [文件目录说明](#文件目录说明)
- [开发的架构](#开发的架构)
- [作者](#作者)
- [xnn支持](#)

### 创建你的.net插件


###### 配置

1. 安装.net9.0sdk https://dotnet.microsoft.com/en-us/download/dotnet/9.0
2. 安装vs2022(废话qwq
3. 将下载的plugins.zip解压进bds的根目录

###### **创建插件**

1. 打开vs2022创建.net core 类库项目,引用plugins/plugins_dotnet/stdlib中的stdlib.dll_
2. 复制temple文件,并填写文件信息
```c#
namespace Plugin
{
    [RegisterAttribute_]
    public static class Plugin
    {

        public static string Name { get; } = "dotnet_plugin_example";

        public static string version { get; } = "0.0.1";

        public static string website { get; } = "example.com";

        public static string describe { get; } = "This is a example";

        public static string author { get; } = "Youm1iHa";

        public static void onLoad()
        {
            Console.WriteLine("Loaded");
        }

        public static void onEnable()
        {
            Console.WriteLine("enable");
        }
        public static void onDisable()
        {
            Console.WriteLine("disable");
        }
    }
}
```
3. 放入mods文件夹,开启endstone运行

### 文件目录说明
eg:

```
files
├── plugins/plugins_dotnet/
|   ├──/runtime/
|   ├──/stdlib/
├── plugins/EndStoneDotNetLoader.dll
├── mods/
├── nethost.dll
```

### 开发的架构 

X64

### 作者

YoumiHa@ATRI.Org

 *您也可以在贡献者名单中参看所有参与该项目的开发者。*

### xnn支持

<a href="https://github.com/ATRI-Org/ATRI.NETLoaderManager/pulse">
  <img src="https://avatars.githubusercontent.com/u/60499296?s=80&v=4" />
</a>
