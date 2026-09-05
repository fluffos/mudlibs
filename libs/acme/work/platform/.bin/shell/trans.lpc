inherit CommandCode;

#include <expand_object.h>
#include <mobile.h>
#include <capability.h>

#define DEFAULT_CONTEXT        "users"

inherit ArgsLib;
inherit GetoptsLib;
inherit ObjectExpansionLib;
inherit ObjectLib;

private int valid_environment(object arg);
private object find_room(object arg);

int do_command(string arg) {
  mixed *args;
  args = getopts(explode_args(arg), "sfw");
  if (sizeof(args[0]) < 2) {
    notify_fail(sprintf("Usage: %s target dest\n", query_verb()));
    return 0;
  }
  arg = implode(args[0], " ");

  string error = "destination unknown";
  object dest = expand_destination(args[0][1], THISP, DEFAULT_CONTEXT, 0,
                                   &error);
  if (!dest) {
    notify_fail(sprintf("%s: %s: %s\n", query_verb(), args[0][1], error));
    return 0;
  }

  int flags = 0;
  if (member(args[1], 's')) { flags |= MUFFLED_MOVE; }
  if (member(args[1], 'f')) { flags |= FORCE_TELEPORT; }
  if (member(args[1], 'w')) { flags |= FOLLOW; }

  mixed *targets = expand_objects(({ args[0][0] }), THISP, DEFAULT_CONTEXT);
  int count = 0;
  foreach (mixed *t : targets) {
    object target = t[OB_TARGET];
    if (dest == ENV(target)) {
      continue;
    }
    if (is_capable(target, CAP_MOBILE)) {
      if (target->teleport(dest, flags)) {
        count++;
      }
    } else {
      if (move_object(target, dest)) {
         count++;
      }
    }
  }

  printf("%s: %s: %d object%s teleported\n",
         query_verb(), arg, count, (count == 1 ? "" : "s"));
  return 1;
}