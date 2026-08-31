//  Created by Whit
//  Leader meeting room

#include <daemons.h>
#include <guild.h>
#include <std.h>

inherit "/std/room";

void create() {
    object ob;
    ::create();
    set_name("Leader meeting room");
    set_properties(([
	"light":2, "night light":2, "no attack":1, "no magic":1, 
	"no bump":1, "no steal":1, "indoors":1, "no teleport":1,
      ]));

    set_short("Guild leader meeting room");
    set_long("This is the meeting room of all the leaders of the guilds "
      "in the realms of Primal Darkness-II.  The room itself still "
      "smells of fresh paint.  A brand new polished table sits in the "
      "middle of the room with paperwork on top of it.  A board sits in "
      "the middle of the room where leaders may post about topics that "
      "only other leaders can see.");
    set_exits((["down":ALL"meeting"]));
    ob = new(BBOARD);
    ob->set_name("leader board");
    ob->set_short("guild leaders board");
    ob->set_long("This board is for the use of the leaders of the guilds.  Only leaders may post and view notes that are here.");
    ob->set_id(({"guild leaders board", "board", "leaders board"}));
    ob->set_location("/d/guilds/leadermeet");
    ob->set_max_posts(100);
ob->set_board_id("leader meetingclear");
//ob->set_board_id("leader meeting");
    ob->set_edit_ok(({"stormbringer", "whit", "daos", "nulvect", "vian", "amun"}));
}
