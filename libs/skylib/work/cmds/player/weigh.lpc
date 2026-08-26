
#define MAX_OBJECTS_AT_ONCE   5

string weight_string( int number );
int cmd( object *things );

string weight_string( int number ) {
   number = ( number + 4 ) / 9;
   switch ( number ) {
      case 0 :
         return "uh oh";
      case 1 :
         return "half a pound";
      case 2 :
         return "a pound";
      case 3 :
         return "a pound and a half";
      case 4 .. 14 :
         return query_num( ( number + 1 ) / 2 ) +" pounds";
      case 15 .. 24 :
         return "ten pounds";
      case 25 .. 34 :
         return "fifteen pounds";
      case 35 .. 149 :
         return query_num( ( ( number + 10 ) / 20 ) * 10 ) +" pounds";
      case 150 .. 249 :
         return "a hundred pounds";
      case 250 .. 349 :
         return "a hundred and fifty pounds";
      case 350 .. 1499 :
         return query_num( ( ( number + 100 ) / 200 ) * 100 ) +" pounds";
      case 1500 .. 2499 :
         return "a thousand pounds";
      case 2500 .. 2499 :
         return "fifteen hundred pounds";
      case 3500 .. 14999 :
         return query_num( ( ( number + 1000 ) / 2000 ) * 1000 ) +" pounds";
      case 15000 .. 24999 :
         return "ten thousand pounds";
      case 25000 .. 34999 :
         return "fifteen thousand pounds";
      default :
/* Detritus... */
         return query_num( ( ( number + 10000 ) / 20000 ) * 10000 ) +" pounds";
   }
} /* weight_string() */


int cmd( object *things ) {
   int accuracy, weight;
   string results;
   object thing, *failed;

   failed = filter( things, (: ENV($1) != TP :) );
   things -= failed;

   if( !sizeof(things) ) {
       add_failed_mess("$I "+({"is","are"})[query_group(failed)]+" not in "
           "your inventory, so you cannot weigh "+({"it","them"})
           [query_group(failed)]+".\n", failed );
       return 0;
   }

   if( sizeof( things ) > MAX_OBJECTS_AT_ONCE ) {
       add_failed_mess("You cannot weigh that many things at once.\n");
       return 0;
   }

   accuracy = 9 + 89 / ( 1 + ( int )TP->query_dex() );

   results = "";

   foreach( thing in things ) {
      if( !objectp( thing->query_worn_by() ) ) {
          results += "You heft "+thing->the_short()+" and guess that "+
              thing->query_pronoun()+" "+( query_group(thing) ? "weigh " :
              "weighs ");
          weight = ( int )thing->query_complete_weight();
          if( 4 * weight > accuracy ) {
              weight = ( 4 * weight + accuracy ) / ( 2 * accuracy );
              results += "about "+ weight_string( weight * accuracy ) + ".\n";
          }
          else {
            results += "less than "+ weight_string( accuracy );
            results += ".\n";
         }
      } else {
         results += "You are wearing " + ( string )thing->the_short() +
            ".\n";
         things -= ({ thing });
         continue;
      }
   }

   tell_object( TP, results );

   if( sizeof( things ) ) {
       tell_room( ENV(TP), TP->the_short()+" hefts "+
          query_multiple_short(things)+" "+( sizeof( things ) > 1 ?
          "one at a time to see how much they weigh" :
          "to see how much "+( query_group(things) ? "they weigh" :
          "it weighs") )+".\n", ({ TP }) );
   }

   return 1;

} /* cmd() */


mixed *query_patterns() {
   return ({ "<indirect:object:me'item(s)'>", (: cmd( $1 ) :) });
} /* query_patterns() */
