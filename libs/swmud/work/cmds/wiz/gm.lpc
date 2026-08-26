#include <mudlib.h>
inherit CMD;

void main(mixed param)
{
   if (!wizardp(this_user()))
   {
      out("This command is for wizard use only.\n");

      return;
   }

   if (!param)
   {
      string setting = this_user()->query_shell_ob()->get_variable("god mode");

      if (setting == "on")
      {
         out("God mode is on.\n");
      }
      else
      {
         out("God mode is off.\n");
      }

      return;
   }
   else if ((param != "on") && (param != "off"))
   {
      out("Option must be either \"on\" or \"off\".\n");
      return;
   }

   if (param == "on")
   {
      this_user()->query_shell_ob()->set_variable("god mode", "on");
      out("God mode is now on.\n");
   }
   else if (param == "off")
   {
      this_user()->query_shell_ob()->set_variable("god mode", 0);
      out("God mode is now off.\n");
   }
}