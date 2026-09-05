// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(BLK +"机器人测试机"+ NOR, ({ "antirobot" }));
	set("long","机器人测试机。\n\n");
	set_weight( 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "hash");
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
	message_vision("忽然一阵刺骨的奇寒袭来，你中的星宿毒掌毒发作了！\n结果你被他一击命中，他的剧毒散至你的全身！\n你略一动情，心如刀绞。\n你突然打了个寒战，明显感到一股寒流已经侵入体内！\n突然你打了个寒战，你中的冰魄寒毒发作了！\n你伤重之下已经难以支撑，眼看就要倒在地上。\n你已经陷入半昏迷状态，随时都可能摔倒晕去。\n你受伤过重，已经有如风中残烛，随时都可能断气。\n你摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。\n\n",this_player());
	return 1;
}

