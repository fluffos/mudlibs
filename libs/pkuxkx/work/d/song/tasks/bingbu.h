//兵部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "bingbu"
mapping *tasks=({
		(["name":"城北兵站操练新军","comment":"不错不错，新军练成，我大宋必再添一强镇。\n","reward":5+random(5),"range":"5-9",]),
		(["name":"询问述职","comment":"你的评价很中肯。\n","reward":3+random(2),"range":"3-4",]),
		(["name":"库部司清点军粮","comment":"不错不错，这么快清点完军粮，我大宋城池必固若金汤。\n","reward":4,"range":"4-4",]),
	});
int ask_finish()
{
    object me=this_player(),ob=this_object();
	string *desc=({"可堪大任","不堪造就","能力平平","天人之资"});
    if (me->query_temp("songtasks/"+DEPART+"/wg_degree")>20)
    message_vision("$N向$n汇报："+me->query_temp("songtasks/"+DEPART+"/wg_name")+"“"+desc[random(sizeof(desc))]+"”。\n",me,ob);
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
		if (me->query_temp("songtasks/"+DEPART+"/task")==2)
		{
			wg=new(__DIR__"wu_guan");
			wg->set("owner",me);
			wg->move("/d/song/bingbusi1");
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N对$n道：听说来了个武官叫做"+wg->name()+"在职方司衙门等候述职，我去问问(ask)他。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 来了个武官叫做"+wg->name()+"在职方司衙门等候述职，大人可以代我去问问(ask)他吗？");
			else
			{
				message_vision("$N看着$n，朗声道：有武职官在职方司衙门述职，你去问问(ask)他吧。\n",ob,me);
				message_vision("$N又道：他的名字叫作"+wg->name()+"什么的。一定要事无巨细，多问几次，知道了解清楚再来回报。\n",ob);
			}
		}
		else
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，朗声道：我朝大军与蒙古人在襄阳正在激战，我去看看"+tasks[me->query_temp("songtasks/"+DEPART+"/task")-1]["name"]+"的情况。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 我朝大军与蒙古人在襄阳正在激战，大人有空去看看"+tasks[me->query_temp("songtasks/"+DEPART+"/task")-1]["name"]+"的情况。");
			else
			message_vision("$N看着$n，朗声道：我朝大军与蒙古人在襄阳正在激战，你且去"+tasks[me->query_temp("songtasks/"+DEPART+"/task")-1]["name"]+"吧。\n",ob,me);
			if (me->query_temp("songtasks/"+DEPART+"/task")==1)
			tell_object(me,"到达城北兵站之后，先行检阅(jianyue)，之后继续练兵(lianbing)。\n");
		}
        pre_1pin(me,DEPART,tasks);
        return 1;
    }
}



