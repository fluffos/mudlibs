#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object fire,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("你现在正忙，无法召唤御气奇术");
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");
	if((int)me->query("neili")< 300)
	return notify_fail("你的法力太差了！\n");
	if((int)me->query_skill("magic-ice",1)< 250)
	return notify_fail("你的气系魔法太差了！\n");
        if ((int)me->query("magicgift")==3)
        return notify_fail("你已经使用御气奇术了！\n");
	me->add("neili",-250);
	me->start_busy(2);
        me->set("magicgift",3);
	message_vision(HIC "\n$N念动咒语 [雷神来，掌握我生命的雷的精灵！！！！！!] !!\n" NOR, me);	
	message_vision(HIC "\n$N的周围出来了无形的气之护盾!\n" NOR, me);
	return 1;
}
