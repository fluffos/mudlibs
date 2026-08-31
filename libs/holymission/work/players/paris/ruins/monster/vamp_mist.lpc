#pragma strict-types

inherit "/obj/monster";
int solid;

/*
 * Vampiric mist, basically a draining monster, has a chance of enveloping 
 * a player and then every attack does some drain - nasty huh.
 * If the mist gets healed then it becomes slightly solid - else you can only
 * damage it through magical means 
 */

void reset(int arg) {
  ::reset(arg);
  if (arg) 
    return;
  set_race("mist");
  set_name("vampiric mist");
  set_long(@@_long@@);
  set_gender(0);
  set_level(50);
  set_wc(50);
  set_ac(12);
  set_al(-500);
  set_dead_ob(this_object());
  set_chance(50);
  set_hp(50000);
  set_walk_chance(5);
  set_walk_limit("/players/paris/waste");
  set_no_steal();
  set_no_ears();
  set_prevent_poison(1);
  set_smell("The mist reeks of old, stale blood.");
  set_aggressive(1);
}

void init() {
  ::init();
  // if someone enters we stop moving
  kill_walking();
}

int monster_died() {
  say("As the final blow is dealt, the mist slowly fades away.\n");
  return 0;
}

varargs mixed hit_player(int dam, int type, mixed elem) {
  /*
   * the purpose of this is when we hit max_hp, we become solid
   * for 'solid' attacks. 
   *
   * we only take damage from either spells, magic attacks, or when solid
   */
  if ((this_object()->query_hp() == max_hp) && !solid) {
    // lets become solid
    solid=(20+random(10));
    tell_room(environment(this_object()),
	      "The mist seems to become more substantial.\n");
  }
  if (type == 5 || solid || type == 7) {
    // we can only be harmed in three stages.
    //       From 'magic' attacks
    //       When solid
    //       From 'other' attacks
    if(solid) 
      solid--;
    tell_room(environment(this_object()),
	      "The mist drips blood on the ground as it is hit.\n");
  } else {
    // we're not affected
    tell_room(environment(this_object()), 
	      "The vampiric mist seems unaffected by your attack.\n");
    dam = 1;
  }
  // call hit_player
  return ::hit_player(dam, type, elem);
}

int attack() {
  /*
   * now we attack
   */
  if(::attack()) {
    if (!random(3)) {
      say("The mist seems to reach out and grasp "+
	  attacker_ob->query_name()+" in it's tendrils.\n", 
	  attacker_ob);
      tell_object(attacker_ob, 
		  "The mist reaches out and grasps you in it's tendrils.\n");
      attacker_ob->hit_player(random(attacker_ob->query_hp()/40));
    }    
    if (!random(2))
      ::attack();
    if (!random(3))
      ::attack();
    if (!random(4))
      ::attack();
    if (!random(5))
      ::attack();
    if (!random(6))
      ::attack();
  }
}

void _long() {
  return "This large %s cloud, billowing gently before you glows with a "+
    "menacing %s glow.\n",
    (solid) ? "slightly substantial" : "gaseous",
    (max_hp != this_object()->query_hp()) ? 
    "pale pink": 
    "crimson red";
}

