// vote.c 
// Zine 2012/10/14
#include <ansi.h>
#include "cmd_assist.h"
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int main(object me,string arg)
{
	mixed tm=localtime(time());
	object ob;
	string user;
	string benefit="yushi_vote",type="day";
	if (arg=="-h")
	return help(me);
	if (me->query("id")!="zine"&&!identifications(me,({"左都御史","右都御史","左副都御史","右副都御史"})))
	return deny(me);
	ming_cycle(me,type,benefit);
	if ((identification(me,"左都御史")||identification(me,"右都御史"))&&me->query("ming/"+benefit+"/times")>=2)
	return 0;
	if ((identification(me,"左副都御史")||identification(me,"右副都御史"))&&me->query("ming/"+benefit+"/times")>=1)
	return 0;
	if (!arg||arg=="")
	return 0;
	if ((identifications(me,({"左都御史","左副都御史",})))&&sscanf(arg, "unchblk %s", user) == 1)
	{
		if (!ob=find_player(user))
		return 0;
		else
		{
			if (ob->query("chblk_chat"))
			{
				ob->delete("chblk_chat");
				tell_object(me,"你发动大明言官的力量打开了"+ob->name()+"的聊天频道。\n");
				message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")发动大明都察院的力量打开了"+ob->query("name")+HIW+"("+capitalize(ob->query("id"))+")的聊天频道！\n"NOR,users());
				me->add("ming/"+benefit+"/times",1);
				return 1;
			}
			else
			return 0;
		}
	}
	else if ((identifications(me,({"右都御史","右副都御史",})))&&sscanf(arg, "chblk %s", user) == 1)
	{
		if (!ob=find_player(user))
		return 0;
		else
		{
			if (!ob->query("chblk_chat"))
			{
				ob->set("chblk_chat",1);
				tell_object(me,"你发动大明言官的力量关闭了"+ob->name()+"的聊天频道。\n");
				message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")发动大明都察院的力量关闭了"+ob->query("name")+HIW+"("+capitalize(ob->query("id"))+")的聊天频道！\n"NOR,users());
				me->add("ming/"+benefit+"/times",1);
				return 1;
			}
			else
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
int help(object me)
{
    write("
指令格式 : vote <id> <unchblk/chblk> 
发动大明言官投票。
"    );
    return 1;
}
