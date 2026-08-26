/**
 * This is called off of the monster to set up a race and
 * profession...   Race should be first then profession..
 * @author Pinkfish
 * @started Sometime in 1991
 */

#include <config.h>

private mapping _races;

void create() {
   _races = ([
      0                  : CONFIG_DEFAULT_RACE,
      "ape"              : "/std/races/ape",
      "arachnid"         : "/std/races/arachnid",
      "basilisk"         : "/std/races/basilisk",
      "badger"           : "/std/races/badger",
      "bat"              : "/std/races/bat",
      "bear"             : "/std/races/bear",
      "beetle"           : "/std/races/beetle",
      "bird"             : "/std/races/bird",
      "bufonid"          : "/std/races/bufonid",
      "cabbage"          : "/std/races/cabbage",
      "camel"            : "/std/races/camel",
      "cat"              : "/std/races/cat",
      "caterpillar"      : "/std/races/caterpillar",
      "chicken"          : "/std/races/chicken",
      "chimera"          : "/std/races/chimera",
      "cockroach"        : "/std/races/cockroach",
      "cow"              : "/std/races/cow",
      "crocodile"        : "/std/races/crocodile",
      "demon"            : "/std/races/demon",
      "dog"              : "/std/races/dog",
      "dryad"            : "/std/races/dryad",
      "drow"             : "/std/races/drow",
      "duck"             : "/std/races/duck",
      "dwarf"            : "/std/races/dwarf",
      "eagle"            : "/std/races/chicken",
      "elemental"        : "/std/races/elemental",
      "elephant"         : "/std/races/elephant",
      "elf"              : "/std/races/elf",
      "ferret"           : "/std/races/ferret",
      "fish"             : "/std/races/fish",
      "fox"              : "/std/races/fox",
      "giant"            : "/std/races/giant",
      "giant bat"        : "/std/races/giant_bat",
      "giant spider"     : "/std/races/giant_spider",
      "gnoll"            : "/std/races/gnoll",
      "gnome"            : "/std/races/gnome",
      "goat"             : "/std/races/goat",
      "grflx"            : "/std/races/grflx",
      "guppy"            : "/std/races/guppy",
      "half elf"         : "/std/races/half_elf",
      "hare"             : "/std/races/hare",
      "hedgehog"         : "/std/races/hedgehog",
      "horse"            : "/std/races/horse",
      "human"            : "/std/races/human",
      "imp"              : "/std/races/imp",
      "insect"           : "/std/races/insect",
      "light"            : "/std/races/light",
      "lion"             : "/std/races/lion",
      "luggage"          : "/std/races/luggage",
      "moose"            : "/std/races/moose",
      "mouse"            : "/std/races/mouse",
      "mustelidae"       : "/std/races/mustelidae",
      "newt"             : "/std/races/newt",
      "noble dragon"     : "/std/races/noble_dragon",
      "nymph"            : "/std/races/nymph",
      "penguin"          : "/std/races/penguin",
      "pig"              : "/std/races/pig",
      "raptor"           : "/std/races/raptor",
      "rat"              : "/std/races/rat",
      "reptile"          : "/std/races/reptile",
      "rodent"           : "/std/races/rodent",
      "sargassum"        : "/std/races/sargassum",
      "satyr"            : "/std/races/satyr",
      "scorpion"         : "/std/races/scorpion",
      "sektarian demon"  : "/std/races/sektarian_demon",
      "sprite"           : "/std/races/sprite",
      "sheep"            : "/std/races/sheep",
      "skunk"            : "/std/races/skunk",
      "slice human"      : "/std/races/slice_human",
      "snake"            : "/std/races/snake",
      "sphinx"           : "/std/races/sphinx",
      "spider"           : "/std/races/spider",
      "squirrel"         : "/std/races/squirrel",
      "stoat"            : "/std/races/stoat",
      "stone giant"      : "/std/races/stone_giant",
      "stone palm"       : "/std/races/stone_palm",
      "strange"          : "/std/races/strange",
      "swamp dragon"     : "/std/races/swamp_dragon",
      "tree"             : "/std/races/tree",
      "troll"            : "/std/races/troll",
      "vulture"          : "/std/races/vulture",
      "unicorn"          : "/std/races/unicorn",
      "vorpal bunny"     : "/std/races/vorpal_bunny",
      "weasel"           : "/std/races/weasel",
      "wolf"             : "/std/races/wolf",
      "wombat"           : "/std/races/wombat",
      "vampire_test"     : "/std/races/vampire",
      "werewolf_test"    : "/std/races/werewolf_temp",
   ]);

} /* create() */

/**
 * This method checks to see if the specified race is valid or not.
 * @param race the race to check for validity
 * @return 1 if it exists, 0 if it does not
 */
int query_valid_race(string race) {
   return !undefinedp(_races[race]);
} /* query_valid_race() */

/**
 * This method sets the level of the npc with the specified attributes.
 * @param lvl the level to set the npc at
 * @param race the race to set the npc with
 */
void set_level( int lvl, string race ) {
   object ob;
   string race_ob;

   ob = PO;
   race_ob = ( _races[race] ? _races[race] : _races[0] );

   ob->set_no_check(1);
   ob->set_race_ob(race_ob);
   race_ob->set_level( ob, lvl );
   ob->race_guild_commands();

} /* set_level() */

private int add_race(string name, mixed ob) {
   if( _races[name] )
       return 0;
   _races[name] = ob;
   return 1;
} /* add_race() */

private int remove_race(string name) {
   if( !_races[name] )
       return 0;
   _races[name] = 0;
   return 1;
} /* remove_race() */

/**
 * This method returns all the current races in the race object.  It is a
 * mapping with matches between the name of the race and race object.
 * @return the race mapping
 */
mapping query_races() { return copy(_races); }

/**
 * This method returns the path associated with the specified race.
 * @param race_name the name of the race
 * @return the path of the race
 */
string query_race_path(string race_name) { return _races[race_name]; }
