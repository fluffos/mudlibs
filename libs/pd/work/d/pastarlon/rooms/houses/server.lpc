#include <std.h>
#include <pastarlon.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(1);
  set_first_sentence("%^BOLD%^%^BLACK%^Dark storm clouds cover the sky.\n %^RESET%^%^BOLD%^The house has been run down and torn apart.%^RESET%^");
  set_day_sentances( ({
      "There isn't much to see here, it is a fairly depressing house.  There is a broken couch and bookcase, with shards of glass littering the ground around both of them.  A staircase is blocked off by a pile of rubble where the upstairs seems to caved in.  A tapestry is on the wall, although it is slashed into many sections.  The only sign that anything was living here is a pile of bones in the corner of the room.",
 
  }) );
  set_night_sentances( ({
      "There isn't much to see here, it is a fairly depressing house.  There is a broken couch and bookcase, with shards of glass littering the ground around both of them.  A staircase is blocked off by a pile of rubble where the upstairs seems to caved in.  A tapestry is on the wall, although it is slashed into many sections.  The only sign that anything was living here is a pile of bones in the corner of the room.",
      
  }) ); 
  set_item_list( ([
      ({"staircase"}) : "The staircase which would lead upstairs is blocked off by a pile of rubble, as the top level of the house seems to have collapsed.",
      ({"bookcase", "book case"}) : "The bookcase is a mere pile of wood on the floor now, only recognizable from the charred books throughout the pile.",
      ({"tapestry"}) : "The tapestry has been torn to pieces, although it still falls together to show a lion.",
      ({"rubble", "pile of rubble"}) : "The rubble is filled with wood, which seems to have been part of the house before the upstairs collapsed.",
      ({"couch"}) : "The couch is broken in half, quite literally.  There is straw falling out through the tears in it.",
      ({"bones"}) : "It seems as if someone forgot to clean up after removing the residents of this house..",

  ]) );
  set_smell("The scent of death and decay overpowers the living room.");
  set_listen("Fighting, screaming, and crying can be heard outside the house.");

  set_reset_list( ({
     MOB"drowinvader", MOB"drowinvader2", MOB"drowinvader3", MOB"drowinvader4" 
  }) );
  set_properties( ([ "light" : 1,
                     "night light" : 1,
                     "indoors" : 1,
                     "house" : 1
                   ]) );
  set_short("The houses of Arlon.");
  set_mob_cap(4);
}
