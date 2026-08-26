/*  -*- LPC -*-  */
/*
 * $Locker: allana $
 * $Id: cold_cure.c,v 1.1 1999/12/02 22:40:33 allana Exp allana $
 *
 *
 */

/**
 * @main
 * @index cold_cure
 * This is a cold cure effect.
 * <p>
 * Argument 0 (int): An integer specifying the strength of the medicine
 * @see help::effects
 */

#include <effect.h>

#define COLD_DISEASE "disease.infection.respiratory.cold" 


/** @ignore */
string query_classification() { return "cure.infection.respiratory.cold"; }

/** @ignore */
void beginning( object player, int strength ) {
   int cure_time, *cold_enums;
 
   cold_enums = player->effects_matching( COLD_DISEASE );
   
   if( sizeof( cold_enums ) ) cure_time = player->arg_of( cold_enums[0] );
 
   /**
    * A strength of 100 or better will cure in 10 seconds flat.
    * A strength of 1 or less will take pretty much natural time. 
    * However, the strength ingested is dependent on the amount of
    * cure which has been ingested.*/      
   if( strength < 1 ) strength = 1;
   if( strength > 100 ) strength = 100;
   
   if( ( cure_time = cure_time * ( 101 - strength ) / 100 ) < 10 )
      cure_time = 10;
   
   tell_object( player, "You feel the overwhelming odour of garlic "
      "assaulting your nose and sinuses.\n" ); 
   tell_room( environment( player ), player->the_short() + " winces "
      "as the overwhelming odour of garlic engulfs " + 
      player->query_possessive() + " head.\n", player);
   
   player->submit_ee( "cure_messages", random( 35 ) + 15, EE_ONCE );
   player->submit_ee( "cure_cold", cure_time, EE_ONCE );
} /* beginning() */

/** @ignore */
void cure_messages( object player ) {
   int *cold_enums;
 
   cold_enums = player->effects_matching( COLD_DISEASE );
   
   if( !sizeof( cold_enums ) ) {
     player->submit_ee( 0, 0, EE_REMOVE );
     return;
   }
   
   switch( random( 2 ) ) {
     case 0 :
       tell_object( player, "You feel your strength slowly returning to you "
          "and your nose seems to be dripping a little less.\n" );
       tell_room( environment( player ), player->the_short() + " seems to be "
          "looking a little better.\n", player );
       break;
     default :
       tell_object( player, "You feel slightly better.  The cold cure seems "
          "to be helping you.\n" );
       tell_room( environment( player ), player->the_short() + " is looking "
          "far better now.  The cold cure seems to be doing some good.\n",
          player);
       break;
   }
   player->submit_ee( "cure_messages", random( 35 ) + 15, EE_ONCE );
} /* cure_messages() */

void cure_cold( object player ) {
   int *cold_enums;

   cold_enums = player->effects_matching( COLD_DISEASE );
   
   player->submit_ee( 0, 0, EE_REMOVE );
   if( sizeof( cold_enums ) ) player->delete_effect( cold_enums[0] );
} /* cure_cold() */

/** @ignore */
int merge_effect( object player, int oldstrength, int newstrength ) {
   int new_time, *cold_enums;

   cold_enums = player->effects_matching( COLD_DISEASE );

   /**
    * The strengths of the cold cures are not added together; instead, if
    * the new cure is stronger than the old one, then its strength will
    * be used to calculate the new cure_time (new_time).  
   if( newstrength <= oldstrength || newstrength < 2 ) return oldstrength; */
   /**
    * Fiddled with 24/06/99 to make strength accumulative, I hope */
   newstrength = oldstrength + ( newstrength / 2 );
   if( sizeof( cold_enums ) ) new_time = player->arg_of( cold_enums[0] );
   else return oldstrength;
     
   if( newstrength > 100 ) newstrength = 100;   
   if( ( new_time = new_time * ( 101 - newstrength ) / 100 ) < 5 )
      new_time = 5;
   
   player->submit_ee( "cure_cold", new_time, EE_ONCE );
   return newstrength;
} /* merge_effect() */                                  

/** @ignore */
void end( object player, int arg, int sid ) {
   if ( !player->query_property( "dead" ) ) {
     tell_object( player, "The foul taste of cough medicine finally leaves "
        "your mouth.\n" );
     tell_room( environment( player ), player->the_short() + " seems to have "
        "been relieved of something nasty tasting.\n", player );
   }
} /* end() */
