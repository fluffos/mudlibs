#include <locations.h>
#include <locations.h>

#include <std.h>
inherit ROOM;

object board;
void create() {
   ::create();
   set_properties( ([
     "water" : 1,
     "light" : 2,
     "indoors" : 1
   ]) );
   set_short("The Delerium");
   set_long(
     "Inside the cerebral event horizon of an ever-maddening dream-world "
     "where the neurotic and nervous thoughts scramble about on impulses "
     "charged with synaptic energy and speed. There are no walls or floor "
     "in this peculiar place. Only the shrieks of a ruined psyche. It is "
     "empty and black here with no real purpose."
   );

     board = new("std/bboard");
     board->set_name("board");
     board->set_id( ({"board","psyche"}) );
     board->set_owner("danovae");
     board->set_max_posts(75);
     board->set_location("/wizards/danovae/workroom");
     board->set_short("Ruined Psyche");
     board->set_long("Board for random Idea's, Pet related anything and Legal Matters.\nDanovae's ");
     board->set_board_id("psyche");

   set_items( ([
     "thoughts" : "They hurry through with an unknown pattern.",
     ({"synapses","impulses"}):
     "Electric movements of varying %^CYAN%^%^BOLD%^blue hues%^RESET%^ "
     "zip past carrying the the nervous decedance to its destination."
   ]) );
   set_exits( ([
     "square" : SQUARE_LOC,
     "hall" : "/d/standard/adv_inner",
     "lounge" : "/wizards/danovae/wizlounge",
   ]) );

/*
   call_out("spark",60);
*/
}

/*
void spark() {
   tell_room(base_name(this_object()), "Sparks fly around on impulse.");
   remove_call_out("spark");
   call_out("spark",120);
}

*/

void init() {
   ::init();
   if(this_player()->query_class() == 0) {
   write("Boom Boom Boom");
   }
}


