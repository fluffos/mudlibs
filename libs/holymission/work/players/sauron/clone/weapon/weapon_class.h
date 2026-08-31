#ifndef __WEAPON_CLASS_H__

#define __WEAPON_CLASS_H__

// Prototypes:

void set_kind(int i);
int query_weapon_kind();
void set_type(int i);
int query_weapon_type();
void set_class(int class);
int query_class();
int query_mod_class();
private void update_mwc();

// End prototypes.


// Global variables:

int modified_wc,class_level,weapon_kind,weapon_type;

// End global variables.

#endif // __WEAPON_CLASS_H__
