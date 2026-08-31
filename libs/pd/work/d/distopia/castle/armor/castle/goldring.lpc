inherit ARMOUR;

void create() {
    ::create();
    set_name("Gold Ring");
    set_short("%^ORANGE%^gold ring");
    set_long("%^ORANGE%^A ring of gold, it shimmers in the light.");
    set_id( ({ "ring" , "gold ring" }) );
    set_ac(1);
    set_mass(3);
    set_curr_value("gold",50+random(40));
    set_type("ring");
set_limbs ( ({ "left hand", "right hand"}) );
}

int query_auto_load() { if (this_player()->query_level() < 20) return 0;

 return 1;
}
