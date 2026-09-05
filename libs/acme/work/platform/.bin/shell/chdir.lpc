inherit CommandCode;

private variables private functions inherit FileLib;

mixed *query_actions() {
  return ({ ({ "chdir", 0 }), ({ "cd", 0 }) });
}

int do_command(string arg) {
  if (!arg || !strlen(arg)) {
    arg = HomeDir +"/" + UNAME;
  }
  
  arg = expand_path(arg, THISP);
  if ((arg[<1] == '/') && (arg != "/")) {
    arg = arg[0..<2];
  }

  if (!file_exists(arg)) {
    printf("%s: %s: no such directory or permission denied.\n", 
      query_verb(), arg);
    return 1;
  }
  THISP->set_cwd(arg);
  return 1;
}
