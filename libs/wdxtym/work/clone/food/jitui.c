// jitui.c 鸡腿

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

void create()
{
	set_name("烤鸡腿", ({ "ji tui", "tui" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一枝烤得香喷喷的鸡腿。\n");
		set("unit", "根");
		set("value", 800);
		set("food_remaining", 10);
		set("food_supply", 100);
		set("wield_msg", "$N抓起一根$n，握在手中当武器。\n");
		set("material", "bone");
	}
	init_hammer(1);
	setup();
}

int finish_eat()
{
	object ob;
	ob = new("/d/city/obj/bone");
	ob->move(environment(this_object()));
	destruct(this_object());
	return 1;
}
