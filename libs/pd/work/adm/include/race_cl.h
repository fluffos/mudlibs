
#ifndef __RACE_CL_H__
#define __RACE_CL_H__

class Race {
  // name of the race
  string name;
  // player = 1 to be pickable at login
  int player;
  // able to begin as this race
  int newplayer;
  // sight modifier, currently ranges -2 to +3
  int sight;
  // how much this race weighs - not currently used
  int size;
  // how many fingers on each hand - affects wearing of gloves and rings
  int fingers;
  // allowed genders
  string *genders;
  // name of this race's native language
  string language;
  // alignment tendencies, "good" makes it harder to become evil for example
  string alignment;
  // stat info, will contain roll and cost modifiers
  mapping stats;
  // skill info for racial skills, will contain start value, amount per level, and cost modifier
  mapping skills;
  // limb info, contains importance, parent limb, and limb flags
  mapping limbs;
  // undead flag
  int undead;
  // rideable flag
  int rideable;
  // always have a set class - meant for use with animal class
  string myclass;
  string mysub;
  // for damage type resistances and weaknesses
  mapping resistances;
  // for setting properties - mostly immunities vs status ailments or commands
  mapping properties;
  // aliases - multiple names for one race
  string *aliases;
  // for holding help information
  mapping help;
  // modifiers to healing rates
  mapping healrate;
}

#endif
