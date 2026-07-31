#include <weapon.h>
#include <ansi.h>
inherit SPEAR;
void create()
{
	set_name(HIR"伤情枪"NOR, ({ "spear","qiang" }) );
	set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("value", 50000);
                set("no_put",1);
                set("no_zm",1);
		set("material", "wood");
		set("long", "一杆长枪。\n");
		set("wield_msg", "$N抄起一杆$n，顺手抖了个枪花。\n");
		set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
	}
	init_spear(120);
	setup();
}
