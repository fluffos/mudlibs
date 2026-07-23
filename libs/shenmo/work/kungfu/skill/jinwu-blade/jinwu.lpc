///NOV.13.2000 by lucas
// jinwu.c 金乌堕地

/*
由于劈断对方武器的功能是这个perform最大的威力，但为了保持独孤九剑在
这一方面的第一地位，特地对发挥这一威力的条件，在程序中做了如下限制
希望以后的巫师不要更改这些设定，毕竟在weapon武功中，不能超越lonely-sword的地位。
*/

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2,target,*inv;
        int skill, ap, dp, neili_wound, qi_wound,equip,skill1,skill2,skill3,skill4;
int attack_time,i;
        me->clean_up_enemy();
        target = me->select_opponent();
        skill  = me->query_skill("jinwu-blade",1);
        skill1 = me->query_skill("xueshan-sword",1);
        skill2 = me->query_skill("bingxue-xinfa",1);
        skill3 = me->query_skill("blade",1);
        skill4 = me->query_skill("unarmed",1);


        if( !(me->is_fighting() ))
            return notify_fail("「"+HIR"金乌堕地"NOR+"」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
            return notify_fail("你使用的武器不对。\n");

        if( skill < 100)
            return notify_fail("你的金乌刀法等级不够, 不能使用「"+HIR"金乌堕地"NOR+"」！\n");
        if(me->query_skill("bingxue-xinfa",1)<100)
            return notify_fail("你的冰雪心法等级不够, 不能使用「"+HIR"金乌堕地"NOR+"」！\n");
 

        if( me->query("neili") < 700 )
            return notify_fail("你的内力不够，无法运用「"+HIR"金乌堕地"NOR+"」！\n");

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
attack_time = random((int)me->query_skill("jinwu-blade", 1) / 30);
me->start_busy(2);
if (attack_time > 9 ) attack_time=9;
        for(i = 0; i < attack_time; i++){
         msg = HIR "$N把手上的钢刀舞成了"+HIW"雪花"+HIR"一般，突然从雪花中劈出一刀来！\n" NOR;
me->set_temp("noauto",1);
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
me->delete_temp("noauto");
me->add("neili",-50);
          }
}
        msg = HIY
    "$N纵身跃起,使出"+HIR"「金乌堕地」"NOR+""+HIY"，挥舞"NOR""+weapon->name()+""NOR+HIY"从半空中挥刀直劈下来，\n刀锋离地尚有数尺，地下已是尘沙飞扬，败草落叶被刀风激得团团而舞，\n将$n逃遁退避的空隙封的严严实实。\n"NOR;
        message_combatd(msg, me, target);

        ap = random(me->query("combat_exp") + skill*5);
        dp = target->query("combat_exp")/2;
        if( dp < 1 )
            dp = 1;
        if( ap > dp )
        {
            if(userp(me))
                 me->add("neili",-250);
            msg = HIC"$n避无可避,只觉一股刚猛之极的劲风扑面而来，使人直欲窒息。\n$n极力后退隔挡，却只见"NOR""+weapon->name()+""HIC"刀光一闪，毫不停息，一刀正中面门。\n"NOR;
            qi_wound = (int)me->query_skill("jinwu-blade",1)+(int)me->query_skill("blade",1)+(int)me->query_str()*10;
            qi_wound = random(qi_wound*2);
// if(qi_wound > target->query("qi")) qi_wound = 100; ?  damage limit is wrong (by xbd)
            if(qi_wound > target->query("qi"))
                 qi_wound = target->query("qi") > 100 ? target->query("qi") - 100 : target->query("qi");
if (qi_wound < 10) qi_wound=10;
            target->receive_damage("qi", qi_wound);
// 4 pfm all npc die, too power? please consider it. (by xbd)
            target->receive_wound("qi", target->query("qi")/3);
target->apply_condition("ill_shanghan",50);
target->apply_condition("iceshock",50);
target->apply_condition("xuantian_han",50);
target->apply_condition("xuanming_poison",50);

            target->start_busy(2+random(1));
            me->start_busy(1+random(2)); 

       objectp(weapon2 = target->query_temp("weapon"));

         if(me->query("str")>=20                                 //先天臂力必须不小于于20
       && objectp(weapon2 = target->query_temp("weapon"))
       && me->query_str() >= 45                                 //后天臂力必须不小于45
       && me->query("max_neili") > 2500                        //最大内力必须大于2800
       && !me->query("betrayer")                               //必须没叛过师
       && (me->query("neili") - me->query("max_neili")) > 300  //现有内力必须比最大内力多300，由于在上面会减掉550，实际必须大于550
       && skill > 200                                           //冰雪心法必须大于200级
       && skill1 > 200                                          //基本拳脚必须大于200级
       && skill2 > 200                                          //雪山剑法必须大于200级
       && skill3 > 200                                          //金乌刀法必须大于200级
       && skill4 > 200                                          //基本刀法必须大于200级
       && !weapon2->query("no_drop")                           //下面这些是确保神兵及自铸武器不被砍断
       && !weapon2->query("no_get") 
       && !weapon2->query("no_put")
       && !weapon2->query("no_beg")
       && !weapon2->query("no_steal")
       && !weapon2->query("no_give") 
       )
       {
		inv = all_inventory(target);
		for(equip=0; equip<sizeof(inv); equip++)
        {
            if(inv[equip]->query("weapon_prop") && ((string)inv[equip]->query("equipped")=="wielded"))

		{
msg += HIW "$N力道未尽，手中刀势不绝，连带$n手上"NOR""+inv[equip]->query("name")+HIW"一起劈断。\n只听当的一声，$n手上的"NOR""+inv[equip]->query("name")+HIW"已被劈成两半，掉在了地上！\n"NOR;
        message_combatd(msg, me,target);

			inv[equip]->unwield();
			inv[equip]->reset_action();
			inv[equip]->move(environment(target));
			inv[equip]->set("name", "断掉的"+ inv[equip]->query("name") );
			inv[equip]->set("value", 0);
			inv[equip]->set("weapon_prop", 0);
			inv[equip]->set("long", "一把破烂武器，从中断开，破口整齐，看来是被高手一刀劈开的。\n");
			}
		}

          return 1;
         }
        }
        else
        {
            if(userp(me))
                 me->add("neili",-100);
            msg = HIW"可是$n轻轻往旁边一闪,闭过了$N这必杀的一刀。\n"NOR;
            me->start_busy(2);
}

//        }
        message_combatd(msg, me, target);
        return 1;
}


