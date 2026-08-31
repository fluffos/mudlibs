#include <std.h>
#include <purgatory.h>
inherit WEAPON;
int weapon_hit(object atk);
 
create() {
    ::create();
   set_short("Blade of the Gods");
   set_name("Blade of the Gods");
   set_id( ({"blade", "sword"}) );
   set_long ("Forged in a small smithy by an aging weapons smith, this blade glows with an inner light that could only be put in the metal by the hand of a God.");
   set_weight(20);
   set_curr_value("gold", 121);
   set_wc(11);
   set_ac(2);
   set("skill level", 200);
   set_type("blade");
   set_hit((: weapon_hit :));
   set_decay_rate(1000);
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) < 15) {
       write("%^BOLD%^%^WHITE%^A peircing white light emerges from the blade to strike your opponent.%^RESET%^");
        say("%^BOLD%^%^WHITE%^"+(string)this_player()->query_cap_name()+"'s blade shoots a white bolt into "+atk->query_cap_name()+".");
       
result= (random(50)*2)+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 60) return 1; }

