#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_MORE;
#define LINE   HIW"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"NOR
string get_remain_time(int due)
{
	if (due<0)
	return WHT+"任务已经失败！请在铜雀台使用abandon命令放弃任务。\n"+NOR;
	else
	return HIG+"任务剩余时间："+NOR+CHINESE_D->chinese_period(due)+HIG+"。\n"+NOR;
}
string safari_info(object me)
{
	int i,j=1,due;
    string remain_time,msg="          "+HBWHT+HIR+"△△△△銅雀台任務△△△△\n"+NOR+LINE;
	mapping *safari="/d/wizard/zine/safari"->ret_safari();
	if (!me->query("safari"))
	{
        msg+="『地点』铜雀台坐落于河北，是曹操击败袁绍后修建，现\n";
        msg+="        在经常发布一些奇怪的任务。\n";
        msg+="『要求』登上铜雀台揭榜领取任务需要"+HIG+"一千万经验"+NOR+"以上。\n";
        msg+="『时间』在每天的一点、五点、九点、十三点、十七点、\n";
        msg+="        十九点、二十一点、二十三点左右铜雀台会有四\n";
        msg+="        个新任务。\n";
        msg+="『揭榜』揭榜会暂扣"+HIR+"一万点经验"+NOR+"，完成任务后会返还并\n";
        msg+="        追加五千点"+NOR+"奖励。每揭榜获得一次铜雀台任务，\n";
        msg+="        将在至少"+HIW+"三天以内"+NOR+"无法揭榜。\n";
        msg+="『奖励』每完成一次铜雀台任务，将获得一点铜雀台任务\n";
        msg+="        积分，可以用于一些特殊用途，比如"+HIY+"逆天改命\n"+NOR;
        msg+="『完成』如果在规定时间内完成所有任务，可在铜雀台用\n";
        msg+=HIG+"        Complete"+NOR+"命令完成，如无法完成请使用"+WHT+"Abandon\n"NOR;
        msg+="        命令放弃。\n";
        msg+="『积分』在铜雀台enter可进入后厅兑换积分。\n";
    }
	else
	{
		for (i=0;i<sizeof(safari);i++)
		{
				if (me->query("safari/"+safari[i]["name"]))
				{
					if (me->query(safari[i]["name"])<me->query("safari/"+safari[i]["name"]))
					{
						j=0;
						if (i<"/d/wizard/zine/safari"->get_shed())
						msg+="☆"+safari[i]["short_name"]+"："+YEL+"尚需"+(me->query("safari/"+safari[i]["name"])-me->query(safari[i]["name"]))+"点完成……\n"+NOR;
						else
						msg+="★"+safari[i]["short_name"]+"："+YEL+"尚需"+U+(me->query("safari/"+safari[i]["name"])-me->query(safari[i]["name"]))+NOR+YEL+"次完成……\n"+NOR;
					}
					else
					{
						if (i<"/d/wizard/zine/safari"->get_shed())
						msg+="☆"+safari[i]["short_name"]+"："+HIY+"已经完成。√\n"+NOR;
						else
						msg+="★"+safari[i]["short_name"]+"："+HIY+"已经完成。√\n"+NOR;
					}
				}
		}
		if (j)
		msg+=HIG"恭喜你！任务完成，铜雀台可用complete领取奖励。\n"NOR;
		else
		{
			due=me->query("safari/duedate")-time();
			remain_time=get_remain_time(due);
			msg+=remain_time+LINE;  
		}
		msg+=BRED+"本次奖励\n"+NOR;
		if (me->query("safari/reward/exp"))
		msg+=HIM+"■经验 "+chinese_number(me->query("safari/reward/exp"))+"点 \n"+NOR;
		if (me->query("safari/reward/pot"))
		msg+=HIM+"○潜能 "+chinese_number(me->query("safari/reward/pot"))+"点 \n"+NOR;
		if (me->query("safari/reward/rep"))
		msg+=HIG+"☆声望 "+chinese_number(me->query("safari/reward/rep"))+"点 \n"+NOR;
		if (me->query("safari/reward/gold"))
		msg+=HIY+"◎金钱 "+MONEY_D->money_str(me->query("safari/reward/gold"))+"\n"+NOR;
		if (me->query("safari/reward/guwan"))
		msg+=CYN+"¤古玩 "+chinese_number(me->query("safari/reward/guwan"))+"件 "+NOR;
	}
	msg+="\n"+LINE;
    if (me->query("gender")=="女性")
    msg+=HIM+me->query("name")+HIM+" ♀ ";
    else
    msg+=HIC+me->query("name")+HIC+" ♂ ";
	if (me->query("safari_credit"))
	msg+=HIY+"【铜雀积分/休闲积分/完成次数】："+me->query("safari_credit")+"/"+me->query("safari_xx_credit")+"/"+me->query("newjobs/completed/safari")+"\n"+NOR;
	return msg;
}
int main(object me,string arg)
{
    string msg;
	object pl;
	
	if (arg&&find_player(arg)&&wizardp(me))
	{
		pl=find_player(arg);
		msg=safari_info(pl);
		msg=replace_string(msg,"你",pl->query("name"));
		tell_object(me,msg);
	}
	else if (time()-me->query_temp("safari_check")<=5&&!wizardp(me))
    {
        tell_object(me,"请勿频繁使用safari命令查询。\n");
    }
    else
	{
		msg=safari_info(me);
		tell_object(me,msg);
	}
	me->set_temp("safari_check",time());
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : safari
 
这个指令, 用来查询铜雀台任务的完成情况。
HELP
    );
    return 1;
}
 
