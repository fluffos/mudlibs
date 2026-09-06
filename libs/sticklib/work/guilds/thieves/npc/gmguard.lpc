#include <npc.h>

#include "dirs.h"

/* Fake "controlled" monster - makes player kills PKs */
status query_ctrl() { return 1; }

void
create_monster()
{
    string tmp;

    if (object_name(this_object())== GDIR2 + "npc/gmguard")
	return;

    set_name("gargantuan guard");
    set_short("Gargantuan guard");
    set_race("giant");
    set_id(({ "gargantuan", "gigantic", "giant", "guard",
	"guild_guard", "mercenary" }));
    set_long(
      "You notice that this gigantic being is not a human at all, but a real \
Mountain Giant! He has been hired to guard this place.");
    set_level(40);
    set_hp(20000);
    set_ac(85);
    set(NPC_YES_CONDITION);
    set_gender(1);
    set_money(random(600) + 399);
    set_stat(ST_INT, 5);
    set_ep(500000);
    set_guild("thief");

    load_chat(4, ({
	"Gargantuan guard rumbles: ME NO BOW NO ONE!\n",
	"Gargantuan guard rumbles: WHO IS YOU SMALL PEOPLE?\n",
	"Gargantuan guard rumbles: WADH IS DIS LITTLE MIDGETS HERE?\n",
	"Gargantuan guard rumbles: HELLO SMALL PEOPLE\n",
	"Gargantuan guard yawns.\n",
	"Gargantuan guard rumbles: ME IS GUARD GUILD MASDER ROOM\n",
	"Gargantuan guard rumbles: HAR HAR HAR\n"
      }));
}

heart_beat()
{
    object *inv;
    int i;

    ::heart_beat();

    if (random(100) < 61) return;

    if (query_attack() && environment()) {
	inv = all_inventory(environment());
	for (i = sizeof(inv) - 1; i >= 0; i--)
	    if (inv[i] != this_object() &&
	      inv[i]->id("guild_guard") &&
	      !inv[i]->query_attack() &&
	      !inv[i]->query_alt_attack())
		inv[i]->attack_object(query_attack());
    }
}

int
extra_aggressive(object ob)
{
    if (ob && !ob->query_npc() && !present("tmark", ob)) return 1;
    return 0;
}
