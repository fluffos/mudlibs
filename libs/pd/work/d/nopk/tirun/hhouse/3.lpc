#include <std.h>
#include <tirun.h>

inherit ROOM;

int armour;

void create() {
    ::create();
    set_smell("default", "Thick dust makes breathing difficult.");
    set_listen("default", "Silence.");
    set_properties((["light":1, "no teleport":1, "indoors":1]));
    set_short("Haunted House");
    set_long(
      "%^ORANGE%^A creaking sound comes from somewhere.%^RESET%^\n "
      "This room of the house was decorated in a somewhat old "
      "fashion.  A knight's armour stands to one side, and a large "
      "tapestry hangs from the opposite wall.  A set of old, unsafe "
      "stairs leads up to the second story.  The room is filled with "
      "all sorts of shadows.  Every step made in this room creaks loudly, announcing "
      "each visitor.");
    set_items(
      (["shadows" : "The shadows are quite hard to see into.",
	"stairs" : "Old and rickety, these stairs havent been used in ages
because of the danger.",
          "armour" : "The ancient armour is a bit rusty, but might be useable. 
There seems to be something inside it, though.",
          "tapestry" : "Tattered and full of holes, the tapestry looks like it
used to portray a large lizard."]) );
    set_exits( ([ "south" : ROOMS"hhouse/1",
                  "stairs" : ROOMS"hhouse/upstairs" ]) );
    armour = 0;
}

void init() {
  ::init();
  add_action("search", "search");
}

void reset() {
  ::reset();
  remove_exit("shadows");
  armour = 0;
}
int search(string str) {
  object mon;
  if(!str) return 0;

  if(str == "armour" && armour)
    return 0;

  if(str == "armour") {
    write("The armour comes to life and attacks you!");
    say(this_player()->query_cap_name()+" fiddles with the armour and makes it
angry!");
    mon = new(UNDEAD);
    mon->set_level(3+random(2));
    mon->set_name("armour");
    mon->set_short("An angry suit of armour");
    mon->set_long("This suit of armour has a life of it's own and blindly
swings at anything it comes across.");
    mon->set_id(({"monster","armour","suit of armour"}));
    mon->set("agressive",100);
    mon->set_race("armour");
    mon->set_body_type("human");
    mon->set_gender("neuter");
    mon->move(this_object());
    mon->kill_ob(this_player());
    armour = 1;
  }

  if(str == "shadow" || str == "shadows") {
    write("In the shadows you see an opening underneath the stairs.");
    say(this_player()->query_cap_name()+" peers closely into the shadows.");
    add_exit(ROOMS"hhouse/outside", "shadows");
  }
  return 1;
}
