#pragma save_binary
// golden_sword.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIY"金锋剑"NOR, ({ "golden sword" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把闪闪发著金光的长剑。\n");
		set("value", 3400);
		set("material", "gold");
	}
	init_sword(40);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

// The setup() is required.

	setup();
}
