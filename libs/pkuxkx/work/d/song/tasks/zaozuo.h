#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "zaozuo"
mapping *tasks=({
		(["name":"整修车驾","comment":"修整完成，你下去休息吧。\n","reward":2+random(2),"range":"2-3",]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}

int ask_task()
{
    object me=this_player();
    object ob=this_object(),gy,che;
	if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		gy=me->query_temp("song_identification");
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			che=new("/d/song/obj/che");
			che->move(environment(ob));
			che->set("owner",me);
			command("say 官家不日准备出行，你去看看车驾备妥了吗。");
			message_vision("$N吩咐几个小黄门把官家的车辇推了出来。\n",ob);
		}
        return 1;
    }
}



