#include <std.h>;
#include <shadow.h>;

inherit ARMOUR;

void create() {
  ::create();

  set_name("cap");
  set("id", ({ "cap", "hat", "jester's cap" }) );
  set("short", "Jester's Cap");
  set("long", "It is a silly hat.
%^BOLD%^%^GREEN%^                   _
%^BOLD%^%^GREEN%^             _____/ \\_____
%^BOLD%^%^GREEN%^            / __  \\_/  __ \\
%^BOLD%^%^GREEN%^           / /  \\     /  \\ \\
%^BOLD%^%^GREEN%^           |/   | ___ |   \\|
%^BOLD%^%^RED%^           O %^GREEN%^   |/   \\| %^RED%^   O");
  set_type("helmet");
  set_ac(2);
  set_limbs( ({ "head" }) );
  set_weight(3);
    set_curr_value("gold", 40);
}

int query_auto_load() {
  if (this_player()->query_level() > 12)
  return 1;
}
