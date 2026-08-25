#ifndef __ROOM_H
#define __ROOM_H

protected  void create();
protected  void reset();
void init();
void set_short(string str);
void set_long(string str);
string query_short();
varargs string query_long(string str);
string query_extra_long();
int query_reset_number();
int move(mixed dest);
string *query_id();
int id(string str);
varargs int receive_objects(object ob);

#endif /* __ROOM_H */
