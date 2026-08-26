/**
 * Effect to go with eggs - Sandoz.
 */

#include <effect.h>

#define CLASSIFICATION "covered.in.egg"

#define TIME arg[0]
#define EGG  arg[1]

/** @ignore yes */
string query_classification() { return CLASSIFICATION; }

/** @ignore yes */
void beginning( object player, mixed arg ) {
    tell_room( ENV(player), EGG->the_short()+" breaks and covers most of "+
        player->the_short()+" in an eggy goo.\n");
    player->submit_ee( "rand_mess", ({ 30, 60 }), EE_CONTINUOUS );
    TIME = ( TIME > 600 ? 600 : TIME );
    player->submit_ee( 0, TIME, EE_REMOVE );
    player->add_extra_look( TO );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, mixed old_arg, mixed arg ) {
    int div, left;

    left = (int)player->expected_tt();
    div = 400 * left / TIME;
    div = ( div < 100 ? 100 : div );
    TIME = left + 100 * TIME / div;
    TIME = ( TIME > 600 ? 600 : TIME );

    tell_room( ENV(player), EGG->the_short()+" breaks and covers "+
        player->the_short()+" in an even thicker layer of egg.\n");

    player->submit_ee( 0, TIME , EE_REMOVE );
    return arg;

} /* merge_effect() */

/** @ignore yes */
void restart( object player, mixed arg ) {
    player->add_extra_look( TO );
} /* restart() */

/** @ignore yes */
void end( object player, mixed arg ) {
   if( !player->query_property( "dead" ) )
       tell_object( player, "You finally raise the willpower to wipe "
           "that egg out of your hair"+( sizeof( filter(
           player->query_wearing(), (: $1->query_clothing() :) ) ) ? ", face "
           "and clothes" : " and face" )+" and feel much better for it.\n" );
    player->remove_extra_look( TO );
} /* end() */

/** @ignore yes */
void rand_mess( object player ) {
   switch( random( 5 ) ) {
     case 0 :
       tell_object( player, "You feel some of the egg slide down your "
           "cheek.\n" );
       tell_room( ENV(player), player->the_short()+" quivers as some egg "
           "slides down "+player->HIS+" cheek.\n", player );
       return;
     case 1 :
       tell_object( player, "You feel the slight warmth of the egg mass "
           "on your face.\n");
       tell_room( ENV(player), player->the_short()+" goes all red as the "
           "layer of egg yolk wobbles on "+player->HIS+" face.\n", player );
       return;
     case 2 :
       tell_object( player, "You wipe a droplet of egg yolk away from your "
           "eyes.\n" );
       tell_room( ENV(player), player->the_short()+" wipes a droplet of egg "
           "yolk away from "+player->HIS+" eyes.\n", player );
       return;
     case 3 :
       tell_object( player, "You feel a bit uncomfortable with all that egg "
           "in your hair.\n" );
       tell_room( ENV(player), player->the_short()+" looks a bit "
           "uncomfortable.\n", player );
       return;
     default :
       tell_object( player, "You watch as some egg dribbles down "
           "onto your nose, hanging like an icicle.\n" );
       tell_room( ENV(player), player->the_short()+" fidgets as some egg "
           "dribbles down onto "+player->HIS+" nose like an icicle.\n",
           player );
   }
} /* rand_mess() */

/** @ignore yes */
string extra_look( object player ) {
    int *enums, nekkid;

    if( !sizeof( enums = player->effects_matching( CLASSIFICATION ) ) )
        return "";

    nekkid = !sizeof( filter( player->query_wearing(),
             (: $1->query_clothing() :) ) );

    switch( player->expected_tt( 1, enums[ 0 ] ) ) {
      case 0..60 :
        return CAP(player->HE)+" has a little bit of egg on "+
            player->HIS+" face.\n";
      case 61..120 :
        return CAP(player->HE)+" has quite a bit of egg on "+
            player->HIS+" face.\n";
      case 121..200 :
        return CAP(player->HE)+" "+( !nekkid ? "and "+player->HIS+" clothes "
            "are" : "is" )+" covered in egg.\n";
      case 201..380 :
        return CAP(player->HE)+" "+( !nekkid ? "and "+player->HIS+" clothes "
            "are" : "is" )+" covered in a thick layer of egg.\n";
      default :
        return CAP(player->HE)+" "+( !nekkid ? "and "+player->HIS+" clothes "
            "are" : "is" )+" completely covered in egg.\n";
    }
} /* extra_look() */
