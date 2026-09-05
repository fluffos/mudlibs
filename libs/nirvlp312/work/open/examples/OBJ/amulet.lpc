/*
File: amulet.c
By: Feldegast @ Nirvana
Updated: 12-31-00
Description:
  A weak amulet sold in the coliseum's armor shop,
  with some magical resistance to fire and poison damage.
*/
#include "/players/feldegast/closed/ansi.h"

inherit "obj/armor";

reset(arg) {
  /* This sets up the function do_special for physical damage, by default. */
  ::reset(arg);

  /* This is necessary to avoid setting the amulet's stats more than once. */
  if(arg) return; 

  /* Set up the armor's physical properties. */
  set_name("amulet");
  set_alias("crystal");
  set_short("A crystal amulet");
  set_long(
    "This is a delicate crystal amulet with a silver chain.\n"
  );
  set_weight(1);
  set_value(15);

  /* No ac for physical damage. */
  set_ac(0);

  /* 1% resistance to physical damage. */
  set_res(1);

  set_type("amulet");  /* armor,helmet,boots,ring,amulet,shield,misc  */

  /*
    This line sets up an ac to fire of 1, a resistance to fire of 2%,
    and a special function called fire_special. 
  */
  set_params("other|fire",1,2,"fire_special");

  /* You can call this function again to set up multiple resistances. */
  set_params("other|poison",0,0,"poison_special");

} /* End of reset */

/*
This function is called when the owner receives damage from a physical
based attack.  The return amount is added to the player's ac.
Don't forget, this_player() is the person doing the attacking.
*/

do_special(owner) {
  if(!random(12)) {
    tell_object(owner, "Your crystal amulet glows protectively.\n");
    if(this_player() && this_player()!=owner)
      write(owner->query_name()+"'s crystal amulet glows protectively.\n");
    return 2;
  }
}

/*
This function is called when the owner receives damage from a fire
based attack.  The return amount is added to the player's ac.
*/
fire_special(owner) {
  if(!random(5)) {
    tell_object(owner, "Your crystal amulet glows intensely!\n");
    return 4;
  }
  if(!random(20)) {
    tell_object(owner, HIW+"Your crystal amulet glows as it protects you from the heat.\n"+NORM);
    return 1000; /* This is 10% resistance.  Not 1000 ac! */
  }
  if(!random(20)) {
    tell_object(owner, HIR+"Your crystal amulet glows as it protects you from the heat.\n"+NORM);
    return 1001; /* This is 10% resistance and a bonus ac of 1. */
  }

  /* This is how to do damage in an armor special.  Be sure to include all of these checks! */
  if(!random(80) &&
     this_player() &&                     /* Make sure there is somebody to hit! */
     this_player()!=owner &&              /* So the owner doesn't hit himself. */
     this_player()->query_hp() > 10) {    /* So the attacker doesn't kill himself. */
    tell_object(owner, "Some of the damage is deflected back at "+
                       this_player()->query_name()+" by your crystal amulet!\n");
    write("Part of your attack is deflected back at you!\n");
    this_player()->hit_player(10);
    return 0;
  }    
}

/*
  This is the poison special we set up in reset with set_params.
*/
poison_special(owner) {
  if(!random(5)) {
    tell_object(owner, "Your crystal amulet glows green.\n");
    return 2;
  }
}

