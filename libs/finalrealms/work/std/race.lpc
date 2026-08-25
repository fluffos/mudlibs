inherit "/std/basic/print_object";
/*
 * This is called off of the monster to set up a race and
 * proffesion...  Race should be first then proffesion..
 */
#include "race.h"

mapping races,
        guilds;

void create() {
  races = ([
    0          : "/std/races/unknown", /* first the null race */
    "troll"    : "/std/races/troll",
    "chicken"  : "/std/races/chicken",
    "duck"     : "/std/races/duck",
    "fish"     : "/std/races/fish",
    "human"    : "/std/races/human",
    "elf"      : "/std/races/elf",
    "half-elf" : "/std/races/half-elf",
    "halfling" : "/std/races/halfling",
    "drow"     : "/std/races/drow",
    "orc"      : "/std/races/orc",
    "dwarf"    : "/std/races/dwarf",
    "fish"     : "/std/races/fish",
    "guppy"    : "/std/races/guppy",
    "penguin"  : "/std/races/penguin",
    "goblin"   : "/std/races/goblin",
    "half-orc" : "/std/races/half-orc",
    "lizard-man":"/std/races/lizard-man",
  ]);
  guilds = ([
    0              : "/std/guild",
    "fighter"      : "/std/guilds/warriors/fighter",
    "warrior"      : "/std/guilds/warrior",
    "cleric"       : "/std/guilds/cleric",
    "priest"       : "/std/guilds/cleric",
    "tymora"       : "/std/guilds/priests/tymora",
    "tempus"       : "/std/guilds/priests/tempus",
    "lathander"    : "/std/guilds/priests/lathander",
/*    "lolth"        : "/std/guilds/priests/lolth", */
    "witch"        : "/std/guilds/wizards/witch",
    "wizard"       : "/std/guilds/wizards/general_wizard",
    "mage"         : "/std/guilds/mage",
/*    "necromancer"  : "/std/guilds/wizards/necromancer", */
    "thief"        : "/std/guilds/rogues/thief",
    "rogue"        : "/std/guilds/rogue",
    "assassin"     : "/std/guilds/rogues/assassin",
  ]);
} /* create() */

int query_valid_race(string race) {
  return races[race];
} /* query_valid_race() */

int query_guild_path(string guild) {
  return guilds[guild];
} /* query_guild_path() */

int add_race(string name, mixed ob) {
  if (races[name]) return 0;
  races[name] = ob;
  return 1;
} /* add_race() */

int remove_race(string name) 
  {
  if (!races[name]) return 0;
  races[name] = 0;
  return 1;
} /* remove_race() */

mapping query_races() { return races; }

int add_guild(string name, mixed ob) 
  {
  if (guilds[name]) return 0;
  guilds[name] = ob;
  return 1;
} /* add_guild() */

int remove_guild(string name) {
  if (!guilds[name]) return 0;
  guilds[name] = 0;
  return 1;
} /* remove_guild() */

mapping query_guilds() { return guilds; }

void monster_heart_beat(string race, string pclass, mixed race_ob, mixed class_ob) {
  race_ob->player_heart_beat(race);
  class_ob->player_heart_beat(pclass);
} /* monster_heart_beat() */

int query_limbs()
  {
  return 2;
} /* int query_limbs */
