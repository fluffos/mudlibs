inherit CommandCode;

#include <expand_object.h>

#define DEFAULT_CONTEXT        "(here,me)"

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit ObjectExpansionLib;

int do_command(string arg) {
  // TODO add -f option to force
  // XXX messaging?
  mixed *args;
  args = getopts(explode_args(arg), "");
  if (sizeof(args[0]) < 1) {
    notify_fail(sprintf("Usage: %s target\n", query_verb()));
    return 0;
  }

  mixed *targets = expand_objects(args[0], THISP, DEFAULT_CONTEXT,
                                  MATCH_BLUEPRINTS|IGNORE_CLONES);
  int count = 0;
  foreach (mixed *t : targets) {
    object target = t[OB_TARGET];
    string path = load_name(target);

    if (clonep(target)) {
      printf("%s: %s: Can't reload clones, only blueprint\n",
             query_verb(), arg);
      continue;
    }

    string err = catch (destruct(target); publish);
    if (err) {
      printf("%s: %s: Caught error %s\n", query_verb(), arg, err);
      return 1;
    }
    if (target) {
      printf("%s: %s: Unable to destruct.\n", query_verb(), arg);
      return 1;
    }

    err = catch (load_object(path); publish);
    if (err) {
      printf("%s: %s: Caught error %s\n", query_verb(), arg, err);
      mixed *last_err = get_error_file(MasterObject->get_wiz_name(arg));
      if (last_err) {
        printf("%s line %d: %s\n", last_err[0], last_err[1], last_err[2]);
      }
      return 1;
    }

    count++;
  }

  printf("%s: %s: %d object%s reloaded\n",
         query_verb(), arg, count, (count == 1 ? "" : "s"));
  return 1;
}
