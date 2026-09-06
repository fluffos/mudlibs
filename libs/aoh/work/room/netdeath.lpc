/* Netdeath Room
 *
 * Room for netdeath players.
 * Only netdeath players and archwizards may enter it
 * TODO: With full autoloading, this should no longer be necessary.
 * TODO:: If removed, update /sys/stdrooms.h
 *
 *   06-Oct-1994 [Mateese]
 */

#include <stdrooms.h>
#include <moving.h>
#include <secure/wizlevels.h>
#include <rooms.h>

inherit "/std/room";

#define PREV previous_object()

public varargs void create() {
  ::create();
  SetIntShort("Room of the Net Challenged");
  SetIntLong("A plain simple room, designed to keep statues fresh.\n");
  SetTPort(TPORT_NO);
  AddExit("center", WSTARTROOM);
}

public void clean() {
  object * inv;

  while (remove_call_out("clean") >= 0) /* skip */;
  inv = all_inventory(this_object());
  inv = inv - filter(inv, #'query_once_interactive);
  filter_objects(inv, "remove");
  filter(inv-({ 0 }), #'destruct);
}

public varargs int allow_enter(int method, mixed extra) {
  if (find_call_out("clean") < 0)
    call_out("clean", 10);
  return  ((!interactive(PREV) && query_once_interactive(PREV))
           || IS_WIZARD(PREV))
          ? ::allow_enter(method, extra)
          : ME_NO_ENTER;
}

public varargs int remove (int method)
{
  clean();
  if (!first_inventory())
    return destruct(this_object()), 1;
  return 0;
}

public varargs int clean_up(int arg) {
  return remove();
}

public void reset() {
  clean();
}
