#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "hetong"
mapping *tasks=({
		(["name":"坐堂","comment":"当值结束，你下去休息吧。\n","reward":3+random(4),"range":"3-6",]),
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
			command("say 你来替我一会，坐堂(zuotang)办公吧。");
			tell_object(me,"你只要判断是入宫还是出宫的器物，宫中宣索的物品，盖章stamp <要验>，出宫的物品，盖章stamp <凭由>。\n");
		}
        return 1;
    }
}



