// sarong.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("»¨²¼È¹", ({ "sarong" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ìõ");
		set("material", "cloth");
		set("armor_prop/armor", 1);
                set("female_only", 1);
	}
	setup();
}