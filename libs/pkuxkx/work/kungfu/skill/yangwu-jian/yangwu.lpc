// yangwu.c 养吾剑法 by jpei

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        object weapon = me->query_temp("weapon");
        int busy, sk1, sk2, pflv, damage, rate=7;
		int lv, ad = 0;

		    if ( !me->query("huashan_newskills/qizong") ||
             me->query("family/family_name")!="华山派" ) 
				{if (!me->query("safari_skill/hs_jq"))
			         return notify_fail("这是华山气宗的秘传绝学，你无法在实战中运用「养吾剑」。\n");
				else
					{
					rate += 2;
					}
				}
			if (( !me->query("betrayer") )&&( !me->query("chushi/done") ))
				{
				if (me->query("safari_skill/hs_jq"))
					{
					rate -= 1;
					}
				}


        if ( !target ) target = offensive_target(me);
        if ( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
             return notify_fail("「养吾剑」诀只能对战斗中的对手使用。\n");
                                
        if ( (int)me->query_skill("zixia-shengong", 1) < 200 )
            return notify_fail("你的紫霞神功等级不够，不能使用「养吾剑」诀。\n");

        if ( (int)me->query_skill("yangwu-jian", 1) < 200 )
            return notify_fail("你的养吾剑法不够娴熟，不会使用「养吾剑」诀。\n");

        if ( !objectp(weapon) || weapon->query("skill_type") != "sword" )
            return notify_fail("你手中无剑，如何使用「养吾剑」？\n");

        if ( (int)me->query("neili") < 1200 )
                return notify_fail("你现在内力太弱，不能使用「养吾剑法」诀。\n");

        if ( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
                
        msg = MAG "$N招式一变展开华山「养吾剑」，连挥数剑，立时剑气漫空，如潮水般向着$n涌来。\n";

		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "华山派")	pflv = 0;

		me->add("neili", -500);
        // 需要控制busy自己的时间，busy不能太短，控制各个门派特色。
        me->start_busy(2);
        sk1=me->query_skill("force", "zixia-shengong");
        sk2=target->query_skill("force",1);
		lv = (int)me->query_skill("sword", "yangwu-jian");
        if ( F_KUNGFU->hit_rate( sk1, sk2, rate, me, target ) ) {
                msg += HIY "$n呼吸一滞，顿时被剑气所制，浑身上下动弹不得！\n" NOR;
                F_KUNGFU->hit_busy( "confuse", 4+lv/40, target );
                me->start_perform(6,"「养吾剑」");
				if (pflv>=3 && me->query("huashan_newskills/qizong")) ad = 500 + lv + random(lv);
        } else {
                msg += "千钧一发之际，$n怒喝一声，运起内功将养吾剑气尽数挡了回来。\n" NOR;
                damage=sk1/2+lv/2;
                damage=damage/2+random(damage);
				if (rate>7)
				{
					damage = damage*3/4;
				}
                F_KUNGFU->hit_wound("qi", damage, 0, me, target);
                damage=target->query_temp("combat/qi_damage");
                if ( damage>0 )
                {
                  me->add("qi", damage/2);
                  if ( me->query("qi") > me->query("eff_qi") )
                    me->set("qi", me->query("eff_qi"));
                  msg += GRN"$N见势急忙运转紫霞真气，将四周激荡的养吾剑气汇入全身。\n"NOR;
                }
                COMBAT_D->report_status(target);
                me->start_busy(2+random(3));
                target->add("neili",-200);
				if (pflv>=3 && me->query("huashan_newskills/qizong")) ad = 500 + lv/2 + random(lv);
        }
        if (ad>0)
		{
			msg += MAG "\n只见$N逆转剑锋，长吸了一口气，脸上隐隐透出一股紫气。\n" NOR;
			me->add("neili", ad);
		}
        message_vision(msg, me, target);
        return 1;
}
