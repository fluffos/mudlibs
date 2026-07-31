// shield.c 银色刺盾 
#include "ansi.h"
#include "armor.h"
 
inherit SHIELD;
 
void create()
{
	set_name(HIR"银色刺盾 "NOR, ({ "metal shield", "metalshield" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "面");
set("long", HIR"这是一面银色刺盾,做工极其精致。是众神的遗产之一。\n"NOR);
               set("value", 15000);
		set("armor_prop/armor",100);
		set("armor_prop/damage",10);
}
	setup();
}