// key1.c

inherit ITEM;

void create()
{
        set_name("铁钥匙", ({"iron key","key"}));
        set("long",
                "这是一把铁钥匙，可能由于经常使用，被磨得闪闪发亮。\n");
        set("unit", "把");
        set("weight", 10);
        set("value", 0);
}
