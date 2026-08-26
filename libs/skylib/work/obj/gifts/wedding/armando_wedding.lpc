/*
* Wedding gift for Armando
*/


inherit CLOTHING_OBJ;

void setup(){
        set_name("shirt");
        set_short("wolfhead shirt");
        add_adjective( ({"wolfhead", "wolf" }) );
        add_property("nosteal");
        add_property("dead usable");

        set_long("This shirt is exquisitely tailored, from only the finest "
            "materials.  An ice blue in colour, the front of the shirt is "
            "filled with an extremely lifelike wolf head.  The detail is "
            "quite amazing, it seems that one can see the steamy breath "
            "coming from the raised muzzle, and the teeth are an ivory so "
            "pure it seems hardly possible.  The back of the shirt depicts "
            "a snowy scene, with a pack of wolves chasing a small animal "
            "across a snowy tundra with only a sprinkling of trees.\n");

        set_type("shirt");
        setup_clothing(5000);
        set_damage_chance(0);

} /* setup() */

void init(){
        if( ENV(TO)->query_name() == "armando" ){
                TO->reset_drop();
        }
} /* init() */
