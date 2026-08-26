// statistic.h

#ifndef __STATISTIC_H__
#define __STATISTIC_H__

#define NUM_STATISTICS		3

#define TYPE_STATIC		0
#define TYPE_HEALTH		1
#define TYPE_WASTING	2

// prototypes

mapping query_exhausted();
mapping query_destroyed();
mapping query_notified();
void clear_statistic_flags();

int query_stat(string what);
int query_stat_current(string what);
int query_stat_maximum(string what);

int set_stat_current(string what, int val);
int set_stat_maximum(string what, int val);

void start_regenerate();
mixed set_stat_regenerate(string what, mixed val);
mixed query_stat_regenerate(string what);

varargs int damage_stat(string type, int damage, object who);
int heal_stat(string type, int heal);

int health_regenerator(object me, string stat, int max, int cur);
int wasting_regenerator(object me, string stat, int max, int cur);

#endif
