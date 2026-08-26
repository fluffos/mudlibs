// Created by Ranma@Koko Wa 1995-10-01
// This command will remove a path from your current exec path
#include <mudlib.h>

inherit CMD;

private void main(string * arg)
{
   string path;
   string * paths;
   object shell_ob;

   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   path = arg[0];
   shell_ob = this_user()->query_shell_ob();
   paths = shell_ob->query_path();

   if (member_array(path, paths) == -1)
   {
      out("The path does not exist in your current path\n");
      return;
   }

   paths -= ({ path });
   shell_ob->set_variable("path", paths);

   out(implode(paths, (: $1 + $2[0..<1] + ", " :), "Your path is now: ")[0..<3] + "\n");
}