#ifndef _OLD_WEAPON_H_
#define _OLD_WEAPON_H_
void set_hit_func(object ob) { set_hit((: ob, "weapon_hit" :)); }

void set_wield_func(object ob) { set_wield((: ob, "extra_wield" :)); }

void set_wield_string(string str) { set_wield(str); }

#endif
