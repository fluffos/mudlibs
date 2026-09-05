#include <ansi.h>
#include "pre&post_task.h"
#include "armytask.h"
#define DEPART "majun"
mapping *tasks=({
		(["name":"换防驻地","comment":"换防完毕，你去休息吧。\n","reward":3+random(4),"range":"3-6",]),
		(["name":"招募新军","comment":"新军招来，你下去去休息吧。\n","reward":2+random(5),"range":"2-6",]),
		(["name":"突袭敌匪","comment":"敌匪消灭，你下去去休息吧。\n","reward":6+random(7),"range":"6-12",]),
		(["name":"驯服战马","comment":"战马驯服了？你果然是此中高手啊。\n","reward":3+random(2),"range":"3-4",]),
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
		if (member_array(me->query_temp("songtasks/"+DEPART+"/task"),({1,2,3}))!=-1)
		{
			armytask(me,ob,gy,DEPART);
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==4)
		{
			gy->prop_horse(me);
			if (DASONG_D->get_my_pin(me)<5)
			command("say 马军都有匹战马神骏异常，可又野性难驯，将军可去马场驯服它。");
			else
			command("say 马军都有匹战马神骏异常，可又野性难驯，你去去马场驯服它。");
			tell_object(me,"驯服后把马牵进北面的马厩以完成任务。\n");
		}
        pre_1pin(me,DEPART,tasks);
        return 1;
    }
}



