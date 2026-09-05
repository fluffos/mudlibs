int accept_fight(object player)
{
  object me=this_object(), *inv;
  int lp;
  
  if(living(me))
  {
    me->kill_ob(player);
    inv=all_inventory(environment(me));
    for(lp=0;lp<sizeof(inv);lp++)
    {
    	if ( inv[lp]->query("nianhua") )
    		inv[lp]->kill_ob(player);
    }
  }
  return 1;
}

int accept_kill(object player)
{
  object me=this_object(), *inv;
  int lp;
  
  if(living(me))
  {
    me->kill_ob(player);
    inv=all_inventory(environment(me));
    for(lp=0;lp<sizeof(inv);lp++)
    {
    	if ( inv[lp]->query("nianhua") )
    		inv[lp]->kill_ob(player);
    }
  }
  return 1;
}

int accept_hit(object player)
{
  object me=this_object(), *inv;
  int lp;
  
  if(living(me))
  {
    me->kill_ob(player);
    inv=all_inventory(environment(me));
    for(lp=0;lp<sizeof(inv);lp++)
    {
    	if ( inv[lp]->query("nianhua") )
    		inv[lp]->kill_ob(player);
    }
  }
  return 1;
}