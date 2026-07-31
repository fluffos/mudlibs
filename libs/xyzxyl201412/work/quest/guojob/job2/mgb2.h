void init()
{
	::init();
	add_action("do_kill","kill");
	add_action("do_kill","hit");    
	remove_call_out("leave");
	call_out("leave", 15);
}

void leave()
{
	object ob = this_object();
	object me = ob->query("ygjg");

	if ( !ob->is_fighting() ) 
	{
		if ( !objectp(me) )
		{
			message_vision(HIC "蒙古兵撤了出去，不见了。\n" NOR, ob);
			remove_call_out("leave");
			destruct(ob);
			return;
		}
		if ( random(10) > 5 )
		{
			remove_call_out("leave");
			call_out("leave", 15);
			return;
		}
			
		message_vision(HIC "蒙古兵撤了出去，不见了。\n" NOR, ob);
		me->delete_temp("start_job");
		me->set_temp("job_over", 1);
		destruct(ob);
	}
	else 
	{
		remove_call_out("leave");
		call_out("leave", 15);
		return;
	}
}

int do_kill(string arg)
{
        object who = this_player();
        object me = this_object();
        
        if(!arg || present(arg,environment(me))!=me) return 0;
        if (me->query("ygjg")==who)
                  {
                  message_vision(CYN"$N加油！$N加油！\n"NOR,who);
                  return 1;
                  }
            else if (me->query("ygjg"))
             {
                  tell_object(who,CYN"你还是各司其职，专心对付你的"HIR"蒙古兵"CYN"吧。\n"NOR);
                  return 1;
                  }
                   return 0;
} 

