int main() {
   if (this_player()->query_level() < WIZLEVEL)
      return 0;

   if (this_player()->query_invis() == 0) {
      this_player()->set_invis(1);
      msg("~CBRTYou are now always ~[060invisible~CBRT to players.~CDEF");
   } else if (this_player()->query_invis() == 1) {
      this_player()->set_invis(2);
      msg("~CBRTYou are now ~[060invisible~CBRT to players only in rooms (see helpfile).~CDEF");
   } else {
      this_player()->set_invis(0);
      msg("~CBRTYou are no longer invisible.~CDEF");
   }

   return 1;
}
