#include <std.h>
#include <dragonevent.h>
#include <rest.h>

inherit DRAG_ROOMS"py/base";

string list_items(string* items);
int touch_ground(string);
int touch_wall(string);
string* query_fake_exits();
void add_fake_exit(string dir);
void add_fake_exits(string* exits);
void make_exits_invis();

//only want to damage one player, the first one in
int heartbeatsSinceLastDamage;
object playerToDamage;

string* fakeExits;

void create() {
  ::create();
  set_properties( ([ "no map" : 1, "polar" : 1 ]) );
  skip_obvious();
  set_short("%^BOLD%^%^CYAN%^A %^RESET%^windy%^BOLD%^%^CYAN%^ cave");
  set_long("A cold wind whips through the cave, obscuring your vision.");
  set_smell("default", "A cold wind whips through the cave, obscuring your sense of smell.");
  set_listen("default", "A cold wind whips through the cave, making it impossible to hear anything else.");

  set_touch(({"ground", "floor"}), (: touch_ground :));
  set_search(({"ground", "floor"}), (: touch_ground :));
  set_touch(({"wall","walls"}), (: touch_wall :));
  set_search(({"wall","walls"}), (: touch_wall :));
  heartbeatsSinceLastDamage = 0;
  fakeExits = ({});
}

void init() {
  ::init();
  make_exits_invis();
  if(!this_player()) return;
  if(!playerToDamage) playerToDamage = this_player();
  set_heart_beat(1);

  add_action("no_look", ({"l","look"}));
}

int touch_ground(string str) {
  string exits = list_items(query_exits() - query_fake_exits());
  if(!exits) {
    write("The ground is completely smooth.");
    return 1;
  }
  message("info", this_player()->query_cap_name()+" bends over and feels the ground.", this_object(), this_player());
  write("The ground below feels as if it is much more heavily travelled to the "+exits+".");
  return 1;
}

int touch_wall(string str) {
  if(!sizeof(query_exits())) {
    write("You carefully feel your way around the walls in the room. It appears as if there is no way out.");
    return 1;
  }
  message("info", this_player()->query_cap_name()+" wanders about the room, feeling around for something.", this_object(), this_player());
  if(sizeof(query_exits()) < random(22)+1) {
    write("You carefully make your way around the room, searching the walls.\nIt seems as if there are "+cardinal(sizeof(query_exits()))+" path"+(sizeof(query_exits())>1?"s":"")+" out of this room: "+list_items(query_exits()));
    return 1;
  }
  write("You wander about, trying to feel your way to a wall. You are unable to do so, and feel as if you have wandered into a new room.");
  this_player()->move(query_exit(query_exits()[random(sizeof(query_exits()))]));
  return 2;
}

void add_fake_exit(string dir) {
  string dest = path_file(file_name(this_object()))[0] + "/";
  int num;
  if(member_array(dir, query_exits()) != -1) return;
  if(clonep(this_object()))
    sscanf(path_file(file_name(this_object()))[1], "%d#", num);
  else
    sscanf(path_file(file_name(this_object()))[1], "%d", num);
  num = num>1?random(num-1)+1:1;
  dest += (num<=9?"0":"")+num;

  add_exit(dest, dir);
  //make sure dir is only added in once
  fakeExits -= ({ dir });
  fakeExits += ({ dir });
}

void add_fake_exits(string* exits) {
  foreach(string exit in exits) { add_fake_exit(exit); }
}

void heart_beat() {
  if(!playerToDamage) {
    set_heart_beat(0);
    return;
  }
  if(!present(playerToDamage)) {
    set_heart_beat(0);
    playerToDamage = 0;
    return;
  }
  heartbeatsSinceLastDamage++;
  if(random(450) < heartbeatsSinceLastDamage*10) {
    message("info", "%^BOLD%^%^CYAN%^A %^RESET%^cold wind %^BOLD%^%^CYAN%^lashes at your body.", playerToDamage);
    heartbeatsSinceLastDamage = 0;
    if(!harm_player(playerToDamage, 20)) return 0;
  }
}

int use_exit() {
  if(random(1000) < 100) {
    message("info", "As you try to leave, a gust of wind knocks you to the ground.", this_player());
    if(random(1000) < 300) message("info", "The ground is rough to the touch.", this_player());
    if(!harm_player(this_player(), 50)) return 0;
    this_player()->set_rest_type(SIT);
    return 0;
  }
  return ::use_exit();
}

string list_items(string* items) {
  string out;
  if(!items || !sizeof(items)) return "";
  if(sizeof(items) < 2) return items[0];
  if(sizeof(items) == 2) return items[0]+" and "+items[1];

  out = "";
  for (int i=0; i<(sizeof(items)-1); i++) {
    out += items[i] + ", ";
  }
  out += "and "+items[<1];
  return out;
}

string* query_fake_exits() { return fakeExits; }

void make_exits_invis() {
  foreach(string exit in query_obvious_exits()) {
    add_invis_exit(exit);
  }
}

int accept_player_into_instance(object player) { return 1; }

int no_look(string str) {
  write("The wind is too strong, you are unable to see anything.");
  return 1;
}
