#include <command.h>
#include <net/daemons.h>

int
main()
{
  mixed* list = FTP_D->query_connections();

  message("system", "Name          Privilege     From Host\n"
	            "------------------------------------------------------\n",
	  this_player());

  foreach(string* info in list)
    message("system", sprintf("%-:12s  %-12s  %s\n",
			      info[0], sprint_priv(info[1]), info[2]),
	    this_player());
  return 1;
}
