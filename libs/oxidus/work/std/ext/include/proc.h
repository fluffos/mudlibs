#ifndef __PROCS_H__
#define __PROCS_H__

void set_procs(mixed *procs) ;
void add_proc(string name, mixed proc) ;
void remove_proc(string name) ;
mapping query_proc(string name) ;
mapping query_all_procs() ;
void set_proc_chance(float chance) ;
float query_proc_chance() ;
void adjust_proc_chance(float chance) ;
string can_proc() ;
varargs void proc(string name, mixed args...) ;

#endif // __PROCS_H__
