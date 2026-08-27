// this file will included by some monk in saulin. added by Kyoko.
#include "../saulin_temple.h"

inherit MONSTER;

void die()
{
	object killer;
	killer = this_object()->query("last_attacker");
	killer->set_temp("saulin_killer", 1);
	::die();
}
