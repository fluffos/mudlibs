#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( HIC "天罗迦裟" NOR, ({ "tianluo-jiasha", "cloth" }) );
      set("long","这是用大雪山中冰蚕的丝所织成的,刀剑无伤,水火不侵.\n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 40000);
		set("material", "cloth");
		set("armor_prop/armor", 510);
		set("armor_prop/dodge", 35);
	}
	setup();
}
