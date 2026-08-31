#ifndef __INIT_H__
#define __INIT_H__

void event_init(object prev, object tp) ;
void add_init(mixed fun) ;
void remove_init(mixed fun) ;
void clear_inits() ;
mapping query_inits() ;

#endif // __INIT_H__
