// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("¸Ö¼×",({"gangjia","jia","armor"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("material","iron");
		set("armor_prop/armor",30);
		set("value",3000);
	}
	setup();
}
