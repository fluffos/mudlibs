#include <ansi.h>

#define RUO "「" HIG "空明若玄" NOR "」"
#define PO "「" HIC "破穹" HIW "云" HIC "蛟" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
	int level;
	string msg;
        object weapon;
        int damage;
        int skill;
        string wname;
        int ap, dp;
        
        string *limb, type, result, str;
        level=(int)me->query_skill("kongming-quan",1);

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(RUO "只能对战斗中的对手使用。\n");


        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if ((level = me->query_skill("kongming-quan", 1)) < 100)
                return notify_fail("你的空明拳不够娴熟，难以施展" RUO "。\n");


        if ((int)me->query("neili", 1) < 100)
                return notify_fail("你现在的真气太弱，难以施展" RUO "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = WHT "$N" WHT "使出空明拳「" HIG "空明若玄" NOR + WHT "」，双手"
              "吞吐不定，运转如意，试图扰乱$n" WHT "的攻势。\n" NOR;

        me->add("neili", -50);
        if (random(level) > (int)target->query_skill("parry", 1) / 3)
        {
		msg += HIR "结果$n" HIR "被$N" HIR "的拳招所牵制，招架"
                       "不迭，全然无法反击！\n" NOR;
		target->start_busy(level / 16 + 3);
	} else
        {
		msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，镇定逾"
                       "恒，全神应对自如。\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);
if (skill>300 && me && target)
{
	
        msg = HIC "\n$N大喝一声，合身向$n扑上，双掌同时击出，是一招「三花聚顶」。\n"NOR;
   if (random(me->query_skill("force")) > target->query_skill("force")/2 || random(3)==0)
        {
                me->start_busy(1);

                damage = (int)me->query_skill("kongming-quan", 1) + (int)me->query_skill("force",1);
                //(昊天掌级别+基本内功)

                damage = damage/2 + random(damage/2)+300 ;

                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                target->start_busy(3);
                me->add("neili", -100);

                msg += HIR"结果$n被$N的气势所摄，一惊之下，竟然忘了抵挡！\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        }
        else
        {
                me->start_busy(2);

                msg += CYN"可是$p识破了$P这一招，斜斜一跃避开。\n"NOR;
		message_combatd(msg, me, target);
        }	
}	
if (skill>500 && me && target)
{
   damage = (int)me->query_skill("kongming-quan", 1)+500;
        damage += random(damage);

        ap = me->query_skill("hand");
        dp = target->query_skill("parry");
        msg = HIC "\n$N" HIC "双目圆睁，单手陡然一振，袖底顿时窜出一道" NOR + MAG
              "紫光" HIC "，直射$n" HIC "前胸。\n" NOR;
        if (ap  + random(ap) > dp || random(3)==0)
        {
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                msg +=HIR "但见$P" HIR "这道气劲来势迅猛之极"
                                           "，$n" HIR "如何避得，顿时被紫劲震开了"
                                           "数尺！\n" NOR;
        } else
        {
                msg += CYN "$p" CYN "见势不妙，急忙向后纵开数尺，避开了$P"
                       CYN "这招。\n" NOR;
        }

        ap = me->query_skill("hand");
        dp = target->query_skill("dodge");
        msg += "\n" HIC "紧接着$N" HIC "左掌蓦的一抬，凭空虚划了道" HIY "弧芒" HIC
               "，至上而下反推$n" HIC "后颈。\n" NOR;
        if (ap  + random(ap) > dp || random(3)==0)
        {
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                msg +=HIR "$p" HIR "只觉后颈一麻，已被$N" HIR
                                           "这招击个正中，顿时全身瘫软，呕出一口鲜"
                                           "血！\n" NOR;
        } else
        {
                msg += CYN "可是$p" CYN "丝毫不为$P"
                       CYN "所动，奋力格挡，稳稳将这一招架开。\n" NOR;
        }

        ap = me->query_skill("hand");
        dp = target->query_skill("force");
        msg += "\n" HIC "便在此时，却见$N" HIC "双掌猛然回圈，平推而出，顿时层层"
               HIW "气浪" HIC "直袭$n" HIC "。\n" NOR;
        if (ap  + random(ap) > dp || random(3)==0)
        {
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                msg +=HIR "$p" HIR "在$N" HIR "的猛攻之下，已"
                                           "再无余力招架，竟被这一掌震得飞起，摔了"
                                           "出去！\n" NOR;
        } else
        {
                msg += CYN "然而$p" CYN "沉身聚气，奋力一格，便将$P"
                       CYN "这掌驱于无形。\n" NOR;
        }
        me->start_busy(2);
        message_combatd(msg, me, target);
 

}

if (skill>600 && me && target)
{
    message_vision(HIR "\n$N怒喝一声，拚尽全力，突然闪电般攻出拳、掌、腿连环三招！\n\n" NOR, me, target);

        me->add_temp("apply/attack",100);
        me->set_temp("lianhuan",1);

        message_vision(HIW"第一招！\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIM"第二招！\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/attack",-100);

        message_vision( HIC"\n紧跟着$N突然腾空飞起，使出一招鸳鸯连环腿，两腿风驰电掣连环踢向$n\n",me,target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 || random(2)==0)
        {
                if( ( target->query_skill("dodge")+target->query_skill("parry") ) < random((me->query_skill("cuff") + me->query_skill("force"))*2/3) )
                {
                        message_vision(HIR"只听$N一声惨叫，这连环二腿正中心口。但见$n一个身躯突然平平飞出，腾的一响，尘土飞扬，跌在丈许之外，直挺挺的躺在地下，再也不动。\n\n"NOR, target,target );
                        target->receive_wound("qi", (int)me->query_skill("force")*3, me);
                        target->receive_damage("qi", (int)me->query_skill("force")*3,  me);
                }
                else
                {
                        damage = random(((int)me->query_skill("cuff"))+me->query("jiali"))*( 1 + random(me->query_skill("kongming-quan")*2) ) ;
                        if(damage > 4500) damage = 4500;
                        if(damage < 300) damage = 300;

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", (int)me->query_skill("strike"), me);

                        limb = target->query("limbs");
                        type = "瘀伤";
                        message_vision(HIY"只听$N一声惨叫，这连环二腿正中$P"+limb[random(sizeof(limb))]+"，结果把$P踢摔了个跟头。\n"NOR,target);

                        str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                        message_vision("($N"+str+")\n", target);
                }
                me->start_busy(1+random(2));
        }
        else if( ( random( target->query_skill("dodge") ) >  me->query_skill("unarmed")*2/3) && random(5) == 1 )
        {
                message_vision(HIR"$N猛觉得劲风罩来，心知不妙，慌忙闪开，结果$n踢了个空，白白自己重重跌了一跤。\n\n"NOR, target,me );
                //me->receive_damage("qi", 30+random(50),  me);
                me->start_busy(1+random(2));
                str = COMBAT_D->status_msg((int)me->query("qi") * 100 /(int)me->query("max_qi"));
                message_vision("($N"+str+")\n", me);
        }
        else
        {
                message_vision( HIG"$N眼见这一腿来势凶猛，当下双足一点，跃高四尺，躲开了$n这一招，不过也出了一身冷汗。\n\n" NOR,  target,me);
                target->start_busy(1+random(2));
                me->start_busy(1);
        }

        me->delete_temp("lianhuan");

        me->start_busy( 2);

}	
	return 1;
}
