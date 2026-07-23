#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	int neili, qi;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「乾坤一击」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("dafumo-quan", 1) < 300 )
                return notify_fail("你的大伏魔拳不够娴熟，无法使用「乾坤一击」。\n");
        if( (int)me->query_skill("jiuyin-zhengong", 1) < 200 )
                return notify_fail("你的九阴真功不够娴熟，无法使用「乾坤一击」。\n");

        if ( (int)me->query("max_neili") < 4000)
                return notify_fail("你的真气不够，无法使用「乾坤一击」。\n");
        if ( (int)me->query("neili") < 6000)
                return notify_fail("你的内力不够，无法使用「乾坤一击」。\n");
        if (target->query("jiuyin/qiankun"))
                return notify_fail("他已经被击中了，放心攻击吧。\n");

        msg = HIY"$N突然眼睛一闪，猛吸一口气，使出全身的力气出拳向$n击去！\n";
        me->start_perform(6,"「乾坤一击」");
	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
                msg += HIR"$n躲闪不及，正中小腹！$n只觉得一股强极的九阴真气猛向自己丹田冲击！\n";
                msg += HIR"$n只觉得丹田有如刀割，结果檀中、玉堂穴气息再也无法顺畅通行！\n"NOR;
	        neili = target->query("max_neili");
	        qi = target->query("max_qi");
                target->start_busy(random(4)+1);
                target->set("jiuyin/qiankun",1);
// set for condition
                target->set("qiankun/qi",qi);
                target->set("qiankun/neili",neili);
                target->set("max_qi",qi/2);
		if (target->query("eff_qi")>qi/2)
			target->set("eff_qi",qi/2);
                if (target->query("qi")>target->query("eff_qi")) 
                       target->set("qi",target->query("eff_qi"));
                target->set("max_neili",neili/2);
                if (target->query("neili")>target->query("max_neili"))
                       target->set("neili",target->query("max_neili"));
                target->apply_condition("qiankun_wound",(int)me->query_skill("force")/50);
		me->add("neili", -1000);
        } 
        else {
                msg += HIG"$n见来势猛烈，连忙避在一旁。\n" NOR;
		me->add("neili", -300);
        }
        message_vision(msg, me, target);
        me->start_busy(2+random(3));
}else
{
        if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	) {
                msg += HIR"$n躲闪不及，正中小腹！$n只觉得一股强极的九阴真气猛向自己丹田冲击！\n";
                msg += HIR"$n只觉得丹田有如刀割，结果檀中、玉堂穴气息再也无法顺畅通行！\n"NOR;
	        neili = target->query("max_neili");
	        qi = target->query("max_qi");
                target->start_busy(random(4)+1);
                target->set("jiuyin/qiankun",1);
// set for condition
                target->set("qiankun/qi",qi);
                target->set("qiankun/neili",neili);
                target->set("max_qi",qi/2);
		if (target->query("eff_qi")>qi/2)
			target->set("eff_qi",qi/2);
                if (target->query("qi")>target->query("eff_qi")) 
                       target->set("qi",target->query("eff_qi"));
                target->set("max_neili",neili/2);
                if (target->query("neili")>target->query("max_neili"))
                       target->set("neili",target->query("max_neili"));
                target->apply_condition("qiankun_wound",(int)me->query_skill("force")/50);
		me->add("neili", -1000);
        } 
        else {
                msg += HIG"$n见来势猛烈，连忙避在一旁。\n" NOR;
		me->add("neili", -400);
        }
        message_vision(msg, me, target);
        me->start_busy(2+random(3));
}
        return 1;
}
