#include <std.h>

inherit FOOD;

void create() {
    ::create();
    set_name("easter egg");
    set_id( ({ "egg", "easter egg" }) );
    set_short("an %^RED%^e%^GREEN%^a%^YELLOW%^s%^BLUE%^t%^MAGENTA%^e"
      "%^CYAN%^r%^RESET%^ egg");
    set_long(
      "A beautiful easter egg brought by the easter bunny.  It looks "
      "yummy.  If you do not want to eat it, why not hide it for "
      "someone else?"
    );
    set_value(0);
    set_mass(10);
    if(random(100) < 30) {
        set_strength(-10);
        set_eat("$N eat $O, and it is ROTTEN!",
          "$N eats $O, and it is ROTTEN!");
    }
    else {
        set_strength(10);
        set_eat("$N eat $O filled with delicious candy!",
          "$N eats $O filled with delicious candy!");
    }
}

void init() {
    ::init();
    add_action("cmd_search", "search");
    add_action("cmd_hide", "hide");
}

int cmd_hide(string str) {
    if(present(str, this_player()) != this_object()) return 0;
    message("my_action", "You hide "+query_short()+".", this_player());
    message("other_action", (string)this_player()->query_cap_name()+
      " hides something.", environment(this_player()), ({this_player()}));
    set_invis(1);
    move(environment(this_player()));
  return 1;
}

int cmd_search(string str) {
    if(!query_invis()) return 0;
    message("my_action", "You find "+query_short()+"!", this_player());
    message("other_action", (string)this_player()->query_cap_name()+
      "finds "+query_short()+"!", environment(this_player()), 
      ({ this_player() }));
    set_invis(0);
    return 1;
}
