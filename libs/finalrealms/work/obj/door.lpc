inherit "std/object";

#define SKILL "other.covert.lockpick"

string type, source, dest, direc, reverse, key;
int obvious_from_dest, obvious_from_source, lock_on_source, lock_on_dest;
int locked, attached, difficulty;

void create() {
  ::create();
  attached = 0;
  direc = "left";
  reverse = "right";
  source = "/std/room";
  dest = "/std/room";
  locked = 1;
  key = "normal";
  lock_on_source = 1;
  lock_on_dest = 1;
  obvious_from_source = 1;
  obvious_from_dest = 1;
  type = "door";
  difficulty = 50;
}

void set_difficulty(int num) {
  difficulty = num;
}

void set_type(string str) {
  type = str;
}

void set_key(string str) {
  key = str;
}

void set_direction(string str1, string str2) {
  direc = str1;
  reverse = str2;
}

void set_obvious_from_source(int val) {
  obvious_from_source = val;
  if(!attached)
    return;
  if(obvious_from_source)
    source->add_extra_look(this_object());
  else
    source->remove_extra_look(this_object());
}

void set_obvious_from_dest(int val) {
  obvious_from_dest = val;
  if(!attached)
    return;
  if(obvious_from_dest)
    dest->add_extra_look(this_object());
  else
    dest->remove_extra_look(this_object());
}

void set_lock_on_source(int val) {
  lock_on_source = val;
}

void set_lock_on_dest(int val) {
  lock_on_dest = val;
}

void set_source(string str) {
  source = str;
}

void set_dest(string str) {
  dest = str;
}

void set_locked(int state) {
  locked = state;
}

int query_difficulty() {
  return difficulty;
}

int query_obvious_from_dest() {
  return obvious_from_dest;
}

string query_key() {
  return key;
}


int query_obvious_from_source() {
  return obvious_from_source;
}

int query_lock_on_source() {
  return lock_on_source;
}

int query_lock_on_dest() {
  return lock_on_dest;
}

string query_type() {
  return type;
}

string query_direc() {
  return direc;
}

string query_reverse() {
  return reverse;
}

string query_source() {
  return source;
}

string query_dest() {
  return dest;
}


int query_locked() {
  return locked;
}

void attach() {
  string dir;

  attached = 1;
  if((dir = (string)source->query_exit(direc)) && dir == dest)
    source->remove_exit(dir);
  source->add_exit(direc, dest, type);
  if((dir = (string)dest->query_exit(reverse)) && dir == source)
    dest->remove_exit(dir);
  dest->add_exit(reverse, source, type);
  source->modify_exit(direc, ({ "function", ({ file_name(this_object()), "unlocked" }) }));
  dest->modify_exit(reverse, ({ "function",  ({ file_name(this_object()), "unlocked" }) }));
  source->modify_exit(direc, ({ "obvious", ({ file_name(this_object()), "obvious1" }) }));
  dest->modify_exit(reverse, ({ "obvious", ({ file_name(this_object()), "obvious2" }) }));
  if(locked) {
    source->add_item(direc+" door", "It is locked.\n");
    dest->add_item(reverse+" door", "It is locked.\n");
  }
  else {
    source->add_item(direc+" door", "It is unlocked.\n");
    dest->add_item(reverse+" door", "It is unlocked.\n");
  }
  source->add_alias("door", direc+" door");
  dest->add_alias("door", reverse+" door");
  if(lock_on_source) {
    source->add_alias("lock", direc);
    source->add_alias("unlock", direc);
  }
  if(lock_on_dest) {
    dest->add_alias("unlock", reverse);
    dest->add_alias("lock", reverse);
  }
  if(obvious_from_dest)
    dest->add_extra_look(this_object());
  if(obvious_from_source)
    source->add_extra_look(this_object());
}

int lock(string str) {
  int lvl;

  if(!sizeof(find_match(key + " key", this_player())) && !sizeof(find_match("master key", this_player()))) {
    lvl = (int)this_player()->query_skill_bonus(SKILL);
    if(random(lvl) <= lvl - difficulty)
      write("You pick the lock.\n");
    else {
      write("You don't have the right key.\n");
      return 0;
    }
  }
  if(locked) {
    write("The door is already locked.\n");
    return 0;
  }
  locked = 1;
  write("click\n");
  say(this_player()->query_cap_name() + " locks the door.\n");
  source->modify_item(direc + " door", "It is locked.\n");
  dest->modify_item(reverse + " door", "It is locked.\n");
  return 0;
}

int unlock(string str) {
  int lvl;

  if(!sizeof(find_match(key + " key", this_player())) && !sizeof(find_match("master key", this_player()))) {
    lvl = (int)this_player()->query_skill_bonus(SKILL);
    if(random(lvl) <= lvl - difficulty)
      write("You pick the lock.\n");
    else {
      write("You don't have the right key.\n");
      return 0;
    }
  }
  if(!locked) {
    write("The door is already unlocked.\n");
    return 0;
  }
  locked = 0;
  write("click\n");
  say(this_player()->query_cap_name() + " unlocks the door.\n");
  source->modify_item(direc + " door", "It is unlocked.\n");
  dest->modify_item(reverse + " door", "It is unlocked.\n");
  return 0;
}

int unlocked(string str) {
  notify_fail("");
  if(query_verb() == "lock")
    return lock(str);
  if(query_verb() == "unlock")
    return unlock(str);
  if(!obvious_from_source && file_name(previous_object()) == source)
    return 0;
  if(!obvious_from_dest && file_name(previous_object()) == dest)
    return 0;
  if(locked)
    write("The door is locked.\n");
  return !locked;
}

int obvious1() {
  return obvious_from_source;
}

int obvious2() {
  return obvious_from_dest;
}

string extra_look() {
  if(file_name(previous_object()) == dest)
    return "A door leads " + reverse + "." + "\n";
  if(file_name(previous_object()) == source)
    return "A door leads " + direc + "." + "\n";
  return "";
}
