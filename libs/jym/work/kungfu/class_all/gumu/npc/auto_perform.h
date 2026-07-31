//Cracked by Roath
// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
		object ping;
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

		if ( me->query_skill("yunu-xinjing", 1) > 100 && random(3) ==1 )
		{
			if (!objectp(obj=present("fengjiang ping", me)))
				if (objectp(ping = new("/d/zhongnan/obj/ping.lpc")))
						ping->move(me);
			command("exert qufeng");
		}

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "sword" )
                        return perform_action("sword.suxin");
        }
        else{
			if( random(2) ==0)
				return perform_action("cuff.wuqing");
			else return perform_action("cuff.youju");
		}
}
