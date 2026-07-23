// lingzhi.c 千年雪莲
//星星(lywin)2000/4/22

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
 set_name(HIR"新春超级大礼包"NOR, ({"kiss"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","每个人只有一个，你都这么大方！\n");
    set("value", 0);
set("no_steal",1);
set("no_beg",1);
set("liwu",1);
    set("no_put",1);
    set("no_get","每个人只有一个，不要这么贪心！\n");
    set("no_drop","这么珍贵的东西你也扔？！\n");

		set("unit", "棵");
set("long", "随机可以得到最多400的最大内力,最多10000潜能,最多50000的经验。\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");
 this_player()->start_busy(300);
 this_player()->set("qi",-1);
 this_player()->set("jing",-1);
  this_player()->add("max_neili",random(400));
 this_player()->set("neili",0);
  this_player()->add("eff_neili",20);
 this_player()->add("combat_exp",random(50000));
this_player()->add("potential",random(10000));
message_vision(HIR"$N亲亲的吻了吻狼，嘿嘿,你兴奋的晕死拉!\n"NOR, this_player());

	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
