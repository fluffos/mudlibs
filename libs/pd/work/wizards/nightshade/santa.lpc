#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("Santa Claus");
  set("id",({"santa","santa claus","monster"}));
  set_level(1);
  set("short","Santa Claus");
  set("long","The jolly santa grabs his belly and chuckles.  If you <have a seat> on his lap, you might get a present!");
  set("race","human");
  set_gender("male");
  set_body_type("human");
/*
  set_emotes(20, ({
    "%^RESET%^%^CYAN%^Santa Claus says: %^RESET%^HO HO HO!",
    "Santa adjusts the pack upon his back."
  }), 0);
*/
  set_alignment(1500);
  set_overall_ac(50);
}

void init() {
  ::init();
  add_action("have","have");
}

int have(string str) {
  object ob;

  if(str != "a seat")
    return 0;

  write("You sit on Santa's lap!\n\n%^RESET%^%^CYAN%^Santa Claus asks: %^RESET%^And what would you like for christmas?");

  write("Santa sticks a candy cane in your mouth before you can reply!");

  say(this_player()->query_cap_name()+" sits on santa's lap and gets a candy cane!");

  ob = new(FOOD);
  ob->set_name("cane");
  ob->set_short("a %^BOLD%^%^RED%^c%^WHITE%^a%^RED%^n%^WHITE%^d%^RED%^y%^WHITE%^ c%^RED%^a%^WHITE%^n%^RED%^e%^RESET%^");
  ob->set_strength(3+random(7));
  ob->set_id(({"candy", "cane", "candy cane", "food"}));
  ob->set_long("It's a tasty %^BOLD%^%^RED%^c%^WHITE%^a%^RED%^n%^WHITE%^d%^RED%^y%^WHITE%^ c%^RED%^a%^WHITE%^n%^RED%^e%^RESET%^!");
  ob->move(this_player());

  return 1;
}
