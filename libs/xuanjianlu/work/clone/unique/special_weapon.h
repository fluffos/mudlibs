//Cracked by Roath
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object obj;
	string weapon, me_weapon, op_skill, *pname,result, str, msg;
	int me_power, victim_power;

	if (objectp(obj = victim->query_temp("weapon"))){

	if (obj->query("skill_type") == "hammer" && obj->query("rigidity") >=50)
	return 0;

	if ( this_object()->query("weapon_prop/damage")*3/4 > obj->query("weapon_prop/damage")){
	message_vision(HIW"「铮」地一声轻响，$N手中的$n"+HIW+"已被"+this_object()->query("name")+HIW"削成两截。\n"NOR, victim, obj);

		// add by xuanyuan
        if( (int)victim->query_skill("murong-jianfa", 1) > 119 
			&& (int)victim->query_skill("douzhuan-xingyi", 1) > 119 
			&& victim->query("neili") > 500 
			&& victim->query("jingli") > 200){
			message_vision(HIG"\n$n猛吃一惊，却不慌乱，右掌急挥，将二三十断刃化作暗器，以满天花雨手法向$N激射去。\n"NOR, me, victim);

        victim_power = victim->query_skill("sword") + victim->query_skill("strike") + victim->query_skill("force")
                   + victim->query_skill("dodge") + victim->query("combat_exp") / 1000;

        me_power = me->query_skill(op_skill) + me->query_skill("dodge") + me->query_skill("force")
                   + me->query_skill("parry") + me->query("combat_exp") / 1000;

        if ( random(victim_power) > me_power/3 ) 
        {
                if ( random(victim->query_kar()) > (me->query_kar())*4/5 ) 
                {
                        message_vision(HIR "\n$N未曾料到$n还有此招，一呆之下，反应不及，无数断刃透体而过。\n" NOR, me ,victim);
                        me->receive_damage("qi", me->query("max_qi")/8 + random(me->query("max_qi")/4), me);
						str = COMBAT_D->status_msg((int)me->query("qi") * 100 /(int)me->query("max_qi"));
						message_vision("($N"+str+")\n", me);
                }
                else // if ( random(victim->query_kar()) > (me->query_kar())*3/5 ) 
                {
                message_vision(HIR "\n$N大叫：“啊哟！”手足无措，慌作一团，急忙伏地。不料动作稍慢，背上被断刃划出几条血痕。\n" NOR, me);
                me->receive_damage("qi", me->query("max_qi")/10 + random(me->query("max_qi")/8), me);
				str = COMBAT_D->status_msg((int)me->query("qi") * 100 /(int)me->query("max_qi"));
				message_vision("($N"+str+")\n", me);
                }
        }
		else {
				if ( objectp(me_weapon = me->query_temp("weapon"))) 
				{
				message_vision(WHT"\n$N一惊之下，反应神速，舞开手中兵刃，将断刃一一荡开。\n" NOR, me);
				}
				else 
				{  
				message_vision(HIY "\n$N大叫：“啊哟！”手足无措，慌作一团，急忙伏地。数十枚断刃都从他头顶飞过，高手比武，竟出到形如“狗吃屎”的丢脸招数，实在难看已极。\n" NOR, me);
				}
		}
			victim->add("neili", -200);
			victim->add("jingli", -100);
	}

		obj->unequip();
        	obj->move(environment(victim));
        	obj->set("name", "断掉的" + obj->query("name"));
		obj->set("value", 0);
        	obj->set("weapon_prop", 0);
        	victim->reset_action();
		set_heart_beat(1);
	     }
	return;
	}
}

