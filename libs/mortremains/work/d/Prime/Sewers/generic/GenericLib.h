#ifndef Generic_Lib

#define Generic_Lib

#define GDir "/d/Prime/Sewers/generic/"   
#define GObjDir "/d/Prime/Sewers/generic/objects/"   
#define GRmDir "/d/Prime/Sewers/generic/rooms/"  
#define GMonDir "/d/Prime/Sewers/generic/monsters/" 
#define GWepDir "/d/Prime/Sewers/generic/weapons/"  
#define GArmDir "/d/Prime/Sewers/generic/armour/"  
#define GLibDir "/d/Prime/Sewers/generic/lib/"   

#define POPULATE_GENERIC_MONSTERS_HEADER "/d/Prime/Sewers/generic/lib/populate_generic_monsters.h"
#define ARM_GENERIC_MONSTER_HEADER "/d/Prime/Sewers/generic/lib/arm_generic_monster.h"
#define EQUIP_GENERIC_MONSTER_HEADER "/d/Prime/Sewers/generic/lib/equip_generic_monster.h"

varargs void set (string prop, mixed data, int security);
void set_weapon_type(string type);
void set_material_type(string type);

#endif


