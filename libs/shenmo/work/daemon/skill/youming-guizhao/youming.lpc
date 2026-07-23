// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// youming.c  幽冥鬼影

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("「幽冥鬼影」只能在战斗中使用。\n");

        if ((int)me->query_skill("youming-guizhao", 1) < 120 )
                return notify_fail("你的幽冥鬼爪等级不够，不能呼唤鬼影！\n");    

        if ((int)me->query_skill("claw", 1) < 120 )
                return notify_fail("你的基本爪法极不够娴熟，不能呼唤鬼影！\n");    

        if (objectp(me->query_temp("weapon")))
                return notify_fail("你必须空手使用「幽冥鬼影」！\n");

        
        if ((int)me->query_skill("xiaowuxiang", 1)<100
		&& (int)me->query_skill("bahuang-gong", 1)<100
		&& (int)me->query_skill("beiming-shengong", 1)<100)
                return notify_fail("你的逍遥派内功火候不够。\n");

        if (me->query_skill_mapped("force") != "xiaowuxiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你没有运用逍遥派内功！\n");	
        

        if (me->query_skill_prepared("claw") != "youming-guizhao"
                || me->query_skill_mapped("claw") != "youming-guizhao"
                )
                return notify_fail("你现在无法呼唤出鬼影进行攻击！\n"); 

        if ((int)me->query("neili") < 800)
                return notify_fail("你现在真气太弱，不能呼唤鬼影！\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你现在内力太弱，不能呼唤鬼影！\n");

        if ((int)me->query_temp("lingjiu/youming", 1)) 
                return notify_fail("你已经呼唤出了幽冥鬼影！\n");

        skill = me->query_skill("claw");

        message_combatd(HIR "突然$N咬破舌尖，高声叫唤天地鬼神，如同疯子一般！跟着地面变得有如水动，只见\n"
                        "一条"HIB"鬼影"HIR"从地底冒出，飞于半空，身行飘渺不定，时而象一火球，时而象一黑影！\n\n" NOR, 
                        me);

        me->add("neili", -skill);    
        me->set_temp("lingjiu/youming", 1);
	me->add_temp("apply/defense",  skill / 2);

        call_out("checking", 1, me, target);
        call_out("remove_effect", skill/5+2, me); 
        
        return 1;
}
void checking(object me, object target)
{
        int skill;
        skill = me->query_skill("claw");

        if( !living(me) || me->is_ghost() )
	{
		message_combatd(HIR"那条"HIB"鬼影"HIR"于半空徘徊了一阵，就消失在地底了！\n"NOR, me);
		me->add_temp("apply/defense",  -skill/2);
		me->delete_temp("lingjiu/youming");
		remove_call_out("remove_effect");
		return ;
	}
        if( !me->is_fighting() )
	{
		message_combatd(HIR"那条"HIB"鬼影"HIR"于半空徘徊了一阵，就消失在地底了！\n"NOR, me);
		me->add_temp("apply/defense",  -skill/2);
		me->delete_temp("lingjiu/youming");
		remove_call_out("remove_effect");
		return ;
	}
        if( me->query_skill_mapped("force") != "bahuang-gong"
	   || me->query_skill_mapped("claw") != "youming-guizhao"
	    )
	{
		tell_object(me,"\n$N骤然变换招数，不能再继续用幽冥鬼影牵制对手的攻击！\n");
		me->add_temp("apply/defense",  -skill/2);
		message_combatd(HIR"那条"HIB"鬼影"HIR"于半空徘徊了一阵，就消失在地底了！\n"NOR, me);
		me->delete_temp("lingjiu/youming");
		remove_call_out("remove_effect");
		return ;
	}
        else 
	        call_out("checking", 1, me, target);
        return;
}
void remove_effect(object me)
{
        int skill;
        
        if (! me) return;
                
        skill = me->query_skill("claw");

        message_combatd(HIR"地面的波动渐渐减弱，那条"HIB"鬼影"HIR"于半空徘徊了一阵，就消失在地底了！\n"NOR, me);
	me->add_temp("apply/defense",  -skill/2);
	me->delete_temp("lingjiu/youming");
        return;
}
