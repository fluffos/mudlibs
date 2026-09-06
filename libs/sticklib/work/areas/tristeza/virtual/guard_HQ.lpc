#include "../DEFS.h"
#include <room_defs.h>

inherit TRISTEZA_ROOM_C;

void
create_room()
{
    int i;

    ::create_room();
    set(ROOM_WD, WD_INDOORS);
    set_short("Guard HQ");
    set_long("This is the headquarters of the (in)famous City Guards.");
    set_exits(([ "south" : CITY_DIR + "guard_front" ]));

    for (i = 1;i < 4;i++)
	add_monster(NPC_DIR + "guard_lieutenant", "Guard Lieutenant arrives.", 1);
    add_monster(NPC_DIR + "guard_captain", "Guard Captain arrives.", 1);
    add_monster(NPC_DIR + "guard_general", "Guard General arrives.", 1);
    add_monster(NPC_DIR + "guard_marshall", "The Marshall arrives.", 1);
}

void
init_room()
{
    object guardian;
    if (interactive(this_player()) && !this_player()->query_coder_level()
      && present("guard", this_object()))
	call_out("warn_em", 2, this_player());
}

void
warn_em(object player)
{
    if (!player || environment(player) != this_object() || !present(
	"guard", this_object())) return;

    // Player has quit, fled, or there are no guards... No message.

    player -> tell_me("Guard notices you and says: You are not supposed\
 to be here! If you don't leave immediately, you are going to be sorry!");
    call_out("attack_victim", 8, player);
}

void
attack_victim(object ob)
{
    object guardian;
    remove_call_out("attack_victim");
    if (!ob || environment(ob) != this_object() || !(guardian =
	present("guard", this_object()))) return;
    tell_here("Guard says: I told you once!", guardian);
    guardian->attack_object(ob);
    guardian->attacked_by(ob);
}
