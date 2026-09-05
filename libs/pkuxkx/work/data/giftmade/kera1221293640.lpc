// toy2.c	玩具(not autoload)
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW +"波斯猫"+ NOR, ({ "bosimao" }));
	set("long","这是一只可爱的波斯猫，它总是温柔的默默注视着你，\n目光中孕含着千种柔情，万般蜜意。\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_drop", 1);
        set("no_store",1);
		set("value",50000);
        set("no_give",1);
		set("owner", "kera");
		set("material", "gold");
	}
	setup();
}	

void init()
{
	add_action("do_play","play");
}

int do_play(string arg)
{
	if (!arg || arg!=query("id"))
	{
		write("你要玩什么？\n");
		return 1;
	}
	message_vision("$N轻轻地抚摸波斯猫的头，眼中充满爱怜。\n波斯猫懒懒地依偎在你的怀里撒娇。 \n     ("`--".___..--"`-._\n     `6_ 6     `-.  (    .`-.__.`\n \n",this_player());
	return 1;
}

