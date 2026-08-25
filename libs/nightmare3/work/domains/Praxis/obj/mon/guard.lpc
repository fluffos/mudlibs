#include <std.h>
#include <rooms.h>

inherit MONSTER;

private object __Target;

void heart_beat() {
    monster::heart_beat();
    if(__Target && environment(__Target) != environment(this_object())) {
      message("say", "%^BOLD%^%^RED%^The guard tells you: %^RESET%^"+
          "An' where do ya think you're goin' buster??", __Target);
      __Target->move_player(environment(this_object()));
    }
}

void set_target(object ob) {
    if(!ob) return;
    __Target = ob;
}
