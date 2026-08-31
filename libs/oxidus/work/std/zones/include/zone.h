#ifndef __ZONE_H__
#define __ZONE_H__

void add_room(object room);
void remove_room(object room);
object *query_rooms();
int query_num_rooms();
int is_zone();
void set_target_mobs(int n);
int query_target_mobs();
float query_spawn_chance();
int add_mob(object ob);
int query_num_mobs();

#endif // __ZONE_H__
