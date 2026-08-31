#include <std.h>
#include <daemons.h>

inherit ROOM;

int holdUntil;

int okayToDeleteContents() {
  return !(sizeof(all_inventory(this_object())) > 0 || (holdUntil != -1 && time() > (holdUntil - 20)));
}

int remove() {
  if(!okayToDeleteContents()) return 0;
  return ::remove();
}

void create() {
  ::create();
  holdUntil = EVENTS_D->query_next_reboot();
}

int query_hold_until() { return holdUntil; }
void set_hold_until(int i) { holdUntil = i; }
