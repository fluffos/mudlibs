inherit CommandCode;

#include <expand_object.h>

#define DEFAULT_CONTEXT        "me"
#define CONTAINER_CONTEXT      "(here,me)"
#define OPTS                   ""

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit ObjectExpansionLib;
private variables private functions inherit ObjectLib;

int do_command(string arg) {
  string container_spec;
  mixed *args;
  if (sscanf(arg || "", "%s in %s", arg, container_spec) == 2) {
    if (!strlen(arg) || !strlen(container_spec)) {
      notify_fail("Put what in what?\n");
      return 0;
    }
    args = getopts(explode_args(arg), OPTS);
    args[0] = ({ implode(args[0], " ") });
  } else {
    args = getopts(explode_args(arg), OPTS);
    if (sizeof(args[0]) < 2) {
      notify_fail("Put what in what?\n");
      return 0;
    }
    container_spec = args[0][0];
    args[0] = args[0][1..];
  }

  if (!sizeof(args[0])) {
    notify_fail("Put what in what?\n");
    return 0;
  }

  mixed *targets = expand_objects(args[0], THISP, DEFAULT_CONTEXT);
  mixed *cont = expand_objects(container_spec,
                               THISP,
                               CONTAINER_CONTEXT,
                               LIMIT_ONE);

  if (!sizeof(targets)) {
    notify_fail("There isn't anything like that here.\n");
    return 0;
  }
  if (!sizeof(cont)) {
    notify_fail("There isn't any container like that here.\n");
    return 0;
  }
  object container = cont[0][OB_TARGET];
  if (!container->is_container()) {
    printf("%s isn't a container.\n", CAP(get_display(container)));
    return 1;
  }
  if (!container->is_open()) {
    printf("You must open %s first.\n", get_display(container));
    return 1;
  }
  if (!is_reachable(container)) {
    printf("You can't get to %s.\n", get_display(container));
    return 1;
  }

  string out = "";
  string room_out = "";
  string container_out = get_display(container);
  // TODO you should be able to move something from one container to another
  // within inventory
  foreach (mixed *t : targets) {
    object target = t[OB_TARGET];
    string id = t[OB_ID];

    if (ENV(target)->is_container()) {
      out += sprintf("You must remove %s from %s before you can move it.\n",
                     get_display(target), get_display(ENV(target)));
    } else if (!is_reachable(target, THISP)) {
      out += sprintf("You can't get to %s.\n", get_display(target));
    } else {
      if (move_resolved(target, container)) {
        out += sprintf("You put %s in %s.\n",
                       get_display(target),
                       container_out);
        if (ENV(container) == ENV(THISP)) {
          room_out += sprintf("%s puts %s in %s.\n",
                              PNAME, get_display(target), container_out);
        } else if (ENV(container) == THISP) {
          room_out += sprintf("%s picks up %s.\n", PNAME, get_display(target));
        }
      } else {
        out += sprintf("An unseen force prevents you from putting "
                       "%s in %s.\n",
                       get_display(target), get_display(container));
      }
    }

  }

  write(out);
  tell_room(ENV(THISP), room_out, ({ THISP }));

  return 1;
}

