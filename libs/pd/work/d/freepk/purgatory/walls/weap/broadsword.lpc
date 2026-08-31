inherit "/std/weapon";
#include <castlewall.h>
int weapon_hit(object atk);
 
create() {
    ::create();
   set_name("Bloodied Broadsword");
   set_short("%^BOLD%^%^RED%^Blo%^RESET%^%^RED%^od%^ORANGE%^ie%^BOLD%^%^RED%^d %^BOLD%^%^WHITE%^Broa%^RESET%^%^CYAN%^dswo%^BOLD%^%^WHITE%^rd%^RESET%^");
   set_id( ({"sword", "broadsword", "bloodied broadsword"}) );
   set_long ("%^RESET%^%^ORANGE%^Dried %^RED%^blood %^BOLD%^%^WHITE%^covers the length of the wide blade. From the many nicks and scars on the metal, it looks like it has seen many battles. Its worn hilt has been wrapped with rough leather that will provide a solid grip in any weather.");
   set_weight(35+random(100));
   set_curr_value("gold", 68+random(25));
   set_wc(9);
   set_ac(2);
   set("skill level", 335);
   set_type("blade");
   set_hit((: weapon_hit :));

   set_wield("%^RESET%^%^ORANGE%^Lea%^BOLD%^%^BLACK%^th%^RESET%^%^ORANGE%^er%^BOLD%^%^WHITE%^ creaks between your fingers as you wield the sword.");
   set_unwield("The impressions of your fingers on the hilt fade quickly as you release the sword.");
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) < 10) {
        write("%^RESET%^%^RED%^Your %^BOLD%^%^RED%^Blo%^RESET%^%^RED%^od%^ORANGE%^ie%^BOLD%^%^RED%^d %^BOLD%^%^WHITE%^Broa%^RESET%^%^CYAN%^dswo%^BOLD%^%^WHITE%^rd%^RESET%^%^RED%^ hacks peices out of "+atk->query_cap_name()+".%^RESET%^");
       tell_room(environment(this_player()), "%^BOLD%^%^WHITE%^"+this_player()->query_cap_name()+
      " beats "+possessive(this_player())+" foe aside with their %^BOLD%^%^RED%^Blo%^RESET%^%^RED%^od%^ORANGE%^ie%^BOLD%^%^RED%^d %^BOLD%^%^WHITE%^Broa%^RESET%^%^CYAN%^dswo%^BOLD%^%^WHITE%^rd%^BOLD%^%^WHITE%^.%^RESET%^", ({ atk, this_player() }));
    tell_object(atk, "%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" Hacks into you with "+this_player()->query_title_gender()+" broadsword.%^RESET%^");
       
result=(random(100))+((this_player()->query_level())*4);

    }
}
int query_auto_load() { if (this_player()->query_level() > 83) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 83) return 0;
   write("You would hurt yourself if you tried this sword out.");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}

