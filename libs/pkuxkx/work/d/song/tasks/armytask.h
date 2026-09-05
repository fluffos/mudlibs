#include <ansi.h>

int armytask(object me,object ob,object gy,string depart)
{
	if (me->query_temp("songtasks/"+depart+"/task")==1)
	{
		gy->prop_target(me,depart);
		if (DASONG_D->get_my_pin(me)<5)
		command("say 将军可从"+environment(ob)->query("songtasks/task_myid")+"驻地调兵(diao)，带领此营官兵前去"+me->query_temp("songtasks/"+depart+"/huanfang_target_name")+"驻地换防。");
		else
		command("say 你从"+environment(ob)->query("songtasks/task_myid")+"驻地调兵(diao)，带领此营官兵前去"+me->query_temp("songtasks/"+depart+"/huanfang_target_name")+"驻地换防。");
		return 1;
	}
	if (me->query_temp("songtasks/"+depart+"/task")==2)
	{
		gy->prop_recruit(me,depart);
		if (DASONG_D->get_my_pin(me)<5)
		command("say 将军可去招募乡勇(recruit)，带领新募兵员前去城北兵站。");
		else
		command("say 你去招募乡勇(recruit)，带领新募兵员前去城北兵站。");
		ANTIROBOT_D->mxpantirobot_ex(me,me->query_temp("songtasks/"+depart+"/recruit_place_c")+"招募新军");
		return 1;
	}
	if (me->query_temp("songtasks/"+depart+"/task")==3)
	{
		gy->prop_war(me,depart);
		if (DASONG_D->get_my_pin(me)<5)
		command("say 将军可去"+environment(ob)->query("songtasks/task_myid")+"驻地点起(diao)一营官兵，进剿临安府"+me->query_temp("songtasks/"+depart+"/loc")+"门外的一队"+me->query_temp("songtasks/"+depart+"/enemy_name")+"。");
		else
		command("say 你去"+environment(ob)->query("songtasks/task_myid")+"驻地点起(diao)一营官兵，进剿临安府"+me->query_temp("songtasks/"+depart+"/loc")+"门外的一队"+me->query_temp("songtasks/"+depart+"/enemy_name")+"。");
		return 1;
	}
}



