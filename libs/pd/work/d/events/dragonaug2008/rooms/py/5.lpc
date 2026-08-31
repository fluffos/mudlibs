#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/base";

void create() {
  ::create();
  set_property("forest", 1);
  set_short("%^GREEN%^A dense jungle.");
  set_long("%^GREEN%^In the middle of a forest, there are tall trees and brush surrounding the small %^ORANGE%^dirt%^GREEN%^ path below. To the south, the path drops into a large pit, filled with rocks, vines, and other foliage. The path below leads through the forest to the east.");
  set_exits( ([
    "east" : DRAG_ROOMS"py/6",
    "south" : DRAG_ROOMS"py/4",
  ]) );
  add_pre_exit_function("south", "go_south");
  add_pre_exit_function("east", "go_east");
  set_items( ([
    "trees" : "They fill the forest.",
    "path" : "It is filled with dirt and small pebbles. It leads through the forest to the east.",
    "pit" : "A tremendous pit. The path continues on a ledge across the pit, but the trees above are too low to allow you to jump or fly to it. One tree in particular hangs low over the pit.",
    "tree" : "It dips low over the pit. A thick branch hangs down from the base of the tree.",
    "branch" : "A thick branch that hangs off of a tree over the pit. It appears to be very sturdy and has a large dip in it, perfect for hanging something from. However, it is too far away for you to reach.",
    "vines" : "There are vines all over, covering the trees and even scattered acrost the bottom of the pit below.",
    "foliage" : "Foliage is scattered all around the forest.",
  ]) );
}

void init() {
  ::init();
  add_action("hang_on_to_vine", ({"grab", "hang"}));
  add_action("jump_north", "jump");
  add_action("throw_vine_at_branch", ({"throw", "hurl", "toss"}));
}

//get the first vinerock in the room, delete all others.
varargs object get_vine(object from) {
  object ret = 0;
  if(nullp(from) || !from) from = this_object();
  foreach(object ob in
    filter(all_inventory(from),
    (: file_name($1)[0..sizeof(DRAG_ITEMS"vinerock")-1] == DRAG_ITEMS"vinerock" :)
    )) {
    if(!ret) ret = ob;
    else ob->remove();
  }
  return ret;
}

int go_east() {
  object ob;
  if(!ob = get_vine()) return 1;
  if(ob->query_rider() != this_player()) return 1;
  write("You let go of the vine.");
  ob->set_rider(0);
  return 1;
}

int hang_on_to_vine(string str) {
  object ob;
  if(!(ob = get_vine())) return notify_fail("There is no vine here.");
  if(str != "vine" && str != "onto vine") return notify_fail("Grab what?");
  if(ob->query_rider()) return notify_fail("You are already hanging onto it.\n");
  ob->set_rider(this_player());
  write("You grab on to the end of the vine.");
  return 1;
}

int jump_south(string str) {
  object ob;
  if(str != "south" && str != "to the south" && str != "in" && str != "down" && str != "into pit" && str != "branch" && str != "to branch" && str != "vine" && str != "onto vine" && str != "rope" && str != "onto rope") {
    return 0;
  }

  if(!(ob = get_vine()) || ob->query_rider() != this_player()) {
    write("You would fall to your untimely death.");
    return 1;
  }

  write("You swing across the pit on the vine rope.");
  this_player()->move_player(DRAG_ROOMS"py/4", "across the pit on a vine");
  if(environment(this_player())->get_vine()) ob->remove();
  else ob->move(environment(this_player()));
}

int go_south() {
  jump_south("south");
  return 0;
}

int throw_vine_at_branch(string str) {
  string vineStr, branchStr;
  object vineOb;
  if(!str) return 0;
  if(sscanf(str, "%s at %s", vineStr, branchStr) != 2 && sscanf(str, "%s %s", vineStr, branchStr) != 2)
    vineStr = str;

  if((vineOb = get_vine(this_player())) != present(vineStr, this_player())) {
    write("Throwing a "+vineStr+" would not help.");
    return 1;
  }
  if (!vineOb) {
    write("You do not have "+vineStr+".");
    return 1;
  }
  if (!branchStr) {
    write("Throw it where?");
    return 1;
  }
  if (branchStr != "north" && branchStr != "branch") {
    write("You wouldn't want to throw "+vineStr+" at "+branchStr+".");
    return 1;
  }

  message("info", this_player()->query_cap_name()+" throws a vine north.", this_object(), this_player());
  write("You throw the vine towards the branch!");
  if(random(100) < 50) {
    write("You miss the branch entirely and pull the vine back in.");
    return 1;
  }
  if(random(100) < 90) {
    write("The vine falls loosely over the branch. You pull the vine back in.");
    return 1;
  }

  write("The rock attached to the end of the vine wraps around the branch and slips between the branch and the vine, securing itself tightly to the branch.");
  vineOb->move(this_object());
  vineOb->set_prevent_get("It is tied firmly to a tree branch.");
  vineOb->set_short(vineOb->query_short()+" tied to a tree branch");
  vineOb->set_long(vineOb->query_long()+" The rock end is tied securely to a tree branch over a pit.");
  return 1;
}

int accept_player_into_instance(object play) { return 1; }
