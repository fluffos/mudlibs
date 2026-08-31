inherit "/std/weapon";

create() {
    ::create();
   set_short("Blade of the Gods");
   set_name("BLade of the Gods");
   set_id( ({"blade", "sword"}) );
   set_long ("Forged in a small smithy by an aging weapons smith, this blade glows with an inner light that could only be put in the metal by the hand of a God.");
   set_weight(90);
   set_curr_value("gold", 121);
   set_wc(8);
   set_ac(2);
   set("skill level", 200);
   set_type("blade");
   set_hit((: this_object(), "weapon_hit" :));

}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^WHITE%^A peircing white light emerges from the blade to strick your opponent.%^RESET%^");
        say("%^BOLD%^%^WHITE%^"+(string)this_player()->query_cap_name()+"'s blade shoots a white bolt into "+atk->query_cap_name()+".");
       
result= (random(90)+35)+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 49) return 1; }
