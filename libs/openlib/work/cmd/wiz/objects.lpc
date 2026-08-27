/*  -*- LPC -*-  */
#include <command.h>

int
main()
{
  mapping info = ([]);
  string* output = ({ "Objects Loaded:" });

  foreach(object ob in objects()) {
    string file = base_name(ob);

    if(!info[file])
      info[file] = 1;
    else
      info[file]++;
  }

  foreach(string file, int i in info)
    output += ({ sprintf("%-50.50'.'s...%d", file, i) });

  this_player()->more(output);

  return 1;
}
