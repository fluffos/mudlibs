// luoying-shenjian bibo 
// liu 2002
/*
傻姑挥手格开黄蓉的擒拿，回掌拍向她肩膀。
突然间刷刷两掌，正是“碧波掌法”中起手的两招，只不过手法笨拙，
殊无半分这路掌法中必不可缺的灵动之致；但掌势如波，方位姿势却确确实实是桃
花岛的武功。

岂知傻姑手臂疾缩，反手便是一掌，正是桃花岛武学“碧波掌法”，她所学虽然不
精，这掌法却甚奥妙。梁子翁没半点防备，拍的一声，这一掌结结实实的打在他手
背之上，落手着实不轻。
*/

#include <ansi.h>
#include <combat.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string *limb, type, result;
        int skill,max_skill,jiajin,max_jiajin,jiali,max_jiali,damage,exp1,exp2;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「碧波掌」只能在战斗中使用。\n");

        if( me->query_skill_mapped("force") != "bitao-xuangong" )
                return notify_fail("你所用的并非碧涛玄功，使不出「碧波掌」！\n");

        if( me->query_skill("force") < 150 )
                return notify_fail("你的内功修为不够，不会使用「碧波掌」。\n");

        if( me->query_skill("strike") < 180 )
                return notify_fail("你的掌法修为不够，不会使用「碧波掌」。\n");

        skill=me->query_skill("luoying-shenjian",1);

        if( me->query("neili") < skill*3 ) return notify_fail("你的内力不够！\n");

        if( me->query("jingli") < skill*2 ) return notify_fail("你的精力不够！\n");

        jiali = me->query("jiali",1);
	jiajin= me->query("jiajin",1);
        damage = me->query_skill("force")+me->query_skill("strike")+random(jiali+jiajin)*2;
        max_skill=pow(me->query("combat_exp")*10,0.33333)+1;
        max_jiali=me->query_skill("force")/2;
        max_jiajin = me->query("max_jingli")/20;
        type="内伤";
        limb = target->query("limbs");
        exp1=me->query("combat_exp",1)/1000;
        exp2=target->query("combat_exp",1)/1000;

        if (skill<max_skill*2/3)
        {
                message_vision(HIB"\n斗然间$N刷刷两掌，掌势如波，正是“碧波掌”中起手的两招，只不过掌法笨拙，殊无半分此招中必不可缺的灵动之致！\n"NOR,me,target);

                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }
        else if (!jiali || !jiajin || jiali<max_jiali/2 || jiajin<max_jiajin/2 )
        {
                message_vision(HIY"\n斗然间$N刷刷两掌，掌势如波，正是“碧波掌”中起手的两招，只不过内劲不足，虽不乏此招灵动之致，却不济骇人声势！\n"NOR,me,target);

                me->add_temp("apply/speed", skill);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
				COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                me->add_temp("apply/speed", -skill);
        }
        else
        {
                message_vision(HIG"\n斗然间$N刷刷两掌，掌势如波，正是“碧波掌”中起手的两招，掌法、内劲具精，已然将此招中灵动之意发挥得淋漓尽致，声势骇人！\n"NOR,me,target);

                me->add_temp("apply/attack", skill);
                me->add_temp("apply/speed", skill);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                me->add_temp("apply/attack", -skill);
                me->add_temp("apply/speed", -skill);
        }

        if (skill<max_skill*2/3)
        {
                message_vision(HIY"\n突然间$N手臂疾缩，反手又是一掌，掌势如波，正是“碧波掌”中的上乘武功，$N所学虽然不精，这掌法却甚奥妙。\n\n"NOR,me, target);
        }
        else if (!jiali || !jiajin || jiali<max_jiali/2 || jiajin<max_jiajin/2 )
        {
                message_vision(HIG"\n突然间$N手臂疾缩，反手又是一掌，掌势如波，正是“碧波掌”中的上乘武功，$N所学虽然精劲，不过出手稍显绵延之意。\n\n"NOR,me, target);
        }
	else
        {
                message_vision(HIM"\n突然间$N手臂疾缩，反手又是一掌，掌势如波，正是“碧波掌”中的上乘武功，$N所学精劲，出手却也毫不留情。\n\n"NOR,me, target);
        }

        if (exp1+me->query_int()+me->query_skill("strike")>exp2+target->query_int()+(target->query_skill("dodge")+target->query_skill("parry"))/2)
        {
                message_vision(HIW"$n没半点防备，拍的一声，结结实实的打在$n"+limb[random(sizeof(limb))]+"之上，落手着实不轻。\n\n"NOR,me, target);

                target->receive_wound("qi", damage, me);
                target->receive_damage("qi", damage+random(damage), me);
                if(!jiali ) type = "瘀伤";
                result = COMBAT_D->damage_msg(damage, type);
                result = replace_string( result, "$l", limb[random(sizeof(limb))]);
                result = replace_string( result, "$p", target->name() );
                message_vision(result, me, target);
        }

        else if (target->query_skill("strike") && target->query("race") == "人类")
        {
                weapon = target->query_temp("weapon");
                if(weapon)
                {
			weapon->unequip();
                        weapon->move(environment(target));
                        target->reset_action();
                }
                message_vision(HIW"$n也是运力于掌，要以数十年修习的内功相抵，这一下是以硬接硬，刹那之间，已是高手比拼真力。\n"NOR,me,target);

                if( me->query("max_neili")+me->query_skill("force")+me->query("neili") > target->query("max_neili")+target->query_skill("force")+target->query("neili"))
                {
                        message_vision(HIB"\n两股劲风刚触到，$n内劲稍有不及，闷哼一声，被$N震得静脉逆转，血气翻涌。\n\n"NOR,me,target);
                        target->receive_wound("qi", damage, me);
                        target->receive_damage("qi", damage+random(damage), me);
                        result = COMBAT_D->damage_msg(damage, type);
                        result = replace_string( result, "$l", limb[random(sizeof(limb))]);
                        result = replace_string( result, "$p", target->name() );
                        message_vision(result, me, target);
                }
                else
                {
                        message_vision(HIG"\n$n内劲刚猛，$N自知难敌，大喝一声，运足真气，将$n震开。\n\n"NOR,me,target);
                }
        }

        else if (exp1+me->query_int()+me->query_skill("strike")*4/3>exp2+target->query_int()+(target->query_skill("dodge")+target->query_skill("parry"))/2)
	{
                message_vision(WHT"$n虽有防备，但身法不灵，拍的一声，结结实实的打在$n"+limb[random(sizeof(limb))]+"之上。\n\n"NOR,me, target);

                damage = damage-random(damage/2);
                target->receive_wound("qi", damage, me);
                target->receive_damage("qi", damage+random(damage), me);
                if(!jiali ) type = "瘀伤";
                result = COMBAT_D->damage_msg(damage, type);
                result = replace_string( result, "$l", limb[random(sizeof(limb))]);
                result = replace_string( result, "$p", target->name() );
                message_vision(result, me, target);
        }
        else
        {
                message_vision(CYN"$n早有防备，连忙闪身，虽已然躲过，却也吓的冷汗直流。\n\n"NOR,me, target);
                me->add("neili", -(skill*2+jiali));
                me->add("jingli", -(skill+jiajin));
                me->start_busy(1+random(2));
                return 1;
        }

        if( wizardp(me) ) tell_object(me,"damage "+damage+"\n");

	COMBAT_D->report_status(target);
        me->add("neili", -(skill*2+jiali));
        me->add("jingli", -(skill+jiajin));
        me->start_busy(2+random(2));
        return 1;
}
