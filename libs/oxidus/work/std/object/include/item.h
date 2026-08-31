#ifndef __ITEM_H__
#define __ITEM_H__

void set_spawn_info(mapping info) ;
void add_spawn_info(string key, mixed value) ;
mixed query_spawn_info(string key) ;
mapping query_all_spawn_info() ;
int move(mixed dest) ;
int allow_move(mixed dest) ;
void set_fixed(int fixed);
int is_fixed();
void set_post_spawn_fixed(int setting);
int query_post_spawn_fixed();

#endif // __ITEM_H__
