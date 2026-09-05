//Cracked by Kafei
// wuji.c 混元无极

#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
        mapping attack_val = ([
            "base" : ([ "no_weapon" : "strike", ]),//基本功夫类型
            "skill" : ([ "no_weapon" : "hunyuan-zhang", ]),//高级技能名称
            ]);

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「混元无极」只能对战斗中的对手使用。\n");

        if( me->query_temp("wuji") )
                return notify_fail("你已在使用「混元无极」了！\n");

/*        if( me->query_skill_mapped("strike") != "hunyuan-zhang" )
                return notify_fail("你所用的并非混元掌，不能施展混元无极！\n"); */

/*        if( me->query_skill_prepared("strike") != "hunyuan-zhang" )
                return notify_fail("你所备的并非混元掌，不能施展混元无极！\n"); */

        if( me->query_skill_mapped("force") != "zixia-shengong" && me->query_skill_mapped("force") != "huashan-neigong" )
                return notify_fail("你所用的并非紫霞功，施展不出混元无极！\n");

        if( me->query_skill("force") < 140  )
                return notify_fail("你的紫霞功火候未到，无法施展混元无极！\n");

        if( me->query_skill("strike", "hunyuan-zhang") < 135 )
                return notify_fail("混元无极需要精湛的混元掌方能有效施展！\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够使用混元无极！\n");

        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力不够使用混元无极！\n");

/*        if( me->query_skill_prepared("cuff") == "poyu-quan" ) {
                me->set_temp("restore", 1);
                me->prepare_skill("cuff");
        } */

        message_vision(MAG "\n$N运起紫霞功，全身泛起丝丝紫气，紧接着翻掌劈出一股气劲，无声无息地涌向$n！\n\n" NOR, me, target);

        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL);

        me->add("neili", -100);
        me->start_busy(random(2));

/*        if( me->query_temp("restore") ) me->prepare_skill("cuff", "poyu-quan"); */

        return 1;
}

