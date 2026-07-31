// g_cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("绸缎", ({ "silk" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "匹");
		set("long", 
         "这是一匹普通的绸缎，质地柔软。\n");
		set("value", 500);
		set("armor_prop/armor", 11);
		set("material", "cloth");
	}
	setup();
}
