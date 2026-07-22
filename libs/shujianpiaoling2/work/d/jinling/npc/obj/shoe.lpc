// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "薄底快靴", ({ "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一种轻巧的鞋，江湖人士最喜欢穿。\n");
		set("material", "cloth");
		set("unit", "双");
		set("value", 500);
		set("armor_prop/armor", 1 );
		set("female_only", 0);
	}
	setup();
}
