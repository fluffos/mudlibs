#define DOM_TITLE "the domain of ss"
#define LORD "fengarance"
#define DOMAIN "ss"
/* PLEASE re-describe me */
#include "path.h";
inherit "/std/dom/cmn_mas";
object board;

void setup() {
  set_dom(DOMAIN);
  set_light(70);
  set_short("Common room of "+DOM_TITLE);
  set_long("Welcome to the common room for the domain of SwordSea and " +
           "Daggerford.\n"+
           "This place looks like it was made by Baldrick, with garbage " +
           "everywhere. In fact, it is made by Baldrick, he even hung a " +
           "picture of him over the ton of bricks that was his attempt to " +
           "make a fireplace.\n" +
           "The room has a table in the middle, and chairs round it. "+ 
           "On one of the walls, Baldrick has tried to hang up a board, " + 
           "It looks like it will fall down anytime.\n" +
           "One one of the other walls, a lot of doors are placed, " +
           "everyone with a name on. The name of the creators of this " +
           "wonderful Domain are on the doors, they lead to their workroom.\n");
  add_alias ("chair", "chairs");

  add_item("chair", "This chair looks ok, you are glad Baldrick didn't try " +
                    "to make it himself.\n");
  add_item("table", "This table are big enough to use for meetings. It's not " +
                    "made by Baldrick.");
  add_item("picture", "This is a picture of the Lord of Swordsea and " +
                      "Daggerford, Baldrick. A perfect copy of his ugly face."+
                      ".\n");
  add_exit("bar", ROOM + "bar", "door");
  add_exit("ll", DAGG + "ladyluck", "door");
  add_exit("baldrick", "/w/baldrick/workroom", "door");
  add_exit("leafstar", "/w/leafstar/workroom", "door");
  add_exit("marte", "/w/marte/workroom", "door");
  add_exit("arkhan", "/w/arkhan/workroom", "door");
  add_exit("parsion", "/w/parsion/workroom", "door");
  add_exit("fengarance", "/w/fengarance/workroom", "door");
  add_exit("zonkul" ,"/w/zonkul/workroom", "door");
  add_exit("morfren", "/w/zonkul/workroom", "door");
  add_exit("wadudu", "/w/wadudu/workroom", "door");

  board = clone_object("/obj/misc/board");
  board->set_datafile(DOMAIN);
  board->move(this_object());
}

void dest_me()
{
  if(board) board->dest_me();
  ::dest_me();
}
