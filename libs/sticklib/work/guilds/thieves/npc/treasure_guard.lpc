#include <sys/configuration.h>
#include <group_npc.h>
#include <daemons.h>

#include "dirs.h"

#define TO this_object()

/* Fake "controlled" monster - makes player kills PKs */
status query_ctrl() { return 1; }
object enemy;
int yelled;

void
create_monster()
{
    string tmp;

    if (object_name(this_object()) == GDIR2 + "npc/treasure_guard")
	return;

    tmp = ({ "Huge", "Massive", "Strong", "Scarred", "Muscled",
      "Veteran", "Expert" })[random(7)];
    set_name(tmp + " guard");
    set_short(tmp + " guard");
    set_long("This " + short() + " is here to guard the guild rooms.");
    set_id(({ "guild_guard", "guard", "lesser_thief_guard",
	"mercenary", lower_case(tmp) }));
    set_group("thief_guard");
    set_level(20 + random(22));
    set_ep(10000);
    set_hp(1000 + 100 * level);
    set_wc(50);
    set_ac(80);
    set_wimpy(0);
    set(NPC_YES_CONDITION);
    set_gender(random(2) + 1);
    set_money(random(100) + 99);
    set_alignment(AL_NEUTRAL);
    set_guild("thief");
    configure_object(this_object(), OC_HEART_BEAT, 1);

    yelled = 0;
}

heart_beat()
{
    string temp;
    string name1;
    string *exits;
    object *inv;
    int i;

    ::heart_beat();

    if (yelled) return;

    if (query_attack())
    {
	if (enemy != query_attack())
	{
	    enemy = TO->query_attack();

	    if (!enemy) return;

	    name1 = capitalize((string)enemy->query_real_name());
	    temp = ({
	      "Reinforcements here! " + name1 + " is attacking!",
	      "Come to help me with " + name1 + " !",
	      "ACK! " + name1 + " is trying to kill me! Help me out!!",
	    })[random(3)];
	    CHANNEL_D->send_channel_message(TO, "thief", temp);
	}
    }
    else yelled = 0;
}
