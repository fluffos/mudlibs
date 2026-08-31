#include <locations.h>
#include <std.h>

inherit ROOM;
 
void
create()
{
    ::create();
    set_properties(([ "light":1, "night light":1, "no steal":1, "no bump":1, "no castle":1, "no attack":1
]));
    set_short("wiz's cloud");
    set_long("%^BLUE%^wiz's cloud in the sky%^RESET%^");

    set_exits(([ "down":SQUARE_LOC ]));
    add_action("open", "open");
 
}
 
void
reset()
{
    ::reset();
    if (present("board")) {
        object board = new(BBOARD);
        board->set_name("board");
        board->st_id(({"board", "wiz board", "wiz's board"}));
        board->set_max_posts(77);
        board->set_location(file_name(this_object()));
        board->set_short("wiz's board");
        board->set_long("This is wiz's board.");
        board->set_board_id("leetice");
    }
#if 0
    if (!present("apu"))
        new(APU)->move(this_object());
#endif
}
 
int
open(string cmd)
{
    write("hmm...");
    return 1;
}
