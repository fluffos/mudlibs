#include <const.h>

int main( string param ) {
   string who;
   string what;
   object *tg;
   object *whotg;
   object *wholist;
   object showee;
   object showob;
   object ob;
   object obtg;
   object tgwho;
   int x;

   if( !param || sscanf( param, "%s to %s", what, who ) != 2 )
      return notify_fail("Show what to who?\n");

   if ( what == 0 )
      return notify_fail( "Show what?\n" );

   if( who == this_player()->query_name() || who == capitalize( this_player()->query_name() ) )
      who = "me";

   if( !all_present( who, environment( this_player() ) ) )
      return notify_fail( "Show who?\n" );

   if ( who == "all" ) {
      whotg = filter( all_inventory( environment( this_player() ) ), (: $1->query_is_living() :) );
      whotg -= ({ this_player() });
   } else {
      if( who != "me" && who != "myself" )
         whotg = all_present( who, environment( this_player() ) );
   }

   if( who == "me" || who == "myself" )
      whotg = ({ this_player() });

   if( !all_present( what, this_player() ) )
      return notify_fail( "Show what?\n" );

   if ( what == "all" ) {
      tg = filter( all_inventory( this_player() ), (: $1->query_distant() :) );
   } else {
      tg = filter( all_present( what, this_player() ), (: $1->query_distant() :) );
   }

   foreach( ob : whotg ) {
      if( !ob || !ob->query_is_living() )
         return notify_fail( "Show who?\n" );
   }

   if( !tg )
      return notify_fail( "Show what?\n" );

   foreach( obtg : tg ) {
      if( !obtg || obtg->query_is_living() )
         return notify_fail( "Show what?\n" );
   }

   if( !tg && !whotg == 0 )
      return notify_fail( "Show what to who?\n" );

   if( !tg )
      return notify_fail( "Show what?\n" );

   if( !whotg )
      return notify_fail( "Show who?\n" );

   if( member( whotg, this_player() ) > 0 && sizeof( whotg ) > 1 )
      return notify_fail( "You realize, of course, that showing things to yourself can lead to insanity.\n" );

   set_actor( this_player() );
   x = 0;

   foreach( tgwho : whotg ) {
      if( !x ) {
         wholist = ({ capitalize( tgwho->query_distant() ) });
         x = 1;
      } else {
         wholist += ({ capitalize( tgwho->query_distant() ) });
      }
   }

   if( who == "me" || who == "myself" ) {
      set_target( this_player() );
      this_player()->msg_local( "~CACT~Name ~verbshow ~targ " + inventory_string( tg ) + ".~CDEF" );
   } else {
      this_player()->msg_local( "~CACT~Name ~verbshow " + comma_list( wholist ) + " " + inventory_string( tg ) + ".~CDEF" );
   }

   foreach( showee : whotg ) {
      foreach( showob : tg ) {
         if ( !showee->query_is_living() ) {
            notify_fail( "Show what to who?.\n" );
            return 0;
         }

         showee->on_show( showob, this_player(), showee  );
         set_target( showee );
         msg_object( showee, showob->query_look() );

      }
   }
   return 1;
}
