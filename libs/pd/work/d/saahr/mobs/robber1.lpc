#include <std.h>
#include <saahr.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("robber");
  set_id(({"robber","cloaked robber"}));
  set_race("human");
  set_body_type("human");
  set_gender("male");
  set_short("Cloaked Robber");
  set_long("The robber is thin and wirey. His cloak hangs very loosely over "
    "his body. Dark eyes flash from under the hood.");
  
  set_class("rogue");
  set_subclass("thief");
  set_level(45);

  set_skill("stealing",250);
  set_stats("dexterity",80);

  set_spells(({"stab", "dirt"}));
  set_spell_chance(15);

  set_swarm(1);
  set_aggressive(30);

  set_inventory( ([
    WEP+"robberdagger" : "wield dagger",
    ARM+"robbercloak" : "wear cloak",
  ]) );

  set_emotes(6,
    ({"%^CYAN%^The cloaked robber exclaims:%^RESET%^ That stupid nymph "
        "never even knew we were there!%^RESET%^",
      "%^CYAN%^The cloaked robber exclaims:%^RESET%^ That jewelry is gonna make "
        "us rich!%^RESET%^",
      "%^CYAN%^The cloaked robber says:%^RESET%^ Boy, burying it and coming back "
        "for it sure was a good idea. I'm glad I thought of it."}),
  0);
}

