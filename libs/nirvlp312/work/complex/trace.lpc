/*
 * complex/trace.c is a trace of an event which has happened somewhere.
 * It contains the information of the event, a delay until when it shall
 * exist. After that time it will be removed automatically.
 *
 * Written by Alfe for Tubmud 98-Jan-2
 */

#include <traces.h>  // changed to traces.h, Coogan, 16-Nov-00
#include <kernel.h>

inherit ACCESS;
inherit "basic/create";

mixed event;
int delay;

void create() {
  create::create();
  if (!clonep())  // don't check for the blueprint
    return;
  if (!IS_SE_TRACES(previous_object()) &&
      !check_previous_privilege("@traces")) {
    destruct(this_object());
    raise_error("Illegal cloning of a trace\n");
  }
  if (load_name(this_object()) != TRACE_OBJECT) {
    destruct(this_object());
    raise_error("Illegal inheriting\n");
  }
}

void set_event(mixed e) {
  if (!IS_SE_TRACES(previous_object()) &&
      !check_previous_privilege("@traces"))
    raise_error("Illegal call of set_event()\n");
  event = e;
}

mixed query_event() {
  if (!check_previous_privilege("@traces"))
    raise_error("Unprivileged trace query\n");
  return event;
}

void set_delay(int d) {
  if (!IS_SE_TRACES(previous_object()) &&
      !check_previous_privilege("@traces"))
    raise_error("Illegal call of set_dealy()\n");
  delay = d;
}

int query_delay() { return delay; }

private status destruction_allowed;

void fade_away() {
  if (!IS_SE_TRACES(previous_object()))
    raise_error("Illegal call of fade_away()\n");
  destruction_allowed = 1;
  destruct(this_object());
}

status trace_matches(mixed part) {
  return (mappingp(event) ? (member(m_values(event),part) >= 0) :
          pointerp(event) ? (member(event,part) >= 0) :
          (part == event));
}

#if 0
void notify_destruct() {
  if (!destruction_allowed)
    log_file("ILLEGAL",ctime() + ": " + object_name() +
             " has been destructed in " + object_name(environment()) + ".\n");
}
#endif
