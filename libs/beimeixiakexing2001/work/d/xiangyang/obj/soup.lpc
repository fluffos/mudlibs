//Cracked by Roath
// soup.c

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
        set_name(HIG"野菜汤碗"NOR, ({"soup"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗新鲜野菜做的汤。\n");
                set("unit", "碗");
                set("value", 0);
        set("max_liquid", 4);
    }


    set("liquid", ([
        "type": "water",
        "name": "野菜汤",
        "remaining": 6,
        "drunk_supply": 15,
    ]));
}
