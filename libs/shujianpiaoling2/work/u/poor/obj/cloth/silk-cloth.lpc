
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("丝绸锦衣", ({ "silk-cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件有钱人才会穿的丝绸锦衣，穿上去觉得非常舒服。\n");
		set("unit", "件");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 1);
		set("female_only", 0);
	}
	setup();
}

