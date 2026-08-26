/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: hallucination.c,v 1.1 1998/01/06 04:14:00 ceres Exp $
 * $Log: hallucination.c,v $
 * Revision 1.1  1998/01/06 04:14:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "mind.hallucination".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification mind.hallucination
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

#define PLAYER capitalize( (string)player->the_short() )

string strange_things() {
   return ({ "red", "orange", "yellow", "blue", "green", "purple",
         "polka-dotted" })[ random( 7 ) ] +" "+ ({ "elephants",
         "winged bananas", "giraffes (very small ones, of course)",
         "floppy hats (which seem to be grinning at you)",
         "electric whelks", "geography teachers", "pigmies "+
         "wielding letter openers" })[ random( 7 ) ];
} /* strange_things() */

/** @ignore yes */
void beginning( object player, int time ) {
   tell_object( player, "Whee, look at the pretty "+ strange_things() +"!\n" );
   tell_room( environment( player ), PLAYER +" stares wide-eyed "+
         "at something that isn't there.\n", player );
   player->submit_ee( "see_things", ({ 40, 40 }), EE_CONTINUOUS );
   player->submit_ee( 0, time, EE_REMOVE );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int time1, int time2 ) {
   player->submit_ee( 0, time1 + time2 - (int)player->expected_tt(),
         EE_REMOVE );
   return time1 + time2;
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, int time ) {
   tell_object( player, "Everything looks a lot less interesting now.\n" );
} /* end() */
 
void see_things( object player ) {
   tell_object( player, "Some "+ strange_things() +" "+ ({ "leap out from "+
         "behind you", "fall from above", "appear in a puff of smoke",
         "saunter into the area", "pop out of your left nostril", "run in "+
         "singing nursery rhymes", "enter" })[ random( 7 ) ] +" and "+
         ({ "run around in ever decreasing circles", "do cartwheels",
         "perform a short scene from a play", "sit down to play a game "+
         "of Cripple Mr Onion", "ask you deep and meaningful questions "+
         "about wombles", "clean out your ears and nostrils with a "+
         "small vole", "just fade away" })[ random( 7 ) ] +".\n" );
   tell_room( environment( player ), PLAYER + replace( ({ " stares at "+
         "something only $pron$ can see.", " makes strange mewling noises.",
         " points over your shoulder and screams: They're coming!",
         " rolls up in a small ball at your feet.", " puts $poss$ hands "+
         "over $poss$ ears.", " trembles and drools a bit.", " peers at you "+
         "and says: Bing?" })[ random( 7 ) ] +"\n", ({ "$pron$",
         (string)player->query_pronoun(), "$poss$",
         (string)player->query_possessive() }) ), player );
} /* make_noises() */

/** @ignore yes */
string query_classification() { return "mind.hallucination"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"hallucination"; }
