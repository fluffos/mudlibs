#ifndef __CONTAINER_H__
#define __CONTAINER_H__

varargs int is_content_accessible(object pov);
int can_receive(object ob);
void receive_effect(object ob);
int can_release(object ob);
void release_effect(object ob);
void set_ignore_capacity(int i);
int ignore_capacity();
void set_ignore_mass(int i);
int ignore_mass();
void set_closeable(int i);
int is_closeable();
void set_lockable(int i);
int is_lockable();
void set_closed(int i);
int is_closed();
void set_locked(int i);
int is_locked();
void set_opaque(int i);
int is_opaque();
varargs mixed query_container_status(int as_number);
public void set_key_id(string str);
public string query_key_id();
int is_container();

#endif // __CONTAINER_H__
