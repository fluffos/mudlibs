// mcrystal.c 神之水晶

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIM "神之水晶" NOR, ({ "magic crystal" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM "一块闪烁着奇异光芒的粉色水晶，让人感到一阵阵的心悸。"NOR"\n");
		set("base_value", 200000);
		set("base_weight", 1);
		set("base_unit", "块");
		set("can_be_enchased", __DIR__"god_eyes");
		set("enchased_need", ({
			(["id":"magic agate","name":"神之玛瑙"]),
			(["id":"magic diamond","name":"神之钻石"]),
			(["id":"magic jade","name":"神之翡翠"]), 
		}));
		set("magic/type", "magic");
		set("magic/power", 150);
	}
	set_amount(1);
	setup();
}
