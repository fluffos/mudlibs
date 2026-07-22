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
	set_name(HIY"金龙丹"NOR, ({"long dan", "longdan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "这是一粒贵重的金龙丹。\n");
		set("no_sell",1);
		set("no_get",1);
		set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
		set("no_steal",1);
		set("drug_type", "良药");
	}
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么东西？\n");
	if ((int)this_player()->query_temp("longdan1_eat")>5)
		return notify_fail("你吃不下了！\n");
		this_player()->add_temp("longdan1_eat", 1);
		this_player()->add("max_kee", 300);
		this_player()->add("max_sen",300);
		message_vision("$N拿起金龙丹往嘴里一丢，胡乱咽了下去。\n", this_player());
		message_vision(HIY"$N觉得自己更加强壮了。\n"NOR, this_player());
		destruct(this_object());
		return 1;
}

