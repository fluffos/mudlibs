#include <daemons.h>
#include <guild.h>
inherit ROOM;

void init() {
    ::init();
#ifndef NO_START
    add_action("fstart", "start");
#endif
}

object board;
void create() {
    ::create();
    restore_object("/d/guilds/save/unholy");
    set_short("Guild of the Unholy");
    set_long("%^RED%^T%^BOLD%^h%^MAGENTA%^i%^RESET%^%^RED%^s is %^BOLD%^th"
      "%^MAGENTA%^e unde%^RED%^r%^RESET%^%^RED%^ground %^BOLD%^h%^MAGENTA%^"
      "a%^RESET%^%^RED%^ll %^BOLD%^o%^RESET%^%^RED%^f th%^BOLD%^e "
      "%^MAGENTA%^Un%^RED%^ho%^BOLD%^ly an%^MAGENTA%^d the %^RESET%^"
      "%^RED%^ma%^MAGENTA%^%^BOLD%^ssive p%^RED%^alm of%^RESET%^%^RED%^ "
      "a g%^BOLD%^iganti%^RESET%^%^RED%^c dem%^BOLD%^on%^MAGENTA%^'s hand."
      "%^RESET%^ %^RED%^T%^BOLD%^h%^MAGENTA%^e %^RESET%^%^RED%^ceili"
      "%^BOLD%^ng %^MAGENTA%^is r%^RED%^ough rock wit%^MAGENTA%^h stag"
      "%^RESET%^%^RED%^limite%^BOLD%^s hangi%^MAGENTA%^ng down. B"
      "%^RESET%^%^RED%^on%^BOLD%^es and%^MAGENTA%^ bits %^RESET%^%^RED%^"
     "of fl%^BOLD%^esh lay a%^MAGENTA%^round " "t%^RESET%^%^RED%^he%^RESET%^ "
      "%^RED%^room.  %^BOLD%^A hal%^MAGENTA%^l le%^RED%^ads s%^RESET%^%^RED%^"
      "outh, d%^BOLD%^eeper " "%^MAGENTA%^unde%^RESET%^%^RED%^rgroun"
      "%^MAGENTA%^%^BOLD%^d, dow%^RED%^n the " "d%^RESET%^%^RED%^emo%^BOLD%^"
      "n's wr%^RESET%^%^RED%^ist.%^RESET%^ ");
    set_items(([
        "palm" : "The palm of the demon's hand is red and pinkish.",
        "hall" : "A hall leading south further into the guild, down the "
        "massive demon's wrist.",        
      ]));
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );
    set_exits(([
        "up" : ROOMS"unholy/entrance",
        "hall" : ROOMS"meeting",
        "east" : ROOMS"unholy/treasury",
        "south" : ROOMS"unholy/room1",
        "west" : ROOMS"unholy/shop",
      ]));
    board = new(BBOARD);
    board->set_board_id("unholy");
    board->set_name("sins");
    board->set_long("This is the evil board of sins.  Guild members may post"
      "about evil plots or anything that comes to mind.");
    board->set_max_posts(99);
    board->set_edit_ok(GUILD_D->post_able("unholy"));
    board->set_short("Unholies evil board of sins");
    board->set_location(ROOMS"unholy/hall");
    board->set_id(({"board", "sins board", "board of sins"}));
}

int fstart(string str) {
    if (!str || str=="") {
        notify_fail("Start where?\n");
        return 0;
    }
    if (str!="here") {
        notify_fail("You cannot start there.\n");
        return 0;
    }
    if(this_player()->query_original_guild() == "illuminati")
      this_player()->set_primary_start("/d/guilds/illuminati/new/board");
    else
    if(this_player()->query_original_guild() == "aod")
      this_player()->set_primary_start("/d/guilds/AoD/hall");
    else
      this_player()->set_primary_start("/d/guilds/"+this_player()->query_original_guild()+"/hall");
    write("You are now set to start in the "+capitalize(this_player()->query_guild())+
      " hall.\n");
    return 1;
}


