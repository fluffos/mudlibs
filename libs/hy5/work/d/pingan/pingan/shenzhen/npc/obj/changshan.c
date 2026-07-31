// changshan.c
// 97.7.14 by Aug

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("青布长衫",({"cloth","chang shan","shan" }));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "件");
		set("material", "cloth");
		set("value",5000);
		set("armor_prop/armor",50);
	}
	setup();
}
