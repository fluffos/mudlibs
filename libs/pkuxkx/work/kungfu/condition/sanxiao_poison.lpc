inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

string query_type(object me) { return "poison"; }

int update_condition(object me, int duration)
{
    // string deathmsg = "诡异地笑了三笑突然七窍流血";
    int skill;

    if( duration < 1 ) 
    {
        me->delete_temp("death_cond_origin/sanxiao_poison");
        return 0;
    }
    if( random(3) ) 
    {
        //message_vision(HIG"$N脸上忽然露出诡异的一笑，看来是"HIB"三笑逍遥散"HIG"发作了！\n" NOR, me);
        message_vision(HIG"$N脸上忽然露出诡异的一笑．．．\n" NOR, me);
			F_POISON->poison_eff(me,"sanxiao_poison",(["qi":({0,to_int(100*log(1+duration)/log(10) + random(10))}),"jing":({1,to_int(500*log(1+duration)/log(10) + random(100))}),]),1); 


    }
    skill = 1 + me->query_skill("poison",1)/100;
    me->apply_condition("sanxiao_poison", duration - skill);

    return CND_CONTINUE;
}

