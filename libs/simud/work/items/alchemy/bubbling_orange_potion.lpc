#include <const.h>
inherit "/obj/food";

NAME( "bubbling orange potion" )
LOOK( "A small glass bottle full of a violently bubbling orange liquid. A small label taped to the side reads, 'Guaranteed to increase the overall potential potential in those consumers who have not already met or exceeded specified specifications!'" )
DISTANT( "a bubbling orange potion" )
SPECIFIC( "the bubbling orange potion" )
PLURAL( "bubbling orange potions" )
ALT_NAME( ({"potion", "orange potion"}) )
ALT_PLURAL( ({"potions", "orange potions"}) )
TASTE( "It tastes like potential potential." )

create() {
   ::create();
/* OBJEDIT { */
   set_drinkable( 1 );
   set_drink_value( 1 );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 500 );
   set_bulk( 2 );
   set_value( 0 );
/* } OBJEDIT */
}

int bump_random_stat( object who ) {
   string *stats = ({ "str", "dex", "con", "spd",
                      "wil", "int", "emp", "cha" });
   object race = who->query_race_object();
   string buf, stat = stats[random(sizeof(stats))];
   while( who->query_stat(stat) >= race->query_stat_max(stat) ) {
      stats -= ({ stat });
      if( !sizeof(stats) ) {
         msg_object(who,"~CWRNYour stomach rumbles painfully.~CDEF");
         who->set_endurance(who->query_endurance(50));
         return 0;
      }
      stat = stats[random(sizeof(stats))];
   }
   // we've already cut out if they're out of stats
   switch( stat ) {
      case "str":
         buf = "You feel your muscles harden."; break;
      case "dex":
         buf = "You feel relaxed."; break;
      case "con":
         buf = "You feel your veins bulge."; break;
      case "spd":
         buf = "You feel your legs tingle."; break;
      case "wil":
         buf = "Your eyes glaze over briefly before snapping back into focus.";
         break;
      case "int":
         buf = "Your mind becomes sharper."; break;
      case "emp":
         buf = "You think you hear voices."; break;
      case "cha":
         buf = "You think you see your skin begin to glow briefly."; break;
   }
   who->set_stat(stat, who->query_stat(stat) + 1);
   msg_object(who, buf);
   return 1;
}

int on_consume( int max ) {
   int x;
   set_actor(this_player());
   set_target(this_object());
   this_player()->msg_local("~CEMO~Name ~verbdrink ~targ.~CDEF");
   for( x = 0; x < 3; x++ )
      if (!bump_random_stat( this_player() ))
         break;
   destruct( this_object() );
   return 1;
}

mapping query_aspects() {
   return ([ C_LIQUID, C_POTION ]);
}
