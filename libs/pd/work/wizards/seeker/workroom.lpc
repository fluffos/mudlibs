#include <std.h>

inherit ROOM;

object board;

string get_desc()
{
 if (this_player()->query_name()!="seeker")
   {
    return "How in the hell did you get here?! shoo before you feel my "
           "wrath you innocent mortal, or immortal.";
   }
    return "%^BOLD%^You have entered the workroom for seeker, the main admin on "
           "Carnage, the place is covered in plans, papers, old "
           "code. This place is hella messy";
   
}

string go_square()
{
 write("You go square..");
 return "/d/tirun/edivos1";
}
void create() {
   room::create();
    set_property("light", 2);
    set_property("indoors", 1);

    set("short", "The workroom of a new immortal");
set_long( "%^GREEN%^This is green %^BLUE%^This is blue.");
    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", " seekers board" }) );
    board->set_max_posts(80);
    board->set_location("wizards/seeker/workroom");
    board->set("short", "Seekers board");
    board->set("long", "This board is for the seeker.\n");
    board->set_board_id("seeker");


    set_smell("default", "It smells like a new immortal in here.");
    set_listen("default", "You hear the sounds of code creation.");

}

int init()
{
 ::init();
/*   ob = get_object("/adm/save/users/s/seeker.o");
  write("ob = "+ob->query_name()); */
/* if (this_player()->query_name()!="seeker")
   this_player()->move_player("/d/standard/square"); */
add_action("fpeer", "peer");
}

int fpeer(string str) { write("You cannot peer."); return 1; }
void reset()
{
 ::reset();
}
