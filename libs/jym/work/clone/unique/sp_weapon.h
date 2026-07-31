//Cracked by Kafei
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object obj;

	if (objectp(obj = victim->query_temp("weapon"))){

	if (obj->query("skill_type") == "hammer" && obj->query("rigidity") >=50)
	return 0;
//  obj = victim->query_temp("weapon");
	if ( this_object()->query("weapon_prop/damage")*3/4 > obj->query("weapon_prop/damage")){
	message_vision(HIW"「铮」地一声轻响，$N手中的$n"+HIW+"已被"+this_object()->query("name")+HIW"上的灵气炸的粉碎。\n"NOR, victim, obj);
		      obj->unequip();
        	obj->move(environment(victim));
        	obj->set("name", "粉碎的" + obj->query("name"));
		      obj->set("value", 0);
        	obj->set("weapon_prop", 0);
        	destruct(obj);
        	victim->reset_action();
		      set_heart_beat(1);
		       }
	return;
	}
}
