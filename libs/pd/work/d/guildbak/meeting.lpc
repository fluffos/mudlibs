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
    set_long("A large table sits in the middle of the room.  A "
      "thin layer of dust covers almost everything.  A small "
      "board sits on the west wall.  Paperwork lays on the "
      "desk about important issues and ideas for guilds. ");

    set_exits((["down":"/d/citrin/rooms/void", "up":ALL"leadermeet", "north":ALL"treasury"]));
    ob = new(BBOARD);
    ob->set_name("meeting board");
    ob->set_short("meeting board");
    ob->set_long("The boards primary usage is for you to ask questions on guild related topics.");
    ob->set_id(({"guild board", "board", "meeting board"}));
    ob->set_location("/d/guilds/meeting");
    ob->set_max_posts(50);
    ob->set_board_id("meeting");
    ob->set_edit_ok(({"whit","stormbringer"}));
    set_pre_exit_functions( ({"up", "down"}), ({"up", "down"}) );
}
int up() {
    if(GUILD_D->query_actual_position(this_player()->query_name())
      != "leader" &&
      GUILD_D->query_actual_position(this_player()->query_name())
      != "main") { write("You may not go into the leader room.\n"); return 0; }
    return 1;
}
int down() {
    string g;
    g=this_player()->query_original_guild();
    if(g=="aod") g="AoD";
    if(g=="illuminati") {
	this_player()->move_player("/d/guilds/illuminati/new/newhall");
	return 0;
    }
    if(wizardp(this_player())) {
	if(!g)
	    this_player()->move_player("/wizards/"+this_player()->query_name()+"/workroom");
	else
	    this_player()->move_player("/d/guilds/"+g+"/hall");
	return 1;
    }
    if(!g) {
	write("An error has occured and you are transfered to Tirun.\n");
	this_player()->move_player("/d/tirun/square"); 
	return 0;
    }

    this_player()->move_player("/d/guilds/"+g+"/hall");
    return 0;
}
