#include <std.h>
#include <tirun.h>

inherit VAULT;

void create() {
 ::create();
    set_short("North Parthos Road.");
    set_long(
      "Parthos Road is lightly traveled.  Houses line the road to the north and east. "
      "Built against the city wall, these houses are not much more than shacks.  "
      "The ancient stones underfoot running west and south make the road easy "
      "to follow. "
);
    set_night_long(
      "Running north and south through the northeast section of Tirun, "
      "Dovin Road is peaceful at night.  Shadows to the north and east show themselves "
      "to be buildings built against the city wall.  The stones underfoot are "
      "hard to make out in the darkness. "
);
    set_exits( 
              (["west" : ROOMS"edovin5",
                "south" : ROOMS"nparthos6",
"house" : ROOMS"houses/cookie1",
]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );

set_door("door", ROOMS"houses/cookie1", "house", "cookie_key");
  set_open("door", 0);
  set_locked("door", 1);
}

void reset() {
  ::reset();
  if(!present("manor", this_object()))
new("/d/nopk/tirun/obj/houses/cookie")->move(this_object());
}

int pick_lock(string str) {
  if(find_player("cookie"))
    if(interactive(find_player("cookie")))
      message("info", "%^BOLD%^%^BLUE%^S%^RED%^o%^BLUE%^m%^RED%^e%^BLUE%^o%^RED%^n%^BLUE%^e%^RED%^ i%^BLUE%^s%^RED%^ b%^BLUE%^r%^RED%^e%^BLUE%^a%^RED%^k%^BLUE%^i%^RED%^n%^BLUE%^g %^RED%^i%^BLUE%^n%^RED%^t%^BLUE%^o %^RED%^y%^BLUE%^o%^RED%^u%^BLUE%^r%^RED%^ h%^BLUE%^o%^RED%^m%^BLUE%^e%^RED%^!%^RESET%^", find_player("cookie"));
  return ::pick_lock(str);
}

void init() {
  ::init();
  add_action("move", "move");
}

int move(string str) {
  if(!str) return 0;
  if(str != "stone") return 0;
  if(this_player()->query_name() != "cookie")
    write("You poke around the stones, but dont know which one to move.");
  else {
    write("You move a secret stone and grab your spare keys.");
    new(ROOMS"houses/cookiekey")->move(this_player());
    new(ROOMS"houses/cookiekey2")->move(this_player());
  }
  return 1;
}
