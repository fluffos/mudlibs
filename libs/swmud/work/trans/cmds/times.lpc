//:COMMAND
// Repeats a command # of times
// Usage:  times <#> <command>
// Rust/Belboz
#include <mudlib.h>

inherit CMD;

void create()
{
   ::create();
   no_redirection();
}

#define USAGE   "Usage:  times <#> <command>\n"

private void main(string orig_input, mixed *arg)
{
   int repeats;
   string command;

   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   command = implode(arg[1]," ");
   repeats = arg[0];

   if (repeats <= 0)
   {
      out("Times: Number of times must be greater than 0.\n");
      return;
   }
   else if ((repeats > 30) && !check_privilege(1))
   {
      out("Times: Cannot execute more than 30 commands at once.\n");
      return;
   }

   while (repeats--)
   {
      this_user()->force_me(command);
   }
}