inherit "/std/weapon";
 
create() {
    ::create();
   set_id( ({ " %^ORANGE%^A S%^BOLD%^%^BLACK%^cyt%^RESET%^%^ORANGE%^he%^RESET%^", "scythe", "a scythe"}) );
   set_name("
%^ORANGE%^A S%^BOLD%^%^BLACK%^cyt%^RESET%^%^ORANGE%^he%^RESET%^");
   set_short("
%^ORANGE%^A S%^BOLD%^%^BLACK%^cyt%^RESET%^%^ORANGE%^he%^RESET%^");
   set("long", "    ");
   set_weight(20);
   set_curr_value("gold", 1115000);
   set_wc(25);
   set_ac(2);
   set("skill level", 1);
   add_poisoning(35);
   set_type("knife");
     set_hit((: this_object(), "weapon_hit" :));

 set_wield("You fee like a pimp as you wield this weapon.");
   set_unwield("Your weapon Pimp-slaps you and runs off with your bitch.");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 30) {
        write("You yell, Whers my money Bitch!");
        say(""+(string)this_player()->query_cap_name()+"'s crotch tents as he pimp slaps "+atk->query_cap_name()+".");
       
result= (random(90)+25);
this_player()->add_hp(result);
       if(random(100)> 10) { 
          query_wielded()->query_current_attacker()->set_paralyzed(5);}

    }
}
int query_auto_load() { if (this_player()->query_level() > 50) return 1; }
