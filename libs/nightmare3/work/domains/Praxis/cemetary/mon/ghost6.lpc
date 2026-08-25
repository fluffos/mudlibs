inherit "/std/monster";

create() {
   ::create();
   set_name("descartes's ghost");
    set_id( ({ "ghost","descartes","Descartes","Descartes's Ghost" }) );
   set_short("Descartes's ghost");
   set_aggressive( 0);
   /*
   set_speed(9);
   set_moving(1);
     */

   set_level(1);
  set_long("This is an android ghost, rusted immobile by a sudden, unexpected mud-rain.\n");
   set_alignment(400);
   set_race( "undead");
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
}

void catch_tell(string str) {
    object ob;
    string a, b, c;

    if(sscanf(str, "%s gives %s to you", a, b) == 2) {
	ob = present( lower_case(a), environment(this_object()));
	if(ob) {
	    tell_object(ob, "The ghost thanks you for your generosity.\n");
	    tell_room(environment(this_object()), "The ghost thanks "+a+" for "+ob->query_possessive()+" generosity.\n", ({this_object(), ob}));
	}
    }
    if(sscanf(str, "%ssmiles%s", a, b) == 2) tell_room(environment(this_object()), " Descartes, the immobile ghost, makes muffled meeping sounds.\n", ({this_object()}));
}
