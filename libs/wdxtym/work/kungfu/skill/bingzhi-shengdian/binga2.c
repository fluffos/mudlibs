#include <ansi.h>
#include <combat.h>
string query_name() { return "[冰魔法]"ZJBR"冰雪护盾"; }
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object fire,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("你现在正忙，无法召唤冰魔法·冰雪护盾");
	if((int)me->query("neili")< 1000)
	return notify_fail("你的法力太差了！\n");
	if((int)me->query_skill("bingzhi-shengdian",1)< 250)
	return notify_fail("你的冰之圣典太差了！\n");
        if ((int)me->query("magicgift")==2)
        return notify_fail("你已经使用冰魔法·冰雪护盾了！\n");
	me->add("neili",-1000);
	me->start_busy(2);
    me->set("magicgift",2);
	message_vision(WHT "\n$N"WHT"念动咒语 跨越天空以及大地的力量啊，凛冽的寒冬啊!!!\n" NOR, me);
	message_vision(WHT "\n$N"WHT"念到 集中到我的手中来成为我的力量吧！！！！！\n" NOR, me);
	message_vision(WHT "\n$N"WHT"的周围出来了无形的冰雪护盾!\n" NOR, me);
	return 1;
}
