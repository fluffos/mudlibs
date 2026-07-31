
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(HIW"雪虹鞋"NOR, ({ "xuehong xie", "shoe", "shoes", "xie" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是一双小巧的女儿鞋。\n");
		set("unit", "双");
		set("value", 300);
		set("female_only",1);
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("armor_prop/dodge", 10);
	}
	setup();
}
