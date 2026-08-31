#include <std.h>
inherit WEAPON;

create() {
  ::create();
        set_id(({"sword", "crystal sword"}));
        set_name("crystalline sword");
        set_short("%^BOLD%^WHITE%^C%^CYAN%^r%^WHITE%^y%^CYAN%^s%^WHITE%^t%^CYAN%^a%^WHITE%^l Sword%^RESET%^");
        set_long("This sword has been made of crystal, yet is hard and light, obviously magical. The shape of the weapon combined with it's crystal nature make it hum slightly as it is swung.");
        set_weight(30);
        set_curr_value("gold",87);
        set_wc(11);
        set("skill level", 225);
        set_ac(1);
        set_type("blade");
        set_hands(1);
        set_wield("The sword hums as it slices the air.");
        set_decay_rate(1000);
}

int query_auto_load() {
    if(this_player()->query_level() > 50) return 1;
    return 0;
}

int special() {
    int dmg;
    if(random(100) > 90) {
      dmg = (((this_player()->query_level()*3/2)+random(this_player()->query_level()/2))*3/4 + this_player()->query_stats("strength")*2/3);
      return dmg;
      }
}
