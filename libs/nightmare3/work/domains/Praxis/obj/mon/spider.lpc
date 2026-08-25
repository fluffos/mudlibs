//  /domains/Praxis/obj/mon/spider.c
//  Semi-Random spiders for the Pit of Spiders
//  Part of the Mortal Law system at Nightmare
//  Created by Manny@Nightmare 940831
 
#include <std.h>
 
inherit MONSTER;
 
create() {
  ::create();
  set_name("spider");
  switch(random(5)) {
    case 0:
      set_id( ({ "spider", "leaper", "black leaper" }) );
      set_short("Black Leaper");
      set_long("There are few spiders larger and more greusome than "
          "the infamous Black Leaper..");
      set_level(20);
      set_spell_chance(50);
      break;
    case 1:
    case 2:
      set_id( ({ "spider", "timber spider", "giant timber spider" }) );
      set_short("Giant Timber Spider");
      set_long("A very large and ugly grey spider.  It looks quite "
          "hungry.");
      set_level(random(3)+12);
      set_spell_chance(20);
      break;
    default:
      set_id( ({ "spider", "cave spider" }) );
      set_short("Praxis cave spider");
      set_long("A medium-sized black spider with a cresent-shaped "
          "moon on its tail end.");
      set_level(random(3)+8);
      break;
  }
  set_race("insect");
  set_gender("male");
  set_body_type("insectoid");
  set_spells( ({"poison"}) );
  set_aggressive(999999);
  set_die( (:"death_func":) );
}

int death_func() {
  message("say", "%^RED%^"+this_object()->query_name()+" squeals out "
      "a loud shreak, then falls dead.", environment(this_object()));
  if(!present("spider", environment(this_object()))) {
    int x;
    
    message("say", "%^RED%^You notice additional spiders "
        "creeping in from cracks at the base of the pit!", 
        environment(this_object()));
    for(x=0; x<10; ++x) {
      new("/"+__DIR__+"obj/mon/spider")->move(environment(this_object()));
    }
  }
  return 1;
}
