// yixing.c 移形大法

#include <ansi.h>

inherit F_SSERVER;
int perform(object me,object target)
{
        int damage;
        string msg;
        string limb,*limbs,attack_skill,attack;
        object weapon;
        mapping my,your,action;
        if( !target ) target = offensive_target(me);

        if(!target||!target->is_character() || !me->is_fighting(target) )
        return notify_fail("移形大法只能对战斗中的对手使用。\n");

                
        if( (int)me->query_skill("kunlun-zhang",1)<100)
        return notify_fail("你的昆仑掌不够娴熟，不会使用「移形大法」。\n");
        if( (int)me->query_skill("xuantian-wuji",1)<100)
        return notify_fail("你的玄天无极功不够深厚，不会使用「移形大法」。\n");
                                
                           if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("你没有用玄天无极。\n");

        if( (int)me->query("neili",1)<600)
        return notify_fail("你现在内力太弱，不能使用「移形大法」。\n");
                        
        msg=CYN"$N身形虚晃，施展「移形大法」神功！！\n"NOR;

        me->start_busy(2);
// if target is not busy, then busy 1 hit (by xbd)
        if (!target->is_busy() ) target->start_busy(1);
        if (!target->is_busy() && random(2)==0) target->start_busy(4);
                
if (random(me->query("combat_exp")) > target->query("combat_exp")/4)
{
        damage = (int)me->query_skill("kunlun-zhang",1);
                
                damage = damage + random(damage);
                
        target->receive_damage("qi",damage);
        target->receive_wound("qi",damage);

        me->add("neili",-damage/10);
                
        weapon=target->query_temp("weapon");
        if(objectp(weapon))     attack_skill=weapon->query("skill_type");
        else                            attack_skill="strike";
        attack=target->query_skill_mapped(attack_skill);
        if(!attack)     attack=attack_skill;
        msg +=CYN"$N突然使出$n所学的"+to_chinese(attack)+"！以彼之道还施彼身！\n"NOR;
        my=target->query_entire_dbase();
        your=me->query_entire_dbase();
                limbs=target->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        action=target->query("actions");
        if( !mapp(action) ) {
                target->reset_action();
                action=target->query("action");
                if( !mapp(action) ) {
                        CHANNEL_D->do_channel( this_object(), "sys",
                                sprintf("%s(%s): bad action = %O",
                                        me->name(1), me->query("id"),
        target->query("actions",1)));
                        return 0;
                }
        }
        msg += action["action"]+"！\n";
        msg+=RED"$n惊慌失措之中躲闪不及，结果在$l造成"+action["damage_type"]+"！！\n\n"NOR;
        msg=replace_string(msg,"$l",limb);
        if(objectp(weapon)) msg=replace_string(msg,"$w",weapon->name());
        msg +=RED"$n惊慌失措之中躲闪不及，只觉眼前一黑。\n"NOR;
}
else    msg=CYN"$n一个跃身，躲开了这一击！！\n"NOR;
        message_vision(msg, me, target);	
        return 1;
}

