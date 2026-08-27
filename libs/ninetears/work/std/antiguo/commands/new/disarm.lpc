
/* Rage '94 - disarm cmd for fighters */
/* Redone '95, Rage */

#include "tweaks.h"

string help()
{
  return "\nSintaxis: desarmar <objetivo>\n"
    "Coste: "+GPCOST_DISARM+" Pg\n"
    "Duracion: Necesitas "+HBLOCKOUT_DISARM+" heartbeats to restore power.\n"
    "     When you disarm a target, you will try to reach out and grab your "
    "target's weapon. If your target is not holding any weapons, nothing will "
    "happen. If your target is holding two weapons, you can only grab one "
    "weapon at a time.\n"
    "     You can both disarm during combat with your target, "
    "and also before fighting your target. Even should you succeed "
    "in disarming a target you are not fighting with, your target will "
    " attack you, the weapon falling to the ground. If you fail to disarm a "
    "target you are not fighting with, there is a large chance that the "
    "target will attack you, seeing what you were trying to do. If you "
    "succeed in disarming, there is a little chance of the weapon being "
    "destroyed by the disarm. This will happen because the weapon is "
    "dragged out of the target's hands so tremendously hard that the "
    "weapon is crushed into the ground.\n"
    "     If your hitpoints are below half of your maximum, you will be too "
    "tired to disarm.\n"
    "     Chance of success is based upon you and your target's strength, "
    "dexterity, level, and a random bonus. A strong and quick person will be "
    "better at disarming than a weak and slow person.\n";
}

int chance(object me,object ob);

int disarm(string str,object x)
{
  object *ob, tar;
  int i;
  int hold;
  object *fuk;
  int cnt;
  object me;

  if(x) 
    me = x;
  else 
    me = this_player();

  hold = 0;    /* gets set to 1 in the loop if target holds any weapons */

  if (!str) 
  {
    tell_object(me,"Desarmar a quien?\n");  /* no string, no dude */
    return 1;
  }

  str = lower_case(str);
  str = (string)me->expand_nickname(str);

  if (str == ((string)me->query_name())) 
  {
    tell_object(me,"No puedes desarmarte a ti mismo.\n");
    return 1;
  }

  fuk = find_match(str, environment(me));
  for (cnt = 0; cnt < sizeof(fuk); cnt++)
    if (((int)fuk[cnt]->query_level() > 0) && living(fuk[cnt]))
    {
      tar = fuk[cnt];
      break;
    }

  if (!tar) 
  {
    tell_object(me,capitalize (str)+ " No esta visible aqui.\n");
    return 1;
  }

  if ((int)me->query_timed_property("dis") == 1)
  {
    tell_object(me,"La parte tactica de tu habilidad necesita un poco "
      "de reposo antes de que puedes desarmar otra vez.\n");
    return 1;
  }
  if ((int)me->query_gp() < GPCOST_DISARM) 
  {
    tell_object(me,"Lo siento, no tienes bastantes puntos de gremio para desarmar.\n");
    return 1;
  }
  if ((int)me->query_hp() < (int)me->query_max_hp() / 2)
  {
    tell_object(me,"Estas demasiado cansado para desarmar.\n");
    return 1;
  }

  if ( tar->query_creator() )
  {
    tell_object(me, "Desarmar a un inmortal no es buena idea.\n");
    return 1;
  }
  ob = (mixed *) tar->query_held_ob();

  for (i=0; i<sizeof(ob); i++) 
    if ((int)tar->is_weapon(ob[i]) == 1)
    {
      me->adjust_gp(-(GPCOST_DISARM));
      me->add_timed_property("dis", 1, HBLOCKOUT_DISARM);
      if (chance(me,tar) == 1)
      {             /* success */
        tell_object(me,"Golpeas la "+ob[i]->query_short()+ " de "+
           tar->query_cap_name()+ " tirandola al suelo.\n");
        tell_room(environment(tar), me->query_cap_name()+ " golpea la "+
          ob[i]->query_short()+ " de "+
          tar->query_cap_name()+ " tirandola al suelo.\n", ({ tar, me }));
        tell_object(tar, me->query_cap_name()+ " golpea tu "+  
          ob[i]->query_short()+ " tirandola al suelo.\n");
  
        if (random(100) > 94)
        {
          tell_object(me,capitalize (ob[i]->query_short())+ " se destruye "
            "por el golpe!\n");
          tell_room(environment(tar),capitalize (ob[i]->query_short())+ 
            " se destruye por el golpe!\n", ({tar, me }));
          tell_object(tar,capitalize (ob[i]->query_short())+ 
            " se destruye por el golpe que recibe!\n");
          ob[i]->dest_me();
        }
        else
          ob[i]->move(environment(tar));
  
        hold = 1;
        break;
      }
      else 
      {                   /* failure */
        tell_object(me,"Fallas al golpear la "+ob[i]->query_short() + " de "+
          tar->query_cap_name()+ " para intentar desarmarle.\n");
        tell_room(environment(tar), me->query_cap_name()+ " falla al golpear la "+
          ob[i]->query_short()+ " de "+
          tar->query_cap_name()+ " al intentar desarmarle.\n", ({ tar, me }));
        tell_object(tar, me->query_cap_name()+ " intenta golpear tu "+  
          ob[i]->query_short()+ " para tirarla al suelo.\n");
        hold = 1;
        if (random(100) > 50) 
        {
          tell_object(me, tar->query_cap_name()+ " se vuelve loco y ataca.\n");
          tar->attack_by(me);
        }
        break;
      }
    } /* end if, for */

  if (hold != 1) 
  {    /* ooops, your target wasn't holding any weps */
    tell_object(me,tar->query_cap_name()+ " no esta empunyando un arma.\n"); 
    return 1;
  }
  else if ( !interactive(tar) )
    tar->attack_by(me);

  return 1;

}


int chance(object me,object ob)
{
  int def, att;

  if ( ob->query_property("nodisarm") )
    return 0;

  att = ((int)me->query_str() * 2);
  att += (int)me->query_dex();
  att += ((int)me->query_level() + random(10));

  def = ((int)ob->query_dex() * 2);
  def += (int)ob->query_str();
  def += ((int)ob->query_level() + random(10));

  if (def > att + 10) 
    ob->adjust_xp(50);
  if (att > def + 10) 
    me->adjust_xp(50);

  if (def > att + 20) 
    ob->adjust_xp(50);
  if (att > def + 20) 
    me->adjust_xp(50);

  if (att > def) 
    return 1;
  else 
    return 0;

}
