/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND
//$$ see: color, colours, ansi, simplify, emoji, hint
// USAGE
//
//   |  ``hints``
//   |  ``hints on``
//   |  ``hints off``
//   |  ``hints <item>``
//
// ``hints on`` turns on hints for the MUD while you move around. It's highly recommended
// for new or inexperienced players. Some hints may pop up from the rooms you enter, whereas
// others may be from items your have in your inventory - ``hints <item>`` can be used to
// check if there are any hints for a specific items usage.
//
// .. TAGS: RST

inherit CMD;
inherit M_COLOURS;

private
void main(string arg)
{
   if (!arg)
   {
      string hintstate;
      if (get_user_variable("hints") == 1)
         hintstate = "<010>on<res>";
      else
         hintstate = "<009>off<res>";

      out("Hints are " + hintstate + ".\n");
   }

   if (arg == "on")
   {
      object tmp;
      this_user()->query_shell_ob()->set_variable("hints", 1);
      tmp = new ("/domains/std/item/hint_token");
      tmp->move(this_body());
      out("Turning hints on - you received a hint token.\n");
      tmp->hook_func();
   }
   else if (arg == "off")
   {
      this_user()->query_shell_ob()->unset_variable("hints");
      if (present("hint token", this_body()))
      {
         this_body()->do_game_command("drop hint token");
      }
      out("Turning hints off.\n");
   }
   else if (arg && present(arg, this_body()))
   {
      object tmp = present("hint_token", this_body());
      if (get_user_variable("hints") == 0)
         main("on");
      if (!tmp->query_hint())
      {
         write("No hints on that item, sorry.");
         return;
      }
      tmp->hint_from(present(arg, this_body()));
   }
   else
   {
      out("Usage:\n"
          "  hints <on/off> - to turn hints on and off\n"
          "  hints <item>   - to check for hints on a specific item near you\n");
      return;
   }
}

void player_menu_entry(string str)
{
   bare_init();
   main(str);
   done_outputing();
}