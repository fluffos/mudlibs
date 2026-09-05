// zhenwujian.c 真武剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIW"真武剑"NOR, ({ "zhenwu jian", "sword" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一副锈迹斑斑的剑鞘，只能看见露在外面的剑柄，深褐色的松纹檀木吞手，使人不由的肃然生敬。\n");
             set("value", 250000);
		set("material", "steel");
		set("wield_msg", HIW "$N从一柄锈迹斑斑的剑鞘中缓缓抽出一把古色古香的长剑。\n" NOR);
		set("unwield_msg", HIY "$N倒转剑锋，慢慢的将真武宝剑还回剑鞘。\n" NOR);
	}
     init_sword(500);
	setup();
}
