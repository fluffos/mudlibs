/* Do not remove the headers from this file! see /USAGE for more info. */

//  Yaynu@Lima Bean

//: PLAYERCOMMAND
//$$see: color, colours, simplify
// USAGE
//
//   |  ``mode``
//   |  ``mode plain``
//   |  ``mode vt100``
//   |  ``mode xterm``
//   |  ``mode ansi``
//
// Typing ``mode`` will show if your character is set to receive ansi codes
// from the MUD (used to display colours).
//
// .. TAGS: RST

inherit CMD;
inherit M_COLOURS;

private
void main(string arg)
{
   string *modes = ({"plain", "vt100", "ansi", "xterm"});
   string term_type = this_user()->query_terminal_type() || "unknown";
   int suggestion = member_array(XTERM256_D->client_compatibility(term_type), modes);
   if (!arg)
   {
      string termmode;
      int mode_index;
      if (terminal_mode())
         termmode = terminal_mode();
      else
         termmode = "plain";

      mode_index = member_array(termmode, modes);

      out("Terminal mode is '" + termmode + "'.\n");
      if (mode_index == -1 || suggestion == -1)
         return;
      if (mode_index < suggestion)
         out("Your " + capitalize(term_type) + " client is even capable of '" + modes[suggestion] +
             "'. Consider switching.\n");
      else if (mode_index > suggestion)
         out("Your " + capitalize(term_type) + " client only capable of '" + modes[suggestion] +
             "'. Switch if you have issues.\nTry the 'palette' command and verify you can see 256 colours.\n");
      else
         out("Your " + capitalize(term_type) + " client fully supports this mode.\n");
      return;
   }

   if (arg == "vt100" || arg == "ansi" || arg == "xterm")
   {
      this_user()->query_shell_ob()->set_variable("mode", arg);
      out("Setting mode to '" + arg + "'.\n");
   }
   else if (arg == "off" || arg == "plain")
   {
      this_user()->query_shell_ob()->unset_variable("mode");
      out("Setting mode to 'plain'.\n");
   }
   else
   {
      out("Usage: mode <plain|vt100|ansi|xterm>.\n");
      return;
   }
   this_user()->update_translations();
}

void player_menu_entry(string str)
{
   bare_init();
   main(str);
   done_outputing();
}