#pragma save_binary
// demon_staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( RED "* 霰 血 天 魔 杵 *" NOR, ({ "demon staff", "staff" }) );
      set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
            set("unit", "把");
            set("value", 10000);
            set("no_pawn", 1);
		set("long", "一把暗红色、两丈多长的巨杵。\n");
		set("material", "crimson gold");
	}
	init_staff(100);

	setup();
}
