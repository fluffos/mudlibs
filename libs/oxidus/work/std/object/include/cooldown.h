#ifndef __COOLDOWN_H__
#define __COOLDOWN_H__

void cooldown() ;
mapping query_cooldowns() ;
void set_cooldown(string id, int cooldown) ;
int add_cooldown(string id, int cooldown) ;
int remove_cooldown(string id) ;
int query_cooldown(string id) ;
int query_cooldown_remaining(string id) ;
int adjust_cooldown(string id, int amount) ;
int wipe_cooldowns() ;

#endif // __COOLDOWN_H__
