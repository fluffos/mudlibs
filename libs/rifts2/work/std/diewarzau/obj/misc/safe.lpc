//    A specialized locker which may only contain money.  Only saves past reboots if 
//    it is in a locker_room.
//    DarkeLIB 0.1
//    -Diewarzau 7/29/95

#include <std.h>
#include <move.h>
#include <daemons.h>
#include <dirs.h>

inherit BAG;
inherit "/std/money";
inherit "/std/locker_logic";

int max_items;
int closed_weight;
     
void set_max_items(int x) { max_items = x; }
     
int query_is_locker() { return 1; }

void create() {
  set_possible_to_close(1);
  is_closed = 1;
  seteuid(getuid());
  ::create();
  set_storage_key("locker");
  set_max_internal_encumbrance(50000);
  set_property("storage room", 1);
  set_max_items(10);
  set_name("safe");
  set_id( ({ "safe" }) );
  set_short("A safe");
  set_long("This is a strong-looking safe.\n");
  set_weight(700);
  set_value(10000);
  set_property("storage room", 1);
  set_closed_long("This is a strong-looking safe.\n");
  set_open_long("This is an open safe which may be used for storing money\n");
}

int query_is_safe() { return 1; }

string query_long(string str) {
  string desc, *currs, *lines;
  int i;

  desc = ::query_long();
  lines = explode(desc, "\n");
  i = member_array("  It contains:", lines);
  if(i >=0 ) lines = exclude_array(lines, i, sizeof(lines) - 1);
  desc = implode(lines, "\n");
  desc += "\n";
  currs = query_currencies();
  if(!currs || this_object()->query_closed()) return desc;
  desc += "It contains:\n";
  i = sizeof(currs);
  while(i--)
    desc += sprintf("%d %s\n", query_money(currs[i]),
		currs[i]);
  return desc;
}

int get_from(string arg) {
  int amt, i;
  string what, curr, *currs;
  object ob;

  if(sscanf(arg, "%d %s from %s", amt, curr, what) != 3) {
    if(sscanf(arg, "%s from %s", curr, what) != 2)
      return 0;
    else {
      if(present(what, this_player()) != this_object() &&
         present(what, environment(this_player())) != this_object()) return 0;
      if(effective_light(this_player()) < 0) {
        write("It is too dark.");
        return 1;
      }
      if(effective_light(this_player()) > 7) {
        write("It is too bright");
        return 1;
      }
      if(this_object()->query_closed()) {
        write("You might try opening it first.");
        return 1;
      }
      if(!query_currencies() || !sizeof(query_currencies())) {
        write("There is no money in the safe.");
        return 1;
      }
      if(curr == "coins" || curr == "all") {
        currs = query_currencies();
        if(!currs || !(i = sizeof(currs))) {
          write("There is no money in the safe.");
          return 1;
        }
        message("other_action", (string)this_player()->query_cap_name() +
                " takes all of the money in "+lower_case(query_short())+".",
                environment(this_player()), ({ this_player() }) );
        while(i--) {
          write(sprintf("You take %d %s.", query_money(currs[i]),
                currs[i]));
          this_player()->add_money(currs[i], query_money(currs[i]));
          set_money(currs[i], 0);  
        }
        return 1;
      }
      currs = query_currencies();
      if(!currs || !sizeof(currs)) {
        write("There is no money in the safe.");
        return 1;
      }
      if(member_array(curr, currs) < 0) {
        write("There is no '"+curr+"' in the safe.");
        return 1;
      }
      message("other_action", (string)this_player()->query_cap_name() +
              " takes all of the "+curr+" in "+lower_case(query_short()) +".",
              environment(this_player()), ({ this_player() }) );
      write("You take all of the "+curr+" in the safe.");
      this_player()->add_money(curr, query_money(curr));
      set_money(curr, 0);
      return 1;
    }
    return 0;
  }
  if(present(what, this_player()) != this_object() &&
     present(what, environment(this_player())) != this_object()) return 0;
  if(effective_light(this_player()) < 0) {
    write("It is too dark.");
    return 1;
  }
  if(effective_light(this_player()) > 7) {
    write("It is too bright");
    return 1;
  }
  if(this_object()->query_closed()) {
    write("You might try opening it first.");
    return 1;
  }
  if(!query_currencies() || !sizeof(query_currencies())) {
    write("There is no money in the safe.");
    return 1;
  }
  if(amt > query_money(curr)) {
    if(!query_money(curr))
      write("There is no "+curr+" in the safe.");
    else
      write("There is only "+query_money(curr)+" "+curr+
	    " in the safe.");
    return 1;
  }
  if(amt < 0) {
    write("WHATEVER!");
    return 1;
  }
  add_money(curr, -amt);
  this_player()->add_money(curr, amt);
  write(sprintf("You take %d %s from the safe.", amt, curr));
  message("other_action", this_player()->query_cap_name() +
	  " takes some money from a safe.",
	  all_inventory(environment(this_player())),
	  ({ this_player() }));
  return 1;
}

void restore_locker(string file) {
  if(!file || !file_exists(DIR_OBJECTS+"/"+file+".o")) return;
  seteuid(geteuid(this_object()));
  restore_object(DIR_OBJECTS+"/"+file, 1);
  return;
}

int put_into(string str) {
  int amt, res, weight;
  string what, what2;
  object coins;

  if(sscanf(str, "%d %s in %s", amt, what, what2) != 3)
    return 0;
  if(effective_light(this_player()) <= -1) {
    write("It is too dark.");
    return 1;
  }
  if(effective_light(this_player()) > 7) {
    write("It is too bright.");
    return 1;
  }
  if(present(what2, environment()) != this_object()) return 0;
  seteuid(getuid());
  if((int)this_player()->query_money(what) < amt) {
    write("You don't have that much "+what+".");
    return 1;
  }
  if(!receive_objects() || query_closed()) {
    write("You cannot do that.");
    return 1;
  }
  if(member_array(what, (string *)ECONOMY_D->__QueryCurrencies()) >= 0)
    weight = to_int(to_float(amt) * (float)ECONOMY_D->__Query(what, "weight"));
  else weight = 0;
  if(!add_encumbrance(weight)) {
    write("The safe will not fit that many "+what+".");
    return 1;
  }
  this_player()->add_money(what, -amt);
  add_money(what, amt);
  write("You put "+amt+" "+what+" in the safe.");
  return 1;
}

int toggle_closed() {
  object *inv, ob;
  int i, j;
  string *currs, save_file, file, *item_keys;

  if(!::toggle_closed()) return 0;
  seteuid(geteuid(this_object()));
  if(!is_closed) {
    if(closed_weight && !query_internal_encumbrance())
      add_encumbrance(closed_weight);
  } else {
    closed_weight = 0;
    currs = query_currencies();
    if(currs && (i = sizeof(currs))) {
      while(i--)
        if(member_array(currs[i], (string *)ECONOMY_D->
                        __QueryCurrencies()) >= 0)
          closed_weight += to_int(to_float(query_money(currs[i])) *
                                  (float)ECONOMY_D->__Query(currs[i],
                                                            "weight"));
    }
    SAVE_ITEMS_D->update_lockers(environment(this_object()));
  }
  return 1;
}

int query_weight() {
  if(!is_closed) return ::query_weight() + query_internal_encumbrance();
  else return ::query_weight() + closed_weight;
}

int clean_up() { return 0; }

int move(mixed dest) {
  if(objectp(dest) && living(dest) && this_object()->query_locked()) {
    if(this_player()) write("It is chained to the ground.");
    return MOVE_NOT_ALLOWED;
  }
  return ::move(dest);
}

