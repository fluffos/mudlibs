#include <std.h>
inherit DAEMON;
int spell();
 
int cmd_shadowveil() {
    object ob = this_player();
    int defense;
    int cost;
    int dex;
    int stealth = (int)this_player()->query_skill("stealth");
 
if(environment(this_player())->query_property("no magic")) {
        notify_fail("Something is blocking your concentration.\n");
        return 0;
    }
    cost = 100 + random(50);
    if((int)this_player()->query_mp() < cost) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    defense = (int)this_player()->query_stats("intelligence");
    if(defense < 10) {
        write("You are not smart enough!");
        say(this_player()->query_cap_name()+" mutters a spell of shadows, but "+
          this_player()->query_possessive()+" words fail.", this_player());
        return 1;
    }
    
    this_player()->add_mp(-cost);
    write("%^BLACK%^Shadows swirl about as you call on them to hide you.%^RESET%^");
    this_player()->add_exp(random(defense));
    return 1;
    this_player()->set_property("stealth", (stealth+dex) * 2);
    return 1;

}

void help() {
  write("Syntax: <shadowveil>\n\nCreates a veil of %^BLACK%^shadows%^RESET%^ for the worthy to hide in.");
}

int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_stats("intelligence") < 10) return 0;
   return 1;
}
