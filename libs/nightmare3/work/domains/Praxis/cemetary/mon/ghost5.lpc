inherit "/std/monster";

void create() {
  ::create();
    set_name("forlock's ghost");
    set_id( ({ "ghost","forlock","Forlock","Forlock's Ghost" }) );
    set_short( "Forlock's ghost");
    set_aggressive( 0);
    set_level(1);
    set_long( "This is Forlock's sad ghost, lost, and bereft "
	"of mortal companions.");
    set_alignment(200);
    set_race( "undead");
    set_gender("male");
    set_max_hp(25);
    set_hp(25);
    set_body_type("human");
}

void catch_tell(string str) {
    object ob;
    string a, b, c;

    if(sscanf(str, "%s gives %s to you", a, b) == 2) {
	ob = present( lower_case(a), environment(this_object()));
	if(ob) {
	    tell_object(ob, "The ghost thanks you for your generosity.");
	    tell_room(environment(this_object()), "The ghost thanks "+a+" for "+ob->query_possessive()+" generosity.", ({this_object(), ob}));
	}
    }
    if(sscanf(str, "%ssmiles%s", a, b) == 2) tell_room(environment(this_object()), "Forlock's ghost grimaces, and asks you if you've seen his mud.", ({this_object()}));
}
