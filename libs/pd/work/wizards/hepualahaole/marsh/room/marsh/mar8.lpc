#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
    ::create();
    set_long("this is a standard
sentence"+this_object()->query_night_long()+".");
    set_exits( ([
"north" : MARSH "mar13",
"southwest" : MARSH "mar6",
"northeast" : MARSH "mar14",
"east" : MARSH "mar9",
    ]) );
}
string query_long() { 
  if(query_night()) 
      return ::query_long() + "A path traces around a small pond."; 
  else 
      return ::query_long() + "A path traces around a small pond."; 
} 
