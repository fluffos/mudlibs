
#include "money.h"
int fix(string str,object fixer)
{
  object *obs, *too_poor, *ok, *fail;
  int w_skill, a_skill, low_c, max_c, high_c, total_cost, per, i, diff, val;
  if(!fixer) fixer = this_player();
  if (!str)
  {
    notify_fail("Sintaxis: reparar <armadura(s)/arma(s)>\n"
		"Necesitas estar en una herreria.\n");
    return 0;
  }
  if (!environment(fixer)->query_property("smithy"))
  {
    notify_fail("Si no estas en una herreria no puedes arreglar nada.\n");
    return 0;
  }
  obs = find_match(str, fixer); /* can only fix things your
					 * holding */
  obs = filter_array(obs, "check_arm_or_weap", this_object());
  if (!sizeof(obs))
  {
    notify_fail("Necesitas arrglar algo ahora.\n");
    return 0;
  }
  if(fixer->query_value()==0)
      { notify_fail("No tienes dinero para arreglar nada.\n");
        return 0;
      }

  a_skill = (int)this_player()->query_level() * 10;
  if(a_skill > 90) a_skill = 90;
     ok = too_poor = fail = ({ });
  val = (int)this_player()->query_value();
  for (i=0;i<sizeof(obs);i++)
  {
    low_c = (int)obs[i]->query_lowest_cond();
    max_c = (int)obs[i]->query_max_cond();
    diff = (int)obs[i]->query_cond();
    val = obs[i]->query_value();
    diff = ((diff - low_c)*100)/max_c;
    if (diff < 0) diff = 0;
    if (!diff)
    {
      fail += ({ obs[i] });
      continue;
    }
    val = (diff * val)/100;
    val = (val * (100 - a_skill))/100;
    if (val < (diff*10)/100 + total_cost) {
      too_poor += ({ obs[i] });
      continue;
    }
    ok += ({ obs[i] });
    obs[i]->adjust_cond(1);
    total_cost += val;
  }
  if (total_cost)
    fixer->pay_money((mixed*)MONEY_HAND->create_money_array(total_cost));
  if (sizeof(fail))
    tell_object(fixer,"Fallas al reparar "+query_multiple_short(fail)+".\n");


  if (sizeof(too_poor))
   { tell_object(fixer,"Estas muy pobre para comprar recursos materiales para reparar "+
	  query_multiple_short(too_poor)+".\n");
     return 0;
   }
  if (sizeof(ok))
  {
    tell_object(fixer,"Reparas "+query_multiple_short(ok)+" por un coste de "+
	  MONEY_HAND->money_value_string(total_cost)+".\n");
    tell_room(environment(fixer),fixer->query_cap_name()+" repara "+
    query_multiple_short(ok)+".\n",fixer);
  }
  return 1;
}
int check_arm_or_weap(object ob)
{
  return (int)ob->query_weapon() || (int)ob->query_armour();
}
string help()
{
  return
"Sintaxis: reparar <objetos>\n\n"
"Este comando te permite reparar armas y armaduras danyadas.  Usar "
"armas y armaduras en combate deteriora su estado. Usando este comando "
"puedes reparar el estado del arma o armadura para que te de mas "
"proteccion o hagan mas danyo. Te cuesta 10 monedas d cobre por punto "
"de estado que reparas y necesitaras estar dentro de una herreria para "
"hacerlo. Solo puedes reparar un arma o armadura hasta que alcance su "
"estado mas alto y pudiendo reparala desde su estado ma bajo.\n\n"
"Ejemplos:\n"
"> reparar espada\n"
"Reparas una espada larga por 6 monedas de plata.\n";
}

