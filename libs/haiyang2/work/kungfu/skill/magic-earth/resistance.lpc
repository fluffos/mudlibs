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
        return notify_fail("你现在正忙，无法召唤御土奇术");
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");
	if((int)me->query("neili")< 300)
	return notify_fail("你的法力太差了！\n");
	if((int)me->query_skill("magic-earth",1)< 250)
	return notify_fail("你的土系魔法太差了！\n");
        if ((int)me->query("magicgift")==4)
        return notify_fail("你已经使用御土奇术了！\n");
	me->add("neili",-250);
	me->start_busy(2);
        me->set("magicgift",4);
	message_vision(YEL "\n$N念动咒语 无尽的大地，展现你的力量，混沌之物，把所有的一切都化为我的盾牌吧！！！！!\n" NOR, me);	
	message_vision(YEL "\n$N的周围出来了无形的大地之护盾!\n" NOR, me);
	return 1;
}
