#include <effect.h>

#define PLAYER capitalize( (string)player->the_short() )

#define CLASS "box.misery"

string query_classification() { return CLASS; }

string random_misery() {
   return ({ "You feel weak and miserable.",
             "You feel absolutely miserable as all the problems on the disc "
                "pokes you in the back, saying: 'You shouldn't have opened "
                "the box, silly!'",
             "Why ever did you open that cursed box?",
             "The world seems a gloomy and distressing place.",
             "Who would've known the Disc is such a troubled place?" })
          [ random( 5 ) ];
} /* random_misery() */

string random_misery_two() {
   return ({ "You still feel bothered by the troubles of the disc, but it "
                "seems to affect you less now than before.",
             "Why ever did you open that cursed box?",
             "The world seems a gloomy and distressing place.",
             "Who would've known the Disc is such a troubled place?" })
          [ random( 4 ) ];
} /* random_misery() */

string random_misery_three() {
   return ({ "The troubles of the disc are still looming over you, but you "
                "seem fully capable of dealing with it now.",
             "You feel better, but the troubles of the Disc are still "
                "after you, criticizing everything you do.",
             "Why ever did you open that cursed box?",
             "The world seems a gloomy and distressing place, but not as "
                "gloomy as before.",
             "Who would've known the Disc is such a troubled place?" })
          [ random( 5 ) ];
} /* random_misery() */

void beginning( object player, int time ) {
   tell_object( player, "You suddenly feel weak and old.\n" );
   tell_room( environment( player ), PLAYER +" looks weak and old.\n", 
                                       player );
   player->submit_ee( "misery", ({ 120, 120 }), EE_CONTINUOUS );
   player->submit_ee( 0, time, EE_REMOVE );
   player->adjust_tmp_str( -2 );
   player->adjust_tmp_con( -2 );
   player->adjust_tmp_wis( 2 );

} /* beginning() */

int merge_effect( object player, int time1, int time2 ) {
   player->submit_ee( 0, time1 + time2 - (int)player->expected_tt(),
              EE_REMOVE );
   return time1 + time2;
} /* merge_effect() */
 
void end( object player, int time ) {
   tell_object( player, "You suddenly feel a lot better, and you make a "
                  "mental note:  Never again open something that specifically "
                  "tells you not to.\n" );
   tell_room( environment( player ), PLAYER +" suddenly looks a lot happier, "
                                       "and quite a bit stronger.\n", player );
   if ( player->query_tmp_con() < -1 ) { 
      player->adjust_tmp_str( 2 );
      player->adjust_tmp_con( 2 );
      player->adjust_tmp_wis( -2 );
   }
   else { 
      if ( player->query_tmp_con() < 0 ) {
         player->adjust_tmp_str( 1 );
         player->adjust_tmp_con( 1 );
         player->adjust_tmp_wis( -1 );
      }
   }
} /* end() */
 
void misery( object player ) {
   int bing;
   bing = player->query_tmp_con();

   if (bing < -1) {
      tell_object( player, random_misery() + "\n" );
      tell_room( environment( player ), PLAYER + " looks tired and worn "
                                  "out.\n", player );
   }
   else {
      if (bing < 0) {
         tell_object( player, random_misery_two() + "\n" );
         tell_room( environment( player ), PLAYER + " looks a bit frustrated "
             "and irritated.\n", player );
      }
      else {
         tell_object( player, random_misery_three() + "\n" );
         tell_room( environment( player ), PLAYER + " looks a bit troubled.\n", 
                                     player );
      }
   }

} /* misery() */
