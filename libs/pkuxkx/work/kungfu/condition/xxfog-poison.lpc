// 星宿麻痹 Zine 23 oct 2010

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    if( duration < 1 )
    {
        me->delete_temp("death_cond_origin/xxfog-poison");
        return 0;
    }
    if (me->query("family/family_name")=="星宿派")//星宿派免疫
    {
        me->delete_temp("death_cond_origin/xxfog-poison");
        return 0;
    }
    if (400-me->query_skill("force",1)<=0)//内功高深免疫
    {
        me->delete_temp("death_cond_origin/xxfog-poison");
        tell_object(me, HIW "你运起本门纯正内功，抵御雾中的毒气。\n" NOR );
        return 0;
    }
    
    if( !living(me) )
            message("vision", me->name() + "身上肌肤开始溃烂。\n", environment(me), me);
    else
    {
            tell_object(me, HIB "你忽然周身剧痛，皮肤迅速开始溃烂。\n" NOR );
            if(environment(me) && environment(me)->query("real_dark") != 1)
            {
            message("vision", me->name() + "的身子痛苦的抽搐起来，皮肤迅速溃烂。\n",
                    environment(me), me);
            }
    }
    me->set_temp("death_cond_id", "xxfog-poison");
	F_POISON->poison_eff(me,"xxfog-poison",(["qi":({1,(50-(int)(me->query_skill("force",1)/10))*10}),"jing":({1,(50-(int)(me->query_skill("force",1)/10))*10}),"busy":({4,random(2)})]),1); 
    me->apply_condition("xxfog-poison", duration - 1);

    return CND_CONTINUE;
}

string query_type(object me)
{
    return "poison";
}

