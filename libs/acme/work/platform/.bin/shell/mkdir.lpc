inherit CommandCode;

private variables private functions inherit FileLib;

int do_command(string arg) {
  if (!arg || !strlen(arg)) {
    notify_fail(sprintf("Usage: %s dir\n", query_verb()));
    return 0;
  }

  arg = expand_path(arg, THISP);

  // FUTURE add -p option

  if (file_exists(arg)) {
    printf("%s: %s: File exists.\n", query_verb(), arg);
    return 1;
  }
  if (!mkdir(arg)) {
    printf("%s: %s: Unable to create directory.\n", query_verb(), arg);
    return 1;
  }
  
  return 1;
}
