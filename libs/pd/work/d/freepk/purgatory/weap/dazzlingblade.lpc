#include <std.h>
#include <purgatory.h>
inherit WEAPON;
int weapon_hit(object atk);
 
create() {
    ::create();
   set_short("%^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^l%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^d%^BOLD%^%^BLUE%^e%^RESET%^");
   set_name("%^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^l%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^d%^BOLD%^%^BLUE%^e%^RESET%^");
   set_id( ({"sword", "blade"}) );
   set_long ("%^BOLD%^%^CYAN%^This blade was forged with the help of the famed Blue and %^BOLD%^%^RED%^Red%^BOLD%^%^CYAN%^ Dragons."
             "%^BOLD%^%^BLUE%^  \nTwined spiderwebs and moonbeams make this blade"
             "%^BOLD%^%^BLUE%^ flexible but strong, with a bit of night spice added in for protection.");
   set_weight(18);
   set_curr_value("gold", 121);
   set_wc(11);
   set_ac(2);
   set("skill level", 200);
   set_type("blade");
   set_hit((: weapon_hit :));
   set_decay_rate(2000);
   set_wield("%^BOLD%^%^CYAN%^The %^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^l%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^d%^BOLD%^%^BLUE%^e%^RESET%^%^BOLD%^%^CYAN%^ sticks to your palm with the spider webs.%^RESET%^");
   set_unwield("%^BOLD%^%^BLUE%^You peel the %^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^l%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^d%^BOLD%^%^BLUE%^e from your hand.%^RESET%^");
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) < 10) {
        write("%^BOLD%^%^CYAN%^Your %^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^l%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^d%^BOLD%^%^BLUE%^e%^RESET%^%^BOLD%^%^CYAN%^ slices through %^RESET%^"+atk->query_cap_name()+"%^RESET%^ %^BOLD%^%^CYAN%^with ease.%^RESET%^");
        say("%^BOLD%^%^BLUE%^"+(string)this_player()->query_cap_name()+"'s %^BOLD%^%^BLUE%^Da%^BOLD%^%^CYAN%^z%^RESET%^%^WHITE%^zl%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^BOLD%^%^BLUE%^B%^BOLD%^%^CYAN%^l%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^d%^BOLD%^%^BLUE%^e%^RESET%^%^BOLD%^%^BLUE%^ slices through %^RESET%^"+atk->query_cap_name()+"%^RESET%^%^BOLD%^%^BLUE%^ with ease.%^RESET%^");
       
result= (random(65))+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 55) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 55) return 0;
   write("You are not yet big enough for this sword, try it later when you grow up.");
   say(this_player()->query_cap_name()+" almost beheads themselves with a sword they cannot wield.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
