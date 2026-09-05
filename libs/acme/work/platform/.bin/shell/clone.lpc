inherit CommandCode;

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit FileLib;
private variables private functions inherit ObjectLib;

int do_command(string arg) {
  // TODO add -f option to force
  // XXX messaging?
  mixed *args = getopts(explode_args(arg), "v");

  if (!sizeof(args[0])) {
    notify_fail(sprintf("Usage: %s file\n", query_verb()));
    return 0;
  }

  mixed *files = ({ });
  foreach (string a : args[0]) {
    files += expand_pattern(a, THISP);
  }

  if (!sizeof(files)) {
    printf("%s: %s: No such file.\n", query_verb(), implode(args[0], " "));
    return 1;
  }

  int count = 0;
  string out = "";
  foreach (mixed *f : files) {
    string file = f[0];
    object blueprint = FINDO(file);
    if (!blueprint) {
      string err = catch (blueprint = load_object(file); publish);
      if (err) {
        out += sprintf("%s: %s: Caught error loading file\n", 
                       query_verb(), file); 
        continue;
      } 
    }

    object clone;
    string err = catch (clone = clone_object(blueprint); publish);
    if (err) {
      out += sprintf("%s: %s: Caught error cloning object\n", 
                     query_verb(), file); 
    } else {
      if (!clone->is_room()) { 
        err = catch (move_object(clone, THISP); publish);
        if (err) {
          out += sprintf("%s: %s: Caught error moving to inventory\n", 
                         query_verb(), file); 
        }
      }
      count++;
      if (member(arg, 'v')) {
        out += sprintf("%s: %s: cloned\n", query_verb(), file);
      }
    }
  }
  
  out += sprintf("%s: %s: %d object%s cloned.\n", 
                 query_verb(), implode(args[0], " "), 
                 count, (count != 1 ? "s" : ""));
  tell_player(THISP, out);
  return 1;
}
