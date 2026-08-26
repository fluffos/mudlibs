#define MAX_GENERIC_MONSTERS 3
#define NUMBER_OF_GENERIC_MONSTER_TYPES 6

void populate_generic_monster(object ob);
/* Populates a room with random monsters - requires all the below routines. */
/* Ironwulf added: created them in object ob */


object *random_generic_monster();
/* 
   Returns an array of random monster objects - requires create_generic_monster()
   (below) and also the functions from arm_generic_monster.c.
*/

object create_generic_monster();
/* 
   Returns a random monster from a set of default types - requires 
   get_generic_monster_file() (below) 
*/

string get_generic_monster_file(int monster_type);
/*
  Returns a random monster file from a set of default files - currently
  hardcoded with a switch, but soon I intend to use array/file combinations 
  instead.
  */
