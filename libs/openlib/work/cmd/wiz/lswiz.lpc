/*  -*- LPC -*-  */
// lswiz.c:  list wizards
// created by Tim 16 Jun 1996

#include <command.h>
#include <daemons.h>

int
main()
{
  string* list = map(sort_array(SECURITY_D->get_wizards(), 1),
		     (: capitalize :));
  string line = "";

  printf("Wizards: (total %d)\n", sizeof(list));

  foreach(string wizard in list[0..<2])
    line += wizard + ", ";
  line += list[<1] + ".";

  line = break_string(line, 60);

  this_player()->more(explode(line, "\n"));
  return 1;
}
