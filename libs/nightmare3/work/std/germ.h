#ifndef __GERM_H
#define __GERM_H

void create();
void init();
void heart_beat();
int filter_living(object ob);
int sort_weak(object a, object b);
void multiply();
int infect(object ob);
int cure(int x);
void suffer(object ob);
void set_communicable(int x);
int query_communicable();
void set_cure_level(int x);
int query_cure_level();
void set_life_span(int x);
int query_life_span();
void set_type(string str);
string query_type();

#endif /* __GERM_H */
