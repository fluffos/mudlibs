// 闪电术

#include <ansi.h>

inherit F_SSERVER;

int thunderspell(object me, object obj)
{
	int	kee, damage, spells;

        if ((int)me->query_skill("magic-old", 1) < 100)
                return notify_fail(WHT"你的古代魔法不够娴熟，还使不出「龙破斩」。\n"NOR);
	message_vision(YEL "\n一个巨大的冲击波向$N"YEL"的身上打来，\n" NOR, obj);
//	obj->receive_damage("jing", 0, me);
	spells = me->query_skill("spells");
//me->start_busy(0);
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
                damage = (int)me->query_skill("magic-old", 5);
                damage = damage + random(damage);
//		damage = (31 - spi)*(spells/4)*(random(31-kar)+1)+100;
		if(damage <= 20) damage = 10;
		if(damage != 0) {
			message_vision(RED "$N"RED"的全身都被打中了！\n" NOR, obj);
  		            obj->receive_damage("qi", damage*2);
                            obj->receive_wound("qi", damage/2);               		    
               		obj->receive_damage("jing", damage/4);
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
                damage = damage + random(damage)+1000;
//	damage = (31 - spi)*(spells/10)*(random(30-kar)+1);
	if(damage < 0) damage = 10;
	if(damage > 3000) damage = 3000;
	if(random(2)==1) {
		message_vision(RED "$N"RED"的全身都被打中了\n" NOR, obj);
		obj->receive_damage("qi", damage*2);
                obj->receive_wound("qi", damage);               		    
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

	if((int)me->query("qi") < 500 )
		return notify_fail("你的体力不够！\n");

	if((int)me->query("jing") < 100 )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("neili", -500);
	me->receive_damage("jing", 40);
if ((int)me->query("qi")+6000 < (int)me->query("eff_qi")) 
{
message_vision(HIW "\n巨大的咒语声过后,$N"HIW"全身笼罩着圣洁的光芒，全身的伤好像好多了！\n" NOR, me);
me->receive_heal("qi", random(2000)+2000);
me->receive_heal("jing", random(2000)+1000);
}
if ((int)me->query("eff_qi")+6000 < (int)me->query("max_qi")) 
{
message_vision(HIW "\n巨大的咒语声过后,$N"HIW"全身笼罩着圣洁的光芒，全身的伤好像好多了！\n" NOR, me);
me->add("eff_qi", random(3000)+3000);
}
	msg = YEL "$N"YEL"脚踩五芒星，双手握成伏魔印，口中喃喃地念著咒文，\n" NOR;
       msg += RED"$N"RED"念到 比黄昏还要昏喑的东西,比血液还要鲜红的东西...\n"NOR;
       msg += RED"$N"RED"继续念到 出现在时间之流  把挡在我面前一切愚不可及的事物摧毁...\n"NOR;
       msg += HIR"$N"HIR"大叫一声  龙破斩!!  巨大的的冲击波直向四周飞去，能量大的可怕.！\n"NOR;
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


