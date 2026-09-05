//手挥五弦 by Zine
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    int damage, p;
    object weapon;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("你只能对战斗中的对手使用「手挥五弦」。\n");

    if( (int)me->query_skill("pipa-shou",1) < 200)
        return notify_fail("你目前功力还使不出「手挥五弦」。\n");

    if (me->query_temp("shouhuiwuxian"))
        return notify_fail("你刚刚使用过琵琶手特殊攻击。\n");

    if( (int)me->query("neili") < 500 )
        return notify_fail("你的内力不够。\n");
            
    me->add("neili", - 200);
    msg = HIW"$N惨然一笑，心中悲意上涌，十指次第弹出，\n" + "天地间只剩下$N的指影指风，$n只觉得呼吸都有些困难！\n"NOR;
    message_combatd(msg, me, target);
    msg = "";
    me->set_temp("shouhuiwuxian",1);
    if (base_name(environment(me))=="/d/jiangzhou/boat")  //一物克一物，漂流时候对付其他门派超级废柴的琵琶手，对付明教是利器。by Zine
    {
        if (target->query("family/family_name")=="明教"&&
            //B-
              F_KUNGFU->hit_rate( (int)me->query_skill("hand", "pipa-shou"), (int)target->query_skill("dodge"), 6, me, target) )
        {
            damage = (int)me->query_skill("pipa-shou",1) + (int)me->query_skill("hand", 1) + me->query("jiali");
            damage += random(damage);
            F_KUNGFU->hit_wound("qi", damage, damage, me, target);
            target->add_temp("琵琶手击中", 1);
            msg += HIR"只见$N指风纵横，瞬间$n浑身被击出十个血洞！\n"NOR;                                               
            if ( target->query_temp("琵琶手击中")>=2 )
            {
                if ( target->query("eff_qi")<damage )
                {
                    target->set("max_qi",1);
                    if (target->query("eff_qi")>1)
                    {
                        target->receive_wound("qi", target->query("eff_qi")-1 , me);
                    }
                    else target->receive_wound("qi", 1, me);
                    if (target->query("qi")>1)
                    {
                        target->receive_damage("qi", target->query("qi")-1 , me);
                    }
                    else target->receive_damage("qi", 1, me);
                }
            }
            me->add("neili", -me->query("jiali"));
            message_vision(msg, me, target); 
            COMBAT_D->report_status(target);
            msg = "";
        }
        if (target->query("family/family_name")!="明教"&&
            //F+            	
            F_KUNGFU->hit_rate( (int)me->query_skill("hand", "pipa-shou"), (int)target->query_skill("dodge"), 9, me, target) )
        {
            damage = (int)me->query_skill("pipa-shou", 1)+ me->query("jiali");
            damage += random(damage);
            F_KUNGFU->hit_wound("qi", damage, damage, me, target);
            msg += HIR"只见$N指风纵横，瞬间$n浑身被击出数个血洞！\n"NOR;                                                
            me->add("neili", -me->query("jiali"));
            message_vision(msg, me, target);
            COMBAT_D->report_status(target);
            msg = "";
        }
        me->add_busy(1);
        call_out("remove_wuxian",5+random(3),me);
        return 1;
    }
//F+        
    if( F_KUNGFU->hit_rate( (int)me->query_skill("hand", "pipa-shou"), (int)target->query_skill("dodge"), 9, me, target) )
    {
            
            damage = (int)me->query_skill("pipa-shou",1) + (int)me->query_skill("hand", 1) + me->query("jiali");
            damage += random(damage);
            F_KUNGFU->hit_wound("qi", damage, damage, me, target);
            msg += HIR"只见$N指风纵横，瞬间$n浑身被击出数个血洞！\n"NOR;                                                
            me->add("neili", -me->query("jiali"));
            message_vision(msg, me, target); 
            COMBAT_D->report_status(target);
            msg = "";
    } 
    else{
            msg += HIC "可是$p早有防备，$P空耗内力，却完全失却了目标。\n" NOR;
            me->add("neili", -me->query("jiali")/2);
            me->add_busy(3);
            message_vision(msg, me, target); 
    }
    
    me->add_busy(1);
    call_out("remove_wuxian",5+random(3),me);
    return 1;
}

void remove_wuxian(object me)
{
    if (!me) return;
    me->delete_temp("shouhuiwuxian");
}


