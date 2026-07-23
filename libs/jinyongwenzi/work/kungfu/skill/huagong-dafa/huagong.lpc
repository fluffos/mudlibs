// huagong.c 化功
// by snowman@SJ
// modify by snowman@SJ 25/02/2000
// Modified by darken@SJ
// Modified by olives@SJ 5/17/2001
// for action.c changed,some bugs.
// Modified by olives@SJ 7/21/2001
// 加上失败的描述

#include <ansi.h>

inherit F_SSERVER;

string exert_name(){ return HBRED"化功"NOR; }
int check_fight(object me);
int halt_fight(object me);

int exert(object me, object target)
{
	object room, ob;

	if( !target) target = offensive_target(me);
	if( !target || !objectp(target) || !me->is_fighting(target) || !living(target))
		return notify_fail("化功只能在战斗中对对手使用。\n");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("用火把来烧比较快。\n");

	if( !userp(target) && !wizardp(me))
		return notify_fail("你不能对他使用化功！\n");

	if(!( room = find_object("/d/taishan/fengchan")) )
		room = load_object("/d/taishan/fengchan");
	if( objectp(ob = present("zhong shentong", room)) ) {
		if(target->query("id") == ob->query("winner"))
			return notify_fail("大胆！竟敢对中神通运用化功大法！\n");
	}

	if( !living(target) || ! target->query("can_speak"))
		return notify_fail("它不是活物，你没法吸取内力？\n");

	if( me->query_temp("weapon"))
		return notify_fail("你必须使用三阴蜈蚣抓，方能抓住对手。\n");

	if( me->query_skill_prepared("claw") != "sanyin-zhua")
		return notify_fail("你必须使用三阴蜈蚣抓，方能抓住对手。\n");

	if( (int)me->query_skill("huagong-dafa",1) < 250 )
		return notify_fail("你的功力不够，不能施展化功大法！\n");

	if( (int)me->query_skill("poison",1) < 200 )
		return notify_fail("你体内的毒素不够，不能施展化功大法！\n");

	if(environment(me)->query("no_death"))
		return notify_fail("此地不能施展化功大法！\n");

	if((int)target->query("max_neili") <= 0
	|| target->query("combat_exp") < me->query("combat_exp")/2)
		return notify_fail( target->name() +"没有多少内力可化了。\n");

	message_vision(BLU"突然$N仰天阴阴一声长笑，接着左手手掌虚扬，右手猛地向$n拍去！\n\n" NOR, me, target );

	if( random(me->query_int()) > target->query_int()/2) {
	    message_vision(HBRED"$n也是一掌拍来挡格，双掌一接，$n似乎想起了什么，暗叫一声不好！\n\n" NOR, me, target );
	    me->start_busy((:check_fight:),(:halt_fight:));
	    me->set_temp("huagong/target",target);
	    target->start_busy(2);
	}
	else
		message_vision(YEL"\n可是$n看破了$N的企图，机灵地溜了开去。"NOR,me,target);

	if( !target->is_killing(me->query("id")) ){
		me->kill_ob(target);
		target->kill_ob(me);
	}

	me->start_exert(2+random(2),"「化功大法」");
	return 1;
}

int check_fight(object me)
{
	object target,victim, *people;
	int i,dp,ap;
	if(!objectp(target = me->query_temp("huagong/target")) || !userp(target))
	{
		me->delete_temp("huagong");
		me->start_exert(2+random(2),"「化功大法」");
		message_vision(HIC"\n$N大袖一拢，将双掌隐于袖中。\n"NOR,me);
		return 0;
	}
	target->start_busy(2);
	dp = target->query_skill("douzhan-xingyi",1);
	if(target->query_skill("qiankun-danuoyi",1)>dp)
		dp = target->query_skill("qiankun-danuoyi",1);
	ap = me->query_skill("sanyin-zhuan",1);
	if(target->query("max_neili") < 1
	|| target->query_temp("huagong/count") > 10) {
	    message_vision(RED"$n被$N化尽了丹元，软软的摊在地上。\n"NOR, me, target);
	    message_vision(RED"$N哈哈一笑，松开了手。\n"NOR, me, target);
	    target->add("max_neili",-50-random(30));
	    if(target->query("max_neili")<0)
		target->set("max_neili",0);
	    target->set("neili",0);
	    target->delete_temp("huagong/count");
//          me->remove_all_enemy();
//          target->remove_all_enemy();
	    me->start_exert(2+random(2),"「化功大法」");
	    return 0;
	}

	if(random(ap+dp)<dp)
	{
	     people = all_inventory(environment(me));
	     i = random(sizeof(people));
	     victim = people[i];
	     if(victim != me
	     && victim != target
	     && victim->is_character()
	     && living(victim)
	     && !wizardp(victim)) {
		message_vision(HBRED"$N灵机一动，一牵一引，把$n转到身前，接过了对手的魔掌！\n"NOR, target, victim);
		target->remove_all_enemy();
		me->remove_all_enemy();
		me->set_temp("huagong/target",victim);
		victim->start_busy(2);
		return 1;
	     }
	}
	if (random(target->query("neili")) > me->query("neili")/2) {
	    message_vision(RED"$n拼著大耗真元，将全身内力用力向$N一送，挣开了$N的掌握。\n"NOR, me, target);
	    target->add("max_neili",-5-random(5));
	    me->start_exert(2+random(2),"「化功大法」");
	    return 0;
	}
	message_vision(RED"$n使劲挣扎，就是无法脱出$N掌握，只觉得内力不断流失。\n"NOR, me, target);
	me->add("combat_exp", random(me->query_skill("poison"))/10);
	target->add("max_neili", -20-random(11));
	target->add_temp("huagong/count", 1);
	return 1;
}

int halt_fight(object me)
{
	notify_fail("你双手一扯，藏入飘飘的双袖中，恍若未动一般。\n");
	me->start_busy(1+random(2));
	me->start_perform(2+random(2),"「化功大法」");
	me->start_exert(2+random(2),"「化功大法」");
	return 1;
}
