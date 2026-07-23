//Cracked by Roath
// icy_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( WHT"铁背心"NOR, ({ "tie beixin", "beixin" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 0);
		set("material", "iron");
		set("armor_prop/armor", 15);
		set("shaolin",1);
	}
	setup();
}
