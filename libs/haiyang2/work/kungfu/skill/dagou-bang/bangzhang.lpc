// bangzhang棒掌双绝

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count,extra,damage;
 	if( !target ) target = offensive_target(me);


	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("你使用的武器不对。\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("xianglong-zhang", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

       if( !wizardp(me) &&(int)me->query_skill("dagou-bang", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("huntian-qigong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "huntian-qigong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

        msg = HBWHT "$N贯通丐帮武学，使出了丐帮的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);      
        extra = me->query_skill("xianglong-zhang",1);
        msg = YEL "$N心中一急,没头没脑的向前面打了出去,但正是打狗棒法的精要之所在！\n" NOR;
        msg+= HIR"$N怒喝一声，横过"+ weapon->name()+HIG"一搭，借势跃起，人未至，棒先到，凌虚下击，连施三下杀手！\n" NOR;
        message_vision(msg, me);
if (random(3)==0) target->start_busy(3);
        me->add_temp("apply/attack", (int)me->query_skill("dagou-bang",1));
        me->add_temp("apply/damage", (int)me->query_skill("dagou-bang",1)/2);
       msg = WHT  "$N转过"+ weapon->name()+HIG"，刷刷刷连进三棒，棒法快捷无伦，都是打狗棒法中的杀招！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                target->receive_wound("qi",random((int)me->query_skill("dagou-bang",1)));
        msg = HIC  "$N突然飞出"+ weapon->name()+HIG"，迎面劈向$n，这棒连戳三下，竟在霎时之间分点$p胸口三处大穴！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                target->receive_wound("qi",random((int)me->query_skill("dagou-bang",1)));
        msg = RED "$N横棒挥出，变守为攻，发挥出打狗棒法中的攻手，连进了三记杀招！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = RED "第一招 $N横棒挥出，使出了封字决！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED "第二招 $N横棒挥出，使出了转字决！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED "第三招 $N横棒挥出，使出了拌字决！！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


                target->receive_wound("qi",random((int)me->query_skill("dagou-bang",1)));
        me->add_temp("apply/attack", - (int)me->query_skill("dagou-bang",1));
        me->add_temp("apply/damage", - (int)me->query_skill("dagou-bang",1)/2);
                 me->add_temp("apply/strength", extra/3);
                 me->add_temp("apply/attack", extra);
	         me->add_temp("apply/damage", extra);
	me->add("neili", -1000);
weapon->unequip();
		 msg = YEL "$N双掌平平提到胸前，神色沉重的缓缓施出降龙十八掌的最后一招「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+YEL"」一招八式推向$n！" NOR;
       	         message_vision(msg, me, target);                
	 msg =  HIC  "第一式！$N右掌一式「龙现于野」，勇猛无比地劈向$n！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第二式！$N双掌施出一式「鸿龙在陆」，隐隐约约带着掌风拍向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "第三式！$N左掌御胸，右掌一式「潜龙出海」缓缓推向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "第四式！$N使出「龙跃在天」，向$n的连拍数掌！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "第五式！$N双掌一式「双龙戏水」一前一后按向$n的胸前！" NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIM  "第六式！$N身形转动，使出「晴天六龙」向$n连打六下！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "第七式！$N脚下一转，突然欺到$n身前，一式「龙战于野」直拍向$n面门" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "第八式！$N突然飞起，双掌居高临下最后一式「龙啸九天」全力拍向$n！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/strength", -extra/3);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        if( random(me->query("combat_exp")) > target->query("combat_exp")/4
		)
	 {

 msg = HIR"你咬紧牙关，双掌护身，心中默念降龙十八掌的口诀!"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔!!"NOR+" ";
                msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
                target->receive_damage("qi",(int)me->query_skill("xianglong-zhang",1)*5);
                target->receive_wound("qi",(int)me->query_skill("xianglong-zhang",1)*3);
		target->receive_wound("jing", 10 + random(200));
                if (!target->is_busy()) target->start_busy(3);
		message_combatd(msg, me, target);
                COMBAT_D->report_status(target);
	}
        me->start_busy(4);


        return 1;
}

