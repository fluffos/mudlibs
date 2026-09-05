inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
        set_name("牛肉汤", ({"niurou tang","soup"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗热气腾腾的牛肉汤。\n");
                set("unit", "碗");
                set("value", 150);
                set("max_liquid", 4);
    }

    set("liquid", ([
        "type": "water",
        "name": "牛肉汤",
        "remaining": 12,
        "drunk_supply": 20,
    ]));
}

