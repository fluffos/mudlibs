//Cracked by Kafei
// auto perform function (dispatched by chat_combat_msg)
// By Xuanyuan 2/7/2002

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if( me->query("qi",1) < 0 || me->query("jing",1) < 0 || me->query("jingli",1) < 0) return 1;

	if ( !me->is_fighting() ) {
					 if ( me->query("eff_qi") < me->query("max_qi") )
								me->exert_function("heal");
					 me->set("jiali", 50);

					 return 1;
		  }
		if( me->query("id") == "murong fu" ){
				if( !me->query_temp("dzxy") )
					return exert_function("xingyi");
		}
		if ( objectp(weapon) ) {
				if ( weapon->query("skill_type") == "sword" )
					return perform_action("sword.lianhuan");
				if ( weapon->query("skill_type") == "blade" )
					return perform_action("blade.baijia");
		  }
		if( me->query_skill("canhe-zhi",1) > 0){
				if( !me->query_temp("canshang") )
					return perform_action("finger.canshang");
				else return perform_action("finger.shedou");
		}
		else return perform_action("strike.zhen");
}