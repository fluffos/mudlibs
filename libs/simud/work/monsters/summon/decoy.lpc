#include <const.h>
inherit "/obj/monster";

DISTANT( "a decoy spirit" )
SPECIFIC( "the decoy spirit" )
LOOK( "A green earth spirit. ~Pron is $(HP)." )
NAME( "decoy" )
PLURAL( "decoys" )
ALT_NAME( ({ "spirit", "earth spirit", "decoy spirit" }) )
ALT_PLURAL( ({ "spirits", "earth spirits", "decoy spirits" }) )
DROPPABLE( 1 )
WEIGHT( 5000 )
TYPE( "summon" )

void create() {
   ::create();
   set_gender( 0 );
/* OBJEDIT { */
   set_spd( 5 );
   set_con( 20 );
   set_str( 5 );
   set_dex( 10 );
   set_wil( 20 );
   set_cha( 5 );
   set_int( 5 );
   set_emp( 5 );
/* } OBJEDIT */

   set_race("generic");

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   set_default_doing("floating barely above the ground");
   set_movement_type("float");

   set_known_forms( (["brawl": ({"dodge"}) ]) );
   set_form("brawl", 1);

   set_skill( "combat.dodging", 75 );

   set_base_ac( 50 );
				
   set_wimpy(0);
}

void setup( string master, int power ) {
	set_endurance( 100 );
	set_hp( power * 4 + 100 );
	set_mana( query_max_mana() );
	command( "defend "+master, this_object() );
}

void on_death(object what) {
	if( what == this_object() ) {
		msg_local("~CBRT~Name ~verbemit a high pitched wailing noise that gradually fades...~CDEF");
		call_out("dest_me",1);
	}
}
void dest_me() {
	destruct(this_object());
}

void on_hunger() {
	set_food(100);
	set_drink(100);
}

void heart_beat() {
	if( !environment() )
		return;
	::heart_beat();
	if( !query_in_combat() )
		add_mana( -1 );
	if( query_mana() < 1 )
		die();	
}

ICON( 'd', 10, LAYER_LIVING )
