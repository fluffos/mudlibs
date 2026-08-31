#include <std.h>
inherit DAEMON;
void do_fix(object tp, int time) {
  call_out("fixit", time + 5, tp);
}
void fixit(object tp) { tp->fix_vital_bonus(); }
