#include <std.h>
#include <saahr.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("robber");
  set_id(({"robber", "fat robber"}));
  set_race("human");
  set_body_type("human");
  set_gender("male");
  set_short("Fat Robber");
  set_long("This guy is pretty big and hefty. His clothes are all dirty "
    "but there could be some muscle under that fat.");

  set_class("rogue");
  set_subclass("thug");
  set_level(42);

  set_stats("strength",90);

  set_spells(({"headbutt", "clobber", "bash"}));
  set_spell_chance(30);

  set_swarm(1);
  set_aggressive(30);

  set_inventory( ([
    WEP+"shovel" : 1,
  ]) );

  set_emotes(6,
    ({"%^CYAN%^The fat robber says:%^RESET%^ Heehee, she sure was a looker.%^RESET%^",
      "%^CYAN%^The fat robber exclaims:%^RESET%^ Let's hurry and go sell it!%^RESET%^",
      "The fat robber daydreams about how much barbeque chicken he'll buy."}),
  0);
}

int is_invincible() {
  command("say You'll never find where we hid it!");
  command("wield shovel");
  return 0;
}
