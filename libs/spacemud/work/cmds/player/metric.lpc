/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND
//$$ see: colours, mode, simplify, emoji
// USAGE
//
//   |  ``metric``
//   |  ``metric on``
//   |  ``metric off``
//
// Typing ``metric`` will show if you are seeing metric system or imperical.
// Typing ``metric on`` or ``metric off`` will turn on/off metric system - not in the real world. Nice try.
//
// .. TAGS: RST

inherit CMD;
inherit M_COLOURS;

private
void main(string arg)
{
   if (!arg)
   {
      string metricstate;
      if (get_user_variable("metric") == 1)
         metricstate = "on";
      else
         metricstate = "off";

      out("Metric is " + metricstate + ".\n");
      return;
   }

   if (arg == "on")
   {
      this_user()->query_shell_ob()->set_variable("metric", 1);
      out("Turning metric on.\n");
   }
   else if (arg == "off")
   {
      this_user()->query_shell_ob()->unset_variable("metric");
      out("Turning metric off.\n");
   }
   else
   {
      out("Usage: metric <on/off>.\n");
      return;
   }
}

void player_menu_entry(string str)
{
   bare_init();
   main(str);
   done_outputing();
}