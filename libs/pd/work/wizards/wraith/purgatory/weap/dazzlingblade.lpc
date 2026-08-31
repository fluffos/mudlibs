inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("%^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^l%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^d%^BOLD%^%^BLUE%^e%^RESET%^");
   set_name("%^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^l%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^d%^BOLD%^%^BLUE%^e%^RESET%^");
   set_id( ({"sword", "blade"}) );
   set_long ("%^BOLD%^%^CYAN%^This blade was forged with the help of the famed Blue and %^BOLD%^%^RED%^Red%^BOLD%^%^CYAN%^ Dragons."
             "%^BOLD%^%^BLUE%^  \nTwined spiderwebs and moonbeams make this blade"
             "%^BOLD%^%^BLUE%^ flexible but strong, with a bit of night spice added in for protection.");
   set_weight(98);
   set_curr_value("gold", 121);
   set_wc(9);
   set_ac(2);
   set("skill level", 125);
   set_type("blade");
   set_hit((: this_object(), "weapon_hit" :));

   set_wield("%^BOLD%^%^CYAN%^The %^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^l%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^d%^BOLD%^%^BLUE%^e%^RESET%^%^BOLD%^%^CYAN%^ sticks to your palm with the spider webs.%^RESET%^");
   set_unwield("%^BOLD%^%^BLUE%^You peel the %^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^l%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^d%^BOLD%^%^BLUE%^e from your hand.%^RESET%^");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^CYAN%^Your %^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^l%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^d%^BOLD%^%^BLUE%^e%^RESET%^%^BOLD%^%^CYAN%^ slices through %^RESET%^"+atk->query_cap_name()+"%^RESET%^ %^BOLD%^%^CYAN%^with ease.%^RESET%^");
        say("%^BOLD%^%^BLUE%^"+(string)this_player()->query_cap_name()+"'s %^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^l%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^d%^BOLD%^%^BLUE%^e%^RESET%^%^BOLD%^%^BLUE%^ slices through %^RESET%^"+atk->query_cap_name()+"%^RESET%^%^BOLD%^%^BLUE%^ with ease.%^RESET%^");
       
result= (random(90)+35)+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 55) return 1; }
