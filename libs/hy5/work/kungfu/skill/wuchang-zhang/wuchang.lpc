// wugou.c 天下无常
// shang 97/6

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
	object *ob;
	int i, skill, damage;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 2000 )
		return notify_fail("你内力不雄厚不能使用天下无常攻击。\n");

	if( (int)me->query("neili") < 500 )
                return notify_fail("你现在没有足够的内力使用天下无常。\n");

        if ((int)me->query("jing") < 100)
                return notify_fail("你现在没有足够的精力使用天下无常。\n");

        if( (int)me->query_skill("wuchang-zhang", 1) < 200 )
                return notify_fail("你的无常杖法火侯还没到，天下无常使不出来。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能攻击他人。\n");


	if( !me->is_fighting())
		return notify_fail("你不在打架，用这个做什么?\n");


	skill = me->query_skill("wuchang-zhang", 1);

	me->add("neili", -300);
	me->receive_damage("jing", 100);

	me->start_busy(2);
	message_vision(
		HIY "$N使出「天下无常」的最后一招，世间皆无常，。\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
                if( !ob[i]->is_fighting(me) ) continue;
                if( ob[i]==me ) continue;
	        if( !ob[i]->is_character() || ob[i]->is_corpse() ) continue;

                damage = (int)me->query_skill("wuchang-zhang", 1);
                damage = (int)me->query_skill("wuchang-zhang", 1) +damage;
                damage = random(damage)+300;
		if( damage > 2000 ) damage = 2001;
		ob[i]->receive_damage("qi", damage , me);
		ob[i]->receive_damage("jing", damage / 4 , me);
		tell_object(ob[i], "你觉得眼前一阵杖雨，挨了不少下。\n");	
	        		if( !me->is_killing(ob[i]) )
			me->fight_ob(ob[i]);

		if( !ob[i]->is_killing(me) )
			ob[i]->fight_ob(me);
	        }

	return 1;
}

	