// jitui.c 鸡腿

#include <weapon.h>

inherit DAGGER;
inherit F_FOOD;

void create()
{
        set_name("烤鸡翅", ({ "kao jichi","jichi", "chi" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一枝烤得香喷喷的鸡翅。\n");
                set("unit", "枝");
             set("value", 140);
                set("food_remaining", 6);
             set("food_supply", 6);
                set("wield_msg", "$N抓起一枝$n，握在手中当武器。\n");
		set("material", "bone");
	}
        init_dagger(1);
	setup();
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
        set_name("啃得精光的鸡翅骨", ({ "bone" }) );
	set_weight(150);
        set("long", "一枝啃得精光的鸡翅骨。\n");
	return 1;
}
