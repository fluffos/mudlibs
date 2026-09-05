#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("皮靴"NOR, ({ "pi xue", "shoes", "xue" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一双牦牛皮制的皮靴，易于保暖，适合雪山之上穿用。\n"NOR);
		set("unit", "双");
		set("value", 100);
		set("material", "leather");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", 1);
	}
	setup();
}