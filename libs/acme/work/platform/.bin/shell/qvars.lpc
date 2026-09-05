inherit CommandCode;

#include <expand_object.h>
// #include <sys/functionlist.h> XXX figure out why this errors
#include "/include/sys/functionlist.h"

#define DEFAULT_CONTEXT        "(here,me)"

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit ObjectExpansionLib;

int do_command(string arg) {
  mixed *args = getopts(explode_args(arg), "");

  // scope to room, include detail ids
  arg = implode(args[0], " ");
  if (!strlen(arg)) {
    notify_fail("Usage: qvars ob\n");
    return 0;
  }
  mixed *targets = expand_objects(arg,
                                  THISP,
                                  DEFAULT_CONTEXT,
                                  UPDATE_CONTEXT|MATCH_DETAIL);

  if (!sizeof(targets)) {
    notify_fail("There isn't anything like that here.\n");
    return 0;
  }

  string out = "";
  foreach (mixed *t : targets) {
    object target = t[OB_TARGET];
    string id = t[OB_ID];
    string detail = t[OB_DETAIL];

      // TODO this should be configurable (id, short, silent, etc)
    out += sprintf("::::: %s :::::\n", object_name(target));
    out += sprintf("%O\n", variable_list(target, RETURN_FUNCTION_NAME
                                                |RETURN_FUNCTION_FLAGS
                                                |RETURN_FUNCTION_TYPE
                                                |RETURN_VARIABLE_VALUE));
  }
  write(out);
  return 1;
}
