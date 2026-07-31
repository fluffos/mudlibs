// lingzhi.c 千年灵芝
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
//        call_out("announce",random(10),this_player());
}

void create()
{
	set_name(HIR"千年灵芝"NOR, ({"ling zhi", "zhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵武林人士梦寐以求的千年灵芝，据说吃一棵可得500经验，200潜能。\n");
		set("value", 0);
	}
	setup();
}

void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "sys",
            who->query("name")+"("+who->query("id")+")"+"得到了"+name()+"！\n");
}
int do_eat(string arg)
{	int addnj;
	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	addnj=1+random(2);
	this_player()->add("combat_exp", 500+random(300));
	this_player()->add("potential",200+random(80));
	this_player()->add("max_neili",1+random(2));
	this_player()->add("max_jingli",addnj);
	this_player()->add("eff_jingli",addnj);
	message_vision("$N吃下一棵千年灵芝，只觉得自己又变利害了一些 !\n", this_player());
	destruct(this_object());
	return 1;
}

