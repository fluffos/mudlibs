

void init()
{
        ::init();
        add_action("do_kill","kill");
        add_action("do_kill","fight");    
        remove_call_out("leave");
        call_out("leave",10);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting() && living(ob)) {
                message_vision(HIC "突厥军队撤了出去，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",15);
}

int do_kill(string arg)
{
        object who = this_player();
        object me = this_object();
        
        if(!arg || present(arg,environment(me))!=me) return 0;
        if (me->query("ygjg")!=who)
                  {
                  tell_object(who,CYN"你还是各司其职，专心对付自己的突厥兵吧。\n"NOR); 
                  return 1;
                  }
            else
             {
                  message_vision(CYN"$N保家卫国，视死如归！\n"NOR,who);
                  return 1;
                  }
                   return 0;
} 


