//Make by Jason@pkuxkx
//统一奖励/惩罚接口，便于整体改变奖励额度


//11.25,统计增加对机器人的惩罚
//11.29,加入get_factor函数，factor动态每天平缓降低0.1%

//取消对5M以下的惩罚，吸引新人加入
//改一下user_special_factor算法
#include <ansi.h>
#include <localtime.h>

float factor = 1;

//stat data for user's incoming
mapping stat = ([]);
int do_stat(string id,string type,int amount);

int binge_start = 0;
int binge_duration = 0;

//特殊时段的奖励系数
int get_special_hour_reward_factor()
{
    return 10;
}

int turn_binge(int onoff, int start,int duration)
{
    if(!userp(this_player()) || SECURITY_D->get_wiz_level(this_player()) < 6) return 0;
    
    if(!onoff)
    {
        binge_start = binge_duration = 0;
    }
    else
    {
        if(start < time() || duration < 30) 
        {
            return 0;
        }
        binge_start = start;
        binge_duration = duration;
    }
    return 1;
}

int is_in_binge()
{
    if(time() > binge_start && time() < binge_start + binge_duration) return 1;
    return 0;
}
//用来控制除经验,qn,score,repute之外的其他一些数值增长的全局速度
//比如用来搞超级狂欢周
float get_global_factor(string type)
{
	mixed* timeinfos;
	int hour;

	timeinfos = localtime(time());

	hour = timeinfos[LT_HOUR];


    if(time() > binge_start && time() < binge_start + binge_duration) return 2.0;
    //每天21,22点，奖励增加10%。集中人气。
    if(hour == 21 || hour == 22)
    {
        return 1.0 + 1.0*get_special_hour_reward_factor()/100;
    }
    

    
    return 1.0;    
}

//某些玩家会有特殊的因子，比如被判定为机器人，或者通过机器人测试的特别奖励。
float get_special_user_factor(object user)
{
	float result=1.0;
	if (time()<user->query("double_reward"))//超级狂欢的个人给出形式，Zine
	{
		if (time()>user->query("double_reward_last_record")+900)
		{
			user->set("double_reward_last_record",time());
			log_file("user/double_reward",sprintf("%s%s\n",ctime(time()),user->query("id")));
		}
		result=2.0;
	}
    if(time() - user->query("antirobot/isnotrobot") <= 7200)
    {
        //通过机器人测试，奖励20%
        result*=1.2;
    }

    if(user->query("antirobot/isrobot/times") == 1 && user->query("antirobot/isrobot/exp_increase") < 1000000)
    {
        result*=0.5;
    }
    else if(user->query("antirobot/isrobot/times") == 2 && user->query("antirobot/isrobot/exp_increase") < 1000000)
    {
        result*=0.1;
    }
    else if(user->query("antirobot/isrobot/times") == 3 && user->query("antirobot/isrobot/exp_increase") < 5000000)
    {
        result*=0.05;
    }
    else if(user->query("antirobot/isrobot/times") == 4 && user->query("antirobot/isrobot/exp_increase") < 50000000)
    {
        result*=0.01;
    }
    else if(user->query("antirobot/isrobot/times") > 4)
    {
        result*=0;
    }
	result*=user->query_rewardcoe();
    return result;
}


float get_factor(string type)
{
	//基准日期为2009年11月28日零点

    //基准时间改为2011年8月9日22点，从0.47继续往下降。

	int start_time = 1312901067; 
	//每天平滑降低0.1%
	factor = 0.47-(time()-start_time)/86400000.0;
	//降低到37%的时候暂停一下看看
	if (factor < 0.409)
		factor = 0.409;
		
    factor *= get_global_factor(type);
    
	return factor;
}

//不实际奖励/惩罚，只是返回计算后的数值。之所以这些函数没有合成一个，
//是考虑将来有可能会给不同的奖励设置不同的折扣算法。

int check_exp(int exp)
{
	return to_int(exp*get_factor("exp"));
}

int check_pot(int pot)
{
	return to_int(pot*get_factor("pot"));
}

int check_rep(int rep)
{
	return to_int(rep*get_factor("rep"));
}

int check_money(int money)
{
	return to_int(money*get_factor("money"));
}

int check_score(int score)
{
	return to_int(score*get_factor("score"));
}


int check_skill(int skill)
{
	int sk = to_int(skill*get_factor("skill"));
	if(sk == 0 && skill > 0) sk = 1;
	if(sk == 0 && skill < 0) sk = -1;
	return sk;
}

int check_robot(object pl,int value)
{
	int deactivity_rate=100;
	int deactivity=pl->query("antirobot/deactivity");
	
	//5M以下不惩罚
	if(pl->query("combat_exp") < 5000000) return value;
	
	//如果反机器人引擎不工作了，就不降低奖励
	//这发生在比如web server down了，dns坏了，等

	if(ANTIROBOT_D->stopped() || value < 0) return value;
	


	if (pl->query("antirobot/deactivity") < 4) 
	{
		deactivity_rate = 100;
	}
    else
	{
		deactivity_rate = 3200/deactivity/deactivity/deactivity;
	}
	value = to_int(1.0 * value / 100 * deactivity_rate);
	return value;
}

//门派提供的加成
int check_family_reward(object pl,int value)
{
	string family;
	family = pl->query("family/family_name");
	if(family != "" && family == FAMILY_D->get_task_winner_family())
	{
		return to_int(1.0*value/100*120);
	}
	else
	{
		return value;
	}
}

//quest为特殊任务标识
//其中 xiaobanhe 为萧半和任务
//     piaoliu   为漂流任务
//     xiangyang 为襄阳保卫任务
//     newbie    为门忠任务，满不懂任务
varargs int add_exp(object pl,int exp, string quest)
{    	
	  string skl, day;
    int final = check_exp(exp);		

    //门忠任务经验不折扣，但是机器人检查和全局变量仍然遵守
    if ( quest=="newbie" )
      final=exp;
    
    final = check_robot(pl,final);		
    final = check_family_reward(pl,final);		
    final =  to_int(1.0*final*get_special_user_factor(pl));
    if(final == 0) final = 1*(exp>0?1:-1);
      
    //增加休闲玩家的处理，休闲玩家每天只能完成最多50次高经验任务，150次低经验任务，并且高经验任务次数+低经验任务次数/3不能超过50次
    if ( userp(pl) && pl->query("xiuxian_player") )
    {
      day=gctime(0,1);
      if ( pl->query("xiuxian/date") != day )
      {
        pl->delete("xiuxian");
        pl->set("xiuxian/date", day);
      }
      
      if ( final> 10 )
      {
        if ( pl->query("xiuxian/high_exp")+pl->query("xiuxian/low_exp")/3< 50 && ( !quest || ( quest!="xiaobanhe" && quest!="piaoliu" ) ) )
        {  
          if ( final>5000 )
          {
            if ( !quest || quest!="xiangyang" )
              final=final*4/3;
            else if ( quest=="xiangyang" )
              final=final/2;
            pl->add("xiuxian/high_exp", 1);
          }
          else
          {
            if ( !quest || quest!="xiangyang" )
              final=final*3/2;
            
            if ( final>5000 )
              pl->add("xiuxian/low_exp", 2);
            else
              pl->add("xiuxian/low_exp", 1);
          }
        }
        else if ( !quest || ( quest!="xiaobanhe" && quest!="piaoliu" ) )
        {
          tell_object(pl, "你今天已经太累了，可以休息休息了。\n");
          final=1;
        }
      }
    }
      
    objectp(pl) && pl->add("combat_exp",final) && pl->query("combat_exp") < 2000 && final < 0 && pl->set("combat_exp",2001);

    if(pl->query("antirobot/isrobot/times"))
    {
        pl->add("antirobot/isrobot/exp_increase",final);
    }
    do_stat(pl->query("id"),"exp",final);
    return final;
}

int add_pot(object pl,int pot)
{    
    int final = check_pot(pot);
    final = check_robot(pl,final);
    final = check_family_reward(pl,final);
    final =  to_int(1.0*final*get_special_user_factor(pl));
    if(final == 0) final = 1*(pot>0?1:-1);
	//10M以下pot奖励增加10%，补偿关闭朱熹
	if(final > 0 && pl->query("combat_exp") < 10000000) final = to_int(1.1*final);
    objectp(pl) && pl->add("potential",final);
    do_stat(pl->query("id"),"pot",final);
    return final;
}

int add_rep(object pl,int rep)
{    
    int final = check_rep(rep);
    final = check_robot(pl,final);
    final = check_family_reward(pl,final);
    final =  to_int(1.0*final*get_special_user_factor(pl));
	if(final == 0) final = 1*(rep>0?1:-1);
    objectp(pl) && pl->add("repute",final);
    do_stat(pl->query("id"),"rep",final);
    return final;
}

int add_money(object pl,int money)
{
    int final = check_money(money);
    final = check_robot(pl,final);
    final = check_family_reward(pl,final);
    final =  to_int(1.0*final*get_special_user_factor(pl));
	if(final == 0) final = 1*(money>0?1:-1);
    objectp(pl) && pl->add("balance",final);
    do_stat(pl->query("id"),"balance",final);
    return final;
}

int add_score(object pl,int score)
{
    int final = check_score(score);
    final = check_robot(pl,final);
    final = check_family_reward(pl,final);
    final =  to_int(1.0*final*get_special_user_factor(pl));
	if(final == 0) final = 1*(score>0?1:-1);
    objectp(pl) && pl->add("score",final);
    do_stat(pl->query("id"),"score",final);
    return final;
}

int add_skill(object pl,string skill,int level)
{
    int final = check_skill(level);
    final = check_robot(pl,final);
    final = check_family_reward(pl,final);
    final =  to_int(1.0*final*get_special_user_factor(pl));
	if(final == 0) final = 1*(level>0?1:-1);
    objectp(pl) && pl->set_skill(skill,pl->query_skill(skill,1)+level);
    return final;
}


//stat = (["userid":(["exp":({total_amount,({TIME,DATA}),...})])])

int do_stat(string id,string type,int amount)
{
    mapping my_stat;
    if(undefinedp(stat[id]))
    {
        my_stat = ([]);
    }
    else
    {
        my_stat = stat[id];
    }
    if(undefinedp(my_stat[type]))
    {
        my_stat[type] = ({});
    }
    if(sizeof(my_stat[type]) == 0)
    {
        my_stat[type] += ({0});
    }
    my_stat[type] += ({ ({time(),amount}) });
    my_stat[type][0] += amount;

    if(time()-my_stat[type][1][0] > 3600)
    {
        my_stat[type] -= ({my_stat[type][1]});
    }

    stat[id] = my_stat;
    return 1;
}

//以小时为单位
int get_stat_rate(string type,string id)
{
    int flag = 0;
    int start_stat_time = 0;
    int amount = 0,i;
    if(undefinedp(stat[id]))
    {
        return 0;
    }

    if(undefinedp(stat[id][type]) || sizeof(stat[id][type]) < 2)
    {
        return 0;
    }

    for(i=1;i<sizeof(stat[id][type]);i++)
    {
        if(time() - stat[id][type][i][0] < 3600)
        {
            if(!flag)
            {
                flag = 1;
                start_stat_time = stat[id][type][i][0];
            }
            amount += stat[id][type][i][1];
        }
    }
    return amount;
}

void get_all_stat_rate(string type)
{
    int i;
    string* ids = keys(stat);
    for(i=0;i<sizeof(ids);i++)
    {
        printf("id:%s,%s rate/hour:%d\n",ids[i],type,get_stat_rate(type,ids[i]));
    }
}

int get_total_stat(string type,string id)
{
    if(undefinedp(stat[id]))
    {
        return 0;
    }

    if(undefinedp(stat[id][type]) || sizeof(stat[id][type]) < 2)
    {
        return 0;
    }
    return stat[id][type][0];
}
