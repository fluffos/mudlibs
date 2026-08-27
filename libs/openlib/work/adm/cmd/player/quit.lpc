#include <command.h>
#include <daemons.h>

int
main(string arg)
{
  string name;
  object me = this_player();
  object conn = this_player()->query_connection();

  name = (string)me->query_cap_name();

  if( conn )
  {
    conn->set_logout_time(time());
    unguarded((: call_other, conn, "save_connection",
	       this_player()->query_name() :), 1);
  }

  me->force_me("save");
  write("Bye now!\n");
  say(name + " implodes into null space.\n");
  destruct(me);

  return 1;
}
