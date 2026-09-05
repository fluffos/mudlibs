inherit CommandCode;

#include <expand_object.h>
#include <capabilities.h>

#define DEFAULT_CONTEXT        "(here,users)"

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit ObjectExpansionLib;
private variables private functions inherit ObjectLib;

int do_command(string arg) {
  mixed *args;
  args = getopts(explode_args(arg), "");
  if (!sizeof(args[0])) {
    notify_fail("Stop following who or what?\n");
    return 0;
  }
  arg = implode(args[0], " ");
  mixed *targets = expand_objects(arg, THISP, DEFAULT_CONTEXT);

  if (!sizeof(targets)) {
    notify_fail("No matching object found to stop following.\n");
    return 0;
  }

  object here = ENV(THISP);
  string display = get_display(THISP);
  foreach (mixed *t : targets) {
    object target = t[OB_TARGET];
    if (!THISP->is_following(target)) {
      out += sprintf("You aren't following %s.\n", get_display(target));
      continue;
    }
    if (!THISP->remove_following(target)) {
      out += sprintf("Unable to stop following %s.\n", get_display(target));
      continue;
    }
    out += sprintf("You stop following %s.\n", get_display(target));
    tell_player(target, (: 
      sprintf("%s stops following you.\n", $1) 
    :), display);
  }

  tell_player(THISP, out);
  return 1;
}

