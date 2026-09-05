//jianzhang.c 「太乙神剑掌」
//iszt@pkuxkx, 2007-01-16
// 2009.8.17 finished by zgbl
//「太乙神剑掌」strike型pfm，化学pfm三连，低伤害高命中，打上限较好

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

    if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手施展此招。\n");

        weapon1 = me->query_temp("secondary_weapon");
		weapon2 = me->query_temp("weapon");

	

	if (me->query("betrayer") > 0)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

    if (me->query("family") || me->query("chushi/last_family"))
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");

	if (me->query_skill("hunyuan-yiqi",1) > 0)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
//有门派或者有过门派都无法使用，纯百姓技能

    if( !objectp(weapon1) || weapon1->query("skill_type") != "sword" )
                return notify_fail("你左手无剑，无法施展「太乙神剑掌」。\n");

	if( objectp(weapon2) )
			    return notify_fail("你腾不出右手，无法施展「太乙神剑掌」。\n");

	if( time() < 10+(int)me->query_temp("taiyi-jianzhang") )        
                return notify_fail("你刚用过一次「太乙神剑掌」，对方已经有了防备！\n");    

    if( me->query_skill_mapped("sword") != "taiyi-jian" )
                return notify_fail("你需要使用太乙神剑作为剑法。(enable strike taiyi-jian)\n");

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
		lvlb = (int)me->query_skill("sword", 1);
		lvlc = (int)me->query_skill("strike", 1);
		lvl = lvla + lvlb + lvlc;

        if( me->query("neili") < 500 )
                return notify_fail("你的内力不够。\n");

        weapon = me->query_temp("weapon");

        message_vision(HIC "\n只见$N"HIC"运起太乙神功，脚踏八卦，猛然间左掌右剑一同翻飞，「太乙神剑掌」攻向$n"HIC"！\n" NOR, me, target);
//b+
        if ( F_KUNGFU->hit_rate( lvla, target->query_skill("dodge",1), 4, me, target) )
			//命中计算，random（force*3/2）大于对方dodge
		   {
			 msg = strikemsg[random(sizeof(strikemsg))];
			 message_vision(NOR"\n$N"+msg+"\n" NOR,me,target);
			 damage = lvla;
			 damage = damage*3/4 + random(damage*3/4) + me->query_temp("apply/damage") + me->query("jiali");
       F_KUNGFU->hit_wound("qi", damage, damage*3/4+random(damage/4), me, target);
			       COMBAT_D->report_status(target);
			 me->add("neili",-me->query("jiali"));
            }
		       else
	       {
			 msg = strikemsg[random(sizeof(strikemsg))];
			 message_vision(NOR"\n$N"+msg+"\n" NOR,me,target);
             message_vision(HIY"$n大惊失色，马上收招后撤，惊险万分的避过此掌\n"NOR,me,target);
		   }
		   //伤害为force等级*3/4+random(force*3/4)+加力，上限受伤比例为3/4-1

        if ( F_KUNGFU->hit_rate( lvlb, target->query_skill("dodge",1), 4, me, target) )
			//命中计算，random（sword*3/2）大于对方dodge
		   {
			 msg = swordmsg[random(sizeof(swordmsg))];
			 message_vision(NOR"\n紧接着$N"+msg+"\n" NOR,me,target);
			 damage = lvlb;
			 damage = damage*3/4 + random(damage*3/4) + me->query_temp("apply/damage") + me->query("jiali");
       F_KUNGFU->hit_wound("qi", damage, damage/2+random(damage/6), me, target);
			       COMBAT_D->report_status(target);
			 me->add("neili",-me->query("jiali"));
            }
		       else
	       {
		     msg = swordmsg[random(sizeof(swordmsg))];
			 message_vision(NOR"\n紧接着$N"+msg+"\n" NOR,me,target);
             message_vision(HIY"$n大惊失色，双足一点一个后空翻，惊险万分的避过此剑\n"NOR,me,target);
		   }
		   //伤害为sword等级*3/4+random(sword*3/4)+加力，上限受伤比例为1/2-2/3

        if ( F_KUNGFU->hit_rate( lvlc, target->query_skill("dodge",1), 4, me, target) ) 
			//命中计算，random（strike*3/2）大于对方dodge
		   {
			 msg = strikemsg[random(sizeof(strikemsg))];
			 message_vision(NOR"\n$N右手马上跟上，"+msg+"\n" NOR,me,target);
			 damage = lvlc;
			 damage = damage*3/4 + random(damage*3/4) + me->query_temp("apply/damage") + me->query("jiali");
       F_KUNGFU->hit_wound("qi", damage, damage*2/3+random(damage/3), me, target);
			       COMBAT_D->report_status(target);
			 me->add("neili",-me->query("jiali"));
            }
		       else
	       {
			 msg = strikemsg[random(sizeof(strikemsg))];
			 message_vision(NOR"\n$N右手马上跟上，"+msg+"\n" NOR,me,target);
             message_vision(HIY"$n大惊失色，就地一个懒驴打滚，惊险万分的避过此掌\n"NOR,me,target);
		   }
		   //伤害为strike等级*3/4+random(strike*3/4)+加力，上限受伤比例为2/3-1

		me->start_busy(1+random(2));
        me->add("neili",-100);

        return 1;
}
