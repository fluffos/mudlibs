#include <ansi.h>
#include <combat.h>
inherit F_SSERVER; 
int perform(object me, object target)
{
        string msg;
        int damage;
        object weapon;
        int mlvl,tlvl; //等级
        int i;
        object* inv;
        
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
        {
                inv = all_inventory(me);
                for (i=0;i<sizeof(inv);i++)
                if (inv[i]->query("skill_type") == "sword")
                {
                        weapon = inv[i];
                        i = -1;
                        break;
                }
                if (i != -1)
                        return notify_fail("你身上没带剑，飞什么呀？\n");
        }
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character())
                return notify_fail("你要对谁使「飞剑式」？\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「飞剑式」只能对战斗中的对手使用。\n");
        //计算level
        if (userp(target))    tlvl  = target->query("level");
           else  tlvl  = to_int(pow(target->query("combat_exp")/400, 0.333)-random(5));
        if (userp(me))        mlvl = me->query("level");
           else  mlvl  = to_int(pow(me->query("combat_exp")/400, 0.333)-random(5));
        if (tlvl < 1) tlvl=1;
        if (mlvl < 1) mlvl=1;
        if (wizardp(me))
           tell_object(me,sprintf("mlvl:%d,tlvl:%d,mysword:%d,tdodge:%d\n",mlvl,tlvl,me->query_skill("sword"),target->query_skill("dodge")));


        if( (int)me->query_skill("xiake-jianfa", 1) < 100 )
                return notify_fail("你的侠客剑法不够娴熟，不会使用「飞剑式」。\n");
        if((int)me->query("neili") < 50)
                return notify_fail("你的内力不够呀!\n");

        msg = HIY "只见$N运起侠客剑法的「飞剑式」，"NOR+weapon->query("name")+HIY"脱手而出，直刺$n。\n"NOR;

        me->start_busy(random(4));
        if( F_KUNGFU->hit_rate( me->query_skill("sword")*mlvl, (int)target->query_skill("dodge")*tlvl, 6, me, target) ) 
        {
                msg += HIR"只听$p一声惨叫，被"NOR+weapon->query("name")+HIR"刺个正着。\n" NOR;
                message_vision(msg, me, target);       
                damage = ((int)me->query_skill("xiake-jianfa", 1)+(int)me->query_skill("sword", 1))/2;
                damage += (int)me->query_skill("xiake-shengong",1);
                F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
                COMBAT_D->report_status(target);
                me->add("neili", -damage/10);
        } else {
                me->start_busy(4);
                msg += HIG "可是$p看破了$P的企图，轻轻松松地躲了过去。\n" NOR;
                message_vision(msg, me, target);
        }
        return 1;
}

