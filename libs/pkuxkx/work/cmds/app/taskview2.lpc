//taskview2是基于COMBAT_D记录的任务完成信息，给出任务奖励程度合理性的建议。
//所以不统计每天只能完成有限次数的保卫、漂流等等，只统计主流任务。Zine
#include <ansi.h>


int main(object me)
{
	mapping tasks,tasks_true_death,tasks_diffculty,tasks_diffculty2;
	string result,task;
	int i,times,mean_duration,mean_exp,mean_pot,mean_rep,base_value;
	float overall;
	tasks = ([
		"yidao":"胡一刀任务",
		"xiaofeng":"萧峰任务",
		"husong":"护送任务",
		"task":"TASK",
		"hubiao":"护镖任务",
		"yuxi":"慕容玉玺任务",
        "han":"韩员外复仇任务",
	]);
    tasks_true_death = ([
		"yidao":1,
		"xiaofeng":0,
		"husong":1,
		"task":1,
		"hubiao":1,
		"yuxi":1,
        "han":1,
	]);
    tasks_diffculty2 = ([
		"yidao":0,
		"xiaofeng":0,
		"husong":1,
		"task":1,
		"hubiao":0,
		"yuxi":0,
        "han":0,
	]);//竞争性或团队任务为1，其余为0
    tasks_diffculty = ([
		"yidao":7,
		"xiaofeng":10,
		"husong":6,
		"task":5,
		"hubiao":2,
		"yuxi":3,
        "han":6,
	]);//任务难易程度，1最容易，10最难（包含战斗以及找npc的难度）
        result = "《北大侠客行》任务奖励性价比报告\n" +
                "—————————————————————————————————————————————————————\n"+
        sprintf("%-14s%-16s%-16s%-16s\n","任务","综合性价比","真死与否","任务难度");
                for (i=0;i<sizeof(tasks);i++)
                {
                        task = keys(tasks)[i];
                        times = COMBAT_D->query("task_stat/" + task + "/complete_times");
                        if (!times)
                        continue;
                        mean_duration=COMBAT_D->query("task_stat/" + task + "/cost_time")/times;
                        mean_exp=COMBAT_D->query("task_stat/" + task + "/exp")/times;
                        mean_pot=COMBAT_D->query("task_stat/" + task + "/pot")/times;
                        mean_rep=COMBAT_D->query("task_stat/" + task + "/repute")/times;
                        base_value=(mean_exp*10+mean_pot*7+mean_rep*3)/10;
                        overall=(base_value/5*(5-tasks_true_death[task])+base_value*(10-tasks_diffculty[task])/10)/mean_duration;
                        overall=overall/(1+tasks_diffculty2[task]);
                        result+= sprintf("%-14s%-16f%-16d%-2d%-2s%-2d\n",task,overall,tasks_true_death[task],tasks_diffculty[task],"/",tasks_diffculty2[task]);
                      
                }
        tell_object(me,result);
        return 1;
}
int help()
{
        write(@LONG
指令格式：taskview2  

计算主流任务奖励情况的合理性。
LONG);
        return 1;
}
