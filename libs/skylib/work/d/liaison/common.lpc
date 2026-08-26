#include <config.h>

#define DOM_TITLE "the domain of liaison"
#define LORD "ohdamn"
#define DOMAIN "liaison"
#define BOSS_ROOM "/w/ohdamn/rooms/workroom"
inherit "/std/dom/cmn_mas";
object board;

void setup() {
   set_dom( DOMAIN );
   set_light( 100 );
   set_short( "common room for the liaison domain" );
   add_property( "determinate", "the " );
   set_long("Large relaxing chairs adorn the room.  The walls are covered "+
          "with strange motifs from different lands and the little shelf "+
          "above the fireplace is chocker block full of strange figurines "+
          "and bits of cloth.  It appears to be the common room of "+
          DOM_TITLE+" (the large red letters on the wall were the " +
          "give away).\nA sign is hanging on the wall.\n");
   add_alias("chairs", "chair");
   add_alias("cloths", "cloth");
   add_alias("motifs", "motif");
   add_alias("figurines", "figurine");
   add_item("chair", "The chairs are lazing around the room relaxing it looks "+
            "like they come here after a hard days working in "+
            DOM_TITLE+".\n");
   add_item("fireplace", "A nice little fire place with a cheery fire burning "+
            "in it keeping every one warm.\n");
   add_item("figurine", "Small figurines, they look strangely familiar "+
            "until you realise they are the members of "+
            DOM_TITLE+".\n");
   add_item("cloth", "Strange coloured bits of cloth strewn over the "+
            "mantlepice for no readily apparent reason.\n");
   add_item("motif", "The motifs on close inspection look like stylised "+
            "signatures of all the members of "+DOM_TITLE+
            ".  Some of them are very strange, in fact there "+
            "seem to be more than there are members of the house.  "+
            "perhaps it is the members of the future.\n");
   add_item("shelf", "A nice normal sort of shelf thing.  It is like all "+
            "those ones you see in houses all over the place, "+
            "execpt... the way it has been burnt... hmm it does "+
            "not look like the fire did it.\n");
   add_item("fire", "There is a fire happily burning away in the fireplace "+
            "spluttering and crackling to itself.  The flames almost "+
            "seem afraid of something.  Looking closer you notice a "+
            "picture tacked to the side of the fire place.\n");
   add_item("picture", "Tacked to the inside wall of the fire thingy, you "+
            "know the hole bit at the bottom, is a small picture "+
            "it looks like it was taken with the best of demon "+
            "photography.  It is a picture of a person holding "+
            "a small staff, you think it might be "+LORD+
            " but you are not sure as the fire light sparkles "+
            "in your eyes.\n");
   add_sign("This is a sign.  Says it all really.\n",
            "Commands available here are:\n"
            "add <name>   : add <name> as alias for you.\n"
            "remove <name>: remove <name> as alias for you.\n"
            "list [<name>]: list aliases added for you or <name>." );
   board = clone_object("/obj/misc/board");
   board->set_datafile(DOMAIN);
   board->move(this_object());
   add_exit("boss", BOSS_ROOM, "door");
   add_exit("drum", CONFIG_START_LOCATION, "path");
   BOSS_ROOM->add_exit("common", "/d/"+DOMAIN+"/common", "door");
} /* setup() */

void init() {
   this_player()->add_command( "add", this_object(), "<word> <word>" );
   this_player()->add_command( "add", this_object(), "<word>" );
   this_player()->add_command( "remove", this_object(), "<word> <word>" );
   this_player()->add_command( "remove", this_object(), "<word>" );
   this_player()->add_command( "list", this_object(), "" );
   this_player()->add_command( "list", this_object(), "<word>" );
} /* init() */

int do_add( object *indir, string indir_match, string dir_match, 
           mixed *args, string pattern  ) {
   switch( pattern ) {
    case "<word> <word>":
      if ( master()->query_lord( this_player()->query_name() ) ) {
         if ( "/d/liaison/master"->add_member_alias( args[ 0 ], 
                                                    args[ 1 ] ) ) {
            this_player()->add_succeeded_mess( this_object(), 
                args[ 1 ] +" added as alias for "+ args[ 0 ] +".\n" );
            return 1;
         } else {
            this_player()->add_failed_mess( this_object(), 
                "Something went wrong.\n" );
            return 0;
         }
      } else {
         this_player()->add_failed_mess( this_object(), 
                "Only lords can add aliases to others.\n" );
         return 0;
      }
      break;
    case "<word>":
      if ( "/d/liaison/master"->add_member_alias( this_player()->query_name(), 
                                                 args[ 0 ] ) ) {
         this_player()->add_succeeded_mess( this_object(), 
                args[ 0 ] +" added as alias for $N.\n" );
         return 1;
      } else {
         this_player()->add_failed_mess( this_object(), 
                "Couldn't add "+ args[ 0 ] +" as alias for $N.\n" );
         return 0;
      }
      break;
   }
} /* do_add */

int do_remove( object *indir, string indir_match, string dir_match, 
           mixed *args, string pattern  ) {
   switch( pattern ) {
    case "<word> <word>":
      if ( master()->query_lord( this_player()->query_name() ) ) {
         if ( "/d/liaison/master"->delete_member_alias( args[ 0 ], 
                                                       args[ 1 ] ) ) {
            this_player()->add_succeeded_mess( this_object(), 
                    args[ 1 ] +" removed as alias for "+ args[ 0 ] +".\n" );
            return 1;
         } else {
            this_player()->add_failed_mess( this_object(), 
                "Something went wrong.\n" );
            return 0;
         }
      } else {
         this_player()->add_failed_mess( this_object(), 
                "Only lords can remove aliases for others.\n" );
         return 0;
      }
      break;
    case "<word>":
      if ( "/d/liaison/master"->delete_member_alias(
                 this_player()->query_name(), args[ 0 ] ) ) {
         this_player()->add_succeeded_mess( this_object(), 
                 args[ 0 ] +" removed as alias for $N.\n" );
         return 1;
      } else {
         this_player()->add_failed_mess( this_object(), 
                 "Couldn't remove "+ args[ 0 ] +" as alias for $N.\n" );
         return 0;
      }
      break;
   }
} /* do_remove */

int do_list( object *indir, string indir_match, string dir_match, 
           mixed *args, string pattern  ) {
   string *names, name;
   int i;
   
   switch( pattern ) {
    case "<word>":
      name = args[ 0 ];
      break;
    case "":
      name = this_player()->query_name();
      break;
   }
   names = "/d/liaison/master"->member_alias( name );
   name = capitalize( name );
   i = sizeof( names );
   if ( i ) {
      if ( i > 1 ) {
         while ( i-- ) {
            names[ i ] = capitalize( names[ i ] );
         }
         this_player()->add_succeeded_mess( this_object(), 
                "Aliases for "+ name +" are "+
                query_multiple_short( names )+".\n" );
      } else {
         this_player()->add_succeeded_mess( this_object(), 
                "Alias for "+ name +" is "+
                capitalize( names[ 0 ] )+".\n" );
      }
   } else {
      this_player()->add_succeeded_mess( this_object(), 
             "No aliases known for "+ name +".\n" );
   }
   return 1;
} /* do_list */

