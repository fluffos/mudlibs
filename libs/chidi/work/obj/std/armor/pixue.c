// man-shoe.c
 
#include <armor.h>
 
inherit BOOTS;
 
void create()
{
	set_name("皮靴", ({ "pi xue", "pixue","xue" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "pi");
		set("unit", "双");
		set("long", "这是一双牛皮制作的靴子，用以保护双脚。\n");
		set("value", 1000);
		set("armor_prop/dodge", 5);
		set("armor_prop/armor", 2);
	}
	setup();
}
