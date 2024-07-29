
namespace Plugin
{
    public static class Plugin
    {
        public static string Name = "dotNet plugin example";
        public static string version = "0.0.1";
        public static string website = "example.com";
        public static string describe = "This is a example";
        public static string author = "Youm1iHa";

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
