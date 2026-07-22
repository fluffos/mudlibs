#include <weapon.h>
#include <ansi.h>
inherit SPEAR;
void create()
{
	set_name(HIY"乌日神枪"NOR, ({ "spear","qiang" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("value", 200000);
                set("no_put",1);
                set("no_zm",1);
		set("material", "wood");
		set("weapon_prop/courage", 5);
		set("long", "这是一件上古宝物。\n");
		set("wield_msg", "$N抄起一杆$n，顺手抖了个枪花。\n");
		set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
	}
	init_spear(150);
	setup();
}
