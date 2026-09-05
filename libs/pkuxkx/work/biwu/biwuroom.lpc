inherit ROOM;

void init()
{
	add_action("do_go","go");
	add_action("do_catch","duo");
	add_action("do_killall","killall");	
 	add_action("do_look","look");
 	add_action("do_perform","perform");
	add_action("do_command","");
	set("no_die",1);
    this_player()->listen_to_die(this_object());	
}

int do_command(string arg)
{
	string verb;
	object pl = this_player();
	verb = query_verb();
	if( !arg &&	query("exits/" + verb))
	{				
		if(!wizardp(pl) && time() - pl->query_temp("biwu/last_go_time") <= 2+random(2))
		{
			write("你发现前面的路不远了，加快了脚步。\n");
			return 1;
		}
		
		pl->set_temp("biwu/last_go_time",time());	
		return 0;
	}
	return 0;
}
int do_killall()
{
	int i;
	object* invs = all_inventory();
	for(i=0;i<sizeof(invs);i++)
	{
		if(userp(invs[i]) && invs[i]->query("family/family_name") != this_player()->query("family/family_name"))
		{
			this_player()->kill_ob(invs[i]);
		}
	}
	this_player()->add_busy(1);
}

int do_look(string arg)
{
  if(arg == "flag" && query("flag"))
  {
    write("这是"+query("flag")+"\n");
    if(query("flag_owner"))
    {
      write("这面"+query("flag")+"现在由"+query("flag_owner")+"掌握\n");
    }
    return 1;
  }
  return 0;  
}

int do_go(string dir)
{
	object pl = this_player();
	
	if(!wizardp(pl) && time() - pl->query_temp("biwu/last_go_time") <= 2+random(2))
	{
		write("你发现前面的路不远了，加快了脚步。\n");
		return 1;
	}
	
	pl->set_temp("biwu/last_go_time",time());
	
	return 0;
}

int do_catch()
{
	int i;
	object pl = this_player();
	object* invs = all_inventory();
	if(pl->is_busy())
	{
	 return notify_fail("你正忙着呢。\n");
  }
	if(query("flag") && BIWU_D->taskstarted())
	{		
	  if(pl->query("family/family_name") == query("flag_owner"))
	  {
	   return notify_fail("这面战旗已经属于你们了，好好守住吧。\n");
    }
		for(i=0;i<sizeof(invs);i++)
		{
			if(userp(invs[i]) && invs[i]->query("family/family_name") != pl->query("family/family_name"))
			{
				return notify_fail("你想要夺旗，但是对手正在一旁虎视眈眈，不打败他们，夺旗是不可能的。\n");
			}
		}
		
		if(query("flag_hp") - 1 <= 0)
		{
		  BIWU_D->catchflag(pl,query("flag"));
		  set("flag_hp",query("default_flag_hp"));
		  set("flag_owner",pl->query("family/family_name"));
    }
    else
    {
      add("flag_hp",-1);
      pl->start_busy(1);
      message_vision("$N飞身而起，直向战旗扑去，势在必得。\n",pl);
    }	
	}
	else
	{
		return notify_fail("这里没有战旗。\n");
	}
	return 1;
}


int valid_leave(object me, string dir)
{       
    me->remove_listen_to_die(this_object());        
    return ::valid_leave(me, dir);
}

int die_notify(object victim)
{
    object killer;
    if(!objectp(victim) || !userp(victim)) return 0;
    if(environment(victim) != this_object())
    {
        victim->remove_listen_to_die(this_object());        
    }
    else
    {
        killer = victim->get_damage_origin_object();
        if(objectp(killer) && userp(killer) )
        {
            if(killer->query("family/family_name") != victim->query("family/family_name"))
            {
                killer->add("family_biwu/lastscore",1);
            }
        }
    }
    return 0;
}

int do_perform()
{
	
}