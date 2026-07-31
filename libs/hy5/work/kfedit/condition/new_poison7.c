// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "new_poison7"; }

string chinese_name() { return "全部伤害"; }

int update_condition(object me, int duration)
{
int damage;
        if( duration < 1 ) return 0;

 message("vision", me->name() + CYN"身上圣光一闪,神圣伤害发作了。\n"NOR, environment(me), me);
damage=me->query("qi",1)/20;
if (damage> 25000) damage=25000;
if (me->query("shen",1) < 0)
{
damage=damage*3;
me->receive_wound("qi", damage);
me->receive_damage("qi", damage);
tell_object(me, CYN "你身上圣光一闪,神圣伤害发作了。\n" NOR );
}
        
 message("vision", me->name() + MAG"身上暗影一闪,暗影伤害发作了。\n"NOR, environment(me), me);
damage=me->query("qi",1)/20;
if (damage> 25000) damage=25000;
if (me->query("shen",1) > 0)
{
damage=damage*3;
me->receive_wound("qi", damage);
me->receive_damage("qi", damage);
tell_object(me, MAG "你身上暗影一闪,暗影伤害发作了。\n" NOR );
}

 message("vision", me->name() + HIR"身上火焰一闪,火焰伤害发作了。\n"NOR, environment(me), me);
damage=me->query("qi",1)/20;
if (damage> 25000) damage=25000;
me->receive_wound("qi", damage);
me->receive_damage("qi", damage);
tell_object(me, HIR "你身上火焰一闪,火焰伤害发作了。\n" NOR );
me->set_temp("apply/defense",-100);
me->set_temp("apply/dodge",-100);

 message("vision", me->name() + BLU"身上冰霜一闪,冰霜伤害发作了。\n"NOR, environment(me), me);
tell_object(me, BLU"你身上冰霜一闪,冰霜伤害发作了。\n" NOR );
if (!me->is_busy()) me->start_busy(6);
me->set_temp("apply/attack",-100);


 message("vision", me->name() + HIG"身上绿光一闪,自然之毒的伤害发作了。\n"NOR, environment(me), me);
damage=me->query("qi",1)/30;
tell_object(me, HIG "身上绿光一闪,自然之毒的伤害发作了。\n" NOR );
if (damage> 25000) damage=25000;
me->receive_wound("qi", damage);
me->receive_damage("qi", damage);

damage=me->query("jing",1)/30;
if (damage> 25000) damage=25000;
me->receive_wound("jing", damage);
me->receive_damage("jing", damage);


 message("vision", me->name() + WHT"身上白光一闪,奥术的伤害发作了。\n"NOR, environment(me), me);
damage=me->query("neili",1)/20;
if (damage> 25000) damage=25000;
if (damage< 1000) damage=1000;	
if ((int)me->query("neili",1)> damage) 
{
me->add("neili", -damage);
tell_object(me, CYN "你身上白光一闪,奥术的伤害发作了。\n" NOR );
}


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
