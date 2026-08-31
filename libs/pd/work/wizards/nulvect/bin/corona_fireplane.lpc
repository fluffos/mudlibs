#include <std.h>
#include <daemons.h>
inherit ROOM;

int times;
int start;
string dest;
string exit;
object portal;

int do_exit();
int do_burn();
void setup(int t, string d);
string random_exit();
string get_long();

string random_exit() {
  string *exits =
    ({"north","south","east","west","up","down",
      "northeast", "northwest", "southeast", "southwest"});
  return exits[random(sizeof(exits))];
}

int do_exit(string str) {
  int amt;
  string v=query_verb();

  if (v != exit) return 0;

  if (exit == "out")
    this_player()->move_player(dest, "out of the flames");
  
  else if (--times <= 0) {
    exit = "out";
    this_player()->describe_current_room(1);
  }
  
  else {
    if (this_player()) {
      amt = this_player()->query_max_hp()/15;
      message("info", "%^RED%^The intense flames burn you.%^RESET%^", this_player());
      this_player()->add_hp(-(amt+random(amt/5)-random(amt/3)));
      this_player()->do_direct_damage("torso", 0);
    }
    
    exit = random_exit();
    
    if (times <= 2 && !objectp(portal)) {
      message("info", "%^BOLD%^%^RED%^A huge gaping corona of flame suddenly "
                      "comes into existance.%^RESET%^", load_object(dest));
      portal=clone_object("/cmds/skills/obj/corona_ob");
      portal->move(dest);
    }
    this_player()->describe_current_room(1);
  }
  return 1;
}

void do_burn() {
  int l=0;
  int amt;
  foreach (object what in all_inventory()) {
    if (what->is_living()) {
      l++;
      amt=what->query_max_hp()/16;
      message("info", "%^RED%^The intense flames burn you.%^RESET%^", what);
      what->add_hp(-(amt+random(amt/5)-random(amt/3)));
      what->do_direct_damage("torso",0);
    }
    else {
      message("info", "%^RED%^The intense flames destroy "+
              what->query_name()+"%^RESET%^.", environment(what));
      what->remove();
    }
  }
  if (!l && time()-start > 20) {
    if (objectp(portal)) {
      message("info","%^YELLOW%^The corona surges with flame and vanishes.%^RESET%^\n",
          environment(portal));
      portal->remove();
    }
    this_object()->remove();
  }
  else call_out("do_burn", 6);
}

void setup(int t, string d) {
  times = t;
  dest = d;
  start = time();
  exit = random_exit();
  do_burn();
}

string get_long() {
  return
    "Flames, flames everywhere. Red, orange, yellow, and white-hot "
    "flames leap and dance in every direction. The ground seems to be made "
    "of solid fire, and even the air is burning.\n\n"
    "%^GREEN%^There seems to be a way through the fire: "+exit;
}

void init() {
  ::init();
  add_action("do_exit", "", 1);
}

void create() {
  ::create();
  set_properties(([ "light" : 2, "no teleport" : 1 ]));
  set_short("Plane of Fire");
  set_long( (: get_long :) );
  set_smell("default","A scorching smell fills the air and chokes the lungs.");
  skip_obvious();
}


