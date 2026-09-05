#include <ansi.h>

int bonus(object me,int reward)
{
    float index,base_exp,exp=me->query("combat_exp");
    int result;
    base_exp=400000000.0;
    index=1-exp/base_exp;
    if (wizardp(me))
    {
        tell_object(me,index+"\n");
    }
    result=to_int(reward*index);
    if (result<0)
    {
        result=1;
    }
    return result;
}

int user_record(object me,int e_reward,string type)
{
	me->add("mengguquest/total_point",e_reward);
	me->add("mengguquest/details/"+type,e_reward);
	if (me->query("mengguquest/total_point")>23000)
	log_file("user/mengguquests",me->query("id")+"累计在蒙古quests中获得超过"+me->query("mengguquest/total_point")+"点。\n");
	return 1;
}