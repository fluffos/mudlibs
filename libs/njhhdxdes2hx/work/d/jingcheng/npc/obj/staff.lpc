// staff.c

#include <weapon.h>  
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name(YEL"黄铜禅杖"NOR, ({ "brass staff", "staff" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条又粗又长，非常沈重的黄铜禅杖，上面镶著六个铜环。\n");
		set("value", 2000);
		set("material", "brass");
		set("wield_msg", YEL"$N拿出一根金光灿然的$n握在手中。\n"NOR);
		set("unwield_msg", YEL"$N放下手中的$n。\n"NOR);
	}

	init_staff(30);
	setup();
}
