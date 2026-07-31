#ifndef __DBASE__
#define __DBASE__

// This is the 'expected' dbase size, which is allocated when initial
#define DEFAULT_DBASE_SIZE		15

mapping query_entire_dbase();
mapping query_entire_temp_dbase();

mixed set(string , mixed );
mixed set_vector(string , mixed ,  mixed );
varargs mixed query(string , int );
mixed add(string , mixed );
int delete(string );

mixed set_temp(string , mixed );
mixed set_temp_vector(string , mixed , mixed );
varargs mixed query_temp(string , int );
mixed add_temp(string , mixed );
int delete_temp(string );

#endif
