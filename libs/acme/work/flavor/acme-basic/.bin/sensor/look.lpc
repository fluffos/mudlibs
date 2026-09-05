inherit CommandCode;

#include <look.h>
#include <expand_object.h>
#include <capabilities.h>

#define DEFAULT_CONTEXT        "(here,me)"

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit ObjectExpansionLib;
private variables private functions inherit ObjectLib;

string format_room(object target, object looker, string id);
string format_default(object target, object looker, string id);
string format_detail(object target, object looker, string id, string detail);
string format_inventory(object target, object looker);
string format_item(object target, object looker);

int do_command(string arg) {
  // TODO add max args param to explode_args
  // TODO opt to not update context
  mixed *args = getopts(explode_args(arg), "hm");

  // scope to room, include detail ids
  arg = implode(args[0], " ");
  if (!strlen(arg)) {
    arg = "here";
  }
  mixed *targets = expand_objects(arg,
                                  THISP,
                                  DEFAULT_CONTEXT,
                                  UPDATE_CONTEXT|MATCH_DETAIL);

  if (!sizeof(targets)) {
    if (!ENV(THISP)) {
      write(VOID_MSG "\n");
      return 1;
    } else {
      notify_fail("There isn't anything like that here.\n");
      return 0;
    }
  }

  LoggerFactory->get_logger(THISO)->trace("targets = %O", targets);
  string out = "";
  foreach (mixed *t : targets) {
    object target = t[OB_TARGET];
    string id = t[OB_ID];
    string detail = t[OB_DETAIL];

    if (member(args[1], 'h')) {
      // TODO this should be configurable (id, short, silent, etc)
      out += sprintf("::::: %s :::::\n", object_name(target));
    }
    if (is_capable(target, CAP_VISIBLE)) {
      if (detail) {
        out += format_detail(target, THISP, id, detail);
      } else {
        if (target->is_room()) {
          // TODO add brief support
          out += format_room(target, THISP, id);
        } else {
          out += format_default(target, THISP, id);
        }
      }
    } else {
      if (target == ENV(THISP)) {
        // TODO invisible room should still show inventory
        out += DEFAULT_ROOM_LONG + "\n";
      } else {
        out += "You sense something there, but see nothing.\n";
      }
    }
  }

  if (member(args[1], 'm')) {
    // TODO add pager support
    write(out);
  } else {
    write(out);
  }

  return 1;
}

string format_room(object target, object looker, string id) {
  string short = target->query_short(looker);
  string long = target->query_long(looker, id);
  mapping exits = target->query_exits();
  string *dirs;
  if (mappingp(exits)) {
    dirs = m_indices(filter(exits, (: $2[1] :)));
    dirs = sort_array(dirs, #'>); // '
  } else {
    dirs = ({ });
  }

  // TODO the default descs could have debug info
  int width = looker->query_screen_width();
  int exit_count = sizeof(dirs);
  return sprintf("%s\n%-=*s\n---- %-=*s\n%s",
    (stringp(short) ? short : DEFAULT_ROOM_SHORT),
    width,
    sprintf("    %s", (stringp(long) ? long : DEFAULT_ROOM_LONG)),
    width,
    ((exit_count > 1 ) ?
      sprintf(MULTI_EXIT_MSG "%s.", implode(dirs, ", ")) :
      (exit_count == 1) ?
      sprintf(SINGLE_EXIT_MSG "%s.", dirs[0]) :
      NO_EXIT_MSG
    ),
    format_inventory(target, looker)
  );
}

string format_default(object target, object looker, string id) {
  int width = looker->query_screen_width();
  string long = target->query_long(looker, id);
  string inv = format_inventory(target, looker);
  string out = sprintf("%-=*s\n%s",
    width,
    (stringp(long) ? long : DEFAULT_LONG),
    (strlen(inv)
      ? sprintf("%s is %s:\n%s",
        CAP(objective(target)),
        (target->is_living() ? "carrying" : "holding"),
        inv)
      : "")
  );
  return out;
}

string format_detail(object target, object looker, string id, string detail) {
  int width = looker->query_screen_width();
  string description = target->query_detail(detail);
  return sprintf("%-=*s\n", width, description);
}

string format_inventory(object target, object looker) {
  string *items = map(all_inventory(target) - ({ looker }),
                      #'format_item, looker); // '

  return (sizeof(items) ? (implode(items, "\n") + "\n") : "");
}

string format_item(object target, object looker) {
  string short = target->query_short(looker);
  return (stringp(short) ? short : DEFAULT_SHORT);
}
