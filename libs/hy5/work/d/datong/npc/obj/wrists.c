// wrists.c

#include <armor.h>

inherit WRISTS;

void create()
{
	set_name("Í­¶¤»¤Íó", ({ "wrists" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ë«");
		set("value",4000);
		set("material", "iron");
		set("armor_prop/armor", 30);
	}
	setup();
}
