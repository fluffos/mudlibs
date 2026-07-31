// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("ÉúĞâµÄÌú¼×",({"tiejia","jia","armor"}));
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼ş");
		set("material","iron");
		set("armor_prop/armor",20);
		set("value",1000);
	}
	setup();
}
