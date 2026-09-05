inherit CommandCode;

private variables private functions inherit FileLib;

int do_command(string arg) {
  // FUTURE figure out what to do when called argless

  if (!arg || !strlen(arg)) {
    notify_fail(sprintf("Usage: %s file\n", query_verb()));
    return 0;
  }

  arg = expand_path(arg, THISP);

  ed(arg);
  return 1;
}
