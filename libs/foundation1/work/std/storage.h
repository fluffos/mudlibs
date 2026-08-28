#ifndef __STORAGE_H
#define __STORAGE_H

nosave int Put(string str);
nosave int Get(string str);
nosave int Open(string str);
nosave int Close(string str);
nosave int Lock(string str);
nosave int Unlock(string str);
int pick_lock();
varargs string query_long(string str);
varargs int receive_objects(object ob);
void set_can_close(int x);
int query_can_close();
void set_can_lock(int x);
int query_can_lock();
void set_closed(int x);
int query_closed();
void set_locked(int x);
int query_locked();
void set_key(string str);
string query_key();

#endif /* __STORAGE_H */
