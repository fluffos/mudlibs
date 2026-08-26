/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.smell.corpse".
 * <p>
 * Describe the arguments in here.
 * @classification body.smell.corpse
 * @see help::effects
 */
#include <effect.h>

/** @ignore yes */
void beginning( object player, int time, int id ) {
   tell_object( player, "Your arms are covered in blood!\n" );
   player->submit_ee( "make_stink", ({ 20, 20 }), EE_CONTINUOUS );
   player->submit_ee( 0, time, EE_REMOVE );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int time1, int time2, int id ) {
   player->submit_ee( 0, time1 + time2 - (int)player->expected_tt(),
         EE_REMOVE );
   return time1 + time2;
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, int time, int id ) {
   tell_object( player, "The disgusting smell is drowned out by "
                        "other less offensive bodily odours.\n" );
} /* end() */
 
void make_stink( object player, int time, int id ) {
   tell_object( player, "The disgusting smell of rotting corpses "
         "wafts from your body.\n" );
   player->remove_hide_invis( "hiding" );
   tell_room( environment( player ),  "The disgusting smell of rotting "
            "corpses wafts from "+(string)player->short() +"\n", player );
} /* make_stink() */

/** @ignore yes */
string query_classification() { return "body.smell.corpse"; }

string smell_string( object player, int time ) { 
   return "the disgusting smell of rotting corpses";
} /* smell_string() */ 
