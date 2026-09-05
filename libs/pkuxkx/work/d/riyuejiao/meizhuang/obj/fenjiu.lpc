//fenjiu.c	汾酒
//by bing
inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name("汾酒", ({"fen jiu", "jiu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一坛三锅头的陈年汾酒。\n");
                set("unit", "坛");
                set("value", 6000);
                set("max_liquid", 10);
                        }
set("liquid", ([
                "type": "alcohol",
                "name": "汾酒",
                "remaining": 10,
                "drunk_apply": 40,
        ]));
}
