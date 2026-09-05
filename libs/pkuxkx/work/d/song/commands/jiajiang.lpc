// jiajiang.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "cmd_assist.h"
int help(object me);
int main(object me,string arg)
{
	object pl;
	string benefit="designate",type="month";
	if (arg=="-h")
	return help(me);
	if (DASONG_D->get_my_pin(me)!=1&&me->query("id")!="zine")
	return deny(me);
	song_cycle(me,type,benefit);
	if (me->query("song/"+benefit+"/times")>=3)
	{
		tell_object(me,"本月，你已至少行文吏部嘉奖三名官员了，不得滥用！\n");
		return 1;
	}
	if (!arg||arg=="")
	{
		tell_object(me,"你要行文吏部嘉奖哪名官员？\n");
		return 1;
	}
	if (present_song_user(me,arg)==1)
	pl=find_player(arg);
	else
	return 1;
	if (DASONG_D->get_my_pin(pl)<=0)
	{
		tell_object(me,pl->name()+"不是大宋官员！\n");
		return 1;
	}
	if (DASONG_D->get_my_pin(pl)>4)
	{
		tell_object(me,"这么小的官，你正式发文吏部，似乎有点小题大作！\n");
		return 1;
	}
	if (DASONG_D->get_my_pin(pl)==1)
	{
		tell_object(me,"嘉奖一品大员？你以为你是皇帝吗？\n");
		return 1;
	}
	if (pl->query("song/designate_obtain"))
	{
		tell_object(me,arg+"已经被吏部嘉奖了，此次提升将容易得多。\n");
		return 1;
	}
	if (pl->query("song/designated"))
	{
		tell_object(me,"这种简拔程序一人一生使用一次，足矣！\n");
		return 1;
	}
	me->add("song/"+benefit+"/times",1);
	pl->set("song/designated",1);
	pl->set("song/designate_obtain",1);
	message_vision("$N行文吏部嘉奖$n，$n将获得更多升迁时的便利。\n",me,pl);
	CHANNEL_D->do_channel(this_object(), "dasong", me->query("song/title")+me->query("name")+"("+capitalize(me->query("id"))+")行文吏部，嘉奖"+pl->query("name")+"("+capitalize(pl->query("id"))+")。", -1);
	return 1;
}
int help(object me)
{
    write("
指令格式 : song jiajiang <id> 
嘉奖某位大宋官员，使其获得升迁的便利。
"    );
    return 1;
}
