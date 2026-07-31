// p_hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("镏金大铜锤", ({ "copper hammer" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "柄");
		set("long", "这是一柄沈重的大铜锤，打造的相当坚实。\n");
		set("value", 400);
		set("material", "iron");
		set("wield_msg", "$N拿出一柄$n，试了试重量，然后握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_hammer(130);
        setup();
}
