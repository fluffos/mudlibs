/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust 2-6-94

//: PLAYERCOMMAND
// USAGE
//    ``who [ -w -p ]``
//
// The who command will give you a list of all user's presently logged
// onto the MUD, and whether or not they are idle.
//
// Used with the given arguments you can alter the way who works:
//
//    ``who -w``
// Will show wizards only.
//
//    ``who -p``
// Will show players only.
//
// .. TAGS: RST

#include <playerflags.h>

inherit CMD;
inherit M_FRAME;

string get_who_string(string arg)
{
   object *u;
   int i;
   string name, extra, retval;
   string uptime = time_to_string(uptime() - (uptime() % 3600));
   // If we have bodies() and they have a level>1, the MUD must use levels.
   // This is not set by a DEFINE but a result of implementation in adversary/body.
   int use_levels_guess = sizeof(bodies()) ? bodies()[0]->query_level() > 0 : 0;
   frame_init_user();

   if (uptime == "")
      uptime = "less then an hour";

   extra = retval = "\n";
   if (this_user())
   {
      switch (arg)
      {
      case "-p":
      case "-z":
         u = filter_array(bodies(), ( : !wizardp($1) :));
         extra = accent("(PLAYERS ONLY)");
         break;
      case "-w":
         u = filter_array(bodies(), ( : wizardp:));
         extra = accent("(Wizards only)");
         break;
      case "-i":
         u = filter_array(bodies(), ( : wizardp:));
         extra = accent("(Implementors only)");
         break;
      case "-m":
         if (wizardp(this_user()))
         {
            u = filter_array(children(USER_OB), ( : !interactive($1) :))->query_body();
            extra = accent("(Non-interactives)");
            break;
         }
         /* FALLTHRU */
      default:
         if (arg)
            extra = warning("Unknown flag" + (sizeof(arg) == 2 ? "" : "s") + " '" + arg + "'");
         u = bodies();
         break;
      }
      if (!wizardp(this_user()))
         u = filter_array(u, ( : $1->is_visible() :));
   }
   else
      u = filter_array(bodies(), ( : $1->is_visible() :));

   u -= ({0});
   i = sizeof(u);
   set_frame_title(sprintf("Who - %d user%s", i, (i != 1 ? "s" : "")));
   if (use_levels_guess)
      frame_add_column("Level", map(u->query_level(), ( : "" + $1:)));
   frame_add_column("Role", map(u, ( : (wizardp($1) ? (adminp($1) ? "Admin" : "Wizard") : "") :)));
#ifdef USE_WIZ_POSITION
   frame_add_column("Position", map(u, ( : (wizardp($1) ? $1->query_wiz_position() || "" : "") :)));
#endif
#ifdef USE_INTRODUCTIONS
#ifdef USE_TITLES
   frame_add_column("Title", u->query_title());
#else
   frame_add_column("Name", u->query_name());
#endif
#else
   frame_add_column("Name", u->query_formatted_desc(80));
#endif
   set_frame_footer(sprintf("%s has been up for %s.", mud_name(), uptime));
   return frame_render_columns();
}

private
void main(string arg)
{
   if (arg == "")
      arg = 0;

   out(get_who_string(arg));
}

void player_menu_entry()
{
   bare_init();
   main(0);
   done_outputing();
}
