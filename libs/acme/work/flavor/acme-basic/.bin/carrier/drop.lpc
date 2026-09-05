inherit CommandCode;

#include <expand_object.h>

#define DEFAULT_CONTEXT        "me"

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit ObjectExpansionLib;
private variables private functions inherit ObjectLib;

int do_command(string arg) {
  mixed *args;
  args = getopts(explode_args(arg), "");
  if (!sizeof(args[0])) {
    notify_fail("Drop what?\n");
    return 0;
  }

  arg = implode(args[0], " ");
  mixed *targets = expand_objects(arg, THISP, DEFAULT_CONTEXT);

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

    if (target->prevent_drop()) {
      out += sprintf("You can't drop %s.\n", get_display(target));
    } else if (ENV(target)->is_container()) {
      object *env = all_environment(target);
      int pass = 1;
      object e;
      foreach (e : env) {
        if (e->is_container()) {
          // check all nested containers are open
          if (!e->is_open()) {
            out += sprintf("You must open %s before you can drop %s.\n",
                           e->short(), get_display(target));
            pass = 0;
            break;
          }
        } else {
          // first non-container must be THISP
          if (e != THISP) {
            out += sprintf("You aren't carrying %s.\n", get_display(target));
            pass = 0;
          }
          break;
        }
      }
      if (!pass) {
        continue;
      }
      if (move_resolved(target, ENV(THISP))) {
        out += sprintf("You drop %s.\n", get_display(target));
        room_out += sprintf("%s drops %s.\n", PNAME, get_display(target));
        moved += ({ target });
      } else {
        out += sprintf("An unseed force prevents you from dropping %s.\n",
                       get_display(target));
      }
    } else if (ENV(target) != THISP) {
      out += sprintf("You aren't carrying %s.\n", get_display(target));
    } else {
      if (move_resolved(target, ENV(THISP))) {
        out += sprintf("You drop %s.\n", get_display(target));
        room_out += sprintf("%s drops %s.\n", PNAME, get_display(target));
        moved += ({ target });
      } else {
        out += sprintf("An unknown force prevents you from dropping %s.\n",
                       get_display(target));
      }
    }
  }

  write(out);
  tell_room(ENV(THISP), room_out, ({ THISP }));
  filter_objects(moved, "drop_signal");

  return 1;
}

