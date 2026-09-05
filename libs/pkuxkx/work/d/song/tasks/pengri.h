#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "pengri"
#include "armytask.h"
mapping *tasks=({
		(["name":"换防殿前都驻地","comment":"换防完毕，你去休息吧。\n","reward":3+random(4),"range":"3-6",]),
		(["name":"招募新军","comment":"新军招来，你下去去休息吧。\n","reward":2+random(5),"range":"2-6",]),
		(["name":"突袭敌匪","comment":"敌匪消灭，你下去去休息吧。\n","reward":6+random(7),"range":"6-12",]),
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
			if (DASONG_D->get_my_pin(me)<5)
			command("say 将军可从捧日卫驻地调兵(diao)，带领此营官兵前去殿前都驻地换防。");
			else
			command("say 你从捧日卫驻地调兵(diao)，带领此营官兵前去殿前都驻地换防。");
		}
		if (member_array(me->query_temp("songtasks/"+DEPART+"/task"),({2,3}))!=-1)
		{
			armytask(me,ob,gy,DEPART);
		}
        pre_1pin(me,DEPART,tasks);
        return 1;
    }
}



