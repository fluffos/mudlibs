inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name("汾酒", ({"fenjiu", "jiu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一坛香气四溢的汾酒。\n");
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
