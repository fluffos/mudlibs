#include <ansi.h>


int main(object me, string arg)
{
	mapping tasks;
	string result,task;
	int i,times;
	
	tasks = ([
		"yidao":"胡一刀任务",
		"xiaofeng":"萧峰任务",
		"husong":"护送任务",
		"songxin":"华山送信任务",
		"task":"TASK",
		"hubiao":"护镖任务",
		"yuxi":"慕容玉玺任务",
		"baowei":"保卫襄阳任务",
		"wananta":"万安塔任务",
		"han":"韩员外复仇任务",
		"hansz":"韩世忠任务",
		"mzj":"都府行刺任务",
		"gongsun":"绝情谷任务",
	]);
        result = "《北大侠客行》重要任务完成情况统计\n" +
                "----------------------------------------------------------------------------------------------------------\n"
                + "任务名称    完成次数  平均耗时  奖经验均值  奖潜能均值  奖声望均值  奖经验比均值    经验增长速度    奖功夫数\n"  
+                "----------------------------------------------------------------------------------------------------------\n";
        if (!arg || arg == "all")
        {
                for (i=0;i<sizeof(tasks);i++)
                {
                        task = keys(tasks)[i];
                        times = COMBAT_D->query("task_stat/" + task + "/complete_times");
                        if (times)
                                result += sprintf("%-14s%-10s%-10s%-12d%-12d%-12d%-16f%-16f%-10s\n",tasks[task],
                                        times+"次",
                                        COMBAT_D->query("task_stat/" + task + "/cost_time")/times+"秒",
                                        COMBAT_D->query("task_stat/" + task + "/exp")/times,
                                        COMBAT_D->query("task_stat/" + task + "/pot")/times,
                                        COMBAT_D->query("task_stat/" + task + "/repute")/times,
                                        to_float(COMBAT_D->query("task_stat/" + task + "/expratio")*10000)/times, 
                                        to_float(COMBAT_D->query("task_stat/" + task + "/expratio")*100000)/(COMBAT_D->query("task_stat/" + task + "/cost_time")), 
                                        COMBAT_D->query("task_stat/" + task + "/skill") + "级" );
                }
	}
	else if (!tasks[arg])
		return notify_fail("没有这种任务的统计信息，请help taskview查看可用的参数。\n");
	else {
		times = COMBAT_D->query("task_stat/" + arg + "/complete_times");
		if (!times)
			return notify_fail(tasks[arg] + "自上次更新combatd以来尚未有人做过，无统计信息。\n");
        result += sprintf("%-14s%-10s%-10s%-12d%-12d%-12d%-16f%-16f%-10s\n",tasks[arg],
					times+"次",
					COMBAT_D->query("task_stat/" + arg + "/cost_time")/times+"秒",
					COMBAT_D->query("task_stat/" + arg + "/exp")/times,
					COMBAT_D->query("task_stat/" + arg + "/pot")/times,
					COMBAT_D->query("task_stat/" + arg + "/repute")/times,
					to_float(COMBAT_D->query("task_stat/" + arg + "/expratio")*10000)/times,
                    to_float(COMBAT_D->query("task_stat/" + arg + "/expratio")*100000)/(COMBAT_D->query("task_stat/" + arg + "/cost_time")), 
                    COMBAT_D->query("task_stat/" + arg + "/skill") + "级" );
	}
	result += "----------------------------------------------------------------------------------------------------------\n";
 	result += "注意：本数据只统计了部分重要任务在百分之百成功时的奖励情况和升级速度，未统计任务失败率和难度等信息，谨供参考。\n奖经验比均值为奖励经验/玩家自身经验之比的均值，单位为万分之。经验增长速度为奖经验比*10/平均耗时\n";
	write(result);
	return 1;
}
int help()
{
        write(@LONG
指令格式：taskview  

查询部分重要任务的完成和奖励情况的统计信息。
参数包括：
		yidao
		xiaofeng
		husong
		songxin
		task
		hubiao
		yuxi
		baowei
		wananta
		hansz
		han
		mzj
		gongsun
不加参数或参数为all时为列出以上所有任务的相关统计信息
LONG
        );
        return 1;
}
