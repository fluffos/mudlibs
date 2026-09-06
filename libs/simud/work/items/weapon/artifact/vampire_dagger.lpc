// NOTE: This item is not meant for usage by players at large, if I catch
// anyone making them easily craftable, I will personally string him up
// and shove carrots up his nose and stuff... - Al

inherit "/battle/weapon";

NAME( "vampire dagger" )
ALT_NAME( ({"dagger"}) )
LOOK( "This weapon is made from a very strange sort of red steel that seems to "+
      "almost posess a life of it's own. The blade is long (about 20 cm) and very "+
      "narrow (barely 1 cm). It does not look like the most pleasant thing to be "+
      "stuck with." )
DISTANT( "a thin red dagger" )
SPECIFIC( "the thin red dagger" )
PLURAL( "thin red daggers" )
TYPE( "weapon" )
WEAPON_TYPE( "dagger" )
TASTE( "It tastes like pennies!" )

WEIGHT( 250 )
VALUE( 10000 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["piercing":5]) );
   set_requirement( (["cha":11]) );
   set_max_condition(100);
}

mixed on_attack(object victim) {
  string message;
  int damage, unholy = 0, hp;
  mapping wc = ([]);

  if (!objectp(victim))
    return ({ "miss", 0, "~Npos dagger twitches in ~poss hand." });

  wc = copy(this_object()->query_wc());

  wc["piercing"] += (this_player()->query_charm() - 10) / 2;
  damage = victim->take_damage(wc);

  if (random(100) < 10) {
    unholy = victim->take_damage( (["unholy":this_player()->query_charm() / 2]) );
    message = "Black light engulfs ~Name as ~poss blade draws from ~poss life force.";
    hp = this_player()->query_max_hp() * unholy / 150;
    this_player()->add_hp(-hp);
  }

  return ({"hit", damage + unholy, message});
}

mapping query_aspects() {
   return ([ C_WEAPON, C_DAGGER, C_METAL, C_STEEL, C_BLADE, C_HILT, C_GUARD, C_POMMEL ]);
}
