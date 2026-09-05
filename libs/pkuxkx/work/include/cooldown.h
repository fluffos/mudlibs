//cooldown 公共配置
#include "ansi.h"
string Common_Refuse_Msg="你暂时接不到这个任务。\n";
int CD_HYD_SL(object me,string mark)
{
	int mylvl;
	mylvl = ((int)me->query(mark+"/times")-250)/70;
	if (mylvl<=0) mylvl=0;
	if (mylvl>=5) mylvl=5;
	if ((int)me->query(mark+"/times")>1600)
	{
		mylvl=mylvl-((int)me->query(mark+"/times")-1600)/500;
		if (mylvl<=0) mylvl=0;
	}
	if (mark=="shenlong_zhanglao"&&me->query(mark+"/last_job_status")=="success") 
	mylvl=5;
	if (mark=="yidao"&&me->query_temp("yidaonotrobot")>0) 
	mylvl=5;
	if(ANTIROBOT_D->stopped())
	{
		mylvl = ((int)me->query(mark+"/times")-250)/70;
		if (mylvl<=0) mylvl=0;
		if (mylvl>=5) mylvl=5;
	}
	mylvl*=60;
	mylvl=600-mylvl;
	return mylvl;
}
mapping *all_jobs_cd(object me)
{
	return
	({
		(["job_id":"萧峰","mark":"xiaofeng/last_fail","cd_period":300,"group":1,"refuse_msg":"你先去在江湖中历练一番吧。",]),
		(["job_id":"萧峰","mark":"xiaofeng/last_job","cd_period":180,"group":1,"refuse_msg":"你先下去休息休息吧。",]),
		(["job_id":"韩世忠","mark":"hansz/last_fail","cd_period":300,"group":1,"refuse_msg":"你去江湖中历练一番吧。",]),
		(["job_id":"韩世忠","mark":"hansz/last_job","cd_period":180,"group":1,"refuse_msg":"你去休息休息，过段时间再来吧。",]),
		(["job_id":"公孙止","mark":"gongsun/last_fail","cd_period":300,"group":1,"refuse_msg":"你去江湖中历练一番再来吧。",]),
		(["job_id":"公孙止","mark":"gongsun/last_job","cd_period":180,"group":1,"refuse_msg":"你去休息休息，过段时间再来问我。",]),
		(["job_id":"萧峰","mark":"xiaofeng/on_job","cd_period":-1,"group":1,"refuse_msg":"上次交给你的任务还没有完成么？",]),
		(["job_id":"韩世忠","mark":"hansz/on_job","cd_period":-1,"group":1,"refuse_msg":"上次交给你的任务还没有完成么？",]),
		(["job_id":"公孙止","mark":"gongsun/on_job","cd_period":-1,"group":1,"refuse_msg":"上次交给你的任务还没有完成，你就来要新的任务了吗？",]),
		(["job_id":"胡一刀","mark":"yidao/on_job","cd_period":-1,"group":2,"refuse_msg":"上次交给你的任务还没有完成么？",]),
		(["job_id":"神龙长老","mark":"shenlong_zhanglao/on_job","cd_period":-1,"group":2,"refuse_msg":"上次交给你的任务还没有完成么？",]),
		(["job_id":"胡一刀","mark":"yidao/last_asked","cd_period":CD_HYD_SL(me,"yidao"),"group":2,"refuse_msg":"你不是刚刚要过任务么，你先下去休息吧！",]),
		(["job_id":"神龙长老","mark":"shenlong_zhanglao/last_asked","cd_period":CD_HYD_SL(me,"shenlong_zhanglao"),"group":2,"refuse_msg":"你不是刚刚要过任务么，你先下去休息吧！",]),
	});
}
int IfInCoolDown(object me,int group)//return 1则在cd中，0反之
{
	mapping *all_cd=all_jobs_cd(me),*my_cd=({});
	for (int i=0;i<sizeof(all_cd);i++)
	if (all_cd[i]["group"]==group)
	my_cd+=({all_cd[i]});
	if (sizeof(my_cd)==0)
	return 0;
	for (int i=0;i<sizeof(my_cd);i++)
	{
		if ((time()-me->query(my_cd[i]["mark"])<=my_cd[i]["cd_period"]&&my_cd[i]["cd_period"]>0)||(my_cd[i]["cd_period"]<0&&me->query(my_cd[i]["mark"])))
		{
			if (stringp(my_cd[i]["refuse_msg"])&&my_cd[i]["job_id"]==this_object()->query("job_id"))
			{
				if (this_object()->is_character())
				command("tell "+me->query("id")+" "+my_cd[i]["refuse_msg"]);
				else
				tell_object(me,my_cd[i]["refuse_msg"]+"\n");
			}
			else
			tell_object(me,Common_Refuse_Msg+"因为，你有"+my_cd[i]["job_id"]+"任务在身。\n");
			if (wizardp(me))
			{
				tell_object(me,"MARK CAUSED FAILURE TO ASK IS"+my_cd[i]["mark"]+"\n");
			}
			return 1;
		}
	}
	return 0;
}