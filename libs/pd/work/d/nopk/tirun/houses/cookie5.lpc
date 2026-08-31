#include <std.h>
#include <tirun.h>

inherit VAULT;

void create() {
  ::create();
  set_properties(([ "light" : 2,
                  "indoors" : 1
                 ]));
  set_short("Upstairs");
  set_long("You stumble up the last of the twisted stairs and enter into the second floor "
           "Of the home. You have three doors up here to chose from, all look very similar, "
           "with the exception of an etching in the door to your east.");
//  set_smell("default","Oak with a hint of unknown spice.");
  set_exits((["down" : ROOMS"houses/cookie2",
              "west" : ROOMS"houses/cookie6",
              "east" : ROOMS"houses/cookie7",
              "south" : ROOMS"houses/cookie8"]));
  set_items((["etching" : 
"   /\\  /\\\n"
"  /  \\/  \\\n"
" /   JRP  \\\n"
" \\    &   /\n"
"  \\  ECH /\n"
"   \\    /\n"
"    \\  /\n"
"     \\/\n" ]));
  set_door("south door", ROOMS"houses/cookie8", "south", "cookie_key");
  set_open("south door", 0);
  set_locked("south door", 1);
  set_door("east door", ROOMS"houses/cookie7", "east", "cookie_key_master");
  set_open("east door", 0);
  set_locked("east door", 1);
  set_door("west door", ROOMS"houses/cookie6", "west", "cookie_key");
  set_open("west door", 0);
  set_locked("west door", 1);
}

void reset() {
  ::reset();
  set_open("east door", 0);
  set_locked("east door", 1);
  set_open("west door", 0);
  set_locked("west door", 1);
  set_open("south door", 0);
  set_locked("south door", 1);
  ROOMS"houses/cookie6"->set_open("door", 0);
  ROOMS"houses/cookie6"->set_locked("door", 1);
  ROOMS"houses/cookie7"->set_open("door", 0);
  ROOMS"houses/cookie7"->set_locked("door", 1);
  ROOMS"houses/cookie8"->set_open("door", 0);
  ROOMS"houses/cookie8"->set_locked("door", 1);
}

int pick_lock(string str) {
  if(find_player("cookie")) {
    if(interactive(find_player("cookie"))) {
      if(str == "east door")
      message("info", "%^YELLOW%^The master bedroom is being lockpicked!", find_player("cookie"));
      else
      message("info", "%^BLUE%^S%^RED%^o%^BLUE%^m%^RED%^e%^BLUE%^o%^RED%^n%^BLUE%^e%^RED%^ i%^BLUE%^s%^RED%^ b%^BLUE%^r%^RED%^e%^BLUE%^a%^RED%^k%^BLUE%^i%^RED%^n%^BLUE%^g %^RED%^i%^BLUE%^n%^RED%^t%^BLUE%^o %^RED%^y%^BLUE%^o%^RED%^u%^BLUE%^r%^RED%^ h%^BLUE%^o%^RED%^m%^BLUE%^e%^RED%^!%^RESET%^", find_player("cookie"));
    }
  }
  if(str == "east door") {
    write("%^BOLD%^The door glows with a magical power.");
    if(this_player()->query_skill("locks") > random(100) + 50)
      return 0;
  }
  return ::pick_lock(str);
}
