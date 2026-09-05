// fuxue.c updated by jpei
// 一阳指点穴，为南帝特色，存内功修为为主，指力为行。
// 添加对蛤蟆功特殊克制于点穴。

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg; 
        int hmg;
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if((int)me->query_skill("kurong-shengong", 1)< 100 
          && (int)me->query_skill("beiming-shengong", 1)<100)
                return notify_fail("你的天龙内功等级不够，不能驱动一阳指力拂穴。\n");

        if( me->query_skill("finger") < 100 )
                return notify_fail("一阳指拂穴需要有效指法 100 级。\n");

        if( me->query("neili") < 100 )
                return notify_fail("一阳指拂穴需要内力 100 以上。\n");
        
        hmg = 1;
        if ((string)target->query_skill_mapped("force") == "hamagong"
          || (string)target->query_skill_mapped("strike") == "hamagong")
                hmg = 2;

        me->add("neili", -100);
        msg = YEL "$N踏前一步，一指隔空点向$n胸前大穴，认穴竟无厘毫之差！\n"NOR;

		if( (int)target->query_temp("hmg_yixue") )
		{
			me->start_busy(3);
			msg += HIR "$P一指点中，心中正自高兴，不料$p早将经脉移位，这一指毫无效果。\n" NOR;	
			message_vision(msg, me, target); 
		}

       else if( random((int)me->query_skill("force")) > (int)target->query_skill("force")/(hmg + 2) ){
                if( hmg == 2 ) msg += HIR"$p一见之下，大为失色，发现这似乎正是自己的克星，结果被$P一阳指内力点中，全身气脉通道阻塞，真气立受干挠！\n" NOR;
                else msg += HIR"结果$p被$P一阳指内力点中，全身气脉通道阻塞，真气立受干挠！\n" NOR;
                target->start_busy(5 + (int)(me->query_skill("finger")/40)); 
        }else{
                me->start_busy(3);
                msg += HIY"$p眼看逼无可逼，便也一指点去，两根指尖相碰，看破了$P的企图，并没有上当。\n" NOR;
        }
        message_vision(msg, me, target);
        //最后再叫杀，使得信息显示更合理
        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
        if( !me->is_fight(target) ) me->fight_ob(target);
    
        return 1;
}

