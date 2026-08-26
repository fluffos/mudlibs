#include <tasks.h>

#define SKILL "general.climbing.rock"

inherit COMMAND_BASE;

void fall_off( object place, int number ) {
   if( place->query_at_bottom() ) {
       add_succeeded_mess( ({ "You try to climb, but you can't seem to get "
           "anywhere.\n", "$N try$s to climb, but fail$s.\n" }) );
       return;
   }
   if( random( (int)TP->query_dex() ) < number / 20 ) {
       add_succeeded_mess( ({ "You begin to climb, but your fatigue makes "
           "you clumsily lose your grip.\n", "$N begin$s to climb but "
           "clumsily lose$s $p grip.\n" }) );
       place->fall_down( TP );
       return;
   }
   add_succeeded_mess( ({ "You begin to climb but wobble precariously and "
       "decide to stay put for the moment.\n", "$N begin$s to climb, but "
       "wobble$s precariously and stop$s.\n" }) );
} /* fall_off() */

mixed cmd( string words ) {
   int difficulty;
   object place;
   mixed *move;

   if( !place = ENV(TP) ) {
       add_failed_mess( "You cannot climb anything: you're in limbo!\n" );
       return 0;
   }

   if( !move = (mixed *)place->query_move( words ) ) {
       add_failed_mess( "You cannot climb \""+ words +"\" from here.\n" );
       return 0;
   }

   if( TP->query_property("dead") ) {
       TP->move_with_look( move[ 1 ], move[ 2 ],
               "$N slowly climb$s "+ words +" and disappears from view." );
       add_succeeded_mess("");
       return 1;
   }

   difficulty = move[ 0 ] + (int)TP->query_loc_weight() / 10;

   if( (int)TP->query_specific_gp( "general" ) < difficulty ) {
       fall_off( place, difficulty );
       return 1;
   }
   TASKER->point_tasker( TP, "general", difficulty / 2 );
    switch( (int)TASKER->perform_task( TP, SKILL, difficulty, TM_COMMAND ) ) {
      case AWARD :
        call_out( "advance_notice", random( 60 ), TP );
      case SUCCEED :
        add_succeeded_mess( ({"You $V "+words+".\n", "" }) );
        TP->move_with_look( move[ 1 ], move[ 2 ],
            "$N slowly climb$s "+ words +" and disappear$s from view." );
        return 1;
      default :
        difficulty = random( difficulty );
        if( (int)TP->query_specific_gp( "general" ) < difficulty ) {
            fall_off( place, difficulty );
            return 1;
        }
        TASKER->point_tasker( TP, "general", difficulty );
        switch( (int)TASKER->perform_task( TP, SKILL,  difficulty / 2,
                                          TM_COMMAND ) ) {
          case AWARD :
            tell_object( TP, "%^YELLOW%^You manage not to fall off!%^RESET%^\n");
          case SUCCEED :
            add_succeeded_mess( ({ "You begin to climb but wobble precariously "
                "and decide to stay put for the moment.\n", "$N begin$s to "
                "climb, but wobble$s precariously and stop$s.\n" }) );
            return 1;
          default :
            fall_off( place, difficulty );
            return 1;
         }
    }
} /* cmd() */

void advance_notice( object thing ) {
    if( !thing )
        return;
    tell_object( thing, "%^YELLOW%^"+ ({
        "In a flash of inspiration, you realise how to balance better "
        "when climbing",
        "Thinking about your climb, you realise something important.",
        "You realise that you've been using better grips to climb.",
        "You realise you've discovered how to find better places to "
        "support your feet.",
        "You find you've worked out a more sensible way to distribute "
        "your weight as you climb.",
        "With all your climbing, you discover you've found a better way "
        "to locate handholds."})[ random( 6 ) ] +"%^RESET%^\n" );
} /* advance_notice() */

mixed *query_patterns() {
   return ({ "<string'direction'>", (: cmd($4[0]) :) });
} /* query_patterns() */
