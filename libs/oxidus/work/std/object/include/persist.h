#ifndef __PERSIST_H__
#define __PERSIST_H__

protected void save_var(mapping vars) ;
public mapping get_saved_vars() ;
protected void set_save_recurse(int flag) ;
varargs string save_to_string(int recursep) ;
void load_from_string(mixed value, int recurse) ;

#endif // __PERSIST_H__
