//    An inheritable object for all containers of saveable items.  Only saves past reboots if 
//    it is in a locker_room.
//    DarkeLIB 0.1
//    -Diewarzau 7/29/95

#include <std.h>
#include <daemons.h>
#include <move.h>
#include <dirs.h>

inherit BAG;
inherit "/std/locker_logic";

int max_items;
private int closed_weight;
void set_max_items(int x) { max_items = x; }
int query_is_locker() { return 1; }

void create() {
  set_possible_to_close(1);
  is_closed = 1;
  seteuid(getuid());
  set_max_internal_encumbrance(1000);
  set_storage_key("locker");
  set_property("storage room", 1);
  ::create();
}

void restore_locker(string file) {
  if(!file || !file_exists(DIR_OBJECTS+"/"+file+".o")) return;
  seteuid(geteuid(this_object()));
  restore_object(DIR_OBJECTS+"/"+file, 1);
  return;
}

int receive_objects() {
  if(!::receive_objects()) return 0;
  if(previous_object() && previous_object() == this_object()) return 1;
  if(!max_items) this_object()->set_max_items(10);
  if(sizeof(all_inventory(this_object())) >= max_items) {
      write("You cannot put more than "+max_items+" in this container.");
    return 0;
  }

  if(previous_object() && (previous_object()->query_property("no save") ||
			   !clonep(previous_object()))) {
    write("That item cannot be saved!");
    return 0;
  }
  return 1;
}

int toggle_closed() {
  object *inv, ob;
  int i;

  if(!::toggle_closed()) return 0;
  seteuid(geteuid(this_object()));
  if(is_closed) {
    closed_weight = 0;
    inv = all_inventory(this_object());
    if(!SAVE_ITEMS_D->register_objects(inv, this_object())) {
      write("Save failed.  Try again.");
      ::toggle_closed();
      return 0;
    }
    i = sizeof(inv);
    while(i--) {
      if(!inv[i]) continue;
      if(intp(inv[i]->query_weight())) closed_weight +=
        (int)inv[i]->query_weight();
      inv[i]->remove();
    }

    SAVE_ITEMS_D->update_lockers(environment(this_object()));
  } else {
    if(!SAVE_ITEMS_D->load_objects(this_object())) {
      write("Unable to restore one or more of your objects.");
      return 1;
    }
  }

  return 1;
}

int move(mixed dest) {
  if(objectp(dest) && living(dest) && this_object()->query_locked()) {
    if(this_player()) write("It is chained to the ground.");
    return MOVE_NOT_ALLOWED;
  }

  return ::move(dest);
}

int query_weight() {
  if(!is_closed) return ::query_weight() + query_internal_encumbrance();
  else return ::query_weight() + closed_weight;
}

int clean_up() { return 0; }