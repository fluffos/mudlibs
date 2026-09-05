// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG +"世界杯足球"+ NOR, ({ "kite" }));
	set("long","一个用世界上最大的牛皮做成的足球型风筝，\n巧妙利用了尘世众人吹牛时产生的小宇宙的力量使之升空，\n并能随着主人的心意攻入任意球门。\n\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "ahp");
		set("auto_load", 1);
		set("material", "gold");
	}
	setup();
}	

void init()
{
	if (this_player()->query("id")!=query("owner"))
	{
		message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
		message_vision(query("name")+"从$N的身上掉了下来，在地上滚了滚，不见了。\n",this_player());
		destruct(this_object());
		return;
	}
	add_action("do_play","play");
}

int do_play(string arg)
{
	if (!arg || arg!=query("id"))
	{
		write("你要玩什么？\n");
		return 1;
	}
	message_vision("$N一个大脚开出了世界杯足球，不料球转了一个超级大弯之后，直冲$N面门而来。\n$N大惊之下，派出飞天之鹰拦截，\n该之足球在前有追兵，后有堵截的艰难境况下，\n凭借巧妙的过人技巧，以哈雷彗星撞地球的气势撞破了$N的大牛皮。\n$N昏迷倒地之前喃喃自语：再也不唧唧歪歪了，饿的神呀！\n",this_player());
	return 1;
}

