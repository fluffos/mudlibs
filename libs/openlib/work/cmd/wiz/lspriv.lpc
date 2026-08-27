/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

int
main()
{
  mixed* list = SECURITY_D->get_privs();
  string line = "";

  list = filter(list, (: intp :)) + sort_array(filter(list, (: stringp :)), 1);

  line = sprintf("Privileges: (total %d)\n", sizeof(list));

  foreach(mixed priv in list)
  {
    line += sprintf("%-10s -> ( %s )\n",
		    sprint_priv(priv),
		    implode(SECURITY_D->get_opened_list(priv), " "));
  }

  line = break_string(line, 60);

  this_player()->more(explode(line, "\n"));
  return 1;
}
