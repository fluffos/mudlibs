inherit "/std/monster";

void create() {
  ::create();
    set_name("flamme");
    set_id( ({ "ghost","flamme","Flamme","Flamme's Ghost" }) );
    set("short", "Flamme's ghost");
    set("aggressive", 0);
    set_level(1);
    set("long", "Long, auburn hair flows down Flamme's back. Her eyes glow "
      "bright red. Her skin is fine and she is beautiful. Flamme's ghost has "
      "long, sharp, black nails. She wears white lipstick and has two white pinpoints "
      "in the center of the red glare that are her eyes.");
    set_alignment(600);
    set("race", "undead");
   set_property("no_corpse", 1);
    set_gender("female");
    set_max_hp(25);
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
	    tell_object(ob, "The ghost thanks you for your generosity.");
	    tell_room(environment(this_object()), "The ghost thanks "+a+" for "+ob->query_possessive()+" generosity.", ({this_object(), ob}));
	}
    }
    if(sscanf(str, "%ssmiles%s", a, b) == 2) tell_room(environment(this_object()), "The little ghost asks: What happened to me?", ({this_object()}));
}
