// soup.c

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
	set_name(HIG"荷叶冬笋汤"NOR, ({"soup"}));
        set_weight(900);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗香气扑鼻的荷叶冬笋汤。\n");
		set("unit", "碗");
                set("value", 600);
        set("max_liquid", 4);
    }

    // because a container can contain different liquid
    // we set it to contain tea at the beginning
    set("liquid", ([
        "type": "water",
        "name": "荷叶冬笋汤",
        "remaining": 5,
        "drunk_supply": 20,
    ]));
}
