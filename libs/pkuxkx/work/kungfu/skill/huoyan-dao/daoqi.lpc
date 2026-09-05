// daoqi.c  火焰刀 [火焰刀气]
// coded by emnil@sj  4/29/2k

#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;

void clear_busy(object);

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg;
    int lvl1,lvl2;
    mapping attack_val = ([
        "base" : ([ "no_weapon" : "strike", ]),//基本功夫类型
        "skill" : ([ "no_weapon" : "huoyan-dao", ]),//高级技能名称
        ]);

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「火焰刀气」只能对战斗中的对手使用。\n");

    if( objectp(me->query_temp("weapon")) )
        return notify_fail("你必须空手使用「火焰刀气」。\n");

    if((int)me->query_skill("huoyan-dao",1) < 120)
        return notify_fail("你的火焰刀修为不够， 目前不能使用「「火焰刀气」」! \n");

    if((int)me->query_skill("longxiang-boruo",1) < 120)
        return notify_fail("你的龙象般若功修为不够， 目前不能使用「火焰刀气」! \n");

    if( me->query_skill_mapped("strike") != "huoyan-dao")
        return notify_fail("你必须激发火焰刀为掌法，才能使用「火焰刀气」的绝技！\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) &&
      me->query_skill_mapped("force") != "longxiang-boruo")
        return notify_fail("你现在所使用的内功同「龙象般若功」相抵触，不能使出「火焰刀气」的绝技！\n");

    if( (int)me->query("max_neili") < 2500 )
        return notify_fail("你的内力修为不够！\n");

    if((int)me->query("neili")<500)
        return notify_fail("你的真气不够！\n");

    if((int)me->query("jingli")<300)
        return notify_fail("你的精力不够！\n");

    switch((int)me->query_temp("hyd/pfm")) 
    {
    case 0:
        lvl1 = me->query_skill("strike", "huoyan-dao") + me->query_skill("force", "longxiang-boruo")/5;
        if( me->query_temp("xs/longxiang") &&  me->query_temp("apply/attack")>0 )
        lvl1 += me->query_temp("apply/attack");
        lvl2 = target->query_skill("dodge");

        me->add("neili",-200);
        me->add("jingli",-100);
        msg = HIY"\n$N双目间陡然灵光一闪，随即向$n的身前，身后，身左，身右连劈四刀，刀气如羚羊挂角，完全不知所踪！\n"NOR;

        if( !F_KUNGFU->hit_rate( lvl2, lvl1, 9, me, target) ) 
        {
            if(target->query_temp("hyd/attack")==0)
                target->set_temp("hyd/attack" , me->query_skill("huoyan-dao",1)/4);
            else
                target->add_temp("hyd/attack" , me->query_skill("huoyan-dao",1)/4);

            if(target->query_temp("hyd/dodge")==0)
                target->set_temp("hyd/dodge" , me->query_skill("huoyan-dao",1)/5);
            else
                target->add_temp("hyd/dodge" , me->query_skill("huoyan-dao",1)/5);

            if(target->query_temp("hyd/parry")==0)
                target->set_temp("hyd/parry" , me->query_skill("huoyan-dao",1)/5);
            else
                target->add_temp("hyd/parry" , me->query_skill("huoyan-dao",1)/5);

            target->add_temp("apply/attack" , -me->query_skill("huoyan-dao",1)/4);
            target->add_temp("apply/dodge" , -me->query_skill("huoyan-dao",1)/5);
            target->add_temp("apply/parry" , -me->query_skill("huoyan-dao",1)/5);

            msg += HIR"$n完全看不懂$N的刀路，只的收招紧守门户。\n却发现前后左右都被$N的刀气封死了，攻击防守都不免大受牵制！\n"NOR;
            me->set_temp("hyd/pfm",1);
            me->start_busy(1);
            if ( !target->is_busy() ) target->start_busy(1);
            me->start_perform(3,"火焰刀气");
            call_out("check_pfm", 4, me, target, me->query_skill("huoyan-dao", 1)/25);
        }
        else 
        {
            msg += HIC"确不料$n完全不顾$N所劈出的刀气，往中庭急进，$N只的回掌御敌。\n"NOR;
            me->start_busy(2);
            me->start_perform(3,"火焰刀气");
        }
        break;
    case 1:
        msg = HIY"\n$N全身骨骼一阵爆响，随即又向$n的东南，东北，西南，西北连劈四刀，企图完全封死$n！！\n"NOR;
        lvl1 = me->query_skill("strike",1);
        if( me->query_temp("xs/longxiang") &&  me->query_temp("apply/attack")>0 )
            lvl1 += me->query_temp("apply/attack");
        lvl2 = target->query_skill("parry",1);

        if( !F_KUNGFU->hit_rate( lvl2, lvl1, 9, me, target) ) 
        {
            me->add("neili",-300);
            me->add("jingli",-100);

            me->set_temp("hyd/busy" , me->query_skill("huoyan-dao",1)/40);
            me->set_temp("hyd/pfm",2);
            me->start_perform(6,"火焰刀气");

            // 以此代替busy
            target->set_temp("lost_attack",10);
            target->apply_condition("no_perform", 4);
            target->apply_condition("no_exert", 4);

            msg += HIR"$n仍旧不能掌握$N的刀路，结果被$N完全封住了攻防的路线，只能不停的向上跳跃以躲避$N的攻击！！\n"NOR;
        }
        else 
        {
            me->add("neili",-150);
            me->start_busy(2+random(2));
            me->start_perform(3,"火焰刀气");
            msg += HIC"$n见招拆招，往$N劈来的刀气上连出四招，总算挡住了$N的攻击。\n"NOR;
        }
        break;
    case 2:
        msg = HIR"\n$N突然大呵一声，拼尽全力，往正跃在半空中的$n劈出驻满内劲的一刀！！！\n"NOR;
        lvl1 = me->query("combat_exp");
        if( me->query_temp("xs/longxiang") )
            lvl1 = lvl1/10*12;
        lvl2 = target->query("combat_exp");

        me->add("neili",-200);
        me->add("jingli",-100);

        if ( !F_KUNGFU->hit_rate( lvl2, lvl1, 9, me, target) ) 
        {
            message_vision(msg, me, target);
            msg = "";

            me->add_temp("apply/strength", me->query_skill("longxiang-boruo",1)/4);
            target->set_temp("must_be_hit",1);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, 0, TYPE_SPECIAL);
            target->delete_temp("must_be_hit");
            me->add_temp("apply/strength", -me->query_skill("longxiang-boruo",1)/4);

            me->start_perform(4,"火焰刀气");
        }
        else 
        {
            msg += HIC"$n退无可退，只得全力封挡这一招，最后虽然挡住了这一招，却也惊出了一身冷汗！
            ?N全力发出的一招给挡了回去，大损$N的内力。\n$N再也无法维持封锁$n东南，东北，西南，西北的刀气。\n"NOR;
            me->start_busy(2);
            me->start_perform(4,"火焰刀气");
            me->delete_temp("hyd/busy");
            me->set_temp("hyd/pfm",1);
            clear_busy(target);
        }
        break;
    default: 
        break;
    }

    message_vision(msg, me , target);

    return 1;
}

void check_pfm(object me,object target,int count)
{
    if( !objectp(me)
      || !objectp(target)
      || !me->is_fighting(target)
      || objectp(me->query_temp("weapon"))
      || count==0
      || me->query_skill_mapped("strike")!="huoyan-dao"
      || me->query_skill_mapped("force")!="longxiang-boruo" )
    {
        if( objectp(target) )
        {
            target->add_temp("apply/attack" , target->query_temp("hyd/attack"));
            target->add_temp("apply/dodge" , target->query_temp("hyd/dodge"));
            target->add_temp("apply/parry" , target->query_temp("hyd/parry"));
            target->delete_temp("hyd/attack");
            target->delete_temp("hyd/dodge");
            target->delete_temp("hyd/parry");
            clear_busy(target);
        }

        if( objectp(me) )
        {
            me->delete_temp("hyd/pfm");
            me->delete_temp("hyd/busy");
        }

        if( objectp(me) && objectp(target) )
            message_vision(HIC"\n$N感觉丹田一顿，却是内力消耗过多，再也不能维持封住$n的刀气。\n"NOR, me , target);
        else
            if ( objectp(me) ) message_vision(HIC"\n$N慢慢收回了劈出的刀气。\n"NOR, me);

        return;
    }

    if( me->query_temp("hyd/pfm")==2 )
    {
        if( me->query_temp("hyd/busy")==0 )
        {
            me->delete_temp("hyd/busy");
            me->set_temp("hyd/pfm",1);
            clear_busy(target);
            message_vision(HIC"\n$n渐渐掌握了$N的刀路，奋力反击，总算破了封住东南，东北，西南，西北的刀气。\n"NOR, me , target);
        }
        else
        {
            target->set_temp("lost_attack",10);
            target->apply_condition("no_perform", 4);
            target->apply_condition("no_exert", 4);

            me->add_temp("hyd/busy",-1);
            if( me->query_temp("hyd/busy")==1 )
                message_vision(HIC"\n$n虽然还没有看破$N的刀气，但动作间似乎已经敏捷了许多。\n"NOR, me , target);
        }
    }

    call_out("check_pfm",4,me,target,count-1);
}

void clear_busy(object target)
{
    if (!objectp(target)) return;
    target->delete_temp("lost_attack");
    target->clear_condition("no_perform");
    target->clear_condition("no_exert");
}
