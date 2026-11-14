
#ifndef _UTIL_
#define _UTIL_


/*
 * declaration of some useful utility functions defined in util.c
 */

string get_path(string path);
int is_me(string desc);
int is_in(object env);
mixed *remove_array(mixed *ar,int start,int end);
mixed *remove_entry(mixed entry,mixed *ar);
void write_array(mixed ar);
object load_object(string file);
match_item(string str,string *ads,string *ids);

void module(string file);
int is_cloned(string file);

#define ForAll(ar,var) if (!empty(ar)) for (var=0; var<sizeof(ar); var++)

#endif

