// jiajiang.c 
// Zine 2012/10/14
#include <ansi.h>
#include "cmd_assist.h"
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int main(object me,string arg)
{
	object pl;
	string benefit="designate",type="month";
	if (arg=="-h")
	return help(me);
	if (me->query("id")!="zine"&&!identifications(me,({"保和殿大学士","文华殿大学士","武英殿大学士","文渊阁大学士","体仁阁大学士","东阁大学士","五军都督府 大都督","五军都督府 左都督","五军都督府 右都督","五军都督府 都督同知"})))
	return deny(me);
	ming_cycle(me,type,benefit);
	if (me->query("ming/"+benefit+"/times")>=3)
	{
		tell_object(me,"本月，你已至少行文吏部嘉奖三名官员了，不得滥用！\n");
		return 1;
	}
	if (!arg||arg=="")
	{
		tell_object(me,"你要行文吏部嘉奖哪名官员？\n");
		return 1;
	}
	if (present_ming_user(me,arg)==1)
	pl=find_player(arg);
	else
	return 1;
	if (pl->query("mingpin")>4)
	{
		tell_object(me,"这么小的官，你正式发文吏部，似乎有点小题大作！\n");
		return 1;
	}
	if (pl->query("mingpin")==1)
	{
		tell_object(me,"嘉奖一品大员？你以为你是皇帝吗？\n");
		return 1;
	}
	if (pl->query("ming/designate_obtain"))
	{
		tell_object(me,arg+"已经被吏部嘉奖了，此次提升将容易得多。\n");
		return 1;
	}
	if (pl->query("ming/designated"))
	{
		tell_object(me,"这种简拔程序一人一生使用一次，足矣！\n");
		return 1;
	}
	me->add("ming/"+benefit+"/times",1);
	pl->set("ming/designated",1);
	pl->set("ming/designate_obtain",1);
	message_vision("$N行文吏部嘉奖$n，$n将获得更多升迁时的便利。\n",me,pl);
	message("daming",HIW"【大明】"+me->query("ming/title")+me->query("name")+HIW+"("+capitalize(me->query("id"))+")行文吏部，嘉奖"+pl->query("name")+HIW+"("+capitalize(pl->query("id"))+")。\n"NOR,users());
	return 1;
}
int help(object me)
{
    write("
指令格式 : ming jiajiang <id> 
嘉奖某位大明官员，使其获得升迁的便利。
"    );
    return 1;
}
