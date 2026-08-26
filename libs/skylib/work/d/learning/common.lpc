
#include <config.h>
#include "defs.h"

/* inherit "/std/dom/cmn_mas";
 * being a common room, this should inherit the previous, but since that's
 * basically a piece of shit, I won't have it contaminate my nice room:)
 */
inherit ROOM_OBJ;

#define HANDLER (LEARNING +"handlers/request")

object board;
object *chairs; /* people sitting */

void setup() {
   set_light( 100 );
   set_short("somewhat boring commonroom of the learning domain");
   set_determinate("the ");

   set_long("This is the common room of the domain of learning, the place "
            "where creators come to learn.  It is a somewhat boring room "
            "except for some chairs strewn around the place which happen to "
            "be an example of having commands defined in add_items, and some "
            "sort of list hanging on the wall which is an example of using "
            "add_command in rooms.\n");

   add_item("chair", ({"long", "This chair looks comfortable, perhaps you "
       "can sit in it.", "sit", ({ TO, "do_sit", "[in] <direct:object>"})
       }), 1 );

   add_item("chairs", ({"long", "These chairs look comfortable, perhaps you "
       "can sit in one of them.", "sit", ({ TO, "do_sit",
       "[in] <direct:object>"}) }), 1 );

   add_item("list",
            "This list has several actions associated with it:\n"
            "\"show list\" will show the current requests.\n"
            "\"request documentation\" will ask for "
            "documentation on something.\n"
            "\"request example\" will ask for an example of "
            "something to be coded.\n"
            "\"claim <number>\" is use to claim a request, thereby attempting "
            "to make sure that only one creator is writing the documentation/"
            "coding the examples.");

   add_exit("entrance", __DIR__+"main", "path" );
   add_exit("pub", CONFIG_START_LOCATION, "path" );

   /* make all chairs empty */
   chairs = ({ });
   /* calling this result in the function extra_look() being called whenever
    * people look at the room */
   add_extra_look(TO);
   /* the normal add_property() calls for the learning domain */
   add_property("commented functions", ({ "add_extra_look", "extra_look",
      "remove_extra_look", "add_command" }) );
   add_property("keywords", ({ "room", "add_item", "action" }) );

   /* make a copy of the domain's board */
   board = clone_object(BOARD_OBJ);
   board->set_datafile( DOMAIN );
   board->move( TO );

} /* setup() */

int do_show( string words ) {
    write( HANDLER->query_list() );
    return 1;
} /* do_show() */

int do_claim( int i ) {
    if( HANDLER->claim_request( TP->query_name(), i ) ) {
        add_succeeded_mess("$N claim$s a request.\n");
        return 1;
    }

    add_failed_mess("Illegal request number.\n");
    return 0;

} /* do_claim() */

int do_remove( int i ) {
    if( HANDLER->remove_request( TP->query_name(), i ) ) {
        add_succeeded_mess("$N remove$s a request.\n");
        return 1;
    }

    add_failed_mess("You can't remove that request.\n");
    return 0;

} /* do_remove() */

int do_request( string words, int doc ) {
    if( doc ) {
        HANDLER->add_request( TP->query_name(), "documentation for "+words );
        add_succeeded_mess("$N request$s some documentation.\n");
        return 1;
    }

    HANDLER->add_request( TP->query_name(), "examples of "+ words );
    add_succeeded_mess("$N request$s some examples.\n");
    return 1;

} /* do_request() */

void init() {
    ::init();
    add_command("show", "list");
    add_command("claim", "request <number>", (: do_claim( $4[0] ) :) );
    add_command("remove", "request <number>", (: do_claim( $4[0] ) :) );
    add_command("request", "examples of <string'text'>",
        (: do_request( $4[0], 0 ) :) );
    add_command("request", "documentation for <string'text'>",
        (: do_request( $4[0], 1 ) :) );
} /* init() */

int do_sit( string command, object *indir, string dir_match,
            string indir_match, mixed *args, string pattern ) {
   /* Note!  I use add_succeeded_mess even though the command failed,
    * because it fails for another reason than being the wrong object.
    * This make it work even though there is a "sit" soul.
    */
   if( dir_match == "chairs" ) {
       add_succeeded_mess( ({"How can you sit on more than one chair at the "
           "same time?\n", ""}) );
       return 1;
   }

   if( member_array( TP, chairs ) != -1 ) {
       add_succeeded_mess( ({"You are already sitting in a chair.\n",
           ""}) );
       return 1;
   }

   /* add the player to the list of people in the chairs */
   chairs += ({ TP });

   /* calling add_extra_look() result in the function extra_look being
    * called whenever people look at the person */
   TP->add_extra_look( TO );

   add_succeeded_mess("$N $V in a "+dir_match+".\n");
   return 1;

} /* do_sit() */

string extra_look( object thing ) {
    if( thing == TO ) { /* we're looking at the room */
        /* remove people who have logged out and those who have left */
        chairs = filter( chairs, (: $1 && ENV($1) == TO :) );
        /* none left sitting */
        if( !sizeof( chairs ) )
            return "";

        if( sizeof( chairs ) == 1 ) { /* only one left */
            if( chairs[ 0 ] == TP ) { /* and it's you */
                return "You are sitting in one of the chairs.\n";
            } else { /* and it's someone else */
                return (string)chairs[ 0 ]->the_short()+" is sitting in "
                    "one of the chairs.\n";
            }
        } else {
            return query_multiple_short( chairs, "the")+" are sitting in "
                "the chairs.\n";
        }
    }

    /* we're looking at someone who might be sitting */
    if( member_array( thing, chairs ) != -1 ) {
        /* sitting and here */
        if( ENV(thing) == TO )
            return thing->HE+" is lazing around in a chair.\n";
    }

    /* calling remove_extra_look() stop extra_look() being
     * called whenever people look at the thing */
    thing->remove_extra_look( TO );

    /* show nothing */
    return "";

} /* extra_look() */
