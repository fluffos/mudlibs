
#include <std.h>
#include <saahr.h>

inherit MONSTER;

void create() {
  ::create();
  set_race("goblin");
  set_body_type("human");
  set_gender(({"male","male","female"})[random(3)]);
  set_class("fighter");
  switch (random(5)) {
    case 0 :  case 1 :
      set_id(({"goblin", "scavenging goblin"}));
      set_short("a scavenging goblin");
      set_long("The goblin is pretty skinny and wearing only rags. "
        +query_subjective()+" glares around with a feral look "
        "and flexes "+query_possessive()+" clawed fingers.");
      set_level(35+random(3));
      set_aggressive(25+random(3));
    break;
    case 2 :  case 3 :
      set_id(({"goblin", "nasty goblin"}));
      set_short("a nasty goblin");
      set_long("This goblin is small but very mean. "+query_possessive()+
        " beady eyes dart around looking for something to break or hurt. "
        "Dirt is all over "+query_possessive()+" clothes and skin.");
      set_level(39+random(2));
      set_subclass("warrior");
      set_spells(({"jab"}));
      set_spell_chance(50);
      set_aggressive(30+random(6));
    break;
    case 4 :  default :
      set_id(({"burly goblin", "goblin"}));
      set_short("a burly goblin");
      set_long("A very big, strong goblin. Muscles ripple all over "
        +query_possessive()+" arms and body. "+query_subjective()+
        "looks around and flexes "+query_possessive()+" entire forehead. "
        "Yikes!");
      set_subclass("berserker");
      set_level(40+random(3));
      set_stats("strength",75);
      set_skill("melee",200);
      set_skill("attack",200);
      set_spells(({"headbutt"}));
      set_spell_chance(40);
      set_aggressive(35+random(4));
    break;
  }
  set_name(remove_article(query_short()));
  set_inventory( ([
    ARM+"goblinrags" : "wear rags",
  ]) );
}
    
