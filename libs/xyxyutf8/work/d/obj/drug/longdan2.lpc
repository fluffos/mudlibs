#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(BLU"孽龙丹"NOR, ({"long dan", "longdan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "这是一粒贵重的孽龙丹。\n");
		set("no_sell",1);
		set("no_get",1);
		set("no_steal",1);
		set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
		set("drug_type", "良药");
	}
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么东西？\n");
	if ((int)this_player()->query_temp("longdan2_eat")>5)
		return notify_fail("你吃不下了！\n");
		this_player()->add_temp("longdan2_eat", 1);
		this_player()->add("combat_exp", 10000);
		this_player()->add("potential",8000);
		message_vision(BLU"$N吃下一颗孽龙丹,只觉得自己又变利害了一些 !\n"NOR, this_player());
		destruct(this_object());
		return 1;
}

