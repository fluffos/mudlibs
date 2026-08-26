// This file is part of the TMI mudlib distribution.
// Please include this header if you use this code.

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


string query_short() { return _query("short"); }
string query_long() { return _query("long"); }
string query_name() { return _query("name"); }
string query_cap_name() { return _query("cap_name"); }
string *query_id() { return _query("id"); }




