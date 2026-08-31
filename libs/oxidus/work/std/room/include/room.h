#ifndef __ROOM_H__
#define __ROOM_H__

mapping gmcp_room_info(object who) ;
string set_room_type(string type) ;
string set_room_subtype(string subtype) ;
string set_room_icon(string icon) ;
string query_room_type() ;
string query_room_subtype() ;
string query_room_icon() ;
string query_room_environment() ;
void set_room_environment(string environment) ;
void set_room_colour(int colour) ;
int query_room_colour() ;
void add_custom_gmcp(string key, mixed value) ;
void set_no_gmcp_room_info(int no_gmcp) ;
void remove_custom_gmcp(string key) ;
mapping query_custom_gmcp() ;
int no_renew() ;
int is_room() ;

#endif // __ROOM_H__
