//萧半和任务奖励
//fix了一下exp限制 by yhzzyahoo @2015.4.18 test
#include <ansi.h>
int FACTOR=1; //参数，2极为慕容奖励的2倍。By Zine Nov 13 2010   
int adjust_exp(int exp,int para1,int para2,int banhe_times,int low_limit,int high_limit,int my_exp_adjust,int random_addition)
{
	exp=exp*(para1+banhe_times/para2);
	if (exp<low_limit)
	exp=low_limit;
	if (exp>high_limit)
	exp=high_limit;
	if (exp>(my_exp_adjust+random_addition))
	exp=my_exp_adjust+random(random_addition);
	if (banhe_times%10==4)
    exp=exp+random(exp/2);
	return exp;
}
int adjust_pot(int pot,int para1,int para2,int banhe_times,int exp)
{
	pot=pot*(para1+banhe_times/para2);
	if (banhe_times%10==9)
    pot=pot+random(exp/2);
	return pot;
}
int bonus(object me,int para)
{
	int exp,pot,rep,times,my_exp,n;
	exp=(me->query("kar")/2+ 40)*(14+random(25))*9/5;
	rep=20*random(5)+150;
	times=(int)me->query_temp("banhe/lianxu");
	my_exp=(int)me->query("combat_exp");
	if (my_exp<1200000)
	exp=exp/4;
	else if (my_exp<2000000&&my_exp>=1200000)
	exp=exp/3;
	else if (my_exp<3500000&&my_exp>=2000000)
	exp=exp/2;
	else if (my_exp<6000000)
	exp=exp/3*2;
	else
	exp=exp;
	pot = exp/6;
    if (times<5)
    {
		exp=adjust_exp(exp,3,5,times,1000,2000,my_exp/800,100);
		pot=adjust_pot(pot,3,5,times,exp);
    }
    else if (times<10)
    {
		exp=adjust_exp(exp,6,8,times,3000,6000,my_exp/500,200);
		pot=adjust_pot(pot,6,8,times,exp);
    }
    else if (times<15)
    {
		exp=adjust_exp(exp,8,8,times,5000,10000,my_exp/250,400);
		pot=adjust_pot(pot,8,8,times,exp);
    }
    else if (times<20)
    {
		exp=adjust_exp(exp,10,8,times,7500,15000,my_exp/150,750);
		pot=adjust_pot(pot,10,8,times,exp);
    }
    if (exp>=1000)
    {
        n=random(exp/4);
        exp=exp-n;
        pot=pot+n;
    }
	//全自动机器人影
	exp = REWARD_D->add_exp(me,exp, "xiaobanhe"); //箫半合任务奖励额外控制
	pot = REWARD_D->add_pot(me,pot);
	rep = REWARD_D->add_rep(me,rep);
	CHANNEL_D->do_channel(this_object(), "sys_misc",sprintf("%s在萧半和任务中获得经验：%d、潜能：%d。", me->name(), exp, pot));
	if (para==3)
	tell_object(me,HIC"找到萧中慧后，你被奖励：\n");
	if (para==2)
	tell_object(me,HIC"打败骚扰萧中慧的贼人后，你被奖励：\n");
	if (para==1)
	{
        if (!me->query_temp("banhe/lianxu"))
        {
            ANTIROBOT_D->same_as_fullme(me);
        }
		me->add_temp("banhe/lianxu",1);
		tell_object(me,HIC"成功地找回鸳鸯刀后，你被奖励：\n");
	}
	tell_object(me,chinese_number(exp)+"点实战经验，\n"+chinese_number(pot)+"点潜能\n"+chinese_number(rep)+"点声望。\n"NOR);
	me->add("exp/banhejob", exp);
	me->add("pot/banhejob", pot);
	me->add("banhe/accu_exp", exp);
	return 1;
}

