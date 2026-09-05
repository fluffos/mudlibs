#include <ansi.h>
#include <armor.h>

inherit HANDS;

void create()
{
	set_name("皮手套"NOR, ({ "pi shoutao", "gloves", "shoutao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一双牦牛皮制的皮手套，易于保暖，适合雪山之上穿用。\n"NOR);
		set("unit", "双");
		set("value", 200);
		set("material", "leather");
		set("armor_prop/armor", 1);
		set("armor_prop/hand", 4);
	}
	setup();
}