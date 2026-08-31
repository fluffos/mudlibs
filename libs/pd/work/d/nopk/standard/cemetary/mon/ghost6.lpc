inherit "/std/monster";

create() {
   ::create();
   set_name("descartes");
    set_id( ({ "skeleton","descartes","Descartes","Descartes's Skeleton","ghost" }) );
   set_short("Descartes's Skeleton");
   set("aggressive", 0);

   set_level(1);
   set_long("This is an android skeleton, instead of bone Descartes' skeleton "
     "is made of metal. Metalloid claws make up what should be fingers on the "
     "undead creature's hands.");
   set_alignment(400);
   set("race", "undead");
   set_property("no_corpse", 1);
   set_gender("male");
   set_max_hp(25);
   set_hp(25);
   add_limb("head", "FATAL", 25, 0, 4);
   add_limb("torso", "FATAL", 50, 0, 4);
   add_limb("right arm", "right hand", 20, 0, 4);
   add_limb("right hand", "", 15, 0, 4);
   add_limb("left arm", "left hand", 20, 0, 4);
   add_limb("left hand", "", 15, 0, 4);
   add_limb("right leg", "right foot", 25, 0, 4);
   add_limb("right foot", "", 20, 0, 4);
   add_limb("left leg", "left foot", 25, 0, 4);
   add_limb("left foot", "", 20, 0, 4);
   set_die( "The ghost %^RED%^dissapates%^RESET%^ before you." );
}

void catch_tell(string str) {
    object ob;
    string a, b;

    if(sscanf(str, "%s gives %s to you", a, b) == 2) {
	ob = present( lower_case(a), environment(this_object()));
	if(ob) {
	    tell_object(ob, "The ghost thanks you for your generosity.\n");
	    tell_room(environment(this_object()), "The ghost thanks "+a+" for "+ob->query_possessive()+" generosity.\n", ({this_object(), ob}));
	}
    }
    if(sscanf(str, "%ssmiles%s", a, b) == 2) tell_room(environment(this_object()), " Descartes, the metal skeleton, makes muffled meeping sounds.\n", ({this_object()}));
}
