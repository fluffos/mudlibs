// /d/heifeng/up.c

inherit ROOM;
#include "up.h"

void init()
{
	add_action("do_pick","cai");
}

int do_pick(string arg)
{
	mapping quest;
	object me = this_player(),ob;

	if(arg != "灵芝" && arg != "lingzhi")
		return notify_fail("你要采什么？\n");

	if(mapp(quest = me->query("quest/shaolin_quest"))
	&& quest["name"] == "紫灵芝"
	&& undefinedp(quest["have_get"]))
	{
		if(sum <= 0)
		{
			message_vision("$N小心翼翼地挪步到悬崖边，一弯腰只抓到了一把蒿草，随手扔在了地下。\n",me);
			return 1;
		}

		if(undefinedp(quest["killed_wugong"]))
		{
			message_vision("$N小心翼翼地挪步到悬崖边，突然窜出来一条大蜈蚣。\n",me);
			ob = new(__DIR__"npc/wugong");
			ob->move(this_object());
			ob->kill_ob(me);
			me->kill_ob(ob);
			return 1;
		}

		message_vision("$N小心翼翼地挪步到悬崖边，采下了一颗紫灵芝。\n",me);
		ob = new(__DIR__"obj/lingzhi");
		if(!ob->move(me))
			ob->move(this_object());
		me->set("quest/shaolin_quest/have_get",1);

		sum--;
		if(!sum && (find_call_out("do_add") == -1))
			call_out("do_add",180);
		return 1;
	}
	message_vision("$N小心翼翼地挪步到悬崖边，一弯腰只抓到了一把蒿草，随手扔在了地下。\n",me);
	return 1;
}

private void do_add()
{
	if(sum >= max)
		return;
	sum++;
	if(sum >= max)
		return;
	call_out("do_add",180);
}
