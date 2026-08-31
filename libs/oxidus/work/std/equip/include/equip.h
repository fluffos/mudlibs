#ifndef __EQUIP_H__
#define __EQUIP_H__

mixed can_equip(string slot, object tp);
void set_slot(string str);
string query_slot();
mixed equip(object tp, string slot);
mixed can_unequip(object tp);
varargs int unequip(object tp, int silent);
int equipped();

#endif // __EQUIP_H__
