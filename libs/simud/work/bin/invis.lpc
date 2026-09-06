int main(string param) {
   int new_invis;

   if (this_player()->query_level() < WIZLEVEL)
      return 0;

   if (param) {
      sscanf(param, "%d", new_invis);
      debug("param: " + param, "gp");
   } else {
      debug("param 0", "gp");
      new_invis = (this_player()->query_invis() + 1) % 3;
   }


   switch(new_invis) {
   case 0:
      this_player()->set_invis(0);
      msg("~CBRTYou are no longer invisible.~CDEF");
      break;

   case 1:
      this_player()->set_invis(1);
      msg("~CBRTYou are now always ~[060invisible~CBRT to players.~CDEF");
      break;

   case 2:
      this_player()->set_invis(2);
      msg("~CBRTYou are now ~[060invisible~CBRT to players only in rooms (see helpfile).~CDEF");
      break;

   default:
      msg("Invalid invisibility setting, current setting unchanged.");
   }

   return 1;
}
