#include <petzoo.h>
#include <std.h>
inherit ROOM;

void create() {
    object board;
    ::create();
    set_property("indoors", 1);
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"no steal"    : 1 ]) );
    set_property("town",1);
    set_property("light", 2);
    set("short", "Petting Zoo Entrance");
    set("long",
      "Welcome to Darien's Petting Zoo.  "+
      "Please watch your step and always wait for the handler's permission to "+
      "pet the animals.  The animals are tame, but not always "+
      "smart enough not to bite the hand that pets it.\n\n"+
      "There is a sign hanging over the entrance and a small donation box built into the wall.");
    set_items( ([ "sign": "Donations accepted.", 
	"box":"This is where visitors donate towards the cost of running the zoo."+
	"  The box appears to be locked.", 
	"wall":"The donation box is built into the sturdy stone wall."]) );
 set_exits( ([
	"south" : ROOMS"arlonroad1", 
	"north" : ROOMS"zoopath1" ]) );
    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", "zoo board" , "announcements" }) );
    board->set_max_posts(500);
    board->set_edit_ok(({"stormbringer","nightshade","seeker","daos","nesoo", "daboura"}));
    board->set_location(ROOMS+"zooentrance");
    board->set("short", "Zoo Announcements");
    board->set("long", "This board is used to let people know about activity in the zoo.\n");
    board->set_board_id("zoo");
}
void reset() {
    ::reset();
    if(!present("darien"))
	new(MOB"darien")->move(this_object());
    if(!present("fountain"))
	new(OBJ "fountain")->move(this_object());
}

