#include <npc.h>
#include <areas.h>

void
create_monster()
{
    set_name("bat");
    set_short("Bat");
    set_id(({ "ugly bat", "vampire bat" }));
    set_move_msg("msgin", "flies in");
    set_move_msg("msgout", "flies");
    set_alignment(AL_NEUTRAL);
    set_race("bat");
    set_money(50);
    set(NPC_AGGRESSIVE);
    set_level(3);
    set_hp(70);
    set_long("It's big and ugly and you don't want to have anything to do\
 with it.");
    set_wc(5);
    set_ac(5);
    set_keep_hb(-120);
    set_wander(10);
    set(NPC_MOVE_AREA, AREA_SUE);
    replace_program(NPC_FILE);
}

status my_test() { return 1; }
