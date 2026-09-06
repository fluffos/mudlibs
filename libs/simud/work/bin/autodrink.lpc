

main(string arg) {
  if (this_player()->query_autodrink()) {
    if (arg == "on" || !arg) {
      msg("You are currently set to automatically drink ~CTIT"+
          this_player()->query_autodrink()+"~CDEF.");
      return 1;
    }
    if (arg == "off" || arg == "clear" || arg == "none") {
      this_player()->set_autodrink(0);
      msg("Autodrink turned off. You will now have to drink manually.");
      return 1;
    }
    this_player()->set_autodrink(arg);
    msg("Autodrink turned on. You will now automatically drink ~CTIT"+arg+
        "~CDEF when you start to get thirsty.");
  } else {
    if (arg == "on" || !arg) {
      msg("==> [Format] ~CCOMautodrink <drink type>~CDEF where drink type "+
          "can be something like ~CTITbottle~CDEF, ~CTIT2 bottles~CDEF, "+
          "~CTITbottle from bag~CDEF, etc...",14);
      return 1;
    }
    this_player()->set_autodrink(arg);
    msg("Autodrink turned on. You will now automatically drink ~CTIT"+arg+
        "~CDEF when you start to get thirsty.");
  }
  if (!this_player()->query_autoeat() && this_player()->query_autodrink())
    msg("~CCOMNote~CDEF: You are automatically drinking when you get "+
        "thirsty, but your ~CTITautoeat~CDEF is not currently active.");
  return 1;
}