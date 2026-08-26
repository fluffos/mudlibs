#include <mudlib.h>

inherit CMD;

private void main(string* arg)
{
   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   if (mkdir(arg[0]))
   {
      outf("Ok.\n");
   }
   else
   {
      outf("Failed to make directory: %s\n", arg[0]);
   }
}