#ifndef __POTABLE_H__
#define __POTABLE_H__

public void set_drink_action(string action);
public void set_self_drink_action(string action);
public void set_room_drink_action(string action);
public void set_sip_action(string action);
public void set_self_sip_action(string action);
public void set_room_sip_action(string action);
public int set_potable(int potable);
public int is_potable();
protected int drink(object tp);
protected int sip(object tp, int amount);
public void reset_potable();

#endif // __POTABLE_H__
