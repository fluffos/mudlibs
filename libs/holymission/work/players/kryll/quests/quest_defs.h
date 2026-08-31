#ifndef __QUEST_DEFS_H__

#define __QUEST_DEFS_H__

#define ALL         -1
#define HOBBE        0
#define TROLLSLAYER  1
#define FIRE_QUEST   2

#define QUEST_LIST ({ "hobbe", "trollslayer", "fire_quest" })

#define INFO ({\
  ({ "hobbe", 1, 0, "Help Hobbe fix his mill", "Hobbe misplaced his "\
     "maul and if you find it, Hobbe will tell you how to help him "\
     "fix his mill.\n" }),\
  ({ "trollslayer", 4, 5, "Kill the evil troll king", "An evil troll "\
     "king has set up camp near the village. Apparently, they plan "\
     "to invade at some point. Find out more about trolls to figure "\
     "out how to rid the village of this scourge.\n" }),\
  ({ "fire_quest", 4, 2, "Help Ergo make his wand", "The great and "\
     "powerful magician, Ergo the Magnificent, is looking for some "\
     "adventurers to help him make his magic wand. If you want some "\
     "money, go to Ergo and ask him about his wand.\n" }),\
})

#endif // __QUEST_DEFS_H__
