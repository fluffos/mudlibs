// mjade.c 神之翡翠

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIG "神之翡翠" NOR, ({ "magic jade" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIG "一颗焕发着奇异的光彩的翡翠，给人以不同寻常的感觉。"NOR"\n");
		set("base_value", 200000);
		set("base_weight", 1);
		set("base_unit", "颗");
		set("can_be_enchased", __DIR__"god_eyes");
		set("enchased_need", ({
			(["id":"magic crystal","name":"神之水晶"]),
			(["id":"magic diamond","name":"神之钻石"]),
			(["id":"magic agate","name":"神之玛瑙"]),
		}));
		set("magic/type", "cold");
		set("magic/power", 150);
	}
	set_amount(1);
	setup();
}
