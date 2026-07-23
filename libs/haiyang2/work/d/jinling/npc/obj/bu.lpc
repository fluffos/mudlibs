// g_cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("布", ({ "bu" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "匹");
		set("long", 
         "这是一匹普通的布，布质柔韧，有少许防御作用。\n");
		set("value", 100);
		set("armor_prop/armor", 1);
		set("material", "cloth");
	}
	setup();
}
