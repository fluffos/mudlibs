#ifndef __WEAPON_SIZE_H__

#define __WEAPON_SIZE_H__

// Prototypes:

void set_size(int sz);
int query_size();
void set_two_handed();
int query_two_handed();
void set_weight(int w);
int query_weight();
private void update_wt();

// End prototypes.


// Global variables:

int two_handed;
int local_weight,weap_size;

// End global variables.

#endif // __WEAPON_SIZE_H__
