#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_properties((["indoors":1, "light":2, "no attack":1, "no magic":1, "no
bump":1, "no steal":1]));
set_short("Illuminati Prayer Room");
    set_long("This is the prayer room for the Tower of Light and it is here where the "
             "Illuminati come to pray to their gods. Plants of all descriptions surround the "
             "room and there are many beautiful flowers to look at. A large statue of a "
             "cleric with her hands cupped before her serves as a unique fountain as the "
             "water trickles between her fingers into a pool at her feet. The walls and roof "
             "are made of a clear glass that give the room the distinct impression of being "
             "outside. The only thing ruining the effect is the archway in the west wall "
             "leading back into the hall.");
    set_exits(([
                "west" : ROOMS"illuminati/hall",
    ]));
    set_items(([
                "flowers"  : "The flowers are very beautiful and add to the peace of this place.",
                "foutain"  : "The fountain is made of silver inlaid with gold and the water is crystal clear.",
    ]));           
}
void init() {
    ::init();
    add_action("pray", "pray");
}
int pray() {
    int x;
    x = this_player()->query_max_hp() - this_player()->query_hp();
    this_player()->add_hp(x);
    x = this_player()->query_max_sp() - this_player()->query_sp();
    this_player()->add_sp(x);
    x = this_player()->query_max_mp() - this_player()->query_mp();
    this_player()->add_mp(x);
    this_player()->set_paralyzed(10);
    write("You are held in prayer.");
    return 1;
}
