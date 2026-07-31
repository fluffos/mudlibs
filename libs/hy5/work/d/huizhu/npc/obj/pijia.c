// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("皮甲",({"pi jia","pijia","jia"}));
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material","pi");
		set("long", "这是一件牛皮制成的甲胄，用来保护上半身。\n");
		set("armor_prop/armor",10);
		set("value",2000);
	}
	setup();
}
