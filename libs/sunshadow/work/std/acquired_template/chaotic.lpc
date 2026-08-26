/*
  Chaotic Acquired Template
  
  Based on the Agent of Chaos acquired template found here:
  https://www.d20pfsrd.com/bestiary/monster-listings/templates/agent-of-chaos/
  
  Shortened to "Chaotic" for the purposes of display in score and for setting/querying.
  
  Template Features:
  +10 spell resistance *
  0 spell resistance against lawful *
  -25% resistance against all damage from lawful *
  +2 to CMB and CMD (maybe you're slippery or distracting or something). *
  warpwave - melee attacks have a chance of applying a random status on failed fort save. *
  chaos field - spells cast on you have a chance to cause wild magic effect. (maybe 10% here?) *
*/

#include <std.h>

string *races_allowed()
{
    return ({});
}

int is_rollable() { return 0; } // not rollable in creation

mapping innate_spells()
{
    return ([ "alter self"          : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
              "polymorph self"      : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
              "displacement"        : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),  
              "confusion"           : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
              "prismatic spray"     : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
              "greater polymorph"   : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),              
              "freedom of movement" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),              
           ]);
}

int query_unbound_age()
{
    return 1;
}

int sight_bonus()
{
    return 2;
}

int apply_template(object ob)
{
    ob->set_acquired_template("chaotic");
    return 1;
}

int remove_template(object ob)
{
    ob->set_acquired_template(0);
    return 1;
}
