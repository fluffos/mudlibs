#include <ansi.h>
#include <combat.h>
//加强一下by yhzzyahoo
#define SAN "「" HIR "神倒鬼跌三连环" NOR "」"
#define Menpai "雪山派"
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        string wname;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SAN "只能对战斗中的对手使用。\n");
 
        if (me->query_temp("weapon") && me->query_temp("secondary_weapon"))
                return notify_fail("只有空手才能施展" SAN "。\n");

        if (me->query_skill("force") < 250)
                return notify_fail("你的内功修为不够，难以施展" SAN "。\n");

        if ((int)me->query_skill("lingxiao-quan", 1) < 180)
                return notify_fail("你的凌霄拳法不够娴熟，难以施展" SAN "。\n");

        if ((int)me->query_skill("xueshan-neigong", 1) < 180)
                return notify_fail("你的雪山内功修为不够，难以施展" SAN "。\n");

    	if( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        	&& !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        	&& me->query_skill_mapped("force") != "xueshan-neigong" )
            	return notify_fail("你真气运转方式不对，无法施展" SAN "。\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("你现在真气不够，难以施展" SAN "。\n");
 
        if ((int)me->query("max_neili") < 1200)
                return notify_fail("你内力修为不够，难以施展" SAN "。\n");

        if (me->query_skill_mapped("cuff") != "lingxiao-quan")
                return notify_fail("你没有激发凌霄拳法，难以施展" SAN "。\n");

        if (me->query_skill_prepared("cuff") != "lingxiao-quan")
                return notify_fail("你现在没有准备使用凌霄拳法，难以施展" SAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        damage = (int)me->query_skill("cuff");
        damage += random(damage);

        ap = me->query_skill("cuff");
        dp = target->query_skill("parry");
        msg = HIR "$N微微一笑，施出「神倒鬼跌三连环」，右手探出，直揪$n后颈。\n" NOR;
//命中率C
        if ( F_KUNGFU->hit_rate( ap, 2*dp-ap, 8, me, target) ){
                msg += HIB "$N出手既快，方位又奇，$n如何避得，当即被$N揪住，重重的摔在地上！\n" NOR; 
                F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        } else {
                msg += CYN "$p见势不妙，急忙凝力稳住，右臂挥出，格开$P手臂。\n" NOR;
                message_vision(msg, me, target);
        }

        ap = me->query_skill("cuff");
        dp = target->query_skill("dodge");
        msg = HIR "\n紧接着$N" HIR "“噫”的一声，左手猛然探出，如闪电般抓向$n的前胸。\n" NOR;
//命中率C
        if ( F_KUNGFU->hit_rate( ap, 2*dp-ap, 8, me, target) ){
                msg += HIB "$n只觉胸口一麻，已被$N抓住胸口，用力顺势一甩，顿时平飞了出去！\n" NOR; 
                F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }else{
                msg += CYN "可是$p丝毫不为$P所动，奋力格挡，稳稳将这一招架开。\n" NOR; 
                message_vision(msg, me, target);        }

        ap = me->query_skill("cuff");
        dp = target->query_skill("force");
        msg = HIR "\n又见$N身子一矮，将力道聚于腿部，右脚猛扫$n下盘，左脚随着绊去。\n" NOR;
//命中率C
        if ( F_KUNGFU->hit_rate( ap, 2*dp-ap, 8, me, target) ){
                msg += HIB "结果$n稍不留神，顿时给$N绊倒在地，呕出一大口鲜血！\n" NOR; 
                F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }else{
                msg += CYN "然而$p沉身聚气，稳住下盘，身子一幌，没给$P绊倒。\n" NOR; 
                message_vision(msg, me, target);        }
        me->start_busy(2 + random(3));
        me->add("neili", -200);
        return 1;
}

