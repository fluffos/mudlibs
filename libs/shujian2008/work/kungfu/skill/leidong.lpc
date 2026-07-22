// leidong.c 雷动九天
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int improve, improve2;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("雷动九天只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用雷动九天！\n");  
                
        if( (int)me->query_skill("poyu-quan", 1) < 100 )
                return notify_fail("你的混元掌不够娴熟，不会使用雷动九天！\n");
                                
        if( (int)me->query_skill("zixia-gong", 1) < 80 )
                return notify_fail("你的紫霞神功不够高，不能用出雷动九天伤敌。\n");

       if (me->query_skill_prepared("cuff") != "poyu-quan"
           || me->query_skill_mapped("cuff") != "poyu-quan")
               return notify_fail("你现在无法使用「雷动九天」进行攻击。\n");                                                                                 

        if( (int)me->query("neili") < 500 )
                return notify_fail("你现在内力太弱，无法使出雷动九天。\n");

        if( me->query_temp("leidong"))
                return notify_fail("你正在使用雷动九天！\n");

        msg = MAG"$N使出劈石破玉拳的绝学雷动九天，顿时天空电闪雷鸣！\n"NOR;
      message_vision(msg, me); 
      
      improve = (int)me->query("dex");
      me->add_temp("apply/dexerity", improve);
      improve2 = (int)me->query("str");
      me->add_temp("apply/strength", improve2);
      me->set_temp("leidong",1);  
      me->add("neili", - 300);
	target->interrupt_me();
	target->start_busy(3);
	COMBAT_D->do_attack(me, target, 0, 1);
	if (random(me->query_skill("poyu-quan",1))>200)
	{
		COMBAT_D->do_attack(me, target, 0, 3);
	}
	call_out("check_fight", 1, me, improve, improve2, me->query_skill("dodge", 1));
	me->start_perform(me->query_skill("dodge", 1) / 2, "雷动九天");
      return 1;
}

void remove_effect(object me, int improve, int improve2)
{
	string msgfinish = MAG"$N雷动九天劲力已过，四周渐渐恢复自然！\n"NOR;
       me->add_temp("apply/dexerity", - improve);
       me->add_temp("apply/strength", -improve2);
       message_vision(msgfinish, me); 
       me->delete_temp("leidong");
	me->start_perform(0);
//    if (!me->is_busy()) me->start_busy(2);
}

void check_fight(object me, int improve, int improve2, int t)
{
	if (!me) return;
	if (t && me->is_fighting()) call_out("check_fight", 1, me, improve, improve2, t-1);
	else remove_effect(me, improve, improve2);
}
