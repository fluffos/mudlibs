#define PPATH  "/players/patience/ezo/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     (this_object())

inherit "room/room";

#define AT_KAI       (1)
#define AT_SEA       (2)
#define AT_EZO       (3)
#define TO_EZO       (1)
#define TO_KAI       (2)
#define EZO          "/players/patience/ezo/coast/c1"
#define KAI          "/room/jetty2"
#define KAI_SEA      "/room/sea"

int _lokation;

clean_up() {}

reset( arg )
{
   if ( arg )
      return;
      
   call_out( "sail1", 20, TO_EZO );
   set_location( AT_KAI );
   
   set_light(1);
   short_desc = "A cargo junk";
   long_desc = "You are on a cargo junk. The junk is made of wood and it is in a good\n" +
               "condition. In the middle of the junk can you see the mast with big yards,\n" +
               "great sails and strong shroud. Many sailors are running around and\n" +
               "are busy doing something and at the back of the ship stands the captain.\n" +
               "@@location@@.\n";
   items = ({ "junk", long_desc,
              "cargo junk", long_desc,
              "wood", "The wood seems to be in a good condition, too",
              "ground", "The ground is made of wood",
              "mast", "It is a massive wooden mast, on which the yards are fixed",
              "yard", "The yard is made of wood and the sail is fixed on it",
              "yards", "The yards are mode of wood and the sails are fixed on them",
              "sail", "The sail is made of cloth and it is dirt-white colored",
              "sails", "The sails are made of cloth",
              "cloth", "It seems, that they are very hard to tear",
              "shroud", "The shroud are made of natureal fibre. They are very thick",
              "fibre", "One fibre is very tiny, but all in all they are very strong",
              "sailor", "The sailor is busy running around",
              "sailors", "The sailors are busy running around",
              "sea", "Water...water...everywhere and not a drop to drink",
              "water", "The water is salty",
              });
   
   smell = "You smell the odor wood and sea.";
              
}

long(str)
{
    int i;
    
    if (!str) {
      write(process_string(long_desc));
      if ( query_location() == AT_KAI || query_location() == AT_EZO )
         write( "The only exit is: out\n" );
      return;
    }
    
    if (!items) return;
    
    i = 0;
    while(i < sizeof(items)) {
      if (items[i] == str) {
         write(process_string(items[i+1]) + ".\n");
         return;
      }
      i += 2;
    }
}

init( )
{
   ::init( );
   
   add_action( "search",   "search" );
   add_action( "climb_it", "climb"  );
   add_action( "out_it",   "out"    );
}

id( arg )
{
   return( ::id( arg ) || arg == "cargo_junk" );
}

search( arg )
{
   if ( !arg )
      return;
         
   write("You search and search, but find nothing special.\n");
   say(this_player()->query_name()+" searches around.\n");
   
   return( 1 );
}

climb_it( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "mast" || arg == "yard" ) {
      write( "You think, that this is the job of the sailors, so you stop it.\n" );
      return( 1 );
   }

   return( 0 );
}

out_it( arg )
{
   switch( query_location() ) {
      case AT_KAI: write( "You jump into the water and swim to the land.\n" );
                   this_player()->move_player( "the junk#room/jetty2" );
                   return( 1 );
      case AT_SEA: write( "You don't dare to leave the junk at the open sea.\n" );
                   return( 1 );
      case AT_EZO: write( "You jump into the water and swim to Ezo.\n" );
                   this_player()->move_player( "the junk#players/patience/ezo/coast/c1" );
                   return( 1 );
      default:     return( 1 );
   }
   
   return( 0 );
}

location( )
{
   switch( query_location() ) {
      case AT_KAI: return( "The junk is lying at the coast of Holy Mission" ); break;
      case AT_SEA: return( "The junk is surrounded by the sea" ); break;
      case AT_EZO: return( "The junk is lying at the coast of Ezo" ); break;
      default:     return( "The junk is in the void. Pray, mortal" ); break;
   }
}

set_location( l )
{
   _lokation = l;
}

query_location( )
{
   return( _lokation );
}

sail1( dest )
{
   tell_room( TO, "The sailors lift the anchor.\n" );
   call_out( "sail2", 20, dest );
}

sail2( dest )
{
   tell_room( TO, "The sailors begin to raise the sails.\n" );
   call_out( "sail3", 20, dest );
}

sail3( dest )
{
   tell_room( TO, "Wind blows into the sails and the junk begins to sail.\n" );
   move_object( this_object(), "/players/patience/ezo/seastore" );
   call_out( "sail4", 30, dest );
   set_location( AT_SEA );
   
   if ( dest == TO_EZO ) {
      tell_room( KAI_SEA, "The cargo junk sails way to the east.\n" );
      tell_room( KAI, "You can see the junk sailing away.\n" );
   }
   else
      tell_room( EZO, "The cargo junk sails away to the west.\n" );
}

sail4( dest )
{
   tell_room( TO, "The junk is sailing on.\n" );
   call_out( "sail5", 40, dest );
}

sail5( dest )
{
   if ( dest == TO_EZO )
      tell_room( TO, "You can see the outlines of an island to the east.\n" );
   else
      tell_room( TO, "You can see a coastline to the west.\n" );

   call_out( "sail6", 20, dest );
}

sail6( dest )
{
   if ( dest == TO_EZO )
      tell_room( TO, "You can see the island coming nearer and nearer.\n" );
   else
      tell_room( TO, "You can see the coastline coming nearer and nearer.\n" );
   
   call_out( "sail7", 10, dest );
}

sail7( dest )
{
   tell_room( TO, "The sailors remove the sails and the junk is anchoring.\n" );
   
   if ( dest == TO_EZO ) {
      move_object( TO, EZO );
      set_location( AT_EZO );
      call_out( "sail1", 200, TO_KAI );
      tell_room( EZO, "You can see a cargo junk arriving.\n" );
   }
   else {
      move_object( TO, KAI_SEA );
      set_location( AT_KAI );
      call_out( "sail1", 200, TO_EZO );
      tell_room( KAI_SEA, "You can see a cargo junk arriving.\n" );
      tell_room( KAI, "You can see a junk arriving to the east.\n" );
   }
}
