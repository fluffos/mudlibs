// 闪电术

#include <ansi.h>

inherit F_SSERVER;

int thunderspell(object me, object obj)
{
	int	kee, damage, spells;

        if ((int)me->query_skill("magic-old", 1) < 100)
                return notify_fail(WHT"你的古代魔法不够娴熟，还使不出「大闪电术」。\n"NOR);
	message_vision(HIC "\n一个闪电向$N"HIC"的头上打来，\n" NOR, obj);
	obj->receive_damage("jing", 0, me);
	spells = me->query_skill("spells");
	if(obj->is_ghost()==1) {
		message_vision(RED "$N"RED"惨叫了一声，化为了灰烬！\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->is_zombie()==1) {
		message_vision(RED "$N"RED"惨叫了一声，化为了一滩血水！\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->query("race")=="野兽") {
//		kar = obj->query("qi");
//		spi = obj->query("jing");
                damage = (int)me->query_skill("magic-old", 1);
                damage = damage + random(damage);
//		damage = (31 - spi)*(spells/4)*(random(31-kar)+1)+100;
		if(damage <= 20) damage = 0;
//		if(damage > 2000) damage = 2000;
		if(damage != 0) {
			message_vision(RED "正打在了$N"RED"的头上！\n" NOR, obj);
  		            obj->receive_damage("qi", 400);
               		obj->receive_damage("jing", 30);
               		obj->receive_damage("qi", damage);
               		obj->receive_damage("jing", damage/2);
	 		COMBAT_D->report_status(obj);
			if( !obj->is_fighting(me) ) {
                		if( living(obj) ) {
                        		if( userp(obj) ) 
						obj->fight_ob(me);
					else
						obj->kill_ob(me);
                		}
                		me->kill_ob(obj);
        		}
		} else 
			message_vision(RED "但被$N"RED"躲过了！\n" NOR, obj);
		return 1;
	}
//	kar = obj->query("qi");
//	spi = obj->query("jing");
                damage = (int)me->query_skill("magic-old", 3);
                damage = damage + random(damage);
//	damage = (31 - spi)*(spells/10)*(random(30-kar)+1);
	if(damage < 0) damage = 10;
	if(random(2)==1) {
		message_vision(RED "正打在了$N"RED"的头上！\n" NOR, obj);
               		obj->receive_damage("qi", damage);
               		obj->receive_wound("qi", damage);
               		obj->receive_damage("jing", damage/2);

 		COMBAT_D->report_status(obj);
		if( !obj->is_fighting(me) ) {
               		if( living(obj) ) {
                       		if( userp(obj) ) 
					obj->fight_ob(me);
				else
					obj->kill_ob(me);
               		}
               		me->kill_ob(obj);
       		}
	} else 
			message_vision(RED "但被$N"RED"躲过了！\n" NOR, obj);
	return 1;
	
}
int perform(object me)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i;

	if((int)me->query_skill("spells") < 200 )
		return notify_fail("你的法术不够高！\n");

	if((int)me->query("neili") < 200 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("qi") < 100 )
		return notify_fail("你的体力不够！\n");

	if((int)me->query("jing") < 100 )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("neili", -200);
	me->receive_damage("jing", 10);

	msg = YEL "$N"YEL"脚踩五芒星，双手握成伏魔印，口中喃喃地念著咒文，\n" NOR;
	msg = msg + HIC "猛地双手一挥，天上打下无数闪电！\n\n" NOR;
	message_vision(msg, me);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(1);
	return 1;
}

