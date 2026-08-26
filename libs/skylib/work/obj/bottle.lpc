#define PHIAL 150
#define BOTTLE 1000
#define QUIRM 2500
#define DEMIJOHN 50000

inherit "/obj/vessel";

nosave string glass;

void make_bottle( string word, int number ) {
   int mass;
   string adjective, noun;
   glass = word;
   set_max_volume(number*4);
   mass = number / 100;
   if ( !mass ) mass = 1;
   set_leak_rate( 0 );
   set_value( mass * 25 + random( mass * 10 ) );
   set_weight( mass + random( mass * 10 ) / 10 );
   set_max_weight( mass * 2 );
   add_property( "fragile", mass * 20 + random( mass * 5 ) );
   switch( number ) {
      case 0..PHIAL:
         adjective = "small";
         noun = "phial";
         break;
      case PHIAL+1..BOTTLE:
         adjective = "medium sized";
         noun = "bottle";
         break;
      case BOTTLE+1..QUIRM:
         adjective = "large";
         noun = "Quirm";
         break;
      case QUIRM+1..DEMIJOHN:
         adjective = "very large";
         noun = "demijohn";
         break;
      default:
         adjective = "huge";
         noun = "tank";
   }
   set_name( lower_case( noun ) );
   set_short( adjective +" "+ glass +" "+ noun );
   set_long( "This is a "+ adjective +" "+ glass +" glass "+ noun +".\n" );
   add_alias( "bottle" );
   add_adjective( ({ adjective, glass }) );
   set_main_plural( adjective +" "+ glass +" "+ noun +"s" );
   add_plural( lower_case( noun ) +"s" );
} /* make_bottle() */

string query_glass() { return glass; }
int query_number() { return (int)query_property( "number" ); }

mixed *stats() {
   return ::stats() + ({
      ({ "glass", glass, }),
   });
} /* stats() */

mapping int_query_static_auto_load() {
   return ([
      "::" : ::int_query_static_auto_load(),
      "glass" : glass,
   ]);
} /* int_query_static_auto_load() */

void init_static_arg( mapping map ) {
   if ( map["::"] )
      ::init_static_arg( map["::"] );
   if ( !undefinedp( map["glass"] ) )
      glass = map["glass"];
} /* init_static_arg() */

mixed query_static_auto_load() {
   if ( explode( file_name( this_object() ), "#" )[ 0 ] == "/obj/bottle" )
      return int_query_static_auto_load();
   return ([ ]);
} /* query_static_auto_load() */
