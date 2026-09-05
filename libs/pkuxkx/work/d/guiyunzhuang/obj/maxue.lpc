
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIC "御马靴" NOR, ({ "ma xue", "xue" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "一双马靴");
		set("value", 6000);
		set("material", "boots");
		set("armor_prop/dodge", 2);
		set("guiyunzhuang",1);
	}
	setup();
}
