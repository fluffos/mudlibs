/*
* Wedding present for Nuana
*/


inherit CLOTHING_OBJ;

void setup(){
        set_name("necklace");
        set_short("beautiful silver necklace");
        add_adjective( ({ "beautiful", "silver" }) );
        add_property("nosteal");

        set_long("This is a beautiful and very ornate silver necklace.  It has "
            "been made from a number of very fine links joined together into "
            "three chains, braided together.  The necklace is held together "
            "by a golden clasp, and has a moonstone set in the middle.  Each "
            "of the individual links has been hand crafted, and on closer "
            "inspection it seems that they have had \"Love\" or \"Respect\" "
            "carved into them.\n");

        set_type("necklace");
        set_weight(0);
        set_value(0);
        setup_clothing(5000);
        set_damage_chance(0);
        add_extra_look(TO);

} /* setup() */

string extra_look() {
        if(ENV(TO)->query_name() != "nuana" ){
return "Please return this necklace to Nuana.\n";
        }
} /* extra_look() */

