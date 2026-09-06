#include <const.h>
inherit "/obj/monster";

void teach_phrase( string text, object actor, object target );

DISTANT( "?(RECO("+query_name()+" the Jack O' Lantern):"+query_cap_name()+"):(an animated jack o' lantern)" )
SPECIFIC( "?(RECO("+query_name()+"):"+query_cap_name()+"):(the jack o' lantern)" )
LOOK( "A floating pumpkin with a face carved out of the front. Flames flicker out of the eyes an mouth, and form stubby little arms and legs. ~Pron is $(HP)." )
PLURAL( "jack o' lanterns" )
TYPE( "summon" )
ALT_NAME( ({ "jack", "lantern", "jackolantern", "jack-o-lantern" }) )
ALT_PLURAL( ({ "jacks", "lanterns", "jackolanterns", "jack-o-lanterns" }) )

void create() {
   ::create();
   set_gender( 0 );
/* OBJEDIT { */
   set_spd( 20 );
   set_con( 10 );
   set_str( 5 );
   set_dex( 10 );
   set_wil( 20 );
   set_cha( 5 );
   set_int( 5 );
   set_emp( 5 );
   set_droppable( 1 );
   set_weight( 5000 );
/* } OBJEDIT */

   set_race("generic");
   set_name( lower_case("/daemon/namegen"->get_dark_name()) );
   set_living_name( query_name() );

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   set_movement_type("float");

   set_known_forms( (["brawl": ({"punch","headbutt","dodge"}) ]) );
   set_form("brawl", 1);

   set_skill( "combat.weapon.unarmed", 25 );
   set_skill( "combat.dodging", 75 );
   set_skill( "magic.mana.earth", 25 );
   set_skill( "magic.mana.wind", 25 );
   set_skill( "magic.mana.fire", 50 );
   set_skill( "magic.technique.charming", 25 );
   set_skill( "magic.technique.dancing", 25 );
   set_skill( "magic.technique.charming", 25 );

   add_spell( "invigorate" );
   add_spell( "fire bolt" );

   set_wc((["fire":8]));
   set_base_ac( 5 );
   set_ac_mod( ([ "fire": 80, "ice": -20, "edged": -5,
				  "piercing": -10, "blunt": 5 ]) );
				
   set_wimpy(0);
}

void on_death(object what) {
	if( what == this_object() ) {
		object pumpkin = clone_object("/econ/crop/pumpkin");
		int coord = this_object()->query_coord();
		command("drop all");
		pumpkin->move(environment());
		pumpkin->set_coord(coord);
		pumpkin->validate_position();
		msg_local("~CBRT~Name ~verbemit a high pitched wailing noise that gradually fades...~CDEF");
		call_out("dest_me",1);
	}
}
void dest_me() {
	destruct(this_object());
}

void on_combat_tick( object form ) {
	command("cast fire bolt");
}

void on_hunger() {
	set_food(100);
	set_drink(100);
}

int time_to_live;
void on_tick() {
	time_to_live--;
	if( time_to_live > 0 )
		command("emote shudders briefly.");
	if( !time_to_live )
		die();
}

void set_time_to_live(int x) { time_to_live = x; }
int query_time_to_live() { return time_to_live; }

string *query_default_ai() {
   return ({ "worker", "talk", "assist" });
}

ICON( 'j', 3, LAYER_LIVING )
