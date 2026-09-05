//Cracked by Kafei
//jianzhang.c 剑掌五连环

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
        string weapon;
        object weapon1;
        int    lvl1, lvl2, amount;
        float factor;
        mapping attack_val = ([
            "base" : ([ "weapon" : "sword", "no_weapon" : "strike", ]),//基本功夫类型
            "skill" : ([ "weapon" : "huashan-jianfa", "no_weapon" : "hunyuan-zhang", ]),//高级技能名称
            ]);

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("剑掌五连环只能对战斗中的对手使用。\n");

        weapon1 = me->query_temp("weapon");
        if( !objectp(weapon1) || weapon1->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何使得剑掌五连环？\n");

/*        if( me->query_skill_mapped("strike") != "hunyuan-zhang" )
                return notify_fail("你所用的并非混元掌，不能与华山剑法配合施展剑掌五连环！\n");

        if( me->query_skill_prepared("strike") != "hunyuan-zhang" )
                return notify_fail("你所备的并非混元掌，不能与华山剑法配合施展剑掌五连环！\n"); */

        if( me->query_skill_mapped("force") != "zixia-shengong" && me->query_skill_mapped("force") != "huashan-neigong"
			&&me->query_skill_mapped("force") != "hunyuan-gong"		)
                return notify_fail("你所用的并非华山派内功，无法施展剑掌五连环！\n");

        if( me->query_skill("zixia-shengong", 1) < 60 &&me->query_skill("hunyuan-gong", 1) < 60
		&&me->query_skill("huashan-neigong", 1) < 60)
                return notify_fail("你的华山派内功火候未到，无法施展剑掌五连环！\n");

        if( (lvl1=me->query_skill("strike", "hunyuan-zhang")) < 100 )
                return notify_fail("剑掌五连环需要精湛的混元掌配合，方能有效施展！\n");

        if( (lvl2=me->query_skill("sword", "huashan-jianfa")) < 100 )
                return notify_fail("你华山剑法修为不足，还不会使用剑掌五连环！\n");

        amount = (lvl1+lvl2) / 15;

        if ( amount < 40 ) amount = 40;
        if ( amount > 160 ) amount = 160;
        if (me->query("huashannewbiejobsword")>=1)//华山新手福利 Zine
        {
            me->add("huashannewbiejobsword",-1);
            factor=1+to_float(me->query("huashannewbiejobsword"))/550;
            amount=to_int(amount*factor);
        }
        if( me->query("neili") <= amount*4 )
                return notify_fail("你的内力不够使用剑掌五连环！\n");
        if( me->query("jing") <= amount )
                return notify_fail("你的精不够使用剑掌五连环！\n");

/*        if( me->query_skill_prepared("cuff") == "poyu-quan" ) {
                me->set_temp("restore", 1);
                me->prepare_skill("cuff");
        } */

        weapon = me->query_temp("weapon");

        me->add_temp("apply/damage", amount);
        me->add_temp("apply/attack", amount*2);
        me->add_temp("apply/dodge", amount*2);
        if (factor>2.5)
        {
            message_vision(HIR "\n突然间$N"HIR"身形电闪，瞬间逼近$n"HIR"，剑掌交替中向$n"HIR"奋力击出三剑两掌！不愧是岳掌门亲传绝技！\n\n" NOR, me, target);
        }
        else if (factor>2)
        {
            message_vision(RED "\n突然间$N"RED"身形电闪，瞬间逼近$n"RED"，剑掌交替中向$n"RED"奋力击出三剑两掌！不愧是岳掌门亲传绝技！\n\n" NOR, me, target);
        }
        else if (factor>1.5)
        {
            message_vision(MAG "\n突然间$N"MAG"身形电闪，瞬间逼近$n"MAG"，剑掌交替中向$n"MAG"奋力击出三剑两掌！威力却异乎寻常！\n\n" NOR, me, target);
        }
        else if (factor>1)
        {
            message_vision(HIM "\n突然间$N"HIM"身形电闪，瞬间逼近$n"HIM"，剑掌交替中向$n"HIM"奋力击出三剑两掌！威力却异乎寻常！\n\n" NOR, me, target);
        }

        else
        {
            message_vision("\n突然间$N"NOR"身形电闪，瞬间逼近$n"NOR"，剑掌交替中向$n"NOR"奋力击出三剑两掌！\n\n" NOR, me, target);
        }
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

        if (objectp(weapon) ) weapon->unequip();
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

        if ( objectp(weapon) )
        {
          weapon->wield();
          me->set_temp("attack_val", attack_val);
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        }

        if ( objectp(weapon) ) weapon->unequip();
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

        if ( objectp(weapon) )
        {
          weapon->wield();
          me->set_temp("attack_val", attack_val);
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        }

        me->start_busy(3+random(3));
        me->add_temp("apply/damage", -amount);
        me->add_temp("apply/attack", -amount*2);
        me->add_temp("apply/dodge", -amount*2);
        me->add("neili", -amount*3);
        me->add("jing", -amount);
/*        if( me->query_temp("restore") ) me->prepare_skill("cuff", "poyu-quan"); */

        return 1;
}

