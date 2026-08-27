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
    notify_fail("Sintaxi: hurtar <objetos> [de <objeto>]\n");
    return 0;
  }
  
  if (sscanf(str, "%s de %s", str, s1) == 2) 
  {
    obs = find_match(s1, environment(me));
    if ( !sizeof(obs) )
    {
      notify_fail("No encuentro "+s1+".\n");
      return 0;
    }
    else
      obs = obs[0];

    if ( living(obs) )
    {
      notify_fail(obs->query_cap_name()+" no le gustaria eso. Podrias intentar "
        "sigilar tal vez.\n");
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
    notify_fail("No encuentro "+str+".\n");
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
      notify_fail("No tienes suficientes puntos de guild para hurtar "+
        query_multiple_short(g_f)+".\n"
        "No puedes hurtar "+query_multiple_short(fail)+".\n");
    else
      notify_fail("No puedes hurtar "+query_multiple_short(fail)+".\n");
    return 0;
  }

  if ( sizeof(fail) )
    tell_object(me, "No puedes hurtar "+query_multiple_short(fail)+".\n");

  if ( sizeof(g_f) )
    tell_object(me, "No tienes suficientes puntos de guild para hurtar "+
      query_multiple_short(g_f)+".\n");

  if ( sizeof(s_f) )
  {
    s1 = query_multiple_short(s_f);
    tell_object(me, "Comienzas a hurtar "+s1+".\n");
    tell_room(environment(me), "Notas a "+me->query_cap_name()+
      " hurtando "+s1+".\n", me);
  }

  tell_object(me, "Hurtas "+query_multiple_short(t_p)+".\n");

  return 1;
}

string help() 
{
  return 
    "Sintaxi: hurtar <objetos> [de <objeto>]\n\n"
    "Hurtaras silenciosamente un objeto del suelo o de alguien.\n\n "
    "Ejemplo:\n"
    "> hurtar moneda\n"
    "Hurtas 1 moneda.\n";
    
}
