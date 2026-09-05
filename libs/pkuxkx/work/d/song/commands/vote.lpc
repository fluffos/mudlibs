// vote.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "cmd_assist.h"
int help(object me);
int main(object me,string arg)
{
	mixed tm=localtime(time());
	object ob;
	string user;
	string benefit="yushi_vote",type="day";
	if (arg=="-h")
	return help(me);
	if (me->query("id")!="zine"&&!DASONG_D->identification(me,({"御史大夫","御史中丞"})))
	return deny(me);
	song_cycle(me,type,benefit);
	if (DASONG_D->identification(me,({"御史大夫"}))&&me->query("song/"+benefit+"/times")>=2)
	return 0;
	if (DASONG_D->identification(me,({"御史中丞"}))&&me->query("song/"+benefit+"/times")>=1)
	return 0;
	if (!arg||arg=="")
	return 0;
	if (DASONG_D->identification(me,({"御史大夫","御史中丞"}))&&sscanf(arg, "unchblk %s", user) == 1)
	{
		if (!ob=find_player(user))
		return 0;
		else
		{
			if (ob->query("chblk_chat"))
			{
				ob->delete("chblk_chat");
				tell_object(me,"你发动大宋御史台的力量打开了"+ob->name()+"的聊天频道。\n");
				CHANNEL_D->do_channel(this_object(), "dasong", me->query("name")+"("+capitalize(me->query("id"))+")发动大宋御史台的力量打开了"+ob->query("name")+"("+capitalize(ob->query("id"))+")的聊天频道！", -1);
				me->add("song/"+benefit+"/times",1);
				return 1;
			}
			else
			return 0;
		}
	}
	else if (DASONG_D->identification(me,({"御史大夫"}))&&sscanf(arg, "chblk %s", user) == 1)
	{
		if (!ob=find_player(user))
		return 0;
		else
		{
			if (!ob->query("chblk_chat"))
			{
				ob->set("chblk_chat",1);
				tell_object(me,"你发动大宋御史台的力量关闭了"+ob->name()+"的聊天频道。\n");
				message("dasong",HIR"【大宋】"+me->query("name")+HIR+"("+capitalize(me->query("id"))+")发动大宋御史台的力量关闭了"+ob->query("name")+HIR+"("+capitalize(ob->query("id"))+")的聊天频道！\n"NOR,users());
				me->add("song/"+benefit+"/times",1);
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
发动大宋言官投票。
"    );
    return 1;
}
