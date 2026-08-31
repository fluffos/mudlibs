inherit "/std/monster";

void create() {
  ::create();
    set_name("darkone");
    set_id( ({ "ghost","darkone","Darkone","Darkone's Ghost" }) );
    set("short", "The ghost of Darkone");
    set("aggressive", 0);
    set_level(1);
    set("long", "This is the evil ghost of Darkone. A horribly wicked "
	"grin crosses his face. Blood trickles down from his forehead where "
        "two black thorns have torn through his skin. His eyes reflect an eternity "
        "of pain.");
    set_alignment(-600);
    set("race", "undead");
   set_property("no_corpse", 1);
    set_gender("neuter");
    set_max_hp(25);
    set_money("gold",25);
    set_hp(25);
    set_body_type("human");
   set_die( "The ghost %^RED%^dissapates%^RESET%^ before you." );
}

void catch_tell(string str) {
    object ob;
    string a, b;

    if(sscanf(str, "%s gives %s to you", a, b) == 2) {
	ob = present( lower_case(a), environment(this_object()));
	if(ob) {
	    tell_object(ob, "The ghost laughs at you for your generosity.");
	    tell_room(environment(this_object()), "The ghost laughs at "+a+" for "+ob->query_possessive()+" generosity.", ({this_object(), ob}));
	}
    }
    if(sscanf(str, "%ssmiles%s", a, b) == 2) 
      tell_room(environment(this_object()), "Darkone's ghost "
		"groans loudly: Aooooooooooooo...*gerk*  (The howl "
		"cuts off abruptly.)", ({this_object()}));
}
