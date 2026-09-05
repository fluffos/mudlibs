// toy.c	玩具
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG +"宝贝猪"+ NOR, ({ "pig" }));
	set("long","这是老公送给你的礼物--一头白白胖胖的小肥猪，完全是按照你的模样做的，漂亮极了\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "vee");
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
	message_vision("$N好奇地摁了一下小猪的鼻子，小猪撒娇地摇摇尾巴，哼哼道：我的老婆是小猪，咿呀咿嘿呦，白白胖胖呼噜噜，咿呀咿嘿呦......$N生气地打了小猪的屁股，小猪马上深情地唱起SEAL的KISS FROM ROSE：I'VE BEEN KISSED BY A ROSE ON THE GAY......$N听到这首熟悉的歌，紧紧抱着怀里的小猪，想起远在天涯的老公，泪水无声地滚落...... y\n",this_player());
	return 1;
}

