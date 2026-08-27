// human.h:  This file is used for both users and monsters
//
// Functions pretaining to the race 'human'.
// Also example for others
// Orig by casper 9/95
 
#include <weapon_types.h>

string query_race()
{
  return "human";
}

/*
 * override of object::query_base_weight
 */
int query_base_weight()
{
  return 140;  // in lbs.
}
 
string *query_armour_types()  //The 'ID' of armours that can be worn.
{
  return copy(({"helm","ring","ring","bracers","body2","legs2","boots",
           "amulet","cloak"}));
}
 
string *query_armour_locations()  //Where the armours are worn
                                  //Parralel to above array
{
  return copy(({"on the head","on the left hand","on the right hand",
          "on the arms","about the body","on the legs",
          "on the feet","around the neck","around the neck"}));
}
 
int *query_base_ac()
{
  return copy(({0,0})); // ({ chance to hit mod(10 = 1%), damage mod })
}
 
int query_hands()  //The number of hands and therefore(?)
{                  //total number of weapons the race can wield
  return 2;  
}
 
//First int is which 'hand pair' is being queried about, the 
//second is 0 if raw score is wanted and 1 if skills for unarmed 
//combat are to be added.  Modifiers are described within.
//Humans have only one pair of hands, so the first int is 
//ignored.
 
varargs mixed *query_unarmed(int not_really_important,string wep_skill)
{
  //**DO NOT CHANGE THIS WITHOUT INFORMING ME, CASPER**
  return copy(({
    2916473 / (3 * (26 - this_object()->query_stat("strength")) + 
      (26 - this_object()->query_stat("agility")) + 2 * (1001 - 
      (wep_skill ? this_object()->query_skill(wep_skill) : 0)) + 
      (1001 - (wep_skill ? this_object()->query_skill("combat") 
      : 0))) - 949,
    //That was the damage bonus.  Worked to balance (somewhat) 
    //skills and the like.  Ask for an explination of why it 
    //is the way it is.  Casper
    (wep_skill && wep_skill == "unarmed" ? 5 + 
      this_object()->query_skill("unarmed")/10 : 0),
    //damage range needed ONLY for unarmed combat.  May need balancing
    7 * this_object()->query_stat("strength") + 21 * 
      this_object()->query_stat("agility") + (wep_skill ? 2 *
      this_object()->query_skill("combat") + 
      this_object()->query_skill(wep_skill) : 0) + 136,
    //base to_hit
    //Again, ask for an explination of why it is the way it 
    //is.  Casper
    (wep_skill && wep_skill == "unarmed" ? 0 : 
      this_object()->query_stat("strength") * 10 + 
      this_object()->query_stat("agility") * 20 + 
      this_object()->query_skill("combat") * 10) +
      (wep_skill != "unarmed" && wep_skill ? 
      this_object()->query_skill(wep_skill) * 10 : 0),
    //parry modifier.  Nill for unarmed combat (how DO you
    //parry with hands?) otherwize 2% per point of agil & 1%
    //per point of str + 1% per combat * weapon skill.
    ({"punch","sock","chop","jab"}),
    ({"punches","socks","chops","jabs"}),
    ({"miss","swing above", "jab beside", "swing short of"}),
    ({"misses","swings above", "jabs beside", "swings short of"}),
    ({"fists","balled hand", "hand", "fist"}),
    WEAPON_FISTS,
    this_object(),
    0}));
}
