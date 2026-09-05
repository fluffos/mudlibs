// query.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include <title.h>
#define LINE "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
#define LEFT_TOP "┏"
#define RIGHT_TOP "┓"
#define LEFT_BUTTOM "┗"
#define RIGHT_BUTTOM "┛"
#define PILLAR "┃"
int help(object me);
int show_update(object me)
{
	string msg;
	object notice=load_object("/clone/board/dasong_notice_b");
	mapping *notes;
	if (!notice)
	{
		tell_object(me,"暂无任何大宋更新记录。\n");
		return 1;
	}
	notes=notice->query("notes");
	msg="\n\n全部大宋更新：\n"NOR;
	for (int i=0;i<sizeof(notes);i++)
	{
		msg+=HBWHT+HIR+"【大宋更新】"+notes[i]["title"]+NOR;
		msg+="\n";
	}
	tell_object(me,msg);
	return 1;
}
int main(object me, string arg)
{
	mixed tm=localtime(time());
    int mins;
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]),who,msg,info,chaiqian_color,chaiqian,jilu_color,jilu,xunzhi_color,xunzhi,jue_color,jue;
    if (arg=="-h")
	return help(me);
	if (arg=="-update")
	return show_update(me);
	msg="\n\n";
    msg+=sprintf("%2s%-62s%2s\n",LEFT_TOP,LINE,RIGHT_TOP);
    info=sprintf("%2s%26s%|10s%-26s%2s\n",PILLAR,"★★★","大  宋","★★★",PILLAR);
    msg+=info;
    msg+=sprintf("%2s%-62s%2s\n",PILLAR,LINE,PILLAR);
	if (stringp(arg))
	{
		if (wizardp(me)&&find_player(arg))
		{
			me=find_player(arg);
			if (!me->query("song/pro"))
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
	if (DASONG_D->my_pin(me)!="")
    {
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【品级】"+who+"是大宋"+DASONG_D->my_pin(me)+"官员。",PILLAR);
        msg+=info;
    }
    else
    {
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【品级】无。",PILLAR);
        msg+=info;
    }
    if (me->get_title(TITLE_SONG1))
    {
		chaiqian_color=COLOR_D->get_color(me->get_title(TITLE_SONG1));
		chaiqian=COLOR_D->uncolor(me->get_title(TITLE_SONG1));
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【差遣】"+who+"的差遣是"+chaiqian+"。",PILLAR);
        msg+=info;
    }
    else
    {
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【差遣】无。",PILLAR);
        msg+=info;
    }
	if (me->get_title(TITLE_SONG2))
    {
		jilu_color=COLOR_D->get_color(me->get_title(TITLE_SONG2));
		jilu=COLOR_D->uncolor(me->get_title(TITLE_SONG2));
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【散阶】"+who+"的散阶官是"+jilu+"。",PILLAR);
        msg+=info;
    }
    else
    {
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【散阶】无。",PILLAR);
        msg+=info;
    }
	if (me->get_title(TITLE_SONG3))
    {
		xunzhi_color=COLOR_D->get_color(me->get_title(TITLE_SONG3));
		xunzhi=COLOR_D->uncolor(me->get_title(TITLE_SONG3));
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【职勋】"+who+"的职勋是"+xunzhi+"。",PILLAR);
        msg+=info;
    }
    else
    {
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【职勋】无。",PILLAR);
        msg+=info;
    }
	if (me->get_title(TITLE_SONG5))
    {
		jue_color=COLOR_D->get_color(me->get_title(TITLE_SONG5));
		jue=COLOR_D->uncolor(me->get_title(TITLE_SONG5));
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【爵位】"+who+"的爵位是"+jue+"。",PILLAR);
        msg+=info;
    }
    else
    {
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【爵位】无。",PILLAR);
        msg+=info;
    }
	if (DASONG_D->get_my_pin(me)!=1)
	{
		if (me->query("song/taskstime"))
		{
			mins=DASONG_D->cdtime(me)-(int)me->query("mud_age")+(int)me->query("song/taskstime");
			info=sprintf("%2s%-62s%2s\n",PILLAR,"【政务】"+who+"下次大宋任务可在"+CHINESE_D->chinese_period(mins)+"后领取。",PILLAR);
			if (mins<=0)
			{
				info=sprintf("%2s%-62s%2s\n",PILLAR,"【政务】"+who+"可以立刻进行下次大宋任务。",PILLAR);
			}
			msg+=info;
		}
		if (!me->query("song/taskstime"))
		{
			info=sprintf("%2s%-62s%2s\n",PILLAR,"【政务】无任务记录。",PILLAR);
			msg+=info;
		}
	}
	else
	{
		if (day!=me->query("song/1pintask/date"))
		{
			info=sprintf("%2s%-62s%2s\n",PILLAR,"【政务】"+who+"今天仍可完成四次大宋任务。",PILLAR);
		}
		else if (me->query("song/1pintask/times")>3)
		{
			info=sprintf("%2s%-62s%2s\n",PILLAR,"【政务】"+who+"今天已完成所有大宋任务。",PILLAR);
		}
		else
		{
			info=sprintf("%2s%-62s%2s\n",PILLAR,"【政务】"+who+"今天仍可完成"+chinese_number(4-(int)me->query("song/1pintask/times"))+"次大宋任务。",PILLAR);
		}
		msg+=info;
	}
	if (me->query("song/credit")>0)
	{
		msg+=sprintf("%2s%-62s%2s\n",PILLAR,"【功勋】"+who+"的大宋功勋累计"+me->query("song/credit")+"点。",PILLAR);
	}
    if (me->query("song/salary"))
    {
        mins=86400-(int)me->query("mud_age")+(int)me->query("song/salary");
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【本俸】"+who+"下次发放本俸将在"+CHINESE_D->chinese_period(mins)+"后。",PILLAR);
		if (mins<=0)
		{
			info=sprintf("%2s%-62s%2s\n",PILLAR,"【本俸】"+who+"将会被尽快核发去岁本俸。",PILLAR);
		}
        msg+=info;
    }
    else
    {
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【本俸】无本俸领取记录。",PILLAR);
        msg+=info;
    }
	if (me->get_title(TITLE_SONG1)&&me->query("song/zhi_salary"))
	{
		if (me->query("song/credit")<=me->query("song/last_zhi_credit"))
		info=sprintf("%2s%-62s%2s\n",PILLAR,"【职钱】"+who+"因为政务处理不足，暂时不能领取"+chaiqian+"的职钱。",PILLAR);
		else if (me->query("mud_age")-me->query("song/salary_zhi")<10000)
		info=sprintf("%2s%-62s%2s\n",PILLAR,"【职钱】"+who+"还没到下次领取"+chaiqian+"的职钱的时候。",PILLAR);
		else if (me->query("song/pro")=="宦")
		info=sprintf("%2s%-62s%2s\n",PILLAR,"【职钱】"+who+"可在内东门司领取(ling)"+chaiqian+"的职钱。",PILLAR);
		else
		info=sprintf("%2s%-62s%2s\n",PILLAR,"【职钱】"+who+"可在三司户部副使处领取(ling)"+chaiqian+"的职钱。",PILLAR);
		msg+=info;
	}
	if (me->get_title(TITLE_SONG3)&&me->query("song/pro")=="文")
	{
		if (DASONG_D->get_my_pin(me)>2&&me->query("song/suikao/time")+3600*24<me->query("mud_age"))
		info=sprintf("%2s%-62s%2s\n",PILLAR,"【补贴】"+who+"未通过今年岁考，无法领取"+xunzhi+"的补贴。",PILLAR);
		else if (me->query("mud_age")-me->query("song/salary_xueshi")<86399)
		info=sprintf("%2s%-62s%2s\n",PILLAR,"【补贴】"+who+"今年已经领取过学士院的补贴。",PILLAR);
		else
		info=sprintf("%2s%-62s%2s\n",PILLAR,"【补贴】"+who+"可在翰林学士处领取(ling)"+xunzhi+"的补贴。",PILLAR);
		msg+=info;
	}
	if (me->query("song/xunjue/rank")>=1&&me->query("song/xunjue/rank")<=12&&me->get_title(TITLE_SONG5))
	{
		if (me->query("mud_age")-me->query("song/salary_jue")<10000)
		info=sprintf("%2s%-62s%2s\n",PILLAR,"【食邑】"+who+"刚刚领取过了"+jue+"的食邑。",PILLAR);
		else
		info=sprintf("%2s%-62s%2s\n",PILLAR,"【食邑】"+who+"可在太常寺少卿处领取(ling)"+jue+"的食邑。",PILLAR);
		msg+=info;
	}
	if (DASONG_D->get_my_pin(me)!=1)
	{
		if (me->query("song/suikao"))
		{
			if (me->query("mud_age")-me->query("song/suikao/time")<3600*24)
			info=sprintf("%2s%-62s%2s\n",PILLAR,"【磨勘】"+who+"尚未到下次磨勘的时候。",PILLAR);
			else
			info=sprintf("%2s%-62s%2s\n",PILLAR,"【磨勘】"+who+"现在就可以进行磨勘了。",PILLAR);
			msg+=info;
		}
		if (!me->query("song/suikao"))
		{
			info=sprintf("%2s%-62s%2s\n",PILLAR,"【磨勘】无上次磨勘记录。",PILLAR);
			msg+=info;
		}
	}
    if (me->query("song/special"))
    {
        if (me->query("song/special")=="fengshui")
        {
            info=sprintf("%2s%-62s%2s\n",PILLAR,"【特技】风水。天机难测，万象始生。",PILLAR);
        }
        if (me->query("song/special")=="tanlan")
        {
            info=sprintf("%2s%-62s%2s\n",PILLAR,"【特技】贪婪。贪狼一出，天下尽墨。",PILLAR);
        }
        if (me->query("song/special")=="wenqu")
        {
            info=sprintf("%2s%-62s%2s\n",PILLAR,"【特技】文曲。文曲下凡，国泰民安。",PILLAR);
        }
        if (me->query("song/special")=="tuji")
        {
            info=sprintf("%2s%-62s%2s\n",PILLAR,"【特技】突击。其势如火，疾不可阻。",PILLAR);
        }
        if (me->query("song/special")=="qunzhan")
        {
            info=sprintf("%2s%-62s%2s\n",PILLAR,"【特技】群战。百战不屈，骄阳似我。",PILLAR);
        }
        if (me->query("song/special")=="guwu")
        {
            info=sprintf("%2s%-62s%2s\n",PILLAR,"【特技】鼓舞。借势助力，顺乎天意。",PILLAR);
        }
        msg+=info;
    }
    if (!me->query("song/special"))
    {
        info=sprintf("%2s%-62s%2s\n",PILLAR,"【特技】你可以到门下省官厅学习(baodao)特技。",PILLAR);
        msg+=info;
    }
    msg+=sprintf("%2s%-62s%2s\n",PILLAR,LINE,PILLAR);
    info=sprintf("%2s%|62s%2s\n",PILLAR,COLOR_D->uncolor(me->query("name")),PILLAR);
    msg+=info;
    msg+=sprintf("%2s%-62s%2s\n",LEFT_BUTTOM,LINE,RIGHT_BUTTOM);
    tell_object(this_player(),msg);
    return 1;
}
int help(object me)
{
    write("
指令格式 : song query
查询大宋基本信息。
"  );
    return 1;
}
