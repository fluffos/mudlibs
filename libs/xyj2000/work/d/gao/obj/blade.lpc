// cracked by vikee 2/09/2002   vikee@263.net
// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("砍刀", ({ "blade" }) );
	set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
"一把大砍刀．\n");
                set("unit", "把");
                set("value", 1000);
        }
        init_blade(20);
        setup();
}

