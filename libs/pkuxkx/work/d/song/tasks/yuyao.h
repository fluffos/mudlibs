#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "yuyao"
mapping *tasks=({
		(["name":"试药","comment":"试药完成，你下去休息吧。\n","reward":3+random(4),"range":"3-6",]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}

int ask_task()
{
    object me=this_player();
    object ob=this_object(),gy,dan;
	if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		gy=me->query_temp("song_identification");
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			dan=new("/d/song/obj/drug");
			dan->move(ob);
			dan->set("owner",me);
			command("say 这里有盒药丸，是进献给官家的，你先试吃一粒。");
			command("give "+me->query("id")+" dan");
		}
        return 1;
    }
}



