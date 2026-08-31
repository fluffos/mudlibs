#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
    "I'm singing in the raiiin,",
    "Such a wonderful feelin'",
    "la la la la",
    "I'm singing in the raaiin!" }));
   set_type("bad");
}

void finish_song() {
   write("yaaay");
   say("The rain, the rain!", this_player());
   target->damage(700, "rain");
   remove();
}
