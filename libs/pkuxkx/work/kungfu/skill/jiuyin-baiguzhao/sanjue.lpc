// jiuyin 九阴三绝爪

#include <ansi.h>
#include <char.h>
#include <combat.h> 
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        int skill, i; 
        int coe1=(int)me->query("jiuyin_2");
        mapping attack_val = ([
            "base": ([ "no_weapon" : "claw" ]),//基本功夫类型
            "skill" : ([ "no_weapon" : "jiuyin-baiguzhao" ]),//高级技能名称
            ]);

        skill = (int)me->query_skill("jiuyin-baiguzhao", 1);

        if ( !target ) target = offensive_target(me);

        if ( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「九阴三绝爪」只能在战斗中使用。\n");

        if ( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("你拿着武器怎么能使用「九阴三绝爪」！\n");   

        if ( (int)me->query_skill("jiuyin-baiguzhao", 1) < 140 )
                return notify_fail("你的九阴白骨爪还不够娴熟，使不出「九阴三绝爪」绝技。\n");

        if ( skill < 180 ) i = 3;
        if ( skill < 220 ) i = 2;
        else i = 1;

/*        if ( me->query_skill_mapped("claw") != "jiuyin-baiguzhao"
          || me->query_skill_prepared("claw") != "jiuyin-baiguzhao")
                return notify_fail("你现在无法使用「九阴三绝爪」！\n"); */

        if( (int)me->query("max_neili") < 400 * i  ) return notify_fail("你现在内力太弱，使不出「九阴三绝爪」。\n");      

        if( (int)me->query("neili") < 1100 ) return notify_fail("你现在真气太弱，使不出「九阴三绝爪」。\n");

        if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_SHEN) &&
            me->query("shen") > -1000000 )
            return notify_fail("你不够狠毒，无法使出「九阴三绝爪」的绝技。\n");

        me->start_perform(5, "九阴三绝爪");
        message_vision(RED"\n$N突然怪叫一声，全身骨骼如爆豆般噼啪作响，手臂突然暴涨三尺！\n"NOR,me);

        me->add("neili", -200);
        me->start_busy( 2 + random(i));

        me->add_temp("apply/attack", skill);       
        me->add_temp("apply/damage", skill);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        if(me->is_fighting(target)||coe1) 
        {
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        }
        if(me->is_fighting(target)||coe1)
        {
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        }
        me->add_temp("apply/damage", -skill);    
        me->add_temp("apply/attack", -skill);

        return 1;
}

