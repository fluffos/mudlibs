
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("木锤", ({ "mu hammer", "hammer" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 16);
                set("material", "woo");
                set("long", "一把大槌\n");
        }
	init_hammer(4);
        setup();

}
