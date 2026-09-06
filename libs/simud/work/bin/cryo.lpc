#include <time.h>

int main(string arg) {
   int *days = this_player()->query_env_var("cryo_days");
   int today = localtime()[TM_WDAY], when;
   string dow, toggle;
   if (!pointerp(days))
      days = ({});
   if (!arg || (arg != "clear" && sscanf(arg,"%s %s",dow,toggle)!=2)) {
      // check if they have cryo options already set, if so, display
      if (sizeof(days)) {
        int x; string buf = "You are currently set to freeze on:\n   ";
        foreach ( x : sort_array(days, #'>) )
           buf += TM_WDAY_STR[x]+", ";
        buf = buf[..<3]; // trim extra comma
        msg(buf);
      } else
        msg("You are not set to freeze on any days");
      msg("Usage: ~CCOMcryo ~CBRT<day of week> <on|off>~CDEF OR ~CCOMcryo clear~CDEF");
      return 1;
   }
   if (member(days,today) != -1) {
      msg("You're supposed to be frozen today! Go away ;)");
      return 1;
   }
   if (arg == "clear") {
      msg("Your cryo list has been cleared");
      days = ({});
   } else { // setting individual days
      when = member(TM_WDAY_STR,dow);
      if (when == -1) {
         msg("You must specify a valid day of the week (ie, monday)");
         return 1;
      }
      if (toggle != "on" && toggle != "off") {
         msg("That's not a valid cryo state, on or off will do.");
         return 1;
      }

      if (toggle == "on") {
         if (member(days,when) != -1) {
            msg("You are already set to freeze on "+dow);
            return 1;
         } else if (sizeof(days) < 6) {
            msg("You will now be prevented from playing on "+dow+". In order to "+
                "unfreeze yourself, you must issue the command on a day when you "+
                "are not frozen.");
            days += ({ when });
         } else {
            msg("I can't let you freeze yourself for the entire week, that's just "+             "silly.");
            return 1;
         }
      } else { // toggle == "off"
         if (member(days,when) == -1) {
            msg("You aren't frozen on "+dow);
            return 1;
         } else {
            msg("You are now unfrozen on "+dow);
            days -= ({ when });
         }
      }
   }
   // actually really make the change ;)
   this_player()->set_env_var("cryo_days",days);
   return 1;
}
