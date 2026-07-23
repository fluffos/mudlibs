// shoe.c

#include <armor.h>
inherit BOOTS;


void create()
{
	set_name( "布鞋", ({ "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一双手工精细的鞋子。\n");
		set("material", "cloth");
		set("unit", "双");
		set("armor_prop/armor", 1 );
	}
	setup();
}


