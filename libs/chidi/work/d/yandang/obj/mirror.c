// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("»¤ÐÄ¾µ", ({ "xinjing" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¸ö");
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	setup();
}
