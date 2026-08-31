#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
   object money;
   ::create();
   set_name("resident");
   set_id( ({ "resident", "man" }) );
   set_short("a new resident");
   set_long("You see a young man dressed in ordinary clothes.  He has calluses "+
      "on his hands, evidence to his attitude of hard work and honesty.\n");
   set_emotes(1,({ "The man smiles at you and shows off the new house he bought." }),0 );
   set_level(8);
   set("race", "human");
   set_body_type("human");
   set_gender("male");
   set("aggressive", 0);
   set_alignment(0);
   money = new("/std/obj/coins");
   money->set_money("gold", 4*(1+random(BASE_GOLD))+(random(BASE_GOLD)));
   money->move(this_object());
}

