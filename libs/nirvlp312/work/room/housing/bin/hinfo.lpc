#include "../defs.h"

int *priv_cost() { return ({ 0, 0 }); }

status
main(string arg, object room, object master)
{
  int i, siz; string text, *lines;

  /* This was for temporary purposes.
  if (!arg || !strlen(arg))
  {
    i = sizeof(lines = get_dir("/players/earwax/housing/help/"));

    while(i--)
      write(lines[i]+"\n");

    return 1;
  }
*/

  if (!arg || !strlen(arg))
    arg = "hinfo";

  arg = implode(explode(lower_case(arg), " "), "_");

  if (file_size(HELPDIR+arg) < 0)
  {
    notify_fail("No help available on that subject.\n");
    return 0;
  }

  write(HIW+"======================================================================\n"+NORM+NORM);
  write(HIK+"Housing System Info: "+arg+"\n");
  write(HIW+"----------------------------------------------------------------------\n"+NORM+NORM);
/* This isn't working properly.
  text = read_file(HELPDIR+arg);
  lines = explode(text, "\n");
  siz = sizeof(lines);

  for (i = 0; i < siz; i++)
    write(lines[i]+"\n");
*/
  cat(HELPDIR+arg);

  write(HIW+"======================================================================\n"+NORM+NORM);

  return 1;
}
