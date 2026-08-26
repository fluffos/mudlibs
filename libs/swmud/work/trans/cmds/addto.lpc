//:COMMAND
// >> makes this command a bit obsolete, so it's not updated to use |
#include <mudlib.h>

inherit CMD;

string *lines;

private void main(mixed * arg)
{
   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   if (is_file(arg[0]))
   {
      lines = explode(read_file(arg[0]), "\n");
      out("Adding to: " + arg[0] + "\nuse '.' when done.\n-------------------------------------------------------\n");
      out(implode(lines[<10..<1], "\n") + "\n");
   }
   else
   {
      out("Creating: " + arg[0] + "\nuse '.' when done.\n-------------------------------------------------------\n");
   }

   new(ADDTO_OB)->addto(arg[0]);
}