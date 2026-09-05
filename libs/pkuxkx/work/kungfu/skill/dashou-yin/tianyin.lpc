// tianyin.c 密宗大手印之天印
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「阿修罗天印」诀只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「阿修罗天印」诀！\n");

        if((int)me->query_skill("longxiang-boruo",1)<80)
                return notify_fail("你的龙象般若功修为不够。\n");

        if( (int)me->query_skill("dashou-yin", 1) < 80 )
                return notify_fail("你的密宗大手印修为不够，不能使用「阿修罗天印」诀。\n");

        if((int)me->query("max_neili",1)<1000)
                return notify_fail("你的内力修为太差无法使用本势。\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你现在内力太弱，不能使用「阿修罗天印」诀。\n");

        if((int)me->query_skill("poison",1)<80)
            return notify_fail("你的毒技不够，无法配合送出掌毒。\n");

        me->start_perform(5,"阿修罗天印");
        msg = HIY "$N默念愤怒咒，运起龙象般若神功，右手陡然大了数倍，带着一股紫黑之气击向$n。\n"NOR;
        msg += HIG "「阿修罗天印」诀。\n\n"NOR;

        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
        if( target->query_temp("fanzhen")){
             msg+=HIY"$n 不闪不躲任由$N一掌击在胸口之上，只见金光一闪，$N的掌毒尽被反震击而回！\n"
                   +"$N失声惊叫：“金刚不坏体神功”。\n"NOR;
                me->start_busy(2);
                damage = 10+random((int)me->query_skill("dashou-yin",1)
                        +(int)me->query_skill("longxiang-boruo",1)
                        +(int)me->query_skill("poison",1));
                damage = damage + random(damage/2);
                if (damage>2000) damage=2000;
                F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
                me->add("neili", -damage/3);

                //me->set_temp("death_cond_origin/dsy_poison", target);
				F_POISON->poison_attack(target,me,"dsy_poison", random(me->query_skill("poison")/10) + 1 +
                                    me->query_condition("dsy_poison"));
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                return 1;
        }
//命中率C-
        if ( F_KUNGFU->hit_rate( me->query("combat_exp"), target->query("combat_exp"), 9, me, target) )
        {
                me->start_busy(3);
                if ( !target->is_busy() )
                  target->start_busy(random(3));
                damage = 10+random((int)me->query_skill("dashou-yin", 1)
                        +(int)me->query_skill("longxiang-boruo",1)
                        +(int)me->query_skill("poison",1));
                if ( (int)me->query_str() > (int)target->query_con() )
                damage = random( (damage*(int)me->query_str())/5 );
                else damage = damage + random(damage/2);
                if ( damage > 3000 ) damage = 3000;
                F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
                me->add("neili", -damage/3);

                //target->set_temp("death_cond_origin/dsy_poison", me);
                if ( me->query_skill("poison",1) > target->query_skill("poison",1) )
				F_POISON->poison_attack(me,target,"dsy_poison", random(me->query_skill("poison")/5) + 1 +
                              target->query_condition("dsy_poison"));
                else
				F_POISON->poison_attack(me,target,"dsy_poison", random(me->query_skill("poison")/10) + 1 +
                        target->query_condition("dsy_poison"));

                if( damage < 100 ) msg += HIY"$n气凝于手，挥掌抵御，将对手掌力悉数化解。\n"NOR;
                else if( damage < 300 ) msg += HIY"$n运气发力，与$N硬拼了一掌，虽不吃亏，但胸腹之间气血翻涌已极是不舒服。\n"NOR;
                else if( damage < 500 ) msg += RED"$n勉强以双手化解敌招，但觉$N内力如怒海狂涛源源而至，挟着一股热气直透$n胸臆！\n"NOR;
                else msg += HIR"$n不及闪避，被$N重重一掌正印中胸口膳中气海，$n只觉真气四散，口一张鲜血狂喷而出。\n"NOR;
        }
        else
        {
               me->start_busy(3);
               msg += CYN"可是$p成竹在胸，两掌轻拍早将$P的掌力化为无形。\n"NOR;
        }
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);

        return 1;
}

