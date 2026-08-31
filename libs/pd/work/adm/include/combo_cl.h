
#ifndef __COMBO_CL_H__
#define __COMBO_CL_H__

// structure to hold info on a combo
class Combo {
  // how much to increase or decrease the damage, as a percentage
  int bonus;
  // the moves, in sequence, that comprise this combo
  string *moves;
}

// structure to keep track of each player's (potential) combo progress
class ComboProgress {
  // name of the player
  string name;
  // array of move names
  string *moves;
  // times at which each move was executed
  int *times;
};

#endif

