#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("皮甲"NOR, ({ "pi jia", "armor", "jia" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件牦牛皮制的皮甲，轻便保暖，适合雪山之上穿用。\n"NOR);
		set("unit", "件");
		set("value", 800);
		set("material", "leather");
		set("armor_prop/armor", 41);
	}
	setup();
}