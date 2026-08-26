/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// Module for salvageable items handling breaking them down into
// "realistic" components so you don't get metal out of a wooden shields.
//
// Initial version by Tsath@PLEXUS, 2020.

#include <config/equipment.h>

/*
** M_SALVAGEABLE by Tsath 2019
**
*/

void add_adj(string *adj...);
mixed need_to_be_unused();

mapping salvageable = ([]);
mapping direct_salvage = ([]);
int damaged = 0;
private
string primary_material;

//: FUNCTION query_salvage_level
// int query_salvage_level()
// Returns the salvage level determining how much material an object
// will drop when salvaged. This function returns sane values for
// weapons, armour and pelts.
int query_salvage_level()
{
   if (this_object()->is_weapon())
      return this_object()->query_weapon_class();
   if (this_object()->is_junk())
      return this_object()->query_junk_level();
   if (this_object()->is_armour())
      return this_object()->query_armour_class();
   if (this_object()->is_pelt())
      return this_object()->query_pelt_size();
   return 0;
}

//: FUNCTION set_direct_salvage
// Sets the direct materials retrieved from salvaging this
// item. The argument is a mapping containing the material gained
// and the number of them.
//  "plastic bag":2 etc
void set_direct_salvage(mapping salv)
{
   direct_salvage = salv;
}

//: FUNCTION query_direct_salvage
// Returns the mapping containing the direct salvageable items.
mapping query_direct_salvage()
{
   return direct_salvage;
}

//: FUNCTION set_damaged
// void set_damaged()
// Sets the object as DAMAGED_EQ_NAME meaning reduced durability,
// and gives it a new adjective.
void set_damaged()
{
   damaged = 1;
   //add_adj(DAMAGED_EQ_NAME);
   this_object()->set_damaged_durability();
}

//: FUNCTION is_damaged
// int is_damaged()
// Returns true is the object is damaged, else 0.
int is_damaged()
{
   return damaged;
}

//: FUNCTION primary_salvage
// Returns the material that is the most prevalent in the item.
//  example:
//    set_salvageable((["wood":15, "metal":85, ]));
//    would return:
//    primary_salvage() -> "metal"
string primary_salvage()
{
   return primary_material;
}

//: FUNCTION set_salvageable
// int set_salvageable(mapping s)
// Sets the salvage mapping for object. Salvage mappings contains
// valid categories are defined by being part of:
//  CRAFTING_D->query_salvage_categories();
// example:
//   set_salvageable((["chemical":5, "metal":85, "mineral":10, ]));
//
// The numbers must sum to 100, or the salvage mapping will be rejected.
int set_salvageable(mapping s)
{
   int sum = 0;
   int largest = 0;
   foreach (string key in keys(s))
   {
      int p = s[key];
      if (CRAFTING_D->valid_category(key))
      {
         if (p > largest)
         {
            primary_material = key;
            largest = p;
         }
         sum += p;
      }
      else
         error("Invalid salvage type: "+key);
   }
   if (sum != 100)
      return 0;

   salvageable = s;
   return 1;
}

//: FUNCTION is_salvageable
// int is_salvageable()
// Returns 1 if the object is salvageable, otherwise 0. If the object doesn't
// have a valid salvage mapping (see set_salvageable()) it always returns 0.
int is_salvageable()
{
   return sizeof(keys(salvageable)) > 0 || sizeof(keys(direct_salvage)) > 0;
}

//: FUNCTION query_salvageable
// mapping query_salvageable()
// Returns the salvage mapping set by set_salvageable().
mapping query_salvageable()
{
   return salvageable;
}

// This always returns 1 to let the salvage verb do the walking.
// Ensure this function is simply and works, otherwise it may crash the mud
// ... currently (2023-10-27).
int direct_salvage_obj()
{
   return need_to_be_unused();
}