// langpi.c

inherit ITEM;

void create()
{
        set_name("狼皮", ({ "wolf skin", "skin" }));
        set_weight(3000);
        
        set("unit", "张");
        set("long", "这是一张上等的" + name() + 
                    "，大得可做成垫子。\n");
        set("value", 3000);
}

