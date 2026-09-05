// 保卫查询 by whuan@pkuxkx
#include <ansi.h>
inherit F_CLEAN_UP;
#include <localtime.h>

int main(object me)
{
        mixed *info;
        int i,number,time,time2;
        string msg;
		mixed* timeinfos;
		int* schedule_time;
		string* schedule;
		int hour;
		int minute;
		int mday;

       
        if(!wizardp(me) && time()-me->query_temp("scan_time") < 15)
                return notify_fail("等等，系统喘气中......\n");
        me->set_temp("scan_time",time());
        
        if(XYTASK_D->query("begin")) 
        {
             tell_object(me,HIY"系统告诉你：现在蒙古鞑子正在攻打襄阳中。\n"NOR); 
        }
        
        msg=HIG"系统告诉你：襄阳保卫战每天固定在3点，7点，11点，15点，19点和23点打响。\n"NOR;
        tell_object(me,msg);
        msg=HIG"系统告诉你：五指山剿匪任务固定在每周六晚上21点开始。(help task-jiaofei)\n"NOR;
        tell_object(me,msg);

		timeinfos = localtime(time());

		hour = timeinfos[LT_HOUR];
		minute = timeinfos[LT_MIN];
		mday = timeinfos[LT_MDAY];

		if(mday % 2 == 1)
		{
			msg=HIG"系统告诉你：今天海战12点开始。\n"NOR;
		}
		else
		{
			msg=HIG"系统告诉你：今天海战21点开始。\n"NOR;
		}
        tell_object(me,msg);
		
		msg=HIY"\n大宋朝廷昭告：门派比武每日";
		schedule_time = BIWU_D->get_schedule_time();
		for(i=0;i<sizeof(schedule_time);i++)
		{
			msg += chinese_number(schedule_time[i]);
			msg += "点,";
		}
		msg += "开始。\n"NOR;
		msg += "从现在开始依次的比赛安排为：\n\n";
		msg += "================================================================\n";
		schedule = BIWU_D->get_schedule();
		for(i=0;i<sizeof(schedule);i++)
		{
			msg += schedule[i];
			msg += "\n";
		}
		msg += "================================================================\n";
		msg += HIW"举例：如果现在是9点，那么下一场比武就是今天10点，依次类推。\n如果现在是10点10分，那么下一场比武就是今天的16点。每场比武\n开始后，自动安排好三天后的比武。\n"NOR;
		tell_object(me,msg);

        return 1;
}
int help()
{
        write(@LONG
指令格式：bwcx 

查询保卫襄阳的时间。
LONG
        );
        return 1;
}
