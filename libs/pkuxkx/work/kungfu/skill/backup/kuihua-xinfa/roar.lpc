// roar.c 葵花心法吟

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准打架。\n");

  	 if( (int)me->query_skill("kuihua-xinfa",1) < 20)
		return notify_fail("你的葵花心法还不够精熟。\n");

        if( (int)me->query("neili") < 150 )
                return notify_fail("你怪笑一声，大家吓了一跳。\n");


        skill = me->query_skill("force");

        me->add("neili", -150);
        me->receive_damage("qi", 10);

        me->start_busy(2);
        message_combatd(
        MAG "$N神情一变，忽然“哈！哈！哈！”三声怪笑。」。\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me )
                        continue;

                if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 )
                        continue;

                if( !ob[i]->is_killing(me->query("id")) )
                        ob[i]->kill_ob(me);
                if( !me->is_killing(ob[i]) )
                        me->fight_ob(ob[i]);

                damage = skill - ((int)ob[i]->query("max_neili") / 10);
                if( damage > 0 ) {
                        ob[i]->receive_damage("jing", damage, me);
                        if( (int)ob[i]->query("neili") < skill * 2 )
                                ob[i]->receive_wound("jing", damage, me);
                tell_object(ob[i], "你忽然觉得一阵寒意扑面而来，心神朦胧中漂移不定。\n");
                }
        }

        return 1;
}

