#include <npc_defs.h>
#include "../priest.h"
inherit PRIEST_MON_DIR "humble_mon";

void
create_monster() {
    real_short = "Brother Claudius the Vintner";
    start_location = PRIEST_ROOM_DIR "wine_cellar";
    dest_location = PRIEST_ROOM_DIR "guild_room";
    to_path = ({"up", "southwest", "south"});
    from_path = ({"north", "northeast", "down"});

    set_name("Brother Claudius");
    set_id( ({"bartender", "claudius", "vintner"}) );
    set_short(real_short);
    set_long(
      "Brother Claudius is a lay brother of the Holy Order. A master vintner, he \
brews the heady draughts that can be purchased here. Be sure to thank him \
for his hours of effort.");
    set_level(25);
    set_gender(G_MALE);
    ::create_monster();
}
