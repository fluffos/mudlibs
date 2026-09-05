inherit CommandCode;

#include <expand_object.h>

#define DEFAULT_CONTEXT        "(here,me)"
#define OPTS                   ""

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit ObjectExpansionLib;
private variables private functions inherit ObjectLib;

int do_command(string arg) {
  string container;
  mixed *args;
  if (sscanf(arg || "", "%s from %s", arg, container) == 2) {
    args = getopts(explode_args(arg), OPTS);
    arg = implode(args[0], " ");
    args[0] = sprintf(OPEN_GROUP "%s" CLOSE_GROUP
                      CONTEXT_DELIM
                      OPEN_GROUP "%s" CLOSE_GROUP,
                      container, arg);
  } else {
    args = getopts(explode_args(arg), OPTS);
  }

  if (!sizeof(args[0])) {
    notify_fail("Get what?\n");
    return 0;
  }
  mixed *targets = expand_objects(args[0], THISP, DEFAULT_CONTEXT);

  if (!sizeof(targets)) {
    notify_fail("There isn't anything like that here.\n");
    return 0;
  }

  object *moved = ({ });
  string out = "";
  string room_out = "";
  foreach (mixed *t : targets) {
    object target = t[OB_TARGET];
    string id = t[OB_ID];

    if (target->prevent_get()) {
      out += sprintf("You can't pick up %s.\n", get_display(target));
    } else if (ENV(target)->is_container()) {
      object *env = all_environment(target);
      int pass = 1;
      object e;
      foreach (e : env) {
        if (e->is_container()) {
          // check all nested containers are open
          if (!e->is_open()) {
            out += sprintf("You must open %s before you can get %s.\n",
                           get_display(e), get_display(target));
            pass = 0;
            break;
          }
        } else {
          // first non-container must be accessible
          if (!is_reachable(e)) {
            out += sprintf("You can't get to %s.\n", get_display(target));
            pass = 0;
          }
          break;
        }
      }
      if (!pass) {
        continue;
      }
      string source_out = get_display(ENV(target));
      if (move_resolved(target, THISP)) {
        out += sprintf("You remove %s from %s.\n",
                       get_display(target), source_out);
        if (e == ENV(THISP)) {
          room_out += sprintf("%s removes %s from %s.\n",
                              PNAME, get_display(target),
                              source_out);
        }
        moved += ({ target });
      } else {
        out += sprintf("An unseen force prevents you from getting %s.\n",
                       get_display(target));
      }
    } else if (ENV(target)->is_room()) {
      if (ENV(target) != ENV(THISP)) {
        out += sprintf("You can't get to %s.\n", get_display(target));
        continue;
      }
      if (move_resolved(target, THISP)) {
        out += sprintf("You pick up %s.\n", get_display(target));
        room_out += sprintf("%s picks up %s.\n", PNAME, get_display(target));
        moved += ({ target });
      } else {
        out += sprintf("An unknown force prevents you from getting %s.\n",
                       get_display(target));
      }
    } else if (ENV(target)->is_living()) {
      out += sprintf("You can't get %s from %s, they have to give it to "
                     "you.\n",
                     get_display(target), ENV(target)->query_name());
    }
  }

  write(out);
  tell_room(ENV(THISP), room_out, ({ THISP }));
  // XXX should get_signal be called when you're getting something from a
  // container that you're already holding?
  filter_objects(moved, "get_signal");

  return 1;
}

