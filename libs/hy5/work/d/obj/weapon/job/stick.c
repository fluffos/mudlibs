// blade.c

#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("无常棒", ({"wuchang bang", "bang"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一把精巧的短棒，一头是白色，一头是黑色。\n");
                set("unit", "根");
		set("material", "steel");
		set("wield_msg", "$N阴笑一声，手里已多了一把$n。\n");
                set("value", 3000);
        }
        init_club(40);
        setup();
}
