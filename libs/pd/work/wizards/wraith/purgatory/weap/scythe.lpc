
inherit "/std/weapon";
 
create() {
    ::create();
   set_id( ({"%^ORANGE%^A S%^BOLD%^%^BLACK%^cyt%^RESET%^%^ORANGE%^he%^RESET%^", "scythe", "%^ORANGE%^A S%^BOLD%^%^BLACK%^cyt%^RESET%^%^ORANGE%^he%^RESET%^"}) );
   set_name("%^ORANGE%^A S%^BOLD%^%^BLACK%^cyt%^RESET%^%^ORANGE%^he%^RESET%^");
   set_short(" %^ORANGE%^A S%^BOLD%^%^BLACK%^cyt%^RESET%^%^ORANGE%^he%^RESET%^");
   set_long ("%^ORANGE%^A S%^BOLD%^%^BLACK%^cyt%^RESET%^%^ORANGE%^he%^RESET%^");
   set_weight(20);
   set_curr_value("gold", 1115000);
   set_wc(15);
   set_ac(2);
   set("skill level", 1);
   add_poisoning(35);
   set_type("knife");
     set_hit((: this_object(), "weapon_hit" :));

 set_wield("%^ORANGE%^A wave of pure %^RED%^e%^BOLD%^%^RED%^vi%^RESET%^%^RED%^l %^ORANGE%^spills forth as you wield this S%^BOLD%^%^BLACK%^cyt%^RESET%^%^ORANGE%^he%^RESET%^");
   set_unwield("%^ORANGE%^The sense of %^RED%^e%^BOLD%^%^RED%^vi%^RESET%^%^RED%^l %^ORANGE%^ receeds back into the depths.");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^BLACK%^Your eyes sparkle as the %^RESET%^ORANGE%^S%^BOLD%^%^BLACK%^cyt%^RESET%^%^ORANGE%^he%^RESET%^%^BOLD%^%^BLACK%^ hacks at your opponent.");
        say(""+(string)this_player()->query_cap_name()+"%^BOLD%^%^BLACK%^'s %^BOLD%^%^RED%^e%^RESET%^%^RED%^y%^BOLD%^%^RED%^e%^RESET%^%^RED%^s%^RESET%^%^BOLD%^%^BLACK%^ twinkle with %^RED%^e%^BOLD%^%^RED%^vi%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^ as he hacks away at "+atk->query_cap_name()+".");
       
result= (random(390)+25);
       if(random(100)> 10) { 
          query_wielded()->query_current_attacker()->set_paralyzed(5);}

    }
}
int query_auto_load() { if (this_player()->query_level() > 90) return 1; }
