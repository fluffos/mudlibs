#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object soldier,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("你现在正忙，无法用内力点火");
        if( !me->is_fighting() )
        return notify_fail("好象没有人要杀你！\n");
	if((int)me->query("neili")< 300)
	return notify_fail("你的内力太差了！\n");
	zhaosheshu = (int)me->query_skill("huagang-dafa");
	yangsheshu = (int)me->query_skill("xuantian-strike");
	exp = (int)me->query("combat_exp");
//	if(huagang-dafa < 10 || chousui-zhang < 10)
//	return notify_fail("你星宿武功太差，内力不足以招火焰！\n");	
	MAX_GUARD = zhaosheshu * yangsheshu / 5000 + 1;
	if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("以你现在的能力，你已经没有能力控制更多的火焰了！\n");
	seteuid(getuid());
	me->add("neili",-150);
	soldier= new("d/xingxiu/obj/huoyan");
	soldier->move(environment(me));
//        soldier->invocation(me, (zhaosheshu+yangsheshu));
//        soldier->set("possessed", me);
        me->add_temp("max_guard",1);
//        me->remove_all_killer();
	message_vision(RED "\n$N用全身的内力注入地上！对着地上一指..\n" NOR, me);	
	message_vision(RED "\n$N烧了起来！\n" NOR, soldier);
	return 1;
}
