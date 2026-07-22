// man-shoe.c
 
#include <armor.h>
 
inherit BOOTS;
 
void create()
{
	set_name("铁靴", ({ "tie xue", "tiexue","xue" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "tie");
		set("oldsix/max_damage",30);
		set("oldsix/protect",4);
		set("unit", "双");
		set("long", "这是一双精铁制作的靴子，用以保护双脚。\n");
		set("value", 4000);
		set("armor_prop/dodge", -3);
		set("armor_prop/armor", 6);
	}
	setup();
}
