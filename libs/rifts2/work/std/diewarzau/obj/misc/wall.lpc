//   A generic wall.

#include <move.h>
#include <dirs.h>

inherit "/std/Object";
inherit "/std/locker_logic";

int saveable;
string caster;
string wall_func;
string verb;
int power;

void set_pow(int x) { power = x; }

void set_caster(object who) {
  caster = (string)who->query_name();
  return;
}

string query_direction() { return verb; }

int query_power() { return power; }

void set_function(string str) {
  if(str == "do_wall") return;
  wall_func = str;
  return;
}

int move(mixed dest) {
  if(objectp(dest) && living(dest)) return MOVE_NOT_ALLOWED;
  return ::move(dest);
}

void set_dur(int dur) {
  call_out("wink_out", dur);
  return;
}

void wink_out() {
  message("info", "%^BOLD%^%^GREEN%^"+query_short()+" winks out of existence.",
    environment());
  remove();
}

void create() {
  ::create();
  set_storage_key("wall");
  set_short("A wall");
  set_long("A wall");
  set_name("wall");
  set_id(({ "wall" }));
  wall_func = 0;
  saveable = 0;
  power = 1;
  verb = 0;
  return;
}

void set_verb(string str) { verb = str; }

void set_save() { saveable = 1; }

int query_is_locker() {
  return saveable;
}

void restore_locker(string file) {
  if(!file_exists(DIR_OBJECTS+"/"+file+".o")) return;
  restore_object(DIR_OBJECTS+"/"+file);
  return;
}

void init() {
  ::init();
  if(verb)
    add_action("do_wall", verb);
  return;
}

string query_short() {
  if(!verb) return ::query_short();
  else return ::query_short() + " blocking the "+verb+" exit";
}

int do_wall(string null) {
  int res;

  if(!wall_func) return 0;
  res = call_other(this_object(), wall_func, this_player());
  return res;
}

