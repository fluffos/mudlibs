#ifndef __PLAYER_H__
#define __PLAYER_H__

void setup_body() ;
void enter_world(int reconnecting) ;
void exit_world() ;
void net_dead() ;
void reconnect() ;
void heart_beat() ;
int supports_unicode() ;
void on_crash(mixed arg...) ;
void move_or_destruct(object ob) ;
mixed query_environ(string key) ;
void clear_environ_data() ;
mapping query_all_environ() ;
void set_environ_option(string key, mixed value) ;
void receive_environ(string var, mixed value) ;
void set_environ(mapping data) ;
void restore_body() ;
int save_inventory() ;
void restore_inventory() ;
void wipe_inventory() ;
int save_body() ;
int has_screenreader() ;
int is_pc() ;
int query_last_login() ;
void set_last_login(int time) ;

#endif // __PLAYER_H__
