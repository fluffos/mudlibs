#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	 int extra;
	 object weapon;
        extra = me->query_skill("xianglong-zhang",1);
	 if( !target ) target = offensive_target(me);
        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+"」只能对战斗中的对手使用。\n");

               if( objectp(me->query_temp("weapon")) )
              return notify_fail("你必须空手使用「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+"」！\n");
     
        if( (int)me->query_skill("xianglong-zhang", 1) < 200 )
                return notify_fail("你的降龙十八掌不够娴熟，无法施展出「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+"」。\n");
if ( me->query_skill_mapped("force") != "huntian-qigong" )
return notify_fail("你没用本门内功！\n");
if ( me->query_skill_mapped("unarmed") != "xianglong-zhang" )
return notify_fail("你没有使用这门掌法！\n");

        if (me->query_skill("huntian-qigong", 1)<120)
                return notify_fail("你的本门内功火候未到，！\n");
       
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("你的内力不够，无法施展出「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+"」。\n");
        if ( (int)me->query("neili") < 1500)
                return notify_fail("你的真气不够，无法施展出「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+"」。\n");
                 me->add_temp("apply/strength", extra);
                 me->add_temp("apply/attack", extra*2);
	         me->add_temp("apply/damage", extra*2);
	me->add("neili", -600);
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

        me->add_temp("apply/strength", -extra);
        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -extra*2);
        if( random(me->query("combat_exp")) > target->query("combat_exp")/4
		&& me->query("xlz/hang"))
	 {

 msg = HIR"你咬紧牙关，双掌护身，心中默念降龙十八掌的口诀!"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔!!"NOR+" ";
                msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
                target->receive_damage("qi",(int)me->query_skill("xianglong-zhang")*2);
                target->receive_wound("qi",(int)me->query_skill("xianglong-zhang")*2);
		target->receive_wound("jing", 10 + random(200));
                if (!target->is_busy()) target->start_busy(2);
//             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		message_combatd(msg, me, target);
                COMBAT_D->report_status(target);
	}
        me->start_busy(5);
        return 1;
}
