inherit CommandCode;

#include <expand_object.h>
#include <mobile.h>

#define DEFAULT_CONTEXT        "users"

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit ObjectExpansionLib;

int do_command(string arg) {
  mixed *args;
  args = getopts(explode_args(arg), "sfw");
  if (!sizeof(args[0])) {
    notify_fail(sprintf("Usage: %s dest\n", query_verb()));
    return 0;
  }
  arg = implode(args[0], " ");

  string error = "destination unknown";
  object dest = expand_destination(arg, THISP, DEFAULT_CONTEXT,
                                   LIMIT_ONE|MATCH_BLUEPRINTS, &error);

  if (!dest) {
    notify_fail(sprintf("%s: %s: %s\n", query_verb(), arg, error));
    return 0;
  }

  if (dest == ENV(THISP)) {
    printf("%s: %s: destination is here\n", query_verb(), arg);
    return 1;
  }

  int flags = 0;
  if (member(args[1], 's')) { flags |= MUFFLED_MOVE; }
  if (member(args[1], 't')) { flags |= FORCE_TELEPORT; }
  if (member(args[1], 'f')) { flags |= FOLLOW; }
  if (!THISP->teleport(dest, flags)) {
    printf("%s: %s: teleport failed\n", query_verb(), arg);
    return 1;
  }

  return 1;
}

