#include "hobbe_defs.h"
#include "/players/kryll/rooms/room_defs.h"

nosave int has_cause, has_item;
nosave string cause_desc, item_desc;

nomask string query_causes() {
  return cause_desc;
}

nomask set_cause_ids(string str) {
  cause_desc = str;
}

nomask set_has_cause(int val) {
  has_cause = val;
}

nomask set_has_item(int val) {
  has_item = val;
}

nomask int query_has_cause() {
  return has_cause;
}

nomask int query_has_item() {
  return has_item;
}

int lift(string str) {
  if(!id(str)) {
    notify_fail("Lift what?\n");
    return 0;
  }

  if(has_cause && member_array(str, query_causes())!=-1) {
    write("You cannot budge the " + str + ".\n");
    say(lw(TP->NAME + " tries to move the " + str + " but cannot.\n"));
    return 1;
  }
  write("You cannot possibly move the " + str + ".\n");
  return 1;
}

int ser(string str) {
  if(!id(str)) {
    notify_fail("Search what?\n");
    return 0;
  }

  if(has_item && member_array(str, query_item())!=-1) {
  }

  write("You search the " + str + " but come up empty-handed.\n");
  say(lw(TP->NAME + " searches the room.\n");
  return 1;
}

int _enter(string str){
  switch(str) {
    case "river" :
    case "water" :
    case "the water" :
    case "the river" :
      write("You don't dare enter the deep river!\n");
      say(lw(TP->NAME + " looks like a person who is trying to "+
             "commit suicide!\n"));
      return 1;
    default :
      notify_fail("Enter what?\n");
      return 0;
  }
}

