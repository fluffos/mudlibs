inherit "/std/monster";

void create() {
  ::create();
    set_name("darkone's ghost");
    set_id( ({ "ghost","darkone","Darkone","Darkone's Ghost" }) );
    set_short( "Darkone, the ghost with a bent neck");
    set_aggressive( 0);
    set_level(1);
    set_long( "This is Darkone's evil ghost.  He is smiling so "
	"evilly that huge black horns have sprouted on his head. "
	"He is deeply grieved he can no longer torture wizards "
	"by nit-picking in their castles.");
    set_alignment(-600);
    set_race( "undead");
    set_gender("neuter");
    set_max_hp(25);
    set_money("gold",25);
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
    if(sscanf(str, "%ssmiles%s", a, b) == 2) 
      tell_room(environment(this_object()), "Darkone's ghost "
		"groans loudly: Aooooooooooooo...*gerk*  (The howl "
		"cuts off abruptly.)", ({this_object()}));
}
