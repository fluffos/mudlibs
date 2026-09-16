#ifndef __ARMOUR_H__
#define __ARMOUR_H__

#include <clothing.h>

public int equip(object tp, string slot);
public int unequip(object tp, int silent);
public void set_defence(mapping def);
public void add_defence(string type, float amount);
public mapping query_defence();
public float query_defence_amount(string type);
public void set_ac(float ac);
public float query_ac();
public float add_ac(float ac);
public int is_armour();


#endif // __ARMOUR_H__
