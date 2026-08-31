#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([
      "outdoors": 1,
      "breeze" : 1,
      "light" : 1,
    ]));
}
void init() {
    ::init();
    if (this_player()->is_player()) {
        remove_call_out("do_room_emote");
        call_out("do_room_emote", 120, this_player());
    }
}
int do_room_emote(object tp) {
    if (present(tp)) {
        tell_object(tp, "A gentle breeze blows from the north.");
        remove_call_out("do_room_emote");
        call_out("do_room_emote", 120, this_player());
        return 1;
    }
}
