#include <const.h>
inherit "/obj/monster";

void teach_phrase( string text, object actor, object target );

DISTANT( "?(RECO("+query_name()+"):"+query_cap_name()+"):(a peasant)" )
SPECIFIC( "?(RECO("+query_name()+"):"+query_cap_name()+"):(a peasant)" )
LOOK( "A fine example of your typical homo sapiens. This one appears to be agriculturally occupied. ~Pron is $(HP)." )
PLURAL( "peasants" )
TYPE( "human" )
ALT_NAME( ({ "peasant" }) )

void self_destruct() {
   destruct(this_object());
}

int twins_of(string name) {
   object *humans = all_clones("/monsters/human");
   humans = filter(humans, (: $1->query_name() == name :) );
   return sizeof(humans);
}

void create() {
   string name;
   ::create();
/* OBJEDIT { */
   set_spd( 10 );
   set_con( 10 );
   set_str( 10 );
   set_dex( 10 );
   set_wil( 10 );
   set_cha( 10 );
   set_int( 10 );
   set_emp( 10 );
   set_droppable( 1 );
   set_weight( 3000 );
/* } OBJEDIT */

   call_out("self_destruct", 0);

   do {
      name = lower_case("/daemon/namegen"->get_elf_name());
   } while (twins_of(name));

   set_name(name);

   if( "/daemon/namegen"->is_name_feminine(query_name()) ) {
      set_gender( 2 );
   } else {
      set_gender( 1 );
   }

   set_living_name( query_name() );


   // note: eventually we will possibly allow sickos to butcher humanoid
   // corpses in exchange for cursings and such from the gods... but not
   // any time soon.

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   add_form("brawl");
   set_form("brawl", 1);

   set_race("human");
   set_wc((["blunt":3]));
   set_wimpy(80);
   remove_call_out("self_destruct");
}

string *query_default_ai() {
   return ({ "talk" });
}

ICON( 'h', 7, LAYER_LIVING )
