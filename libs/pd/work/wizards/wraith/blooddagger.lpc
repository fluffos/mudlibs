inherit "/std/weapon";

create() {
    ::create();
   set_short("%^BOLD%^%^RED%^B%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^od%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^e%^BOLD%^%^RED%^d Dagger%^RESET%^");
   set_name("%^BOLD%^%^RED%^B%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^od%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^e%^BOLD%^%^RED%^d Dagger%^RESET%^");
   set_id( ({"dagger"}) );
   set_long ("This dagger has been bloodied from being thrust into too many players.");
   set_weight(20);
   set_curr_value("gold", 0);
   set_wc(10);
   set_ac(1);
   set("skill level", 150);
   set_type("knife");
   set_hit((: this_object(), "weapon_hit" :));

   set_wield("A %^BOLD%^%^RED%^Mu%^RESET%^%^RED%^der%^BOLD%^%^BLACK%^ous %^RESET%^ feeling washes over you.");
   set_unwield("%^BOLD%^%^CYAN%^You suddenly feel sleepy as you release the dagger.%^RESET%^");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^RED%^The Dagger wails as it cuts into flesh again.");
        say("%^RESET%^%^RED%^"+(string)this_player()->query_cap_name()+"'s daggers releases a mournful wail as it peirces "+atk->query_cap_name()+".");
       
result=(random(100)+40)+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 999) return 1; }
