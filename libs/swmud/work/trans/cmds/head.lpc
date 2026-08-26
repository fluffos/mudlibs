//:COMMAND
// Prints out the top few lines of a file
// The specification is: head file *
// We will recieve: ({ array of file names })
#include <mudlib.h>

inherit CMD;

void tail(string file, int n)
{
   out(implode(explode(read_file(file), "\n")[0..(n - 1)], "\n"));
}

private void main( mixed *arg, mapping flags, string stdin )
{
   int i;
   int n = 10;

   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   if (flags["n"])
   {
      n = (to_int(flags["n"]) || 10);
   }

   if (stdin)
   {
      out(implode(explode(stdin, "\n")[0..(n - 1)], "\n"));
      return;
   }

   for (i = 0; i < sizeof(arg[0]); i++)
   {
      tail(arg[0][i], n);
   }
}