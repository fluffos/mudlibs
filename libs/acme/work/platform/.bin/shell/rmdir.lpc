inherit CommandCode;

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit FileLib;

int do_command(string arg) {
  mixed *args = getopts(explode_args(arg), "v");

  string *files = ({ });
  foreach (string a : args[0]) {
    string *f = expand_pattern(a, THISP);
    if (!sizeof(f)) {
      printf("%s: %s: No such file.\n", query_verb(), a);
      return 1;
    }
    files += f;
  }

  int count = 0;
  foreach (string file : files) {
    if (!is_directory(file)) {
      printf("%s: %s: use rm to remove regular files.\n", query_verb(), file);
      continue;
    }

    if (!rmdir(file)) {
      printf("%s: %s: Unable to remove directory.\n", query_verb(), file);
      continue;
    }

    if (member(args[1], 'v')) {
      printf("%s: removed %s\n", file);
    }
    count++;
  }

  printf("%s: removed %d director%s", 
         query_verb(), count, (count == 1 ? "y" : "ies"));
  return 1;
}
