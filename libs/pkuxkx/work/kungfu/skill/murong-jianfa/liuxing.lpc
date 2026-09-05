//Edit by cloth 2000-09-19
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

void extra_attack(object me, object target, int pflv);

int perform(object me, object target)
{
        string msg;
        int extra, pflv, addt, dmg = 0;
        object weapon;
        mapping attack_val = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "murong-jianfa" ]),//高级技能名称
            ]);
        extra = me->query_skill("murong-jianfa",1);
        if ( extra < 180) return notify_fail("你的慕容剑法还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("「流星快剑」只能对战斗中的对手使用。\n");
        if ((int)me->query("neili")<850)
                return notify_fail("你的内力不够。\n");
/*  whuan，canshang的影响不大吧
        if( me->query_temp("canshang") )
                return notify_fail("你已经在使用「参商指」了！\n");
*/

//      if(me->query_skill_mapped("force") != "shenyuan-gong")
//              return notify_fail("你的内功不是神元功，无法使用「流星快剑」！\n");
        if( (int)me->query_skill("shenyuan-gong", 1) < 120 )
                return notify_fail("你的内功还未练成，不能使用「流星快剑」！\n");

        if (!objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if((int)me->query_temp("lianhuan"))
                return notify_fail("你正在使用「七剑连环指」！\n");

		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "姑苏慕容") 
			pflv=0;
		if (pflv>5) pflv=5;

		me->start_perform(5,"「流星快剑」"); 
        me->add("neili",-100);
        me->start_busy(1);
        message_vision(HIG"$N"HIG"使出慕容复家传剑法，招招连绵不绝，犹似行云流水一般，瞬息之间，全身便如罩在一道光幕之中！\n" NOR,me,target);
//A-
        if ( F_KUNGFU->hit_rate( (int)me->query_skill("dodge"), (int)target->query_skill("dodge"), 3, me, target)
         || target->is_busy() )
        {
                message_vision(HIG"突然间，从光幕中爆出六道"HIW"剑芒"HIG"，快似流星般地飞向$n"HIG"！\n" NOR,me,target);
                me->add_temp("apply/strength", extra/12);
                me->add_temp("apply/dexerity", extra/12);
                me->add_temp("apply/attack", extra/8);
				me->set_temp("attack_val", attack_val);
                if (COMBAT_D->do_attack(me,target, weapon, TYPE_SPECIAL)>0) dmg ++;
				me->set_temp("attack_val", attack_val);
                if (COMBAT_D->do_attack(me,target, weapon, TYPE_SPECIAL)>0) dmg ++;
				me->set_temp("attack_val", attack_val);
                if (COMBAT_D->do_attack(me,target, weapon, TYPE_SPECIAL)>0) dmg ++;
				me->set_temp("attack_val", attack_val);
                if (COMBAT_D->do_attack(me,target, weapon, TYPE_SPECIAL)>0) dmg ++;
				me->set_temp("attack_val", attack_val);
                if (COMBAT_D->do_attack(me,target, weapon, TYPE_SPECIAL)>0) dmg ++;
				me->set_temp("attack_val", attack_val);
                if (COMBAT_D->do_attack(me,target, weapon, TYPE_SPECIAL)>0) dmg ++;
				if (pflv>=3)  // pflv 3 增加一招
				{
					message_vision(HIW"\n剑芒一敛，猛然间犹如流星炸开，爆出一丛灿烂的光芒！\n" NOR, me);
					addt = extra/15;
					me->add_temp("apply/damage", addt);
					me->add_temp("apply/attack", addt);
					me->set_temp("attack_val", attack_val);
					if (COMBAT_D->do_attack(me,target, weapon, TYPE_SPECIAL)>0) dmg ++;
					me->add_temp("apply/damage", -addt);
					me->add_temp("apply/attack", -addt);
				}
				if (pflv>=5)  // pflv 5 再增加一招
				{
					message_vision(HIW"\n一道剑光如毒蛇吐信，从剑幕中疾刺而出！\n" NOR, me);
					addt = extra/10;
					me->add_temp("apply/damage", addt);
					me->add_temp("apply/attack", addt);
					me->set_temp("attack_val", attack_val);
					if (COMBAT_D->do_attack(me,target, weapon, TYPE_SPECIAL)>0) dmg ++;
					me->add_temp("apply/damage", -addt);
					me->add_temp("apply/attack", -addt);
				}
                me->add_temp("apply/strength", -extra/12);
                me->add_temp("apply/dexerity", -extra/12);
                me->add_temp("apply/attack", -extra/8);
                me->add("neili",-200);
				if (pflv>=3 && dmg >=3 // 连招击中3次以上，有概率额外增加一个化学攻击
					&& (int)me->query_temp("liuxing_extra_effect_cd")<time()
					&& me->query_skill("douzhuan-xingyi", 1)>=500
					&& me->query_skill_mapped("parry") == "douzhuan-xingyi") 
					extra_attack(me, target, pflv);
        } else {
                message_vision(HIR"\n$n"HIR"看破了$N"HIR"的剑路，信手使出一招，$N"HIR"身形一滞，前后剑招无法连贯，光幕立即瓦解！\n" NOR,me,target);
        }
        return 1;
}

void extra_attack(object me, object target, int pflv)
{
	int dmg;
	if ( me->query_skill_mapped("force")=="shenyuan-gong"
		&& F_KUNGFU->hit_rate( (int)me->query("combat_exp"), (int)target->query("combat_exp"), 12-pflv, me, target))
	{
		dmg = me->query_skill("douzhuan-xingyi",1) + me->query_skill("shenyuan-gong",1);
		dmg += target->query_skill("parry") + target->query("jiali");
		dmg += dmg * (pflv-3) / 5;
		dmg = dmg/2 + random(dmg/5);
		me->set_temp("liuxing_extra_effect_cd", time()+5); // 5秒之内只能刷出一次额外效果
		message_vision(HIW"\n$N"HIW"陡然间领悟贯通了家传各项绝学的奥秘，默运神元功，在剑法中使出了斗转星移的暗劲。\n"
			+HIM"$n"HIM"顿时身不由己，把所有气力全都击回了自身，哇的一声喷出一口血来！\n" NOR,me,target);
		F_KUNGFU->hit_wound("qi", dmg, dmg / 3, me, target);
		COMBAT_D->report_status(target);
	}
}

