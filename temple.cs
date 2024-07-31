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