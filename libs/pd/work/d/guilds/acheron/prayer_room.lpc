#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Acheron Prayer Room");
  set_properties((["light"       :2, 
                   "indoors"     :1, 
                   "no teleport" :1, 
                   "no attack"   :1, 
                   "no magic"    :1, 
                   "no bump"     :1,]));
    set_long("%^BOLD%^%^BLACK%^A grand statue of the god Tyr stands in the middle of the "
"%^BOLD%^%^BLACK%^room. %^BOLD%^%^WHITE%^S%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^l%^BOLD%^%^BLACK%^k%^BOLD%^%^WHITE%^y %^RESET%^%^WHITE%^pillows%^BOLD%^%^BLACK%^ lay around the statue so that members can "
"%^BOLD%^%^BLACK%^sit and <pray> to their god for health.");
    set_exits(([
        "west" : ROOMS"acheron/hall",
      ]));
    set_items(([ "statue" : "A semblance of the god Tyr stands before you. There is a small plaque at the base of the statue.",
                 "plaque" : "Show your homage to Tyr, kneel and <pray> to be healed.",]));
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
