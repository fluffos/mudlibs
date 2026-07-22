// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "绣花小鞋", ({ "flower-shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一双绣着细花的小鞋，是女孩子的东西。\n");
		set("material", "cloth");
		set("unit", "双");
		set("value", 700);
		set("armor_prop/armor", 1 );
		set("female_only", 1);
	}
	setup();
}
