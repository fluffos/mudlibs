// clay.h:  included by both users and monsters
//
// Functions pretaining to the race 'clay'.
// Malieable race, for all forms of animals and creatures
// Orig by casper 11/95
 
#include <weapon_types.h>
 
string *armour_types, *armour_locations;
int *base_ac, hands;
mixed *combat_info;
 
string *query_armour_types()  //The 'ID' of armours that can be worn.
{
  return copy(armour_types);
}
 
void set_armour_types(string *new_at)
{
  armour_types = new_at;
}
 
string *query_armour_locations()  //Where the armours are worn
                                  //Parralel to above array
{
  return copy(armour_locations);
}
 
void set_armour_locations(string *new_al)
{
  armour_locations = new_al;
}
 
int *query_base_ac()
{
  return copy(base_ac);
}
 
void set_base_ac(int *new_ac)
{
  base_ac = new_ac;
}
 
 
int query_hands()  //The number of hands and therefore(?)
{                  //total number of weapons the race can wield
  return hands;
}
 
void set_hands(int new_hands)
{
  hands = new_hands;
}
 
varargs mixed *query_unarmed(int hand_pair,string wep_skill)
{
  return copy(combat_info[hand_pair]);
}
 
void set_unarmed(mixed *new_combat_info)
{
  combat_info = new_combat_info;
}
