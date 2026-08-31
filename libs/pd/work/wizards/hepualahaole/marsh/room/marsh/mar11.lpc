#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
    ::create();
    set_long("this is a standard
sentence"+this_object()->query_night_long()+".");
    set_exits( ([
"northwest" : MARSH "mar15",
"north" : MARSH "mar16",
"west" : MARSH "mar10",
"east" : MARSH "mar12",
    ]) );
}
string query_long() { 
  if(query_night()) 
      return ::query_long() + "A small pond can be seen to the south."; 
  else 
      return ::query_long() + "A small pond can be seen to the south."; 
} 
