// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "tmqidu_poison"; }

string chinese_name() { return "唐门催命散"; }

int update_condition(object me, int duration)
{
	int damage,damage2,damage3;
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIB"惨嚎一声，脸色铁青，全身经脉倒流，不住的颤抖。。\n"NOR, environment(me), me);
                tell_object(me, HIB "你只觉全身经脉倒流，全身肌肉快要坏死一般。！\n" NOR );
damage= (int)me->query("qi",1)/3;
if (damage>=30000) damage=30000;

damage2= (int)me->query("jing",1)/3;
if (damage2>=30000) damage2=30000;

damage3= (int)me->query("neili",1)/3;
if (damage3>=30000) damage3=30000;


if (random(3)==0 )
{
if (me->query("qi") > damage)
        me->add("qi", -damage);
tell_object(me,HIG"你的气力减低了!\n"NOR);
}
else if (random(3)==1 )        
{
if (me->query("jing") > me->query("jing")/2)
        me->add("jing", -damage2);
tell_object(me,HIG"你的精力减低了!\n"NOR);
}
else 
{
if (me->query("neili") > me->query("neili")/2)
        me->add("neili", -damage3);
tell_object(me,HIG"你的内力减低了!\n"NOR);
}
        if (!me->is_busy())
        me->start_busy(4);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
