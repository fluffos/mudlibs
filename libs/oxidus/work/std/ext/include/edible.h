#ifndef __EDIBLE_H__
#define __EDIBLE_H__

public void set_eat_action(string action);
public void set_self_eat_action(string action);
public void set_room_eat_action(string action);
public void set_nibble_action(string action);
public void set_self_nibble_action(string action);
public void set_room_nibble_action(string action);
public int set_edible(int edible);
public int is_edible();
protected mixed eat(object user);
protected mixed nibble(object user, int amount);
public void reset_edible();

#endif // __EDIBLE_H__
