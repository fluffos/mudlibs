//兵部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "junqi"
mapping *tasks=({
		(["name":"督造军械","comment":"新的军械造成，大宋军队的战力有了上升。\n","reward":2+random(5),"range":"2-6",]),
		(["name":"送交草图","comment":"希望新的草图能很快转换为战斗力。\n","reward":3+random(2),"range":"3-4",]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}

int ask_task()
{
    object me=this_player();
    object ob=this_object(),wg;
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			if (DASONG_D->get_my_pin(me)<5)
			command("say 大人可以在军器监城北作坊帮助督造(duzao)军械吗？");
			else
			command("say 你去军器监城北作坊帮助督造(duzao)军械吧。");
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==2)
		{
			if (DASONG_D->get_my_pin(me)<5)
			command("say 大人可以在军器监库房找(find)一张草图送(deliver)到城北作坊吗？");
			else
			command("say 你去军器监库房找(find)一张草图送(deliver)到城北作坊吧。");
		}
        ob->pre_1pin(me,DEPART,tasks);
        return 1;
    }
}



