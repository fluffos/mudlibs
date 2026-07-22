// troop.h
#ifndef __TROOP__
#define __TROOP__

string query_troop_mapped(string troop);
varargs void map_troop(string troop, string mapped_to);
varargs int query_troop(string troop, int raw);
varargs void improve_troop(string troop, int amount, int weak_mode);

#endif
