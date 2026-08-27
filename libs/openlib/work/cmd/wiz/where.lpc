/*  -*- LPC -*-  */
// where.c   print locations of all users
//   Orig by Tim...someone else can pretty this up
//
#include <command.h>

int
main()
{
  object ob;

  write("User                         Where\n");

  foreach(ob in users()) {
    printf("%-10s               %O\n",
	   ob->query_cap_name(),
	   environment(ob));
  }

  return 1;
}
