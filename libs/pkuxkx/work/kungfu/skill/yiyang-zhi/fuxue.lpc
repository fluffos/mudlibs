//fuxue.c
//modified by Zine，合并天龙寺和全真的一阳指

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
	int hmg, tls_force;

    if ( !target ) target = offensive_target(me);

    if ( !objectp(target)) return notify_fail("你要对谁施展「拂穴」？\n");

    if ( target->is_busy() ) return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	if ( (me->query("yiyang_zhi/quanzhen") && !me->query("yiyang_zhi/tianlong"))||
        (me->query("yiyang_zhi/quanzhen") && me->query("yiyang_zhi/tianlong") && me->query("env/yiyang")=="quanzhen") )
	{
        if( me->query_skill("finger", "yiyang-zhi") < 100 )
            return notify_fail("一阳指拂穴需要有效指法 100 级。\n");

        if( me->query_skill("xiantian-gong", 1) < 100 )
        return notify_fail("你的内功修为火候未到，施展只会伤及自身！\n");

        if( me->query_skill_mapped("force") != "xiantian-gong" )
        return notify_fail("使用一阳指拂穴必须激发先天功才能使出这个绝招。！\n");

        if( me->query("neili") < 100 )
            return notify_fail("一阳指拂穴需要内力 100 以上。\n");

        msg = CYN "$N使出一阳指拂穴绝技，右手食指突然点向$n要穴。\n";
        me->add("neili", -100);
        if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 9, me, target ) )
        {
            msg += "结果$p被$P一击点中。\n" NOR;
            F_KUNGFU->hit_busy("dianxue", 6 + random(6), target );
        }
        else
        {
            me->start_busy(3);
            msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
        }
        message_vision(msg, me, target);
        // 最后再叫杀，使得信息显示更合理
        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
        if( !me->is_fight(target) ) me->fight_ob(target);
        return 1;
	}


	//***天龙一阳指***//

	if ( (!me->query("yiyang_zhi/quanzhen") && me->query("yiyang_zhi/tianlong")) ||
         (me->query("yiyang_zhi/quanzhen") && me->query("yiyang_zhi/tianlong") && (me->query("env/yiyang")=="tianlong"||!me->query("env/yiyang"))) )
	{
        if((int)me->query_skill("kurong-shengong", 1)< 100
          && (int)me->query_skill("beiming-shengong", 1)<100)
                return notify_fail("你的天龙内功等级不够，不能驱动一阳指力拂穴。\n");

        if( me->query_skill("finger", "yiyang-zhi") < 100 )
                return notify_fail("一阳指拂穴需要有效指法 100 级。\n");

        if( me->query("neili") < 100 )
                return notify_fail("一阳指拂穴需要内力 100 以上。\n");

        hmg = 1;
        if ((string)target->query_skill_mapped("force") == "hamagong"
          || (string)target->query_skill_mapped("strike") == "hamagong")
                hmg = 2;

        me->add("neili", -100);
        msg = YEL "$N踏前一步，一指隔空点向$n胸前大穴，认穴竟无厘毫之差！\n"NOR;

        tls_force = me->query_skill("force", "kurong-shengong")>me->query_skill("force", "beiming-shengong")?
            me->query_skill("force", "kurong-shengong"):me->query_skill("force", "beiming-shengong");
//命中率B-或者B+
		if( F_KUNGFU->hit_rate( tls_force, (int)target->query_skill("force"), 8-hmg*2, me, target ) )
		{
                if( hmg == 2 ) msg += HIR"$p一见之下，大为失色，发现这似乎正是自己的克星，结果被$P一阳指内力点中，全身气脉通道阻塞，真气立受干挠！\n" NOR;
                else msg += HIR"结果$p被$P一阳指内力点中，全身气脉通道阻塞，真气立受干挠！\n" NOR;
                F_KUNGFU->hit_busy("jiemai", 5 + (int)(me->query_skill("finger", "yiyang-zhi")/40), target );
    }
		else
		{
                me->start_busy(3);
                msg += HIY"$p眼看逼无可逼，便也一指点去，两根指尖相碰，看破了$P的企图，并没有上当。\n" NOR;
        }
        message_vision(msg, me, target);
        //最后再叫杀，使得信息显示更合理
        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
        if( !me->is_fight(target) ) me->fight_ob(target);
		//***天龙一阳指***//
    return 1;
	}
}
