#include <std.h>

inherit SKY_ROOM;

void create() {
   ::create();
   set_exits((["castle":"/d/warwick/main"]));
   set_coords(({32, 23, 1}));
}

string query_long() {
   return ::query_long()+"\n\n%^BOLD%^%^RED%^A castle is here%^RESET%^\n\n%^GREEN%^There is one exit: castle.\n";
}
