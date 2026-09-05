// yinbu.c 
// Zine 2012/10/14
#include <ansi.h>
#include "cmd_assist.h"
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int main(object me,string arg)
{
	object pl;
	string benefit="yinbu",type="month";
	if (arg=="-h")
	return help(me);
	if (me->query("id")!="zine"&&!identifications(me,({"吏部尚书","吏部左侍郎","吏部右侍郎",})))
	return deny(me);
	ming_cycle(me,type,benefit);
	if (identification(me,"吏部尚书")&&me->query("ming/"+benefit+"/times")>=2)
	{
		tell_object(me,"本月，你已至少荫补了两名候补官员了。大明名额有限，不得滥用！\n");
		return 1;
	}
	if (identifications(me,({"吏部左侍郎","吏部右侍郎",}))&&me->query("ming/"+benefit+"/times")>=1)
	{
		tell_object(me,"本月，你已至少荫补了一名候补官员了。大明名额有限，不得滥用！\n");
		return 1;
	}
	if (!arg||arg=="")
	{
		tell_object(me,"你要荫补哪位作为大明候补官员？\n");
		return 1;
	}
	if (present_ming_user(me,arg)==-1)
	pl=find_player(arg);
	else if (present_ming_user(me,arg)==1)
	{
		tell_object(me,arg+"本来就是我朝官员，候补什么？\n");
		return 1;
	}
	else
	return 1;
	if (pl->query("gender")!="男性")
	{
		tell_object(me,"他这样的性别怎么立足朝堂之上呢？\n");
		return 1;
	}
	if (pl->query("family/family_name")=="朝廷")
	{
		tell_object(me,"你是想叛国吗？居然收清廷的人？\n");
		return 1;
	}
	if (pl->query("ming/in_wait_list"))
	{
		tell_object(me,arg+"本来就是我朝候补官员，候补什么？\n");
		return 1;
	}
	if (pl->query("ming/tj/pin"))
	{
		tell_object(me,arg+"本来就是我朝一名太监，候补什么？\n");
		return 1;
	}
	me->add("ming/"+benefit+"/times",1);
	pl->set("ming/in_wait_list",1);
	tell_object(me,"你将"+arg+"荫补为大明候补官员！\n");
	tell_object(pl,me->query("name")+HIW+"将你荫补为大明官员，只需十次史可法任务即可获得进入大明的机会！\n"+NOR);
	message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")荫补"+pl->query("name")+HIW+"("+capitalize(pl->query("id"))+")为大明候补官员！\n"NOR,users());
	return 1;
}
int help(object me)
{
    write("
指令格式 : yinbu <id> 
荫补某位非大明官员为候补大明官员。
"    );
    return 1;
}
