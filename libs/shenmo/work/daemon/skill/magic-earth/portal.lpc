#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object fire,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
	string startroom;
        if ( me->is_busy() )
        return notify_fail("你现在正忙，无法召使用回城术");
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");
	if((int)me->query("neili")< 300)
	return notify_fail("你的法力太差了！\n");
	if((int)me->query_skill("magic-earth",1)< 50)
	return notify_fail("你的土系魔法太差了！\n");
        if (me->query("neili") < 400)
        return notify_fail("你的法力不足！\n");
        if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
        if (me->is_busy()) 
        return notify_fail("你正忙着呢!\n");

	if( environment(me)->query("outdoors")=="12gong" )
		return notify_fail("在12宫内不允许使用回城术。\n");

   if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR)
	return notify_fail("只有在比较安全的地方才能使用回城术。\n");

        if( !environment(me)->query("no_fight") )
		return notify_fail("只有在比较安全的地方才能使用回城术。\n");
        startroom = me->query("startroom");
        if( !me->query("startroom") )
		return notify_fail("请先确定你要去的目标吧!\n");
	me->add("neili",-150);

	message_vision(YEL "\n$N在地上划了一个五芒星，口中喃喃地念著咒文!!\n" NOR, me);	
	message_vision(YEL "\n$N站在的地上出现了巨大的光芒，把$N包围了!\n" NOR, me);
        message_vision(YEL "\n$N在光芒中，消失不见了!\n" NOR, me);
        me->move(startroom);
	me->start_busy(3);
	return 1;
}
