#ifndef __HEALING_H__
#define __HEALING_H__

public float set_healing(float amt);
public float set_max_healing(float amt);
public float set_healing_hp(float amt);
public float set_max_healing_hp(float amt);
public float set_healing_sp(float amt);
public float set_max_healing_sp(float amt);
public float set_healing_mp(float amt);
public float set_max_healing_mp(float amt);
public float get_healing_hp();
public float get_max_healing_hp();
public float get_healing_sp();
public float get_max_healing_sp();
public float get_healing_mp();
public float get_max_healing_mp();
public mapping get_healing();
public varargs int is_healing(int only_healing);

#endif // __HEALING_H__
