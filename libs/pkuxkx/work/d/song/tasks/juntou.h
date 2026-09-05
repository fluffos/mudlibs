#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "juntou"
mapping *tasks=({
		(["name":"引见军将","comment":"引见完成，你下去休息吧。\n","reward":2+random(2),"range":"2-3",]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}

int ask_task()
{
    object me=this_player();
    object ob=this_object(),gy;
	if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		gy=me->query_temp("song_identification");
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			gy->prepare_juntou(me);
			if (objectp(me->query_temp("songtasks/juntou/target")))
			{
				command("say 官家近日准备接见"+me->query_temp("songtasks/juntou/target")->query("name")+"，你去丽正门候着(wait)他吧。");
				tell_object(me,"如果接见对象是npc，不用wait，直接lead他福宁宫即可。\n");
				tell_object(me,"如果接见对象是玩家，在丽正门输入wait，见到玩家后输入yinjian，引入福宁宫即可。\n");
				tell_object(me,"如果对象玩家两分钟之内没有出现在和宁门，会有替补npc出现。\n");
				me->set_temp("songtasks/pass_palace",1);
				me->set_temp("songtasks/see_emperor",1);
			}
		}
        return 1;
    }
}



