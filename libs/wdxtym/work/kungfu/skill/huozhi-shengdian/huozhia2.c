#include <ansi.h>
#include <combat.h>
string query_name() { return "[火魔法]"ZJBR"魔法火焰"; }
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object fire,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("你现在正忙，无法召唤火魔法·魔法火焰");
	if((int)me->query("neili")< 300)
	return notify_fail("你的法力太差了！\n");
	if((int)me->query_skill("huozhi-shengdian",1)< 50)
	return notify_fail("你的火之圣典太差了！\n");
        if (present("fire", me))
        return notify_fail("你已经召唤火魔法·魔法火焰了！\n");
        if (me->query("neili") < 400)
        return notify_fail("你的法力不足！\n");
         if (me->is_fighting())
        return notify_fail("你正打的热闹着呢!\n");

	me->add("neili",-150);
	me->start_busy(2);
	fire= new("/clone/magic/fire");
	fire->move(me);

	message_vision(RED "\n$N左手一张 [出来吧炎之力量!] 一团魔法火焰, 漂浮在了$N的前方!!\n" NOR, me);
	message_vision(RED "\n$N的力量使四周一下子亮了起来!\n" NOR, fire);
	return 1;
}
