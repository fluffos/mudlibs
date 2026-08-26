/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: panic.c,v 1.1 1998/01/06 04:14:00 ceres Exp $
 * $Log: panic.c,v $
 * Revision 1.1  1998/01/06 04:14:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "witch.curse.panic".
 * <p>
 * Describe the arguments in here.
 * @classification witch.curse.panic
 * @see help::effects
 */
#include <effect.h>

#define RUN_CHANCE 5
#define MAX_DURATION 7200
#define MAX_STRENGTH 12000
#define MIN_STRENGTH 0

string *panic_msg = ({
   "You hear a noise behind you and nearly jump out of your skin.\n",
   "You're certain someone is sneaking up behind you.\n",
   "You see something moving in the shadows.\n",
   "The hairs on your neck suddenly stand up for no apparent reason.\n",
   "Your heart begins to beat faster, and you break out in a cold sweat.\n"
});

int diminish(int x, int x_max, int y_max) {
    // Sort of a poor-man's 1-e(-x) - it's actually 2x-x**2
    float xf;

    if (x > x_max) return y_max;
    xf = x / to_float(x_max);
    return to_int((2.0 - xf)*xf*y_max);
} /* diminish() */

/** @ignore yes */
int beginning( object player, int time ) {

   if (time < MIN_STRENGTH) return 0;
   player->submit_ee( "run_like_l", ({ 30, 60 }), EE_CONTINUOUS );
   time = diminish(time, MAX_STRENGTH, MAX_DURATION);
   player->submit_ee( 0, time, EE_REMOVE );
   tell_object(player, "A feeling of fear and panic begins to " +
               "overcome you.\n");
   return time;
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int time1, int time2 ) {
   int duration;

   duration = diminish(time2 + player->expected_tt(), MAX_STRENGTH,
                       MAX_DURATION);
   player->submit_ee( 0, duration, EE_REMOVE );
   tell_object(player, "The feeling of panic increases.\n");
   return duration;
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, int time ) {
   tell_object( player, "You finally calm down.\n" );
} /* end() */

void run_like_l( object player ) {

   tell_object(player, panic_msg[random(sizeof(panic_msg))]);
   if (!random(RUN_CHANCE)) {
      tell_room(environment(player), (string)player->short() +
                " runs away screaming.\n", player);
      player->run_away();
   } else {
      tell_room(environment( player ), (string)player->short() +
                " suddenly jumps and looks around nervously.\n", player);
   }
} /* run_like_l() */

/** @ignore yes */
string query_classification() { return "witch.curse.panic"; }
