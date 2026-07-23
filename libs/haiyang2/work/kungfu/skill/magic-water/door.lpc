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
        return notify_fail("你现在正忙，无法使用时间之门");
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");
	if((int)me->query("neili")< 300)
	return notify_fail("你的法力太差了！\n");
	if((int)me->query_skill("magic-water",1)< 50)
	return notify_fail("你的水系魔法太差了！\n");
        if (me->query("neili") < 400)
        return notify_fail("你的法力不足！\n");
         if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");

	if( environment(me)->query("outdoors")=="12gong" )
		return notify_fail("在12宫内不允许使用这个命令。\n");

   if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR)
	return notify_fail("只有在比较安全的地方才能使用时空之门。\n");
	me->add("neili",-150);
	me->start_busy(3);
        if( !environment(me)->query("no_fight") )
		return notify_fail("只有在比较安全的地方才能使用时空之门。\n");
        me->set("startroom", base_name(environment(me)));
	me->save();
	message_vision(WHT "\n$N念到:冻土啊，冰河啊，狂舞吧！！！！！\n" NOR, me);	
	message_vision(WHT "\n$N的脚下出现了一个六芒星。!!!\n" NOR, me);
	write(WHT"当你下次连线进来时，会从这个设过时空门的地方开始。\n"NOR);
	message_vision(WHT "\n$N脚下的六芒星慢慢消失了!!!\n" NOR, me);
	return 1;
}
