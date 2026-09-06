#include <group_npc.h>

void
create_monster()
{
    set_name("nurse");
    set_race("human");
    set_short("Nurse");
    set_group("hospital");
    set_long("You always liked those small, pretty nurses\
 that you sometimes saw at the hospital. This nurse, however\
 is not one of those. She is large, overweight, and has a\
 cross expression on her round face.");
    set_gender(G_FEMALE);
    set_level(20);
    set_hp(2000);
    set_wander(0);
    set_money(random(40));
    set_alignment(AL_NEUTRAL);
    load_chat(3, ({
	"Nurse frowns.",
	"Nurse says: Don't worry, this won't hurt a bit."
      }));
    load_a_chat(10, ({
	"Nurse screams: EEEEEEEEEKKKKKKKK!",
	"Nurse yells: HELP!!!",
	"Nurse shouts: HELP! I'm being raped!"
      }));
    set_breath_attack(
      25, 4, "Nurse sprays acid from a bottle upon you!",
      "Nurse sprays acid from a bottle!", DT_ACID);
}
