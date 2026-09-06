int main(string arg) {
   mapping spells = this_player()->query_known_spells();
   if (!arg)
      return notify_fail("Syntax: forget <spell>\n");
   if (!member(spells, arg))
      return notify_fail("You do not know any spell by that name.\n");
   spells -= ([ arg ]);
   this_player()->set_known_spells( spells );
   msg("~CBRTYou have forgotten how to cast the ~[060"+arg+"~CBRT spell.~CDEF");
   return 1;
}
