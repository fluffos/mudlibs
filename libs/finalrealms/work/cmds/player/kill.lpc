
/* kill command from player.c externalized by Baldrick.
 */

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
        position = 0;
}

string query_usage()
{
        return "kill <targets>";
}

string query_short_help()
{
        return "Starts attacking the specified targets.";
}

protected int cmd (string str, object me)
{
  int i;
  object *obs;

  if (!str || str == "")
    {
    notify_fail("Usage: kill <object>\n");
    return 0;
    }

  str = lower_case(str);

  if (str=="all" || str[0..0] == "0")
    {
    notify_fail("Sorry, not allowed.\n");
    return 0;
    }

  // Fix by Wonderflug.  Ghosts shouldn't attack :)
  if ( me->query_dead() )
  {
    notify_fail("Alas, your etherealness has little effect on "
      "the material world.\n");
    return 0;
  }
obs = find_match(str, environment(me));
 //obs = find_living(str, environment());
  if (!sizeof(obs) || obs[0]->query_hidden() == 1)
    {
    notify_fail("Cannot find "+str+"\n");
    return 0;
    }

/* Notice that there is no check for living().  One can attack anything.
 * Should have..
 */

  if (obs[0]==me)
    {
    notify_fail("Why commit suicide?\n");
    return 0;
    }
  if(!obs[0]->query_alive())
  {
    notify_fail("You begin to hack away at "+str+", but "+str+" doesn't "
		"seem to notice.\n");
    return 0;
  }
  for (i=0;i<sizeof(obs);i++)
  {
// Taniwha 1995, make sure the targets are alive
    if(obs[i]->query_alive())
       me->attack_ob(obs[i]);
    if(obs[i]->query_statue())
      log_file("LINK", ctime(time())+" "+me->query_cap_name()+" attacked "+
                obs[i]->query_cap_name()+".\n");
    if (interactive(obs[i]))
      log_attack(me->query_name(), me->query_level(), obs[i]->query_name(),
               obs[i]->query_level());
  }
  write("Ok.  Fight with "+str+" starts.\n");
  return 1;
}
