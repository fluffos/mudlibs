#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "neidongmen"
mapping *tasks=({
		(["name":"登记造册","comment":"造册完成，你下去休息吧。\n","reward":3+random(4),"range":"3-6",]),
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
			command("say 今年宫内各处用度不一，你在这里查看(chakan)一下，登记造册吧。");
		}
        return 1;
    }
}



