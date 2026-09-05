inherit ITEM;
inherit F_LIQUID;
void create()
{
         set_name("烧刀子", ({"shao daozi", "jiu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一坛烧刀子，散发着浓烈的酒香\n");
                set("unit", "坛");
                set("value", 2000);
                set("max_liquid", 10);
                        }
set("liquid", ([
                 "type": "alcohol",
                 "name": "烧刀子",
                 "remaining": 10,
                 "drunk_apply": 50,
        ]));
}
