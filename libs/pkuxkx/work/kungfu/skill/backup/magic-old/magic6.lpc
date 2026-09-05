#define message_combatd message_vision
// 闪电术

#include <ansi.h>

inherit F_SSERVER;

int thunderspell(object me, object obj)
{
	int	kee, damage, spells;

        if ((int)me->query_skill("magic-old", 1) < 300)
                return notify_fail(WHT"你的古代魔法不够娴熟，还使不出「重破斩」。\n"NOR);
	message_vision(HIB "\n一个巨大的黑喑冲击波向$N的身上打来，\n" NOR, obj);
	obj->receive_damage("jing", 0, me);
	spells = me->query_skill("spells");
	if(obj->is_ghost()==1) {
		message_vision(HIB "$N惨叫了一声，化为了灰烬！\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->is_zombie()==1) {
		message_vision(HIB "$N惨叫了一声，化为了一滩血水！\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->query("race")=="野兽") {
//		kar = obj->query("qi");
//		spi = obj->query("jing");
                damage = (int)me->query_skill("magic-old", 15);
                damage = damage + random(damage);
//		damage = (31 - spi)*(spells/4)*(random(31-kar)+1)+100;
		if(damage <= 20) damage = 0;
		if(damage > 35) damage = 35;
		if(damage != 0) {
			message_vision(HIB "$N的全身都被黑喑笼罩了！\n" NOR, obj);
  		            obj->receive_damage("qi", 8000);
               		obj->receive_damage("jing", 800);
  		            obj->receive_damage("qi", damage);
               		obj->receive_damage("jing", damage);
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
			message_vision(RED "但被$N躲过了！\n" NOR, obj);
		return 1;
	}
//	kar = obj->query("qi");
//	spi = obj->query("jing");
                damage = (int)me->query_skill("magic-old", 15);
                damage = damage + random(damage);
//	damage = (31 - spi)*(spells/10)*(random(30-kar)+1);
	if(damage < 0) damage = 0;
	if(damage > 20) damage = 20;
	if(damage != 0) {
			message_vision(HIB "$N的全身都被黑喑笼罩了！\n" NOR, obj);
  		            obj->receive_damage("qi", 8000);
               		obj->receive_damage("jing", 800);
		obj->receive_damage("qi", damage);
               		obj->receive_damage("jing", damage);
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
			message_vision(RED "但被$N躲过了！\n" NOR, obj);
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

	if((int)me->query("qi") < 500 )
		return notify_fail("你的体力不够！\n");

	if((int)me->query("jing") < 100 )
		return notify_fail("你的精神没有办法有效集中！\n");


	msg = YEL "$N脚踩五芒星，双手握成伏魔印，口中喃喃地念著咒文，\n" NOR;
       msg += HIB"$N念到 比黑喑还要黑喑的东西,比深夜还要深的东西...\n"NOR;
       msg += HIB"$N继续念到 出现在时间之流  把挡在我面前一切愚不可及的事物摧毁...\n"NOR;
       msg += HIC"$N大叫一声  重破斩!!   巨大的的喑黑冲击波直向四周飞去，黑喑的能量充满了世界！\n"NOR;
	message_vision(msg, me);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( !inv[i]->is_character() || inv[i]->is_corpse() || userp(inv[i])) continue;
		thunderspell(me, inv[i]);
        }
     //        me->start_busy(5);
	return 1;
}


