#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(10)
NAME( "towel" )
ALT_NAME( ({"pink towel"}) )
DISTANT( "a pink towel" )
LOOK( "It's a fluffy pink towel, with embossed palm tree designs on it.")
SPECIFIC( "the pink towel" )
PLURAL( "pink towels" )
ALT_PLURAL( ({ "towels" }) )
WEIGHT( 700 )
TASTE( "It tastes vaguely of coconuts." )

void create() {
   ::create();
   set_base_ac(5);
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(10);
   set_body_parts(BP_LEGS);
}

mapping query_aspects() {
   return ([ C_CLOTHING, C_PANTS, C_CLOTH ]);
}

void on_attack( mapping wc ) {
   object old_targ, *all_targets, victim, coconut;

   if( random(4) ) return;

   if( member(wc, "coconut") ) return;
   all_targets = filter( all_inventory(environment(this_player())), (:$1->query_is_living():) );
   victim = all_targets[random(sizeof(all_targets))];
   coconut = clone_object( "/econ/seed/coconut" );
   coconut->move(environment(victim));
   old_targ = query_target();
   set_target(victim);
   msg_room( environment(this_player()), "~CACTSuddenly, out of the blue, ~subt ~vertis bonked by a flying coconut!~CDEF");
   set_target( old_targ );
   victim->take_damage( (["coconut":3]), 0 );
   coconut->set_coord( victim->query_coord() );
   coconut->validate_position();
}
