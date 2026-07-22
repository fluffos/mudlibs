#include <armor.h>
inherit ARMOR;
void create()
{
	set_name("羊皮袄",({"yangpi ao","cloth"}));
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","件");
		set("long","藏人从小穿到大的皮袄。\n");
	set("value",5000);
		set("material","armor");
		set("armor_prop/armor", 4);
	}
	setup();
}
