// cracked by vikee 2/09/2002   vikee@263.net
// yinshen.c 隐身术

inherit SSERVER;
#include <ansi.h>


int cast(object me)
{
	int howlong;
	
	if((int)me->query_skill("spells") < 100)
		return notify_fail("你还没学会隐身法。。。\n");

	if( (int)me->query("mana") < 2*(int)me->query_skill("spells"))
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < 50 )
		return notify_fail("你的精神无法集中！\n");

	if( (int)me->query("env/invisibility") )
		return notify_fail("你已经在隐身中了。\n");

  if (me->query_temp("yinshen_busy")) return notify_fail("你刚隐身过，先休息一会儿吧。\n");
	message_vision("$N喃喃地念了几句咒语。\n", me);

	if( random(me->query("max_mana")) < 200 ) {
        me->add("mana",-(int)me->query_skill("spells",1));
		me->receive_damage("sen",10);
		message("vision", "但是什么也没有发生。\n", environment(me));
		return 5+random(5);
	}

    me->add("mana", -2*(int)me->query_skill("spells",1));
	me->receive_damage("sen", 20);

	howlong = 15 + random((me->query_skill("spells") -100));
	if (!me->query("env/invisibility"))
		call_out("free", howlong, me, howlong);
	me->set_temp("yinshentime", howlong+(int)me->query_temp("yinshentime"));

	me->set("env/invisibility", 1);
	me->set_temp("no_heal_up/yinshen",1);
	
  me->set_temp("yinshen_busy",1);
	message_vision(HIW"\n只见一道白光闪过，$N踪迹皆无。\n\n"NOR, me);
	
	return 5+random(5);
}

void free(object user, int howlong)
{
        if(!user) return;
	if (!user->query("env/invisibility")) return;
	if (user->query_temp("yinshentime") - howlong) {
		user->set_temp("yinshentime", 
			user->query_temp("yinshentime") - howlong);
		call_out("free", user->query_temp("yinshentime"), 
			user, user->query_temp("yinshentime"));
		return;
		}
	user->delete_temp("yinshentime");
	user->set("env/invisibility", 0);      
  call_out("free2",random(user->query_skill("spells")-100)+10,user);
	user->save();
	message_vision(HIW"\n白光闪过之后，$N又现出了身形。\n\n"NOR, user);
	user->delete_temp("no_heal_up/yinshen");
	return;
}

void free2(object me) {
  if (!me) return;
  me->delete_temp("yinshen_busy");
}