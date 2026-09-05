// toy2.c	玩具(not autoload)
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG +"宝贝猪"+ NOR, ({ "pig" }));
	set("long","这是老公送给你的礼物--\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_drop", 1);
        set("no_store",1);
		set("value",50000);
        set("no_give",1);
		set("owner", "vee");
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
	message_vision("$N好奇地摁了一下小猪的鼻子，小猪撒娇地摇摇尾巴，哼哼道："我的老婆是小猪，咿呀咿嘿呦，白白胖胖呼噜噜，咿呀咿嘿呦……" \y 你生气地打了小猪的屁股，小猪马上深情地唱起SEAL的KISS FROM ROSE："I'VE BEEN KISSED BY A ROSE ON THE GAY……" \y 听到这首熟悉的歌，$N想起远在天涯的老公，望着怀里的小猪，鼻子一酸，泪水无声地滚落……\n",this_player());
	return 1;
}

