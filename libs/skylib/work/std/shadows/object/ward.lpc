/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: ward.c,v 1.3 2000/06/18 08:35:03 shrike Exp $
 * $Log: ward.c,v $
 * Revision 1.3  2000/06/18 08:35:03  shrike
 * Fixed up a 'someone' bug, and made it so they don't explode if you palm from your own inventory.
 *
 * Revision 1.2  2000/02/19 02:07:19  gerbil
 *  Forcibly unlocked by taffyd
 *
 * Revision 1.1  1998/01/06 04:40:23  ceres
 * Initial revision
 *
*/
inherit "/std/effect_shadow";

int move( object dest, string messin, string messout ) {
   string prev_ob, caster;
   int triggered, target_hp;

   prev_ob = file_name( previous_object() );
   caster = arg()[ 2 ];

   if( strsrch( prev_ob, "covert" ) != -1 ) {
      triggered = 1;

      // If it's palm, and the object is in a container that's in your
      // inventory, then don't trigger.
      if( strsrch( prev_ob, "palm" ) >= 0
       && environment(player)
       && environment( environment(player) )
       && environment( environment(player) ) == dest )
         triggered = 0;
   }

   if(triggered) {
      if( dest == this_player() && caster != this_player()->query_name() ) {
         /* methinks I am being stolen */
         tell_object( dest, "BANG!\nA warding glyph explodes in your "
           "face.\n" );
         tell_room( environment( dest ),
           "BANG!\nA warding glyph explodes near "
           + "/global/player"->convert_message( dest->the_short() )
           + ".\n", dest );
         target_hp = dest->query_hp();
         dest->adjust_hp( -arg()[ 1 ] );
         if( dest->query_hp() < 0 )
         /* He's dead Jim, so claim the honours */
            dest->attack_by( find_object( "/std/effects/object/ward" ) );
         call_out( "all_over", 1);
         if( random( 100 ) < ( 100 * arg()[ 1 ] ) / target_hp ) {
            tell_object( dest, "The blast makes you drop "
              + player->the_short() + ".\n" );
            tell_room( environment( dest ), dest->the_short() + " drops "
              + player->the_short() + " in shock.\n", dest );
            return player->move( environment( dest ), messin, messout );
         }
      }
   }
   return player->move( dest, messin, messout );
}

void all_over() {
   remove_this_effect();
}
