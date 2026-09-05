//task.c
//Made by jason@pkuxkx
//2001.2.2
#include <ansi.h>
#include <localtime.h>

int main(object me)
{
	string output;
	mixed* timeinfos;
	int hour;
	int minute;



	if(!find_object(TASK_D)) 
		return notify_fail("任务精灵并未载入。\n");
    if (time()-me->query_temp("scan_time") < 6 && !wizardp(me))
                return notify_fail("不要频繁的查询，谢谢！\n");

    me->set_temp("scan_time",time());
        output=sprintf(HIW"                "+BBLU+HIW"北大侠客行任务榜"NOR);
        output += sprintf(HIR"\n─────────────────────────────────\n"NOR);
	output+=TASK_D->query_task_list();
        output += sprintf(HIR"─────────────────────────────────\n"NOR);
//        write(output);
        write(output);
    if(TASK_D->is_family_race_mode())
    {
        write("现在是门派争胜轮。完成task最多的门派在接下来的四个小时中，\n所有主流任务奖励提升两成!掉宝率提高两成。\n");
    }
    if(stringp(FAMILY_D->get_task_winner_family()) && sizeof(FAMILY_D->get_task_winner_family()) > 0 && FAMILY_D->get_task_winner_family() != "INVALID")
    {
        write("上一轮争胜模式胜利的门派是："+FAMILY_D->get_task_winner_family()+"\n");
    }
	timeinfos = localtime(TASK_D->get_next_family_task_time());

	hour = timeinfos[LT_HOUR];
	minute = timeinfos[LT_MIN];

    write("下一轮争胜模式开始的时间是："+chinese_number(hour)+"点"+chinese_number(minute)+"分。\n");
	return 1;
}

int help(object me)
{
        write(@HELP
        北大侠客行新增Task系统。task命令用于列出系统中的task，
        locate xxx的xxx用于寻找task所在的位置。找到后将其交给
        其主人，就可以得到奖励。
HELP
    );
    return 1;
}
