// This file is part of the TMI mudlib distribution.
// Please include this header if you use this code.
// This object is intended to make 0.8.* code compatible with 0.9 mudlibs.
// If you are not converting old code, them rm this file and don't use it.
// Mobydick renamed this file 11-14-92 to see if anything was inheriting it.

// Leto fixed all _query to query to make it loadable again,
// but better do as moby said and delete this ;) 94-11-11

// Description stuff: this stuff is compatibility busting. 
// use set("short", str) and query("short").  
// These are here for the interim.
// query_name: returns the string true_name
// query_cap_name: returns the capitalized true_name, set to save cpu

#define set_short(s)	set("short", s) 
#define set_long(s)	set("long", s) 
#define set_weight(i)	set("weight", i)
#define set_name(n)	set("name", n)
#define set_id(x)	set("id", x)
#define set_light(i)	set("light", i)

#include <mudlib.h>

inherit OBJECT ;




string query_short() { return query("short"); }
string query_long() { return query("long"); }
string query_name() { return query("name"); }
string query_cap_name() { return query("cap_name"); }
string *query_id() { return query("id"); }




