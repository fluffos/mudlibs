#ifndef __WEAPON_MAGIC_H__

#define __WEAPON_MAGIC_H__

// Prototypes:

nomask void set_magic(int mgc);
int query_magic_level();
nomask void modify_resistance(int kind,int value);
nomask void modify_stat(int stat,int value);
private void _do_modify(int wwi);
int enchant(int amt);
int disenchant(int amt);

// End prototypes.


// Global variables:

int magic_level;    // magic level of weapon
private mapping res_mod;
private mapping stat_mod;

// End global variables.

#endif // __WEAPON_MAGIC_H__
