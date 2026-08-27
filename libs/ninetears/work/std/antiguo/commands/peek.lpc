#include "tweaks.h"
/* peek.  Look at a player's inventory without being seen doing it.
 * based on cha. */


string help()
{
  return "\nSyntax:  peek <target>\n"
    "Cost: "+PEEK_GP_COST+" GP\n\n"
    "This command allows you to attempt to look at someone's belongings "
    "without being noticed.  Depending on how experienced and "
    "charismatic you are, you may succeed without them noticing, or the "
    "target may notice you but you'll still get a good look, or the "
    "target may notice you and won't give you a chance to see their "
    "equipment.  \n";
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
    notify_fail("Syntax: peek <target>\n");
    return 0;
  }

  ob = (object*)find_match(str, environment(peeker));

  if (!(sizeof(ob)))
  {
    notify_fail("Your target is not here.\n");
    return 0;
  }

  target = ob[0];

  if (!living(target))
  {
    notify_fail("You stare intently at an inanimate object.  Fascinating.\n");
    return 0;
  }

  if ((int)peeker->query_gp() < PEEK_GP_COST )
  {
    notify_fail("You don't have the energy to go peeking around "
      "right now.\n");
    return 0;
  }

  peeker->adjust_gp(-PEEK_GP_COST);

  peeker_roll = (int)peeker->query_level();
  peeker_cha = (int)peeker->query_cha();
  target_save = (int)target->query_level();

  if ( (string)peeker->query_guild_name() == "wizthief" )
    peeker_cha *= 2;

  peek_roll = peeker_cha + random(peeker_roll) - random(target_save);

  switch( peek_roll )
  {
    case 1..1000:
      tell_object(peeker, "You see the following items as you peek at "+
        target->query_cap_name()+": \n"+
        target->query_living_contents(0));
      break;
    case -10..0:
      tell_object(peeker, "You think "+target->query_cap_name()+
        " noticed you looking, but you saw the following items anyway: \n"+
        target->query_living_contents(0));
      tell_object(target,"You notice "+peeker->query_cap_name()+
        " looking intently at your belongings.\n");
      tell_room(environment(peeker), peeker->query_cap_name()+" gets "
        "caught staring at "+target->query_cap_name()+"'s equipment.\n",
        ({ target, peeker }) );
      if (!(interactive(target)))
      {
        tell_room(environment(peeker), target->query_cap_name()+
          " gets angry and attacks.\n");
        target->attack_ob(peeker);
      }
      break;
    default:
      tell_object(peeker, "It seems "+target->query_cap_name()+
        " noticed you staring at "+target->query_objective()+", and you "
        "didn't get a good look at anything.\n");
      tell_object(target,"You notice "+peeker->query_cap_name()+
        " looking intently at your belongings.\n");
      tell_room(environment(peeker), peeker->query_cap_name()+" gets "
        "caught staring at "+target->query_cap_name()+"'s equipment.\n",
        ({ target, peeker }) );
      if (!(interactive(target)))
      {
        tell_room(environment(peeker), target->query_cap_name()+
          " gets angry and attacks.\n");
        target->attack_ob(peeker);
      }
      break;
  }

  return 1;
}
