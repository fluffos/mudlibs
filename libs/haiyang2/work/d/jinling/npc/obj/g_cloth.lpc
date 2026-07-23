// g_cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("官差制服", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", 
         "这是一件官差穿的制服，布质柔韧，有少许防御作用。\n");
		set("value", 100);
		set("armor_prop/armor", 25);
		set("material", "cloth");
	}
	setup();
}
