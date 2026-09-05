inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name("老白干", ({"lao baigan", "baigan", "jiu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是江湖好汉最喜欢的老白干。\n");
                set("unit", "坛");
                set("value", 2000);
                set("max_liquid", 10);
                        }
set("liquid", ([
                "type": "alcohol",
                "name": "老白干",
                "remaining": 10,
                "drunk_apply": 40,
        ]));
}
