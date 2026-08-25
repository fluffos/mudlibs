#ifndef __STORAGE_H
#define __STORAGE_H

protected  int Put(string str);
protected  int Get(string str);
protected  int Open(string str);
protected  int Close(string str);
protected  int Lock(string str);
protected  int Unlock(string str);
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
