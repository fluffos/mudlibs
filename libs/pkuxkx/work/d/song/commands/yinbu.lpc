// yinbu.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "cmd_assist.h"
int help(object me);
int main(object me,string arg)
{
	object pl;
	string benefit="yinbu",type="month";
	if (arg=="-h")
	return help(me);
	if (me->query("id")!="zine"&&!DASONG_D->identification(me,({"吏部尚书","吏部左侍郎","吏部右侍郎",})))
	return deny(me);
	song_cycle(me,type,benefit);
	if (DASONG_D->identification(me,({"吏部尚书"}))&&me->query("song/"+benefit+"/times")>=2)
	{
		tell_object(me,"本月，你已至少荫补了两名候补官员了。大宋官员名额有限，不得滥用！\n");
		return 1;
	}
	if (DASONG_D->identification(me,({"吏部左侍郎","吏部右侍郎",}))&&me->query("song/"+benefit+"/times")>=1)
	{
		tell_object(me,"本月，你已至少荫补了一名候补官员了。大宋官员名额有限，不得滥用！\n");
		return 1;
	}
	if (!arg||arg=="")
	{
		tell_object(me,"你要荫补哪位作为大宋候补官员？\n");
		return 1;
	}
	if (present_song_user(me,arg)==-1)
	pl=find_player(arg);
	else if (present_song_user(me,arg)==1)
	{
		tell_object(me,arg+"本来就是我朝官员，候补什么？\n");
		return 1;
	}
	else
	return 1;
	if (pl->query("family/family_name")=="朝廷")
	{
		tell_object(me,"你是想叛国吗？居然收清廷的人？\n");
		return 1;
	}
	if (pl->query("song/in_wait_list"))
	{
		tell_object(me,arg+"本来就是我朝候补官员，候补什么？\n");
		return 1;
	}
	me->add("song/"+benefit+"/times",1);
	pl->set("song/in_wait_list",1);
	tell_object(me,"你将"+arg+"荫补为大宋候补官员！\n");
	//tell_object(pl,me->query("name")+HIW+"将你荫补为大宋官员，只需十次史可法任务即可获得进入大宋的机会！\n"+NOR);
	CHANNEL_D->do_channel(this_object(), "dasong", me->query("name")+"("+capitalize(me->query("id"))+")荫补"+pl->query("name")+"("+capitalize(pl->query("id"))+")为大宋候补官员！", -1);
	return 1;
}
int help(object me)
{
    write("
指令格式 : yinbu <id> 
荫补某位非大宋官员为候补大宋官员。
"    );
    return 1;
}
