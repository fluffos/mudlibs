#define NUMBER_OF_WEAPON_TYPES 4
#define NUMBER_OF_WEAPON_MATERIALS 4

void arm_generic_monster(object weapon, object monster);
/* Arms a monster. */

object create_generic_weapon();
/* Returns a random weapon */

string random_weapon_type();
/* Returns a random weapon type */

string random_weapon_material();
/* Returns a random weapon material */

string create_weapon_short(string weapon_type, string weapon_material);
/* Returns a short description for the particular weapon type */

string create_weapon_long(string weapon_type, string weapon_material);
/* Returns a long description for the particulare weapon type */

void set_weapon_properties(string weapon_type, string weapon_material);
/* 
   Sets the weapon properteis based on the weapon type and material. Currently,
   properties are:

   short description
   long description
   type
   length
   name
   alias
   weapon class
   weight
   value

*/

int create_weapon_length(string weapon_type);
/* Returns a length for the weapon, based on type */

string create_weapon_name(string weapon_type);
/* Returns a name for the weapon, based on type */

string create_weapon_alias(string weapon_type);
/* Returns an alias for the weapon, based on type */

int create_weapon_class(string weapon_type, string weapon_material);
/* Returns a class for the weapon, based on type and material */

int create_weapon_weight(string weapon_type, string weapon_material);
/* Returns a weight for the weapon, based on type and material */

int create_weapon_value(string weapon_type, string weapon_material);
/* 
   Returns a value for the weapon, based on type and material. Currently,
   I'm only using weapon class, since none of these are antiques, so neither
   craftsmanship nor material are particularly important.
   */

