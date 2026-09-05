//jianzhang.c 「太乙神剑掌」
//iszt@pkuxkx, 2007-01-16
// 2009.8.17 finished by zgbl
//「太乙神剑掌」sword型pfm，化学pfm三连，高伤害低命中，打上限较差

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

string *swordmsg=({
	"往下一矮身，一招"CYN"「太乙无痕」"NOR"，手中之剑如一缕浮云向对方横削而过"NOR,
	"往上一纵身，一招"HIC"「太乙有痕」"NOR"，手中之剑如一股流水向对方竖劈而下"NOR
});

string *strikemsg=({
	"贴地窜出，身子离地仅一尺，头前脚后，一招"CYN"「太乙无虚」"NOR"，双掌向对方击去"NOR,
	"腾空而起，身子在空中倒转，头下脚上，一招"HIC"「太乙有虚」"NOR"，双掌向对方击去"NOR
});

int perform(object me, object target)
{
        string weapon;
        object weapon1, weapon2;
		string msg;
        int lvl, lvla, lvlb, lvlc, damage;

        if( !target ) target = offensive_target(me);

	if ((int)me->query("family"))
	  		    return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

	if (me->query("betrayer") > 0)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

    if ((int)me->query("reborn/chushi")>=1)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

	if (me->query_skill("hunyuan-yiqi",1) > 0)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
//有门派或者有过门派都无法使用，纯百姓技能

    if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手施展此招。\n");

        weapon1 = me->query_temp("weapon");
		weapon2 = me->query_temp("secondary_weapon");

    if( !objectp(weapon1) || weapon1->query("skill_type") != "sword" )
                return notify_fail("你右手无剑，无法施展「太乙神剑掌」。\n");

	if( objectp(weapon2) )
			    return notify_fail("你腾不出左手，无法施展「太乙神剑掌」。\n");

	if( time() < 10+(int)me->query_temp("taiyi-jianzhang") )        
                return notify_fail("你刚用过一次「太乙神剑掌」，对方已经有了防备！\n");    

    if( me->query_skill_mapped("strike") != "taiyi-zhang" )
                return notify_fail("你需要使用太乙神掌作为掌法。(enable strike taiyi-zhang)\n");

	if( me->query_skill_prepared("strike") != "taiyi-zhang" )
                return notify_fail("你需要使用太乙神掌出招。(prepare taiyi-zhang)\n");

	if( me->query_skill("taiyi-shengong", 1) < 100 )
                return notify_fail("你的太乙神功等级太低，无法施展「太乙神剑掌」。\n");

	if( me->query_skill("taiyi-zhang", 1) < 100 )
                return notify_fail("你的太乙神掌等级太低，无法施展「太乙神剑掌」。\n");

	if( me->query_skill("taiyi-jian", 1) < 100 )
                return notify_fail("你的太乙神剑等级太低，无法施展「太乙神剑掌」。\n");

        if( ( me->query_skill("strike")) < 100 )
                return notify_fail("你的掌法修为还不够。\n");

	    if( ( me->query_skill("sword")) < 100 )
                return notify_fail("你的剑法修为还不够。\n");

        if( ( me->query_skill("force")) < 100 )
                return notify_fail("你的内功修为还不够。\n");

        if( me->query("neili") < 500 )
                return notify_fail("你的内力不够。\n");

		me->set_temp("taiyi-jianzhang",time());
		//sword与strike型剑掌共用一个冷却

        lvla = (int)me->query_skill("force", 1);
		lvlb = (int)me->query_skill("strike", 1);
		lvlc = (int)me->query_skill("sword", 1);
		lvl = lvla + lvlb + lvlc;

        if( me->query("neili") < 500 )
                return notify_fail("你的内力不够。\n");

        weapon = me->query_temp("weapon");

        message_vision(HIC "\n只见$N"HIC"运起太乙神功，脚踏八卦，猛然间左掌右剑一同翻飞，「太乙神剑掌」攻向$n"HIC"！\n" NOR, me, target);
//B-
        if ( F_KUNGFU->hit_rate( lvla, target->query_skill("dodge",1), 6, me, target) ) 
			//命中计算，random（force）大于对方dodge
		   {
			 msg = swordmsg[random(sizeof(swordmsg))];
			 message_vision(NOR"\n$N"+msg+"\n" NOR,me,target);
			 damage = lvla;
			 damage = damage + random(damage/2) + me->query_temp("apply/damage") + me->query("jiali");
       F_KUNGFU->hit_wound("qi", damage, damage/3+random(damage/3), me, target);
			       COMBAT_D->report_status(target);
			 me->add("neili",-me->query("jiali"));
            }
		       else
	       {
			 msg = swordmsg[random(sizeof(swordmsg))];
			 message_vision(NOR"\n$N"+msg+"\n" NOR,me,target);
             message_vision(HIY"$n"HIY"大惊失色，马上收招后撤，惊险万分的避过此剑\n"NOR,me,target);
		   }
		   //伤害为force等级+random(force/2)+加力，上限受伤比例为1/3-2/3

        if ( F_KUNGFU->hit_rate( lvlb, target->query_skill("dodge",1), 6, me, target) ) 
			//命中计算，random（strike）大于对方dodge
		   {
			 msg = strikemsg[random(sizeof(strikemsg))];
			 message_vision(NOR"\n紧接着$N"+msg+"\n" NOR,me,target);
			 damage = lvlb;
			 damage = damage + random(damage/2) + me->query_temp("apply/damage") + me->query("jiali");
			 F_KUNGFU->hit_wound("qi", damage, damage/4+random(damage/4), me, target);
			       COMBAT_D->report_status(target);
			 me->add("neili",-me->query("jiali"));
            }
		       else
	       {
		     msg = strikemsg[random(sizeof(strikemsg))];
			 message_vision(NOR"\n紧接着$N"+msg+"\n" NOR,me,target);
             message_vision(HIY"$n"HIY"大惊失色，双足一点一个后空翻，惊险万分的避过此掌\n"NOR,me,target);
		   }
		   //伤害为strike等级+random(strike/2)+加力，上限受伤比例为1/4-1/2

        if ( F_KUNGFU->hit_rate( lvlc, target->query_skill("dodge",1), 6, me, target) )
			//命中计算，random（sword）大于对方dodge
		   {
			 msg = swordmsg[random(sizeof(swordmsg))];
			 message_vision(NOR"\n$N右手马上跟上，"+msg+"\n" NOR,me,target);
			 damage = lvlc;
			 damage = damage + random(damage/2) + me->query_temp("apply/damage") + me->query("jiali");
       F_KUNGFU->hit_wound("qi", damage, damage/6+random(damage/6), me, target);
			       COMBAT_D->report_status(target);
			 me->add("neili",-me->query("jiali"));
            }
		       else
	       {
			 msg = swordmsg[random(sizeof(swordmsg))];
			 message_vision(NOR"\n$N右手马上跟上，"+msg+"\n" NOR,me,target);
             message_vision(HIY"$n"HIY"大惊失色，就地一个懒驴打滚，惊险万分的避过此剑\n"NOR,me,target);
		   }
		   //伤害为sword等级+random(sword/2)+加力，上限受伤比例为1/6-1/3

		me->start_busy(1+random(2));
        me->add("neili",-100);
		//内力消耗100，加力时击中消耗加力数值内力

        return 1;
}
