/* Do not remove the headers from this file! see /USAGE for more info. */
/* Tsath 2022 */

//: PLAYERCOMMAND
//$$ see: color, colours, mode
// USAGE
//
//  |  ``simplify``
//  |  ``simplify on``
//  |  ``simplify off``
//
// Typing ``simplify`` will show if your character is set to ascii like graphics
// from the mud (used for small charts etc). These can be hard to use on
// screen readers, so if you are using a screen reader it can be recommended
// to be ``simplify off``.
//
// .. TAGS: RST

inherit CMD;
inherit M_WIDGETS;

private
void main(string arg)
{
   if (!arg)
   {
      string simplestate;
      if (i_simplify())
         simplestate = "on";
      else
         simplestate = "off";

      out("Simplify is " + simplestate + ".\n");
      return;
   }

   if (arg == "on")
   {
      this_user()->query_shell_ob()->set_variable("simplify", 1);
      out("Turning simplification for screen readers on.\n");
   }
   else if (arg == "off")
   {
      this_user()->query_shell_ob()->unset_variable("simplify");
      out("Turning simplification for screen readers off.\n");
   }
   else
   {
      out("Usage: simplify <on/off>.\n");
      return;
   }
}

void player_menu_entry(string str)
{
   bare_init();
   main(str);
   done_outputing();
}