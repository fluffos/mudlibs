
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("千层底布鞋", ({ "qiancengdi", "shoes" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "这是一般人常穿的布鞋");
		set("value", 5000);
		set("material", "boots");
		set("armor_prop/dodge", 2);
		//set("shaolin",1);
	}
	setup();
}
