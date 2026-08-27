/* allows someone to quitely pick something up.  Is based on the objects
 * bulk.  It is hard to palmn something big ;)
 */
#define COST 3

int slip(string str, object doer)
{
  mixed obs;
  object *obs2, *fail, *t_p, *g_f, *s_f;
  object me;
  int i, j, skill, g_p;
  string s1;

  me = me ? me : this_player();

  str = me->expand_nickname(str);

  if (!str) 
  {
    notify_fail("Sintaxis: introducir <objeto> en <objeto>\n");
    return 0;
  }
  
  if (sscanf(str, "%s en %s", str, s1) != 2) 
  {
    notify_fail("Sintaxis: introducir <objeto> en <objeto>\n");
    return 0;
  }

  obs = find_match(s1, environment(me));
  if (!sizeof(obs)) 
  {
    notify_fail("Introducir a quien?\n");
    return 0;
  }

  obs = obs[0];
  skill = (int)me->query_level();
  g_p = (int)me->query_gp();

  t_p = fail = g_f = s_f = ({ });
  obs2 = find_match(str, me);
  for (j=0;j<sizeof(obs2);j++)
  {
    if (obs2[j]->query_in_use())
    {
      me->unhold_ob(obs2[j]);
      me->unwear_ob(obs2[j]);
    }
    if (COST > g_p)
      g_f += ({ obs2[j] });
    else if (obs2[j]->move(obs))
      fail += ({ obs2[j] });
    else 
    {
      if ( obs->query_property("sense_life") ||
           skill < random(obs2[j]->query_weight())+random(10))
        s_f += ({ obs2[j] });
      else
        t_p += ({ obs2[j] });
      me->adjust_gp(-COST);
      g_p -= COST;
    }
  }

  if (sizeof(fail))
    tell_object(me, "No puedes introducir "+query_multiple_short(fail)+
      " en "+obs->query_cap_name()+".\n");

  if (sizeof(g_f))
    tell_object(me, "No tienes Pg para introducir "+
      query_multiple_short(g_f)+" en "+obs->query_cap_name()+".\n");

  if (sizeof(t_p)) 
    tell_object(me, "Introduces "+query_multiple_short(t_p)+
      " en "+obs->query_cap_name()+".\n");

  if (sizeof(s_f))
  {
    tell_room(environment(me), me->query_cap_name()+" intentas introducir "+
      query_multiple_short(s_f)+" en "+obs->query_cap_name()+".\n",
      ({ me, obs }));
    tell_object(obs, me->query_cap_name()+" intenta introducir "+
      query_multiple_short(s_f)+" en ti.\n");
    if ( !interactive(obs) )
    {
      tell_room(environment(me), obs->query_cap_name()+" no parece "
        "demasiado contento.\n", ({ }) );
      obs->attack_by(me);
    }
  }

  return 1;
}

string help() 
{
  return 
    "Sintaxis: introducir <objetos> en <objetos>\n\n"
    "Este comando te permite introducir cosas en jugadores o contenedores "
    "sin generar ningun mensaje.  Usar este comando te "
    "costara "+COST+" puntos de gremio por cada objeto que introduces en "
    "alguien/algo.  Usa el nivel para determinar el exito.\n\n";
    
}
