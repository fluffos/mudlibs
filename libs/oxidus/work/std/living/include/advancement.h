#ifndef __ADVANCEMENT_H__
#define __ADVANCEMENT_H__

int query_xp() ;
float query_tnl() ;
float query_level() ;
float query_effective_level() ;
float set_level(float l) ;
float adjust_level(float l) ;
float query_level_mod() ;
float set_level_mod(float l) ;
float adjust_level_mod(float l) ;
int adjust_xp(int amount) ;
int set_xp(int amount) ;
void on_advance(object tp, float l) ;

#endif // __ADVANCEMENT_H__
