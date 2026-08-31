#include <std.h>

inherit OBJECT;

string extra_look();

void create() {
  ::create();
  set_short("");
    set_long( "" );
  set_name("");
  set_id(({"badmark_quest"}));
  set_weight(0);
}

string extra_look() {
  return "%^BOLD%^%^RED%^A sense of strong evil radiates off of "+objective(environment(this_object()))+".%^RESET%^\n";
}

int query_auto_load() {
    return 1;
}

int drop() { return 1; }

int get() { return 1; }

int give() { return 1; }
