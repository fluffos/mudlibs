#include <std.h>

inherit OBJECT;

string extra_look();

void create() {
  ::create();
  set_short("");
    set_long( "" );
  set_name("");
  set_id( ({ "aura" }) );
  set_weight(0);
}

string extra_look() {
  return "%^BOLD%^%^RED%^A great mass of flames engulfs "+objective(environment(this_object()))+".%^RESET%^\n";
}

int query_auto_load() {
    return 1;
}

int drop() { return 1; }
int get() { return 1; }
