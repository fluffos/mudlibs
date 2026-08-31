#ifndef __EQUIPMENT_H__
#define __EQUIPMENT_H__

public int equip(object ob, string slot);
public mapping query_equipped();
public mapping query_wielded();
public object equipped_on(string slot);
public object wielded_in(string slot);
public mixed equipped(object ob);
public int unequip(mixed ob);
public mixed can_equip(mixed ob, string slot);

protected int equip_weapon(object weapon, string slot);
protected int equip_wearable(object wearable, string slot);

protected int unequip_weapon(object weapon);
protected int unequip_wearable(object wearable);

#endif // __EQUIPMENT_H__
