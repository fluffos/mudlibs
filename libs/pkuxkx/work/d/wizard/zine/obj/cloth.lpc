// pink_cloth.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIY"黄袍"NOR, ({ "huang pao","pao", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件明黄色的长袍，做工考究。\n");
		set("unit", "件");
		set("value", 600);
		set("material", "cloth");
		set("armor_prop/armor", 100);
	}
	setup();
}

