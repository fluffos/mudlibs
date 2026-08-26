#include <mudlib.h>
inherit CMD;

void main(mixed param)
{
   if (!param)
   {
      int setting = to_int(this_user()->query_shell_ob()->get_variable("assume first"));

      if (setting)
      {
         out("When your commands could apply to more than one object, the MUD will assume you mean the first object.\n");
      }
      else
      {
         out("When your commands could apply to more than one object, the MUD will ask you which one you mean.\n");
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
      this_user()->query_shell_ob()->set_variable("assume first", 1);
      out("The MUD will now assume that you mean the first object if there is any ambiguity.\n");
   }
   else if (param == "off")
   {
      this_user()->query_shell_ob()->set_variable("assume first", 0);
      out("The MUD will now ask which object you mean if there is any ambiguity.\n");
   }
}