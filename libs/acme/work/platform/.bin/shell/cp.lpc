inherit CommandCode;

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit FileLib;

int do_command(string arg) {
  mixed *args = getopts(explode_args(arg), "fv");

  if (sizeof(args[0]) < 2) {
    notify_fail(sprintf("Usage: %s srcfile dest\n", query_verb()));
    return 0;
  }

  string *src = expand_pattern(args[0][0], THISP);
  if (!sizeof(src)) {
    printf("%s: %s: no such file.\n", query_verb(), args[0][0]);
    return 1;
  }

  string dest = expand_path(args[0][1]);

  int count = 0;
  foreach (string file : src) {
    if (!member(args[1], 'f')) {
      if (is_directory(dest)) {
        // FIXME munge dirname
        string f = sprintf("%s/%s", dest, basename(file));
        if (file_exists(f)) {
          printf("%s: %s: destination file exists, use -f to force", 
            query_verb(), f);
          return 1;
        } 
      } else {
        if (file_exists(dest)) {
          printf("%s: %s: destination file exists, use -f to force", 
            query_verb(), dest);
          return 1;
        } 
      }
    }

    if (copy_file(file, dest)) {
      printf("%s: %s: permission denied", query_verb(), dest);
      continue;
    } else if (member(args[1], 'v')) {
      printf("%s: %s -> %s\n", query_verb(), file, dest);
    }
    count++;
  }

  printf("%s: %d file%s copied\n", query_verb(), count, 
                                   (count != 1 ? "s" : ""));
  return 1;
}
