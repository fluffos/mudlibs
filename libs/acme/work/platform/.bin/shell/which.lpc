inherit CommandCode;

#include <expand_object.h>

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit ObjectExpansionLib;

int do_command(string arg) {
  // XXX messaging?
  mixed *args;
  args = getopts(explode_args(arg), "dulbisc:");
  int flags = 0;
  if (member(args[1], 'd')) { flags |= MATCH_DETAIL; }
  if (member(args[1], 'u')) { flags |= UPDATE_CONTEXT; }
  if (member(args[1], 'l')) { flags |= LIMIT_ONE; }
  if (member(args[1], 'b')) { flags |= MATCH_BLUEPRINTS; }
  if (member(args[1], 'i')) { flags |= IGNORE_CLONES; }
  if (member(args[1], 's')) { flags |= STALE_CLONES; }
  string default_context = args[1]['c'];
  arg = implode(args[0], " ");

  if (sizeof(args[0]) < 1) {
    notify_fail(sprintf("Usage: %s target\n", query_verb()));
    return 0;
  }

  mixed *targets = expand_objects(args[0], THISP, default_context, flags);
  int count = 0;
  string out = "";
  foreach (mixed *t : targets) {
    count++;
    object target = t[OB_TARGET];
    string id = t[OB_ID];
    string detail = t[OB_DETAIL];
    out += sprintf("[%3d] object: %s\n          id: %s\n",
                   count, object_name(target), id);
    if (detail) {
      out += sprintf("%5s detail: %s\n", "", detail);
    }
  }

  out += sprintf("%s: %s: %d object%s\n",
                 query_verb(), arg, count, (count == 1 ? "" : "s"));
  write(out);
  return 1;
}
