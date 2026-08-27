#include "tweaks.h"
/* peek.  Look at a player's inventory without being seen doing it.
 * based on cha. */


string help()
{
  return "\nSintaxi:  espiar <target>\n"
    "Coste: "+PEEK_GP_COST+" PG\n\n"
    "Este comando te permite espiar el inventario de alguien sin que este "
    "se de cuenta de ello. Dependiendo de lo experienciado que estes y lo "
    "carismatico que seas, podras hacerlo sin que se de cuenta, o el "
    "<target> se dara cuenta pero tu seguiras espiandolo, o el "
    "<target> se dara cuenta y no podras ver su inventario.  \n ";
    
}

int peek(string str, object me)
{
  int peeker_roll, peeker_cha, target_save, peek_roll;
  object* ob;
  object target;
  object peeker = ( me ? me : this_player() );
 
  str = peeker->expand_nickname(str);

  if (!str)
  {
    notify_fail("Sintaxis: espiar <objetivo>\n");
    return 0;
  }

  ob = (object*)find_match(str, environment(peeker));

  if (!(sizeof(ob)))
  {
    notify_fail("Tu objetivo no esta aqui.\n");
    return 0;
  }

  target = ob[0];

  if (!living(target))
  {
    notify_fail("Intentas espiar un objeto inanimado? Fascinante.\n");
    return 0;
  }

  if ((int)peeker->query_gp() < PEEK_GP_COST )
  {
    notify_fail("No tienes ganas ni Pg suficientes para ir espiando por "
      "ahi ahora mismo..\n");
    return 0;
  }

  peeker->adjust_gp(-PEEK_GP_COST);

  peeker_roll = (int)peeker->query_level();
  peeker_cha = (int)peeker->query_cha();
  target_save = (int)target->query_level();

  if ( (string)peeker->query_guild_name() == "Mago-Guerrero" )
    peeker_cha *= 2;

  peek_roll = peeker_cha + random(peeker_roll) - random(target_save);

  switch( peek_roll )
  {
    case 1..1000:
      tell_object(peeker, "Ves los siguientes objetos cuando hurtas en "+
        target->query_cap_name()+": \n"+
        target->query_living_contents(0));
      break;
    case -10..0:
      tell_object(peeker, "Ves que "+target->query_cap_name()+
        " se nota que le miras, pero sigues viendo lo siguiente: \n"+
        target->query_living_contents(0));
      tell_object(target,"Ves que "+peeker->query_cap_name()+
        " mira curiosamente tus pertenencias.\n");
      tell_room(environment(peeker), peeker->query_cap_name()+" pilla "
        "espiando al equipo de "+target->query_cap_name()+".\n",
        ({ target, peeker }) );
      if (!(interactive(target)))
      {
        tell_room(environment(peeker), target->query_cap_name()+
          " se molesta y ataca.\n");
        target->attack_ob(peeker);
      }
      break;
    default:
      tell_object(peeker, "Parece que "+target->query_cap_name()+
        " se dio cuenta que le espiabas "
        "y no has podido verle nada.\n");
      tell_object(target,"Notas a "+peeker->query_cap_name()+
        " mirar curiosamente tus pertenencias.\n");
      tell_room(environment(peeker), peeker->query_cap_name()+" pilla "
        "espiando en las pertenencias de "+target->query_cap_name()+".\n",
        ({ target, peeker }) );
      if (!(interactive(target)))
      {
        tell_room(environment(peeker), target->query_cap_name()+
          " se da cuenta y te ataca.\n");
        target->attack_ob(peeker);
      }
      break;
  }

  return 1;
}
