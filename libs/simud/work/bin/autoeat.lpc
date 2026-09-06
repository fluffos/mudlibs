main(string arg) {
  if (this_player()->query_autoeat()) {
    if (arg == "on" || !arg) {
      msg("You are currently set to automatically eat ~CTIT"+
          this_player()->query_autoeat()+"~CDEF.");
      return 1;
    }
    else if (arg == "off" || arg == "clear" || arg == "none") {
      this_player()->set_autoeat(0);
      msg("Autoeat turned off. You will now have to eat manually.");
      return 1;
    }
    else {
       this_player()->set_autoeat(arg);
       msg("Autoeat turned on. You will now automatically eat ~CTIT"+arg+
        "~CDEF when you start to get hungry.");
    }
  } else {
    if (arg == "on" || !arg) {
      msg("==> [Format] ~CCOMautoeat <food type>~CDEF where food type can "+
          "be something like ~CTITapple~CDEF, ~CTIT2 apples~CDEF, "+
          "~CTITapple from bag~CDEF, etc...",14);
      return 1;
    }
    this_player()->set_autoeat(arg);
    msg("Autoeat turned on. You will now automatically eat ~CTIT"+arg+
        "~CDEF when you start to get hungry.");
  }
  if (this_player()->query_autoeat() && !this_player()->query_autodrink())
    msg("~CCOMNote~CDEF: You are automatically eating when you get hungry, "+
        "but your ~CTITautodrink~CDEF is not currently active.");
  return 1;
}
