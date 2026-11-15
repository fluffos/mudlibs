// jinsijia.c


#include <armor.h>

inherit ARMOR;

void create()
{
	set_name( HIY"金丝甲"NOR, ({ "jinsi jia", "jia"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
/*
		set("no_get", "1");
		set("no_put", "1");
		set("no_beg", "1");
		set("no_drop", "1");
		set("no_steal", "1");
*/
		set("value", 100000);
		set("material", "leather");
		set("armor_prop/armor", 100);
	}
	setup();
}


void owner_is_killed()
{
	write(HIY"只见眼前金光一闪...好象是....."NOR"\n");
	destruct(this_object());
} 
