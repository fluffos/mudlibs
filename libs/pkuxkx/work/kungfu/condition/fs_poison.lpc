inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

string query_type(object me) { return "poison"; }

int update_condition(object me, int duration)
{
    int skill;

    if( duration < 1 ) 
    {
        me->delete_temp("death_cond_origin/fs_poison");
        return 0;
    }
    tell_object(me, HIB "你突然觉得一股恶臭从腹中升起，不禁大呕起来！\n" NOR );
    tell_room(environment(me), HIB + me->name()+"脸上浮着一层黑气，脚步蹒跚，突然吐出一堆秽物！\n" NOR, ({ me }));
    me->set_temp("death_cond_id", "fs_poison");
	F_POISON->poison_eff(me,"fs_poison",(["qi":({1,to_int(40*log(1+duration)/log(10)+random(10))}),"jing":({1,to_int(25*log(1+duration)/log(10)+random(10))}),]),1); 
    skill = 1 + me->query_skill("poison",1)/40;
    me->apply_condition("fs_poison", duration - skill);

    return CND_CONTINUE;
}

