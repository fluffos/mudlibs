#ifndef __DAMAGE_H__
#define __DAMAGE_H__

public float adjust_damage_by_severity(float damage, string severity);
public varargs float calculate_damage(object enemy, mixed weapon_or_skill);
public float deliver_damage(object victim, float damage, string type);
public float deliver_magic_damage(object victim, float damage, string type);
public float deliver_mundane_damage(object victim, float damage, string type);
public float receive_damage(object attacker, float damage, string type);
public float receive_magic_damage(object attacker, float damage, string type);
public float receive_mundane_damage(object attacker, float damage, string type);

#endif // __DAMAGE_H__
