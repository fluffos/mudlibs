inherit "/std/monster";

void create() {
  ::create();
    set_name("shadowwolf's ghost");
    set_id( ({ "ghost","shadowwolf","Shadowwolf","Shadowwolf's Ghost" }) );
    set_short( "Shadowwolf's ghost");
    set_aggressive( 0);
    set_level(1);
    set_long( "The ghost is a pale wraithe, holding a NI clutched "
	"tightly to his chest.");
    set_alignment(100);
    set_race( "undead");
    set_gender("male");
    set_max_hp(25);
    set_hp(5);
    set_body_type("human");
    remove_limb("left foot");
    remove_limb("right hand");
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
    if(sscanf(str, "%stickle%s", a, b) == 2) tell_room(environment(this_object()), "The ghost says: It's only a flesh wound!!", ({this_object()}));
}
