#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name(RED"轰天锤"NOR, ({ "bighammer", "hammer" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("material", "steel");
		set("long", "这是一把沉重的轰天锤，锤起东西来非常历害。\n");
		set("value", 1500);
//                set("no_put", 1);
//                set("no_drop", 1);
 		set("wield_msg", "$N拿出一把$n，握在手中当作武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_hammer(800, TWO_HANDED);
	setup();
}
