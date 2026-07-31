// cloth.c
//
// This is the basic equip for players just login.
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(RED "血色战袍" NOR, ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
                set("value", 50000);
		set("armor_prop/armor", 100);
	}
	setup();
}
