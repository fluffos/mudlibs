// clay.h:  included by both users and monsters
//
// Functions pretaining to the race 'clay'.
// Malieable race, for all forms of animals and creatures
// Orig by casper 11/95
 
#include <weapon_types.h>
 
string *clay_armour_types, *clay_armour_locations;
int *clay_base_ac, clay_hands;
mixed *clay_combat_info;
 
string *query_armour_types()  //The 'ID' of armours that can be worn.
{
  return copy(clay_armour_types);
}
 
void set_armour_types(string *new_at)
{
  clay_armour_types = new_at;
}
 
string *query_armour_locations()  //Where the armours are worn
                                  //Parralel to above array
{
  return copy(clay_armour_locations);
}
 
void set_armour_locations(string *new_al)
{
  clay_armour_locations = new_al;
}
 
int *query_base_ac()
{
  return copy(clay_base_ac);
}
 
void set_base_ac(int *new_ac)
{
  clay_base_ac = new_ac;
}
 
 
int query_hands()  //The number of hands and therefore(?)
{                  //total number of weapons the race can wield
  return clay_hands;
}
 
void set_hands(int new_hands)
{
  clay_hands = new_hands;
}
 
varargs mixed *query_unarmed(int hand_pair,string wep_skill)
{
  return copy(clay_combat_info[hand_pair]);
}
 
void set_unarmed(mixed *new_combat_info)
{
  clay_combat_info = new_combat_info;
}
