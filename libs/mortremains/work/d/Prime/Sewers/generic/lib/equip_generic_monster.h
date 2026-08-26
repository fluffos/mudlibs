#define NUMBER_OF_EQUIP_TYPES 8
#define NUMBER_OF_EQUIP_MATERIALS 4

void equip_generic_monster(object equip, object monster);
object create_generic_armour();
string random_equip_type();
string random_equip_material();
void set_equip_properties(string equip_type, string equip_material);
string create_equip_short(string equip_type, string equip_material);
string create_equip_long(string equip_type, string equip_material);
int create_equip_ac(string equip_type, string equip_material);
int create_equip_weight(string equip_type, string equip_material);
int create_equip_value(string equip_type, string equip_material);




