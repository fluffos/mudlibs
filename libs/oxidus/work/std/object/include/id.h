#ifndef __ID_H__
#define __ID_H__

void set_id(mixed str) ;
void set_adj(mixed str) ;
void add_id(mixed str) ;
void add_adj(mixed str) ;
void remove_id(mixed str) ;
void remove_adj(mixed str) ;
string *query_ids() ;
string *query_plural_ids() ;
string *query_adjs() ;
void rehash_ids() ;

#endif // __ID_H__
