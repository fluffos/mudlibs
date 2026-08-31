#ifndef __ALIAS_H__
#define __ALIAS_H__

void init_aliases() ;
void wipe_aliases() ;
void add_alias(string k, string v) ;
void remove_alias(string k) ;
int has_alias(string k) ;
string get_alias(string k) ;
mapping get_aliases() ;

#endif // __ALIAS_H__
