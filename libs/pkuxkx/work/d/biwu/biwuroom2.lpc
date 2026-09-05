inherit ROOM;


void init()
{
	add_action("do_go","go");
	add_action("do_catch","duo");
	add_action("do_killall","killall");	
 	add_action("do_look","look");
	add_action("do_pfm","perform");
	add_action("do_steal","steal");	
	add_action("do_kill","kill");
	add_action("do_hit","hit");	
	add_action("do_hit","hitall");	
	set("no_die",1);
    this_player()->listen_to_die(this_object());	
}

int do_killall()
{
	write("比武大会以武会友，你来搞大屠杀吗？\n");
	return 1;
}

int do_hitall()
{
	write("比武大会以武会友，你来搞大屠杀吗？\n");
	return 1;
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
	
	if(time() - pl->query_temp("biwu/last_go_time") <= 2)
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
	if(query("flag")) //&& BIWU_D->taskstarted())
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
		  //BIWU_D->catchflag(pl,query("flag"));
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

int do_pfm(string arg)
{
	write("比武大会点到即止，你刚要施展绝招，蓦然省起，强行压下浓浓的杀意。\n");
	return 1;
}

int do_steal(string arg)
{
	write("你是来比武的，还是来偷鸡摸狗的？\n");
	return 1;
}

int do_kill(string arg)
{
	int meexp,obexp;
	object ob;
	object me=this_player();
	meexp=me->query("combat_exp")/2;
	if (!arg)
		return notify_fail("你想杀谁？\n");
	ob=present(arg,environment(me));
	if(!objectp(ob))
		return notify_fail("这里没有这个人。\n");
	if (!ob->is_character() || ob->is_corpse())
		return notify_fail("看清楚一点，那并不是活物。\n");
	if (ob == me) return notify_fail("比武大会点到为止，也不许自杀。\n");
	obexp=ob->query("combat_exp");
	if (meexp>obexp)
		{
			write("比武大会点到为止，你怎么好意思向晚辈下手？\n");
		}
	else
		{
			write("江湖恩怨江湖了，但要记住，多造杀孽，必遭天谴。\n");
			me->kill_ob(ob);
			ob->kill_ob(me);
		}
	return 1;
}

int do_hit(string arg)
{
	int meexp,obexp;
	object ob;
	object me=this_player();
	meexp=me->query("combat_exp")/3;
	if (!arg)
		return notify_fail("你想杀谁？\n");
	ob=present(arg,environment(me));
	if(!objectp(ob))
		return notify_fail("这里没有这个人。\n");
	if (!ob->is_character() || ob->is_corpse())
		return notify_fail("看清楚一点，那并不是活物。\n");
	if (ob == me) return notify_fail("比武大会点到为止，也不许自杀。\n");
	obexp=ob->query("combat_exp");
	if (meexp>obexp)
		{
			write("比武大会点到为止，你怎么好意思向晚辈下手？\n");
		}
	else
		{
			write("江湖恩怨江湖了，但要记住，多造杀孽，必遭天谴。\n");
			me->fight_ob(ob);
			ob->fight_ob(me);
		}
	return 1;
}
