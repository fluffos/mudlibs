//把巫师会客室技能对应命令变为玩家命令，并加cd时间，减少系统负担。Zine 2011-11-25
#include <ansi.h>
#define X 5
#define Y 5
#define S 1

string chinese_diff(int time_diff)
{
    int hr,min,sec,tmp;
    string msg="";
    if (time_diff<0)
    {
        return HIR"计时错误！"NOR;
    }
    if (time_diff>3600)
    {
        hr=time_diff/3600;
        tmp=time_diff%3600;
        if (tmp>60)
        {
            min=tmp/60;
            tmp=tmp%60;
        }
        else
        {
            min=0;
            tmp=tmp%60;
        }
        if (tmp>0)
        {
            sec=tmp;
        }
        else
        {
            sec=0;
        }
    }
    else if (time_diff>60)
    {
        hr=0;
        min=time_diff/60;
        tmp=time_diff%60;
        if (tmp>0)
        {
            sec=tmp;
        }
        else
        {
            sec=0;
        }
    }
    else
    {
        hr=0;
        min=0;
        sec=time_diff;
    }
    if (hr)
    {
        msg+=chinese_number(hr)+"小时";
    }
    if (min)
    {
        msg+=chinese_number(min)+"分";
    }
    if (sec)
    {
        msg+=chinese_number(sec)+"秒";
    }
    return msg;
}

float ratio(int exp,int time)
{
    float result,hr=to_float(time)/3600;
    result=to_float(exp)/hr;
    return result;
}
int show_improve(object me,int flag)
{
    int time,login_time,time_diff,cur_exp,login_exp,exp_diff;
    string msg;
    if (!me)
    {
        return 1;
    }
    if (!me->query_temp("log"))
    {
        return 1;
    }
    time=time();
    login_time=me->query_temp("log/time");
    time_diff=time-login_time;
    cur_exp=me->query("combat_exp");
    login_exp=me->query_temp("log/combat_exp");
    exp_diff=cur_exp-login_exp;
    msg=HIW+"你"+HIW+"连线进入北侠已经有"+chinese_diff(time_diff)+"了。\n"+NOR;
    if (exp_diff>0)
    {
        msg+=HIG+"本次连线，你"+HIG+"累计增加了"+NOR+chinese_number(exp_diff)+HIG+"点经验，平均效率："+NOR+ratio(exp_diff,time_diff)+HIG+"/小时。\n"+NOR;
    }
    else if (exp_diff<0)
    {
        msg+=HIR+"本次连线，你"+HIR+"累计减少了"+NOR+chinese_number(-exp_diff)+HIR+"点经验，平均效率："+NOR+ratio(exp_diff,time_diff)+HIR+"/小时。\n"+NOR;
    }
    else
    {
        msg+=HIC+"本次连线，你"+HIC+"的经验没有变化。\n"+NOR;
    }
    if (!flag) tell_object(me,msg);
    else
    {
        msg+=HIM+"近期你"+HIM+"的累计fullme时间(实时)为";
        msg+=NOR+(me->query("antirobot/total_activity_time")+((me->query("antirobot/deactivity")<4&&me->query("antirobot/seg_first_activity_time"))?time()-me->query("antirobot/seg_first_activity_time"):0))/60+HIM+"分钟，";
        msg+="累计变化为"+NOR+chinese_number(((me->query("antirobot/first_activity_exp")==0)?0:cur_exp-me->query("antirobot/first_activity_exp")))+HIM+"点经验，";
        msg+="时间区间(15分钟颗粒度)为"+NOR+((me->query("antirobot/last_activity_time")-me->query("antirobot/first_activity_time")>0)?(me->query("antirobot/last_activity_time")-me->query("antirobot/first_activity_time")):0)/60+HIM+"分钟；\n";
        msg+="期间主动fullme次数为"+NOR+me->query("antirobot/hand_fullme_times")+HIM+"次,被动fullme次数为"+NOR+me->query("antirobot/pic_fullme_times")+HIM+"次。\n"+NOR;
        
     
        msg=replace_string(msg,"你",NOR+me->query("name")+"("+capitalize(me->query("id"))+")"+NOR);
        tell_object(this_player(),msg);
    }
    return 1;
}

int main(object me,string arg)
{
  int y, x, lvl, exp, mylvl = me->query_skill_limit(), start;
  string str;
    if (arg&&find_player(arg)&&wizardp(me))
    {
        me=find_player(arg);
        show_improve(me,1);
        return 1;
    }
  if(!wizardp(me)&&time()-(int)me->query("statistics/exp_query")<5&&time()-(int)me->query("statistics/exp_query")>0)
    return notify_fail("请勿频繁查询！\n");
  write(HIW"\t\t\t【等级和经验简明对照表】\n"NOR);
  start = mylvl - X * Y / 2 + 2;
  if (start < 0)
    start = 0;
  for (y = 1; y <= Y; y++) {
    str = "";
    for (x = 0; x < X; x++) {
      lvl = (y + x * Y) * S -1 + start;
      exp = me->query_level_exp(lvl-2);
      if (lvl >= mylvl+2 && lvl < mylvl+2 + S)
        str += HIR;
      str += sprintf("%3d %8d", to_int(lvl-2), to_int(exp));
      if (lvl >= mylvl+2 && lvl < mylvl+2 + S)
        str += NOR;
      if (x < X-1)
        str += " | ";
    }
    write(str + "\n");
  }
    show_improve(me,0);
    if (!wizardp(me))
    me->set("statistics/exp_query",time());
  return 1;
}

int help(object me)
{
write(@HELP
指令格式 : exp

你可以使用这个命令获得经验和所支持技能
等级的简单对照。

HELP
    );
    return 1;
}

