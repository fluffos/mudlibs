//  Whit

#include <std.h>
#include <cogain.h>

inherit ROOM;
int closed;

void create() {
    ::create();
    set_name("Cogain Village");
    set_short("The Cogain Villa");
    set_long("The tall walls of the castle stand to the south protecting the "
      "city from intrusion.  ");
    set_exits(([
	"south":VROOM+"1",
	"north":VROOM+"3",
      ]));
    set_pre_exit_functions( ({"south"}), ({"go_south"}) );
}

string query_long() {
    if(closed)
	return "The tall walls of the castle stand to the south protecting the "
	"city from intrusion.  The drawbridge to the south is up, preventing "
	"anyone from exiting the city.";
    return "The tall walls of the castle stand to the south protecting the "
       "city from intrusion.  The drawbridge to the south is lowered, allowing
"
       "access to anyone entering the city.";
  
}

void set_closed(int i) { closed=i; }
int query_closed() { return closed; }

int go_south() {
   if(query_closed()) {
     write("The drawbridge is not lowered.\n");
     return 0;
   }
   return 1;
}

