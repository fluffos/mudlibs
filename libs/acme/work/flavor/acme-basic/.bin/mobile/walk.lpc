inherit CommandCode;

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit ObjectLib;

int do_command(string arg) {
  mixed *args;
  args = getopts(explode_args(arg), "");
  if (!sizeof(args[0])) {
    notify_fail("Walk where?\n");
    return 0;
  }

  // TODO limit number of rooms walkable
  foreach (string dir : args[0]) {
    if (!THISP->exit(dir)) {
      tell_player(THISP, "You stop walking.\n");
      break;
    }
  }
 
  return 1;
}
