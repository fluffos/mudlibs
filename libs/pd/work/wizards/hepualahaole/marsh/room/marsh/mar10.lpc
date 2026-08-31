#include <std.h>
#include <marshserver.h>
inherit VIRTUALROOM;
void create() {
  set_server(SERVER);
    ::create();
    set_long("this is a standard
sentence"+this_object()->query_night_long()+".");
    set_exits( ([
"north" : MARSH "mar15",
"northeast" : MARSH "mar16",
"east" : MARSH "mar11",
"west" : MARSH "mar9",
    ]) );
}
string query_long() { 
  if(query_night()) 
      return ::query_long() + "A small pond can be seen to the south."; 
  else 
      return ::query_long() + "A small pond can be seen to the south."; 
} 
