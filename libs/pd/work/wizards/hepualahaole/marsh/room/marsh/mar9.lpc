#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
    ::create();
    set_long("this is a standard
sentence"+this_object()->query_night_long()+".");
    set_exits( ([
"north" : MARSH "mar14",
"northwest" : MARSH "mar13",
"east" : MARSH "mar10",
"west" : MARSH "mar8",
    ]) );
}
string query_long() { 
  if(query_night()) 
      return ::query_long() + "A small pond can be seen to the south."; 
  else 
      return ::query_long() + "A small pond can be seen to the south."; 
} 
