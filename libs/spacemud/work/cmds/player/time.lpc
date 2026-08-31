/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 * time  -  reports how long the mud has been up.
 * copied from ideaexchange where it was originally
 * created by beek@nightmare
 * copied by zifnab@zorkmud
 */

//: PLAYERCOMMAND
//$$ see: timezone
// USAGE
//   ``time``
//
// Displays the current local time (where the mud server is located),
// and the GMT conversion of that, and player's local time (if the
// GMT offset has been entered using the ``timezone`` command)
// together with time the mud was last rebooted (on mud local time),
// and how long it has been up.
//
// .. TAGS: RST

#include <config/time.h>
#include <localtime.h>

inherit CMD;
inherit M_FRAME;

private
string week_view()
{
   string day = EVENT_D->time_to_weekday();
   string out = "";

   foreach (string d in EVENT_D->week_days())
   {
      out += "[" + (d == day ? "<190>" : "") + d + "<res>] ";
   }
   return out + "\n";
}

private
void main(string notused)
{
   int time = time();
   string restarted_at = ctime(time - uptime());
   string str = "";
   mixed local = localtime(time);
   mixed my_offset;

   my_offset = this_body()->query_tz();
   if (intp(my_offset) || floatp(my_offset))
      my_offset = to_int(3600.0 * my_offset);

#ifdef USE_GAME_TIME
   str += sprintf("<190>%s<res> -  %d game days / real day\n", EVENT_D->time_to_str(), EVENT_D->game_days_per_day());
   str += week_view() + "\n";
#endif
   str += sprintf("%s.\n", ctime(time));
   str += sprintf("%s.\n", ctime(time - local[LT_GMTOFF]));
   my_offset = this_body()->query_tz();
   if (intp(my_offset) || floatp(my_offset))
   {
      my_offset = to_int(3600.0 * my_offset);
      str += sprintf("\n%s.\n", ctime(time + my_offset));
   }
   str += sprintf("\n" + mud_name() + " restarted on " + restarted_at + ". \n");
   str += mud_name() + " has been up for " + time_to_string(uptime());

   str = str[0.. < 2] + ".\n";

   // Create the frame
   frame_init_user();
   set_frame_left_header();

#ifdef USE_GAME_TIME
   set_frame_title("Game Time & Real Time");
   set_frame_header("Game Time\n\n\nLocal MUD\nGMT\n\nTimezone\n\nUptime");
#else
   set_frame_title("Time");
   set_frame_header("Local MUD\nGMT\n\nTimezone\n\nUptime");
#endif

   set_frame_content(str);
   out(frame_render());
}

void player_menu_entry(string str)
{
   bare_init();
   main(str);
   done_outputing();
}
