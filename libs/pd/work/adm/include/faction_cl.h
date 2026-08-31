#ifndef __FACTION_CL_H__
#define __FACTION_CL_H__

#include "funccheck_cl.h"

class Faction {
  string name;
  class FuncCheck *member_criteria;
};

class Alliance {
  string name;
  string *allied_factions;
  string *enemy_alliances;
  mapping score;
  mapping death;
}

#endif
