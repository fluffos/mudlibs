// tieshou.c玄天护手
#include <armor.h>
inherit HANDS;
void create()
{
	set_name( HIC"玄天护手"NOR, ({ "hands", "hand" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "块");
		set("long", "这是一块铁质的手掌形护具，用以保护手掌。\n");
		set("value", 1000);
                set("merit", 10);
                set("armor_prop/armor", 100);
                set("armor_prop/armor_vs_force", 20);
                set("armor_prop/intelligence", 100);
                set("armor_prop/attack", 100);
                set("armor_prop/dodge", -10);
		
	}
	setup();
}
