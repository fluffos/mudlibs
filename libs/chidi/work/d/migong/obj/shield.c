#include <ansi.h> 
#include <armor.h>
 
inherit SHIELD;
 
void create()
{
	set_name(HIR"虎皮盾"NOR, ({ "hupi shield", "shield", "dun" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	
else {
		set("material", "leather");
		set("unit", "面");
		set("long", "这是一面用虎皮缝制而成的盾。\n");    set("value", 1000000);
		set("armor_prop/armor", 80);
		}
	setup();
}