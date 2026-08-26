/*
** File: /adm/obj/follow_ob.c
** Purpose: The driving force behind charm/summoning spells.
**    Allows the holder to essentially force any living object in its
**    "charmed" property (an array of objects) to do almost anything.
**    Certain restrictions apply to users.
** Credits:
**   15 Nov 97  Cyanide created the file.
*/

#define LINE1 \
"=+=--=+=--=+=--=+=--=+=--=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=--=+=\n"

object *followers;

object get_slave(object, string, int);
int do_release(object, object);
string follow_help();

inherit SECURE_OBJECT;

void create() {
  set("id", ({ "#FOLLOWER_OB#" }) );
}

void init() {
  add_action("follower", "follower");
}

int follower(string str) {
  int f_num = 1, t_num = 1;
  string fname, command, tname;
  object slave, target;

  if (!str || str=="help") {
    write( follow_help() );
    return 1;
  }

  if (str=="list") {
    write("follow_list");
    return 1;
  }
  
  followers = (object *)TP->query("charmed");
//followers = filter_array("filter_followers", this_player() ); 

  // These next sscanf's are meant to filter all possible usages of numbers
  // and strings.

  if (sscanf(str, "%s %s", fname, command) != 2)
  if (sscanf(str, "%s %s %s", fname, command, tname) != 3)
  if (sscanf(str, "%s %n %s %s", fname, f_num, command, tname) != 4)
  if (sscanf(str, "%s %s %s %n", fname, command, tname, t_num) != 4)
  if (sscanf(str, "%s %n %s %s %n", fname, f_num, command, tname, t_num)!=5)
  {
    write( follow_help() );
    return 1;
  }

  slave = get_slave(TP, fname, f_num);
  if (!slave) return 1;

  str = command;
  if (tname) str = str + " " + tname;
  if (t_num && (t_num!=1)) str = str + " " + t_num;

  if (command=="release") {
    do_release(slave, TP);
    return 1;
  }

  slave->command(str);
  
  return 1;
}


// This find the object being referred to, determines legality, and
// returns the object designation.

object get_slave(object master, string name, int num) {
  int i, counter;
  object slave = 0;
  string str;

  counter = 0;
  for (i=0;i<sizeof(followers);i++) {
    if (followers[i]->id("name")) counter++;
    if (followers[i]->id("name") && (counter==num))
      slave = followers[i];
  }

  if (!slave) {
    str = "You have no "+name;
    if (num && num!=1) str = str + " " + num;
    str += " as a follower.\n";
  
    tell_object(master, str);
    return 0;
  }

  if (environment(slave) != environment(master)) {
    tell_object(master, slave->query("short")+
      " is not in your vicinity.\n");
    return 0;
  }

  if (userp(slave)) {
    tell_object(master, "That is a user, and may not be charmed.\n");
    return 0;
  }

  return slave;
}


// This little func releases an object from servitude.

int do_release(object slave, object master) {
  followers -= ({ slave });
  master->set("charmed", followers);
  return 1;
}


// The "follow help" module.

string follow_help() {
  string str = LINE1;

  str += (@EndText

You may perform the following actions:
  follower list
  follower release (name)

Typical commands:
  follower (name) follow (name)
  follower (name) protect (name)

You may also use numbers, as follows:
  follower rat 5 get drop sword 1

EndText
);

  str += LINE1;
  return str;
}
