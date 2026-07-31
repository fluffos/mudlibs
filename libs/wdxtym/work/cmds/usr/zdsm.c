// quest.c
#include <ansi.h> 
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	mapping q;
	string area;
	int times=time();
	
	        if (me->is_ghost()) 
        return notify_fail("等你还了阳再说吧。\n");                 
        if (me->is_in_prison())   
        return notify_fail("你正在做牢呢。\n");
        if( me->query("doing") )
        return notify_fail("你还想干什么？！\n");
		if( me->is_net_dead()&& !me->query("zjvip/lxsm"))
        return notify_fail("你不符合使用条件？！\n");
	
		 if (me->query("combat_exp")>=800000 && ! objectp(ob = present("tishen kuilei", me)))
                return notify_fail("你身上又没有傀儡，死了咋办！\n"); 

		if(me->query("shimen/today")<3)
			{
					me->force_me("refuse quest");
			}else
				me->force_me("accept quest");
	if(!mapp(q=me->query("quest")))
	{
      		return notify_fail("你现在没有任务，使用自动师门干什么?\n");  
	}
	
	 if (me->is_fighting()) 
		return notify_fail("你现在正在战斗！\n");

	if(q["type"]!="kill")
	{
      		return notify_fail("你现在没有师门杀人任务，无需使用。\n");  
	}
	if(ob=find_living(""+q["id"]+""))
	{
		sscanf(base_name(environment(ob)),"/d/%s/%*s",area);
        message_vision(HIC"。。。。。。。。。。。。。"NOR"\n" , me);
		tell_object(me,HIR+q["name"]+NOR"（"+q["id"]+"）目前正在"HIW+MAP_D->query_map_short(area)+NOR"的"HIW+environment(ob)->query("short")+NOR"活动。\n");
me->move(environment(ob));
me->force_me("kill " + me->query("quest/id"));
	}
	else
	tell_object(me,"无法自动到目标人物，可能是目标人物已被杀死或者消失了。\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : quest  这个指令可以用来向你的门派的掌门或世家长辈
领取任务，如果不加任何参数则显示出你当前的任务。
HELP );
	return 1;
}

