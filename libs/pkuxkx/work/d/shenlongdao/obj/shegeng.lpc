// soup.c

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
        set_name("神龙羹", ({"shenlong geng","geng"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "一碗香喷喷的蛇羹。\n");
		set("unit", "碗");
		set("value", 150);
        set("max_liquid", 4);
    }

    // because a container can contain different liquid
    // we set it to contain tea at the beginning
    set("liquid", ([
        "type": "water",
        "name": "神龙羹",
        "remaining": 12,
        "drunk_supply": 20,
    ]));
}
