inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("烧酒", ({"shao jiu", "jiu", "shaojiu"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个用来装着烧酒的牛皮大酒袋，大概装得八、九升的酒。\n");
                set("unit", "个");
                set("value", 100);
                set("max_liquid", 15);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "青稞烧酒",
                "remaining": 15,
                "drunk_apply": 3,
        ]));
}

