inherit "/std/monster";

void create() {
  ::create();
    set_name("flamme's ghost");
    set_id( ({ "ghost","flamme","Flamme","Flamme's Ghost" }) );
    set_short( "Flamme's ghost");
    set_aggressive( 0);
    set_level(1);
    set_long( "The ghost still has a few tufts of auburn hair "
	"sticking out in all directions. She is smiling, but "
	"with a rather surprised look on her face.");
    set_alignment(600);
    set_race( "undead");
    set_gender("female");
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
    if(sscanf(str, "%ssmiles%s", a, b) == 2) tell_room(environment(this_object()), "The little ghost asks: What happened to me?", ({this_object()}));
}
