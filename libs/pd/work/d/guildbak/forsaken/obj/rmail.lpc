inherit ARMOUR;

void create() {
    ::create();
    set_name("platemail");
    set_short("%^BOLD%^%^BLACK%^Raknid %^RESET%^P%^BOLD%^%^BLACK%^lat%^RESET%^e%^BOLD%^%^BLACK%^mail%^RESET%^");
    set_long("This platemail has been forged by the Forsaken to aid their Raknid followers.");
    set_id(({"platemail", "raknid platemail"}));
    set_ac(15);            
    set_mass(60);
    set_curr_value("gold", 500);
    set_type("leggings");
    set_limbs(({"third arm", "torso", "abdomen", "right foreleg", "second arm", "first arm", "fourth arm", "left foreleg", "right rear leg", "left rear leg"}));
}

int query_auto_load() { 
    if(this_player()->query_guild() == "forsaken") return 1;

}
