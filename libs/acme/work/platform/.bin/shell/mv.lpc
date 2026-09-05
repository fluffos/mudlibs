inherit CommandCode;

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit FileLib;

int do_command(string arg) {
  mixed *args = getopts(explode_args(arg), "f");

  if (sizeof(args[0]) < 2) {
    notify_fail(sprintf("Usage: %s srcfile dest\n", query_verb()));
    return 0;
  }

  if (!file_exists(args[0][0])) {
    printf("%s: %s: no such file.\n", query_verb(), args[0][1]);
    return 1;
  }

  if (!member(args[1], 'f')) {
    if (is_directory(args[0][1])) {
      // FIXME munge dirname
      if (file_exists(sprintf("%s/%s", args[0][1], basename(args[0][0])))) {
        printf("%s: %s: destination file exists, use -f to force", 
          query_verb(), args[0][1]);
        return 1;
      } 
    } else {
      if (file_exists(args[0][1])) {
        printf("%s: %s: destination file exists, use -f to force", 
          query_verb(), args[0][1]);
        return 1;
      } 
    }
  }

  if (rename(args[0][0], args[0][1])) {
    printf("%s: %s: permission denied", query_verb(), args[0][1]);
    return 1;
  }

  return 1;
}
