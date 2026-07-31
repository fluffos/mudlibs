// roar.c 沧浪一笑

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够。\n");

	skill = me->query_skill("force");

	me->add("neili", -100);
	me->receive_damage("qi", 10);

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不能攻击别人! \n");
	
	if( !me->is_fighting())
		return notify_fail("你不在打架，用这个做什么?\n");

	me->start_busy(5);
	message_combatd(HIC "$N" HIC "纵声长笑，声音远远的传了"
                        "开去，犹如波浪声一般此起彼伏！\n" NOR, me);

	ob = all_inventory(environment(me));
	for (i = 0; i < sizeof(ob); i++)
        {
		if (! ob[i]->is_character() || ob[i] == me)
			continue;

		if (skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2)
			continue;
		if( !living(ob[i]) || ob[i]==me ) continue;
                if( !ob[i]->is_fighting(me) ) continue;
                if( ob[i]==me ) continue;
                //me->want_kill(ob[i]);
                //me->fight_ob(ob[i]);
                ob[i]->kill_ob(me);
		
		damage = skill+10 - ((int)ob[i]->query("max_neili") / 10);
		
		if (damage > 0)
                {
                        ob[i]->set("last_damage_from", me);
			ob[i]->receive_damage("jing", damage * 2, me);
			if ((int)ob[i]->query("neili") < skill * 2)
				ob[i]->receive_wound("jing", damage, me);
		        tell_object(ob[i], "你只觉得眼前一团漆黑，阵阵晕眩......\n");
		}
	}
	return 1;
}
