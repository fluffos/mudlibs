// magate.c 神之玛瑙

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIR "神之玛瑙" NOR, ({ "magic agate" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIR "一块闪烁着奇异光芒的暗红色玛瑙，让人感到一阵阵的心悸。"NOR"\n");
		set("base_value", 200000);
		set("base_weight", 1);
		set("base_unit", "块");
		set("can_be_enchased", __DIR__"god_eyes");
		set("enchased_need", ({
			(["id":"magic crystal","name":"神之水晶"]),
			(["id":"magic diamond","name":"神之钻石"]),
			(["id":"magic jade","name":"神之翡翠"]), 
		}));
		set("magic/type", "fire");
		set("magic/power", 150);
	}
	set_amount(1);
	setup();
}
