// Created by Ranma@Koko Wa 1995-10-01
// This command will show you your current exec path
#include <mudlib.h>

inherit CMD;

private void main() 
{
   string * paths = this_user()->query_shell_ob()->query_path();

   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   out("Your current path is: " + implode(paths, (: $1 + ", " + $2 :)) + "\n");
}