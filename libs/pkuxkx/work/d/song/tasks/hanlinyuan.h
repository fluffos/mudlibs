#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "hanlin"
mapping *tasks=({
		(["name":"送画","comment":"书画已经呈送官家御览，你下去休息吧。\n","reward":2+random(2),"range":"2-3",]),
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
			command("say 官家想要鉴赏一幅画，你去翰林书画院找(find)出来，送过去吧。");
			me->set_temp("songtasks/see_emperor",1);
		}
        return 1;
    }
}



