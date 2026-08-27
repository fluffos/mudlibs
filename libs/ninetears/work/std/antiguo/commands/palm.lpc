/* allows someone to quitely pick something up.  Is based on the objects
 * bulk.  It is hard to palmn something big ;)
 */
#define COST 3

int palm(string str, object who) 
{
  mixed obs;
  object *fail, *t_p, *s_f, *g_f, *from;
  object me;
  int i, skill, g_p;
  string s1;

  me = ( who ? who : this_player() );

  str = me->expand_nickname(str);

  if (!str) 
  {
    notify_fail("Syntax: palm <objects> [from <object>]\n");
    return 0;
  }
  
  if (sscanf(str, "%s from %s", str, s1) == 2) 
  {
    obs = find_match(s1, environment(me));
    if ( !sizeof(obs) )
    {
      notify_fail("Cannot find "+s1+".\n");
      return 0;
    }
    else
      obs = obs[0];

    if ( living(obs) )
    {
      notify_fail(obs->query_cap_name()+" wouldn't like that.  You could "
        "try stealing maybe.\n");
      return 0;
    }
    s1 = str;
    str = str+" in "+obs->short();
    obs = find_match(s1, obs);
  }
  else
    obs = find_match(str, environment(me));

  if (!sizeof(obs)) 
  {
    notify_fail("Cannot find "+str+".\n");
    return 0;
  }

  skill = me->query_level();
  s_f = t_p = fail = g_f = ({ });

  g_p = (int)me->query_gp();

  for (i=0;i<sizeof(obs);i++)
    if (COST > g_p)
      g_f += ({ obs[i] });
    else if (obs[i]->move(me))
      fail += ({ obs[i] });
    else 
    {
      if ( skill > obs[i]->query_weight() / (random(20)+5) )
        t_p += ({ obs[i] });
      else 
        s_f += ({ obs[i] });
      me->adjust_gp(-COST);
      g_p -= COST;
    }

  if (sizeof(fail) == sizeof(obs)) 
  {
    if (sizeof(g_f))
      notify_fail("You do not have enough guild points to palm "+
        query_multiple_short(g_f)+".\n"
        "You cannot palm "+query_multiple_short(fail)+".\n");
    else
      notify_fail("You cannot palm "+query_multiple_short(fail)+".\n");
    return 0;
  }

  if ( sizeof(fail) )
    tell_object(me, "You cannot palm "+query_multiple_short(fail)+".\n");

  if ( sizeof(g_f) )
    tell_object(me, "You do not have enough guild points to palm "+
      query_multiple_short(g_f)+".\n");

  if ( sizeof(s_f) )
  {
    s1 = query_multiple_short(s_f);
    tell_object(me, "You sorta fumbled palming "+s1+".\n");
    tell_room(environment(me), "You notice "+me->query_cap_name()+
      " palming "+s1+".\n", me);
  }

  tell_object(me, "You palm "+query_multiple_short(t_p)+".\n");

  return 1;
}

string help() 
{
  return 
    "Syntax: palm <objects> [from <object>]\n\n"
    "Will silently pick up an object either from the ground or "
    "from another object.  This ability is level dependent.\n\n"
    "Example:\n"
    "> palm coin\n"
    "You palm the coin.\n"
    "\nSee also:\n  slip\n";
}
