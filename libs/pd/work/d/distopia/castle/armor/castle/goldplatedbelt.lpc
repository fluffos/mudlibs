
inherit ARMOUR;

void create() 
{
    ::create();
    set_name("gold plated belt");
    set_short("%^ORANGE%^a gold plated belt");
    set_long("%^ORANGE%^This belt is made out of pure gold! It's really heavy but offers decent protection");
    set_id( ({ "belt" , "gold belt" }) );
	set_ac(2);
    set_mass(35);
    set_curr_value("gold",50+random(40));
    set_type("belt");
    set_limbs( ({ "torso"}) );
}

int query_auto_load() { if (this_player()->query_level() < 20) return 0;

 return 1;
}
