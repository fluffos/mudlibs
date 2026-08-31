#ifndef __WEAPON_CONDITION_H__

#define __WEAPON_CONDITION_H__

// Prototypes:

int query_condition();
nomask void init_conditions();
private void check_condition();
string show_condition();
nomask void decay_condition(int amt);
varargs void fix_condition(int lvl);

// End prototypes.


// Global variables:

private int max_condition,curr_condition;
private int weap_condition;

// End global variables.

#endif // __WEAPON_CONDITION_H__
