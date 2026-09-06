main(string state) {
   if(state == "on") {
      this_player()->set_ansi(1);
      msg("ANSI codes are ~CBRTON.~CDEF Use the 'termsize' command to set your terminal size.");
   } else if(state == "off") {
      this_player()->set_ansi(0);
      msg("ANSI codes are OFF.");
   } else {
      if(state) msg("==> [Format] ansi <on/off>");
      else {
         if(this_player()->query_ansi())
            msg("==> ANSI is currently ~CBRTON.~CDEF");
         else msg("==> ANSI is currently OFF.");
      }
   }
   return 1;
}
