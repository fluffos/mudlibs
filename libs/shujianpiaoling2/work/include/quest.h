// quest.h
#ifndef __QUEST__
#define __QUEST__

string query_quest_mapped(string quest);
varargs void map_quest(string quest, string mapped_to);
varargs int query_quest(string quest, int raw);
varargs void improve_quest(string quest, int amount, int weak_mode);

#endif
