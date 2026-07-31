// color_head.c

#include <armor.h>
#include <ansi.h>

inherit SHIELD;

string* titles = ({
	HIY "雨花石" NOR,
	HIR "雨花石" NOR,
	HIG "雨花石" NOR,
	HIB "雨花石" NOR,
	HIM "雨花石" NOR,
	HIC "雨花石" NOR,
	HIW "雨花石" NOR,
});

void create()
{
	int i = random(sizeof(titles));

	set_name(titles[i], ({ "stone", "yuhuashi" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一块美丽的雨花石。\n");
		set("unit", "块");
		set("value", 1000);
		set("material", "stone");
		set("armor_prop/armor", 1);
//		set("armor_prop/personality", 0);
//		set("female_only", 1);
	}
	setup();
}

