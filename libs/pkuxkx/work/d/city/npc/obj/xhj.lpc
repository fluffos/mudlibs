inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name("雄黄酒", ({"xionghuang jiu", "xhjiu", "jiu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一坛为端午节特制的雄黄酒，据说有辟邪的作用\n");
                set("unit", "坛");
                set("value", 4000);
                set("max_liquid", 10);
                        }
set("liquid", ([
                 "type": "water",
                 "name": "雄黄酒",
                 "remaining": 10,
                 "drunk_apply": 50,
        ]));
}
