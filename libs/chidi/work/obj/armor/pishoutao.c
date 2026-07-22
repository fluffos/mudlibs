// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit HANDS;

void create()
{
	set_name("Æ¤ÊÖÌ×",({"pishoutao","shoutao"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","Ë«");
		set("material","iron");
		set("armor_prop/armor",5);
	}
	setup();
}
