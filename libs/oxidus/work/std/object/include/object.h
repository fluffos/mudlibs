#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "module.h"

string set_name(string str);
string query_name();
string query_real_name();

int remove();
varargs void reset(mixed args...);
string set_real_name(string str);
string find_path(string path);
void set_virtual_master(string str);
string query_virtual_master();
int add_destruct(function f);
int remove_destruct(function f);
void process_destruct();
void add_reset(function f);
void remove_reset(function f);
void process_reset();
void set_prevent_get(mixed val);
int query_prevent_get();
string query_last_location();
object last_location();

#endif // __OBJECT_H__
