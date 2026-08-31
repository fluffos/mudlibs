#include <std.h>
#include <tirun.h>

inherit ROOM;

int found;

void create() {
    ::create();
    set_smell("default", "Fresh air blows in from a broken window.");
    set_listen("default", "Silence.");
    set_properties((["light":1, "no teleport":1, "indoors":1]));
    set_short("Haunted House");
    set_long(
        "%^CYAN%^This room does not feel uninhabited...%^RESET%^\n"
        "This is the dining room of the old mansion.  Places are set at the table "
        "for two people, and a large dish sits in a corner of the room.  Rubble has "
        "piled up over the passage to the kitchen, making it inaccessible.  There is "
        "no old food left out, it seems to have been all eaten by the different rodents "
        "of the house.");
    set_items(
        (["places" : "It seems as if a place was set for the owner of the house and one guest.",
          "leash" : "The leash has been broken, letting whatever was attached loose.",
          "rubble" : "Large pieces of wood, chairs, and other debris has covered the doorway."]) );
    set_exits( ([ "west" : ROOMS"hhouse/1" ]) );
}

void reset() {
  ::reset();
  found = 0;
}

void init() {
  ::init();
  add_action("look", "look");
}

int look(string str) {
  object ob;
  if(!str) return 0;
  if(str == "dish") {
    if(!found)
      write("An overly large food dish for an animal is left in the corner.  A large leash type chain rests broken next to it.  There also seems to be a bone in the dish.");
    else
      write("An overly large food dish for an animal is left in the corner.  A large leash type chain rests broken next to it.");
    return 1;
  }
  if(str == "bone") {
    if(found) return 0;
    write("After digging around in the food, you realize the 'bone' is actually a lever of some sort.  You figure it's important, so you take it.");
    say(this_player()->query_cap_name()+" digs around in the food bowl and pulls out a stick-like thing.");
    ob = new(OBJECT);
    ob->set_short("lever");
    ob->set_name("lever");
    ob->set_id(({"lever", "lever_qo"}));
    ob->set_weight(4);
    ob->set_long("This lever seems to have come off of some wall somewhere.  It's pretty useless by itself.");
    ob->move(this_player());
    found = 1;
    return 1;
  }
  return 0;
}
