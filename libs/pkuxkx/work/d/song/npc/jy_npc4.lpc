#include <ansi.h>
inherit __DIR__"song_officer";
#include "/d/song/tasks/jianyuan.h"
void create()
{
	call_out("npc_to_player",1,"左司谏",40,-1);
	::create();
}

void init()
{
	add_action("do_giveup","giveup");
}

int do_giveup()
{
	object me=this_player();
	if (me->query_temp("songtasks/jianyuan/task")!=1||!me->query("song/pro"))
	return 0;
	if (DASONG_D->get_my_pin(me)==1)
	return notify_fail("一品官员自选的任务不能放弃。\n");
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	command("say 既然你没什么意见和建议，那就算了，回政事堂看看相公们还有其他什么事可以麻烦你。");
	return 1;
}