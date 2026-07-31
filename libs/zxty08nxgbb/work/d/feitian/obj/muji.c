// mu ji.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(HIM"日式木屐"NOR, ({ "mu ji", "ji"}) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "双");
		set("long", "一双用木头做成的鞋子。\n");
		set("value", 0);
		set("armor_prop/armor", 10 );
		set("female_only", 1);
	}
	setup();
}
