#include <std.h>

inherit OBJECT;

int old;

void create() {
  ::create();
  set_short("%^BOLD%^%^YELLOW%^Light Sphere%^RESET%^");
  set_name("light sphere");
  set_long("This glowing sphere of light will help to brighten any room it's in.");
  set_id(({"sphere", "light sphere"}));
  set_curr_value("gold",1200);
  set_weight(4);
  old = 0;
}

int move(mixed dest) {
    int x;
 
    if(environment(this_object()))
        if(living(environment(this_object())))
            environment(this_object())->set_property("light", 0);
    x = ::move(dest);
    if(living(environment(this_object()))) {
        if((old = environment(environment(this_object()))->query_property("light")) < 3) {
            //message("info",old,find_player("nightshade"));
            environment(this_object())->set_property("light", 3 - old);
        }
    }
    return x;
}

int remove() {
  if (environment(this_object()))
    environment(this_object())->set_property("light",-1);
  return ::remove();
}
