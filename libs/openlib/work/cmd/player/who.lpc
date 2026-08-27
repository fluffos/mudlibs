/*  -*- LPC -*-  */
#include <command.h>
#include <login.h>

int
main(string arg)
{
  object user;
  int j;

  write("Players on " + mud_name() + " at " + ctime(time()) +
	" (*edit, +input)\n");
  write(repeat_string("-", this_interactive()->get_env("WIDTH") - 1) + "\n");

  foreach(user in users()) {
    if(user->short())
      write((in_edit(user) ? "*" : " ") + (in_input(user) ? "+" : " ") +
	    (string)user->short()+".\n");
    else
      write("(Someone)\n");
  }

  return 1;
}
