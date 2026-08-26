#ifndef __CONDITION_H__
#define __CONDITION_H__

void restore_condition();
void update_condition();
void delete_condition(string cnd);
void clear_condition();
void set_condition(string cnd, mapping info);
mapping query_condition(string cnd);
mapping query_all_conditions();

#endif
