#include <std.h>
#include <tirun.h>

inherit VAULT;

void create() {
  ::create();
  set_properties(([ "light" : 2,
                  "indoors" : 1,
                  "town" : 1,
                 ]));
  set_short("Entrance");
set_long("The entrance of Cookie's home. The simple trimmings are "
         "done in an english Oak. The house has a warm and cozy feel to it.");
  set_smell("default","Oak with a hint of unknown spice.");
  set_exits((["out" : ROOMS"nparthos7",
              "north" : ROOMS"houses/cookie2",
              "east" : ROOMS"houses/cookie3"]));
  set_door("door", ROOMS"nparthos7", "out", "cookie_key");
  set_open("door", 0);
  set_locked("door", 1);
}

void reset() {
  ::reset();
  set_open("door", 0);
  set_locked("door", 1);
  ROOMS"nparthos7"->set_open("door", 0);
  ROOMS"nparthos7"->set_locked("door", 1);
}

int pick_lock(string str) {
  if(find_player("cookie"))
    if(interactive(find_player("cookie")))
      message("info", "%^BOLD%^%^BLUE%^S%^RED%^o%^BLUE%^m%^RED%^e%^BLUE%^o%^RED%^n%^BLUE%^e%^RED%^ i%^BLUE%^s%^RED%^ b%^BLUE%^r%^RED%^e%^BLUE%^a%^RED%^k%^BLUE%^i%^RED%^n%^BLUE%^g %^RED%^i%^BLUE%^n%^RED%^t%^BLUE%^o %^RED%^y%^BLUE%^o%^RED%^u%^BLUE%^r%^RED%^ h%^BLUE%^o%^RED%^m%^BLUE%^e%^RED%^!%^RESET%^", find_player("cookie"));
  return ::pick_lock(str);
}
