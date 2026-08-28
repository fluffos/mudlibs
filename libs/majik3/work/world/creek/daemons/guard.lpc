#include "../path.h"

object *guards;

load_guards ()
{
  for (int i=0;i<4;i++)
    {
      if (!guards)
        guards = ({ clone_object (MONSTER_PATH + "cityguard") });
      else
        guards += ({ clone_object (MONSTER_PATH + "cityguard") });
    }
}

wake_guard (object ob)
{
  object guard;
  string *dir;

  if (!guards || sizeof(guards) == 0)
    load_guards();

  guard = guards[random(sizeof(guards))];

  if (objectp(guard) && objectp(ob))
    {
      if (ENV(guard))
        message ("3", guard->query_cap_name() + " runs away.\n", ENV(guard));

      guard->move (ENV(ob));
  
      dir = ENV(guard)->query_exit_dir();

      message ("3", guard->query_cap_name() + " arrives from "+dir[random(sizeof(dir))]+".\n", ENV(guard));
      guard->force_us("say I'll take you, "+ob->query_cap_name()+" - BANZAI!");
      guard->force_us("kill "+ob->query_name()+"");
      ob->add_aligny (-random(25));
    }

  return 1;
}
