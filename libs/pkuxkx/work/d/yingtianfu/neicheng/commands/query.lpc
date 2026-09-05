// query.c 
// Zine 2012/10/14
#include <ansi.h>
#include <title.h>
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int main(object me, string arg)
{
	mixed tm=localtime(time());
    int mins;
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]),who,msg,info;
    if (arg=="-h")
	return help(me);
	msg="\n\n";
    msg+=HIY"┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR;
    info=HIY"              ★★★"+HIW+"大  明"+HIY+"★★★\n"NOR;
    msg+=info;
    msg+=HIY"┃━━━━━━━━━━━━━━━━━━━━━━━━━┃\n"NOR;
	if (stringp(arg))
	{
		if (wizardp(me)&&find_player(arg))
		{
			me=find_player(arg);
			if (!me->query("mingpin"))
			{
				me=this_player();
			}
		}
	}
	if (me==this_player())
	{
		who="你";
	}
	else 
	{
		if (me->query("gender")=="男性")
		who="他";
		else
		who="她";
	}
	if (me->query("mingpin"))
    {
        info="  【品级】"+who+"是大明"+get_major(me->get_title(TITLE_MING2))+chinese_number(me->query("mingpin"))+"品官员。\n";
        msg+=info;
    }
    else
    {
        info="  【品级】无。\n";
        msg+=info;
    }
    if (me->query("ming/title"))
    {
        info="  【本官】"+who+"的本官是"+me->query("ming/title")+"。\n";
        msg+=info;
    }
    else
    {
        info="  【本官】无。\n";
        msg+=info;
    }
	if (me->get_title(TITLE_MING2))
    {
        info="  【散阶】"+who+"的散阶是"+me->get_title(TITLE_MING2)+"。\n";
        msg+=info;
    }
    else
    {
        info="  【散阶】无。\n";
        msg+=info;
    }
	if (me->get_title(TITLE_MING3))
    {
        info="  【加官】"+who+"的加官是"+me->get_title(TITLE_MING3)+"。\n";
        msg+=info;
    }
    else
    {
        info="  【加官】无。\n";
        msg+=info;
    }
	if (me->get_title(TITLE_MING4))
    {
        info="  【爵位】"+who+"的爵位是"+me->get_title(TITLE_MING4)+"。\n";
        msg+=info;
    }
    else
    {
        info="  【爵位】无。\n";
        msg+=info;
    }
	if (me->query("mingpin")!=1)
	{
		if (me->query("ming/taskstime"))
		{
			mins=3600*(int)me->query("mingpin")-(int)me->query("mud_age")+(int)me->query("ming/taskstime");
			if (me->query("ming/title")=="詹士府詹士")
			{
				mins-=3600;
			}
			info="  【政务】"+who+"下次大明任务可在"+CHINESE_D->chinese_period(mins)+"后领取。\n";
			if (mins<=0)
			{
				info="  【政务】"+who+"可以立刻进行下次大明任务。\n";
			}
			msg+=info;
		}
		if (!me->query("ming/taskstime"))
		{
			info="  【政务】无任务记录。\n";
			msg+=info;
		}
	}
	else
	{
		if (day!=me->query("ming/1pintask/date"))
		{
			info="  【政务】"+who+"今天仍可完成四次大明任务。\n";
		}
		else if (me->query("ming/1pintask/times")>3)
		{
			info="  【政务】"+who+"今天已完成所有大明任务。\n";
		}
		else
		{
			info="  【政务】"+who+"今天仍可完成"+chinese_number(4-(int)me->query("ming/1pintask/times"))+"次大明任务。\n";
		}
		msg+=info;
	}
    if (me->query("ming/salary"))
    {
        mins=86400-(int)me->query("mud_age")+(int)me->query("ming/salary");
        info="  【俸薪】"+who+"下次发放俸薪将在"+CHINESE_D->chinese_period(mins)+"后。\n";
		if (mins<=0)
		{
			info="  【俸薪】"+who+"将会被尽快核发去岁俸薪。\n";
		}
        msg+=info;
    }
    else
    {
        info="  【俸薪】无俸薪领取记录。\n";
        msg+=info;
    }
    if (me->query("ming/duty_salary"))
    {
		mins=3600*48-(int)me->query("mud_age")+(int)me->query("ming/duty_salary");
        info="  【职贴】尚需"+CHINESE_D->chinese_period(mins)+"后"+who+"才能领取职贴。\n";
		if (mins<=0)
		{
			info="  【职贴】"+who+"可以立刻在通政司领取(ling)职贴。\n";
		}
        msg+=info;
    }
	else
	{
		info="  【职贴】无职贴领取记录。\n";
        msg+=info;
	}
	if (me->query("mingpin")!=1)
	{
		if (me->query("ming/suikao"))
		{
			if (me->query("mud_age")-me->query("ming/suikao/time")<3600*24)
			info="  【岁考】"+who+"尚未到下次岁考的时候。\n";
			else
			info="  【岁考】"+who+"现在就可以进行岁考了。\n";
			msg+=info;
		}
		if (!me->query("ming/suikao"))
		{
			info="  【岁考】无上次岁考记录。\n";
			msg+=info;
		}
	}
    if (me->query("ming/special"))
    {
        if (me->query("ming/special")=="fengshui")
        {
            info="  【特技】风水。天机难测，万象始生。\n";
        }
        if (me->query("ming/special")=="tanlan")
        {
            info="  【特技】贪婪。贪狼一出，天下尽墨。\n";
        }
        if (me->query("ming/special")=="wenqu")
        {
            info="  【特技】文曲。文曲下凡，国泰民安。\n";
        }
        if (me->query("ming/special")=="tuji")
        {
            info="  【特技】突击。其势如火，疾不可阻。\n";
        }
        if (me->query("ming/special")=="qunzhan")
        {
            info="  【特技】群战。百战不屈，骄阳似我。\n";
        }
        if (me->query("ming/special")=="guwu")
        {
            info="  【特技】鼓舞。借势助力，顺乎天意。\n";
        }
        msg+=info;
    }
    if (!me->query("ming/special"))
    {
        info="  【特技】无。\n";
        msg+=info;
    }
    msg+=HIY"┃━━━━━━━━━━━━━━━━━━━━━━━━━┃\n"NOR;
    info="                   "+me->query("name")+"\n";
    msg+=info;
    msg+=HIY"┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR;
    tell_object(this_player(),msg);
    return 1;
}
int help(object me)
{
    write("
指令格式 : ming query
查询大明基本信息。
"    );
    return 1;
}
