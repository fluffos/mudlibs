inherit "/std/monster";

void create() {
  ::create();
    set_name("shadowwolf");
    set_id( ({ "ghost","shadowwolf","Shadowwolf","Shadowwolf's Ghost" }) );
    set("short", "The wraith form of Shadowwolf");
    set("aggressive", 0);
    set_level(1);
    set("long", "The wraith takes the form of a midnight blue misty werewolf. "
      "His eyes a deep, blood red, he is always hungry for blood and waits to "
      "take his next victim.");
    set_alignment(-100);
    set("race", "undead");
   set_property("no_corpse", 1);
    set_gender("male");
    set_max_hp(25);
    set_hp(5);
    set_body_type("human");
    remove_limb("left foot");
    remove_limb("right hand");
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
    if(sscanf(str, "%stickle%s", a, b) == 2) tell_room(environment(this_object()), "The ghost says: It's only a flesh wound!!", ({this_object()}));
}
