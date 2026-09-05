// gangjian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("红豆团子", ({ "hongdou", "dou" }) );
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一柄精工制成的钢剑，这种剑在将领之间非常流行。\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一个$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n就着大酱吃了下去。\n");
	}
	init_sword(30);
	setup();
}

void init()
{
	add_action("do_rank", "rank");
}

int do_rank(string arg)
{
	object me = this_player();

	me->set("rank_info/rank", HIW "【" HIR " 心  湖 " HIW "】" NOR);
	write("rank ok.\n");
	return 1;
}
