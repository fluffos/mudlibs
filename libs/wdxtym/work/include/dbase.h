#ifndef __DBASE__
#define __DBASE__

// This is the 'expected' dbase size, which is allocated when initial
#define DEFAULT_DBASE_SIZE		15

mapping query_entire_dbase();
mapping query_entire_temp_dbase();

// The optional trailing object of set/delete and the second argument of query may name the object whose
// dbase is meant (query("id", ob) is ob->query("id")); see feature/dbase.lpc.
varargs mixed set(string prop, mixed data, object ob);
mixed set_vector(string prop, mixed owner, mixed func);
varargs mixed query(string prop, mixed raw_or_ob);
mixed add(string prop, mixed data);
varargs int delete(string prop, object ob);

varargs mixed set_temp(string prop, mixed data, object ob);
mixed set_temp_vector(string prop, mixed owner, mixed func);
varargs mixed query_temp(string prop, mixed raw_or_ob);
mixed add_temp(string prop, mixed data);
varargs int delete_temp(string prop, object ob);

#endif
