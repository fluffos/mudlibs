inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
        set_name(HIW"鱼头豆腐汤"NOR, ({"yutoudoufu tang","soup"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗热气腾腾的鱼头豆腐汤。\n");
                set("unit", "碗");
                set("value", 150);
                set("max_liquid", 4);
    }

    set("liquid", ([
        "type": "water",
        "name": "鱼头豆腐汤",
        "remaining": 12,
        "drunk_supply": 20,
    ]));
}
