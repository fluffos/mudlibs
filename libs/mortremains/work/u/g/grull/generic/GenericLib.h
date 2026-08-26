#ifndef Generic_Lib

#define Generic_Lib

#define GDir "/u/g/grull/generic/"   
#define GObjDir "/u/g/grull/generic/objects/"   
#define GRmDir "/u/g/grull/generic/rooms/"  
#define GMonDir "/u/g/grull/generic/monsters/" 
#define GWepDir "/u/g/grull/generic/weapons/"  
#define GArmDir "/u/g/grull/generic/armour/"  
#define GLibDir "/u/g/grull/generic/lib/"   

#define POPULATE_GENERIC_MONSTERS_HEADER "/u/g/grull/generic/lib/populate_generic_monsters.h"
#define ARM_GENERIC_MONSTER_HEADER "/u/g/grull/generic/lib/arm_generic_monster.h"
#define EQUIP_GENERIC_MONSTER_HEADER "/u/g/grull/generic/lib/equip_generic_monster.h"

varargs void set (string prop, mixed data, int security);
void set_weapon_type(string type);
void set_material_type(string type);

#endif


