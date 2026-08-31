#include <std.h>

inherit OBJECT;

string extra_look();

void create() {
  ::create();
    set_short("");
    set_long("");
    set_id(({"aura"}));
    set_weight(0);
}

string extra_look() {
  return "%^BOLD%^%^YELLOW%^A faint yellow glow can be seen around "+objective(environment(this_object()))+".\n";
}

int query_auto_load() {
    return 1;
}

int drop() { return 1; }

int get() { return 1; }

int give() { return 1; }

int bury() { return 1; }
