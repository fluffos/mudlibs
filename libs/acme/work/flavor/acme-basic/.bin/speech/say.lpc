inherit CommandCode;

int do_command(string arg) {
  object env = ENV(THISP);
  // TODO design a formal usage API
  if (!arg || !strlen(arg)) { 
    notify_fail(sprintf("Usage: %s -l language msg\n", query_verb())); 
    return 0; 
  }

  mixed *args = getopts(explode_args(arg, 1), "l:");
  arg = implode(args[0], " ");
  mapping opts = args[1];

  string language = opts['l'] || get_langage();
  if (!is_capable(THISP, CAP_SPEECH)) {
    printf("You are not capable of speech.\n");
    return 1;
  }
  if (!THISP->is_language_spoken(language)) {
    printf("You don't speak the %s language.\n", language);
    return 1;
  }
  
  string topic = "";

  say(msg);
  write(msg);
  object container = env;
  while (container->is_container()) {
    if (!container->is_soundproof()) {
      tell_room(ENV(container), msg, ({ container }));
    }
    write(msg);
    // check if sound passes through container
  }
}

string get_language(object who) {
  // TODO check user preferences
  // TODO check room/zone
  return "default";
}
