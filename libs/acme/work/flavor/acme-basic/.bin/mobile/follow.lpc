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
  args = getopts(explode_args(arg), "f");
  if (!sizeof(args[0])) {
    notify_fail("Follow who or what?\n");
    return 0;
  }
  arg = implode(args[0], " ");
  mixed *targets = expand_objects(arg, THISP, DEFAULT_CONTEXT);

  if (!sizeof(targets)) {
    notify_fail("No matching object found to follow.\n");
    return 0;
  }

  object here = ENV(THISP);
  string display = get_display(THISP);
  string out = "";
  foreach (mixed *t : targets) {
    object target = t[OB_TARGET];
    if (!member(args[1], 'f') && (ENV(target) != here)) {
      out += sprintf("%s isn't here to follow, use -f to force.\n",
                     get_display(target));
      continue;
    }
    if (!is_capable(target, CAP_MOBILE)) {
      out += sprintf("%s is immobile.\n", get_display(target));
      continue;
    }
    if (THISP->is_following(target)) {
      out += sprintf("You are already following %s.\n", get_display(target));
      continue;
    }
    if (!THISP->add_following(target)) {
      out += sprintf("Unable to follow %s.\n", get_display(target));
      continue;
    }
    out += sprintf("You begin following %s.\n", get_display(target));
    tell_player(target, "%s begins following you.\n", display);
  }

  tell_player(THISP, out);
  return 1;
}

