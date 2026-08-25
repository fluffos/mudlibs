inherit "/std/armour";

void create() {
    ::create();
    set_name("helm");
    set_id( ({ "helm", "helmet", "knight's helm" }) );
    set_short( "Knight's helm");
    set_long( "The helm of a knight of justice.");
    set_mass(375);    set_value( 95);

    set_type("helmet");
    set_limbs( ({ "head" }) );
    set_ac(3);
    set_wear( (: this_object(), "extra_worn" :) );
}

int extra_worn() {
    if((int)this_player()->query_alignment() < 200) {
	write("This helmet burns with disgust.");
	say(this_player()->query_cap_name()+" is burned trying to wear the knight's helm.");
	return 0;
    }
    write("You feel the the powers of goodness flowing through you.");
    say(this_player()->query_cap_name() + " shines with the powers of goodness of the knight's helm.");
    return 1;
}
