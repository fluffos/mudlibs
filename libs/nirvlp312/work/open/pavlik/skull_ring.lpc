inherit "obj/armor";
#include "/open/ansi.h"

/*
 *
 * Valid Mage bonus stats are:
 *	intelligence	wisdom		power		will power
 *	conjuration	enchantment	evocation
 *	illusion	necromancy
 *
 * Bonus amount should be between 1 and 10, with 7-10 being *very* good
 *
 */

#define MAGE_GUILDID		"mageobj"
#define MAGE_BONUS_STAT		"necromancy"
#define BONUS_AMOUNT	2

reset(arg){
  ::reset(arg);
  set_short("A skull ring");
  set_long(
	"A ring carved from dark ebony and adorned with the polished white\n"+
	"semblance of a skull.  The empty sockets of the skull seem to stare\n"+
	"into your soul.\n");
  set_name("Skull Ring");
  set_ac(1);
  set_weight(1);
  set_value(6969);
  set_alias("ring");
  set_arm_light(0);
  set_save_flag(1);
  set_type("ring");
}

query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(MAGE_GUILDID, this_player()))
	present(MAGE_GUILDID, this_player())->add_guild_bonus(MAGE_BONUS_STAT, BONUS_AMOUNT);
}

remove_guild_bonus()
{
  if(present(MAGE_GUILDID, this_player()))
	present(MAGE_GUILDID, this_player())->add_guild_bonus(MAGE_BONUS_STAT, -BONUS_AMOUNT);
}

