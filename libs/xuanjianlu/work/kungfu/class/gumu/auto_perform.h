//Cracked by Kafei
// auto perform function (dispatched by chat_combat_msg)

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

			if ( me->query_skill("wudu-xinfa") && !me->query_temp("wudu/shield") ) 
					return exert_function("wudu");

			if ( objectp(weapon) ) {
					 if ( weapon->query("skill_type") == "whip" && me->query_skill("jueqing-bian") )
								return perform_action("whip.sanwu");
					 else if ( weapon->query("skill_type") == "whip" && me->query_skill("yinsuo-jinling"))
								return perform_action("whip.dian");
					 else  if ( weapon->query("skill_type") == "sword" )
								return perform_action("sword.suxin");
			}
			else if( me->query("id") == "yang guo" ){  
				command("perform xiaohun");
			}
			else if ( !me->query_temp("xieshou") ) {
				return perform_action("strike.xieshou");
			}
			else return perform_action("cuff.luowang");
}