// kanyu.c 
// Zine 2012/10/14
#include <ansi.h>
#include "special_permit.h"
inherit F_CLEAN_UP;
int help(object me);
int afterkanyu(object me,string arg)
{
        object target,env,qt,goodplace;
		object uniob;
        env=environment(me);
        if (!arg)//测有额外加成xiulian的地方。
        {
           
            qt=load_object("/d/yingtianfu/neicheng/qintian");
            if (!qt)
            {
                tell_object(me,"现在推算不到修炼内功的灵地。\n");
                return 1;
            }
            if (qt)
            {
                if (qt->query("good_place"))
                {
                    goodplace=load_object(qt->query("good_place"));
                }
                if (!qt->query("good_place"))
                {
                    tell_object(me,"现在推算不到修炼内功的灵地。\n");
                    return 1;
                }
                
            }
            if (TASK_D->place_belong(env)!=TASK_D->place_belong(goodplace))
            {
                tell_object(me,"似乎在"+TASK_D->place_belong(base_name(goodplace))+"有帮助修炼内功的东西。\n");
                return 1;
            }
            if (TASK_D->place_belong(env)==TASK_D->place_belong(goodplace)&&base_name(env)!=base_name(goodplace))
            {
                tell_object(me,"似乎帮助修炼内功的东西周围的环境是\n"+goodplace->query("long")+"\n");
                return 1;
            }
            if (TASK_D->place_belong(env)==TASK_D->place_belong(goodplace)&& base_name(env)==base_name(goodplace))
            {
                tell_object(me,"就是这里了，似乎有帮助修炼内功的东西，你可以把它挖出(wachu)来。\n");
                return 1;
            }
        }
        if (arg)
        {
            target=find_player(arg);
            if (!target)
            {
                target=find_living(arg);
                if (!target)
                {
                tell_object(me,"似乎什么也没有找到。\n");
                return 1;
                }
            }
            if (wizardp(target))
            {
                tell_object(me,"这个人行踪不定，很难感应到。\n");
                return 1;
            }
			if(target->query("is_tasknpc"))
			{
				write(HIY"你费了半天的力气，就是推算不出"+target->name(1)+"的位置。\n"NOR);
				return 1;
			}

			if (target->query("hide"))
			{
				write(HIY"此人已经隐姓埋名，你费了半天的力气，就是推算不出其位置。\n"NOR);
				return 1;
			}
			if((objectp(uniob=target->query("uni_target")))&& (uniob->query("id")!=me->query("id"))) 
			{        
					write(HIY"你费了半天的力气，就是推算不出"+target->name(1)+"的位置。\n"NOR);
					return 1;
			}
            env=environment(target);
            {
                if (!env)
                {
                    tell_object(me,"这个人行踪不定，很难推算出。\n");
                    return 1;
                }
                else if (random(100)>1)
                {
                    tell_object(me,"你似乎推算出这个人身处的环境是\n"+env->query("long")+"。\n");
                    tell_object(target,"似乎有人在用风水之术窥测你的位置。\n");
                    return 1;
                }
                else
                {
                    tell_object(me,"这个人行踪不定，很难推算出。\n");
                    return 1;
                }
            }
        }
}
int main(object me,string arg)
{
    object room=environment(me);
    string need="fengshui";
	if (arg=="-h")
	return help(me);
    if (special_permit(me,need)==0)
    {
		return 1;
    }
    
    else
    {
        message_vision(WHT"$N掐起手指，默念着什么。\n"NOR,me);
        me->add_busy(3);
        remove_call_out("afterkanyu");
        call_out("afterkanyu",4,me,arg);
        return 1;
    }
}
int help(object me)
{
    write("
指令格式 : ming kanyu
堪舆风水或寻人，需要大明特技风水。
"    );
    return 1;
}
