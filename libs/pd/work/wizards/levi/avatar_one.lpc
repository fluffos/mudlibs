#include <std.h>

inherit OBJECT;

string extra_look();

void create() {
  ::create();
  set_short("");
    set_long( "You do not notice that here." );
  set_name("");
  set_id(({"avatar_one"}));
  set_weight(0);
}

string extra_look() {
  return "%^CYAN%^"+environment()->query_cap_name()+" is a Knight of the Avatar.%^RESET%^\n";
}

int query_auto_load() {
    return 1;
}

int drop() { return 1; }

int get() { return 1; }

int give() { return 1; }
