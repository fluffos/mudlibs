// Created by Ranma@Koko Wa 1995-10-01
//:COMMAND
// This command will add a new path to your current exec path
#include <mudlib.h>

inherit CMD;

private void main(string * arg)
{
   string userid = this_user()->query_userid();
   string * paths;
   string item;
   object shell_ob = this_user()->query_shell_ob();

   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   if (get_privilege(this_user()) && !check_privilege(userid))
   {
      out("Permission denied.\n");
      return;
   }

   paths = shell_ob->query_path();

   foreach (item in paths)
   {
      if (item == arg[0])
      {
         out("That path has already been added.\n");
         return;
      }
   }

   paths += ({ arg[0] + "/" });
   shell_ob->set_variable("path", paths);

   out(implode(paths, (: $1 + ($2[<1] == '/' ? $2[0..<2] : $2) + ", " :),
      "Your path is now: ")[0..<3] + "\n");
}