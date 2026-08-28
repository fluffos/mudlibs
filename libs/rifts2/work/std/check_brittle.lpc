/*

 * Small file that checks for brittleness of a weapon in a spell.

 * The spell should contian the following AFTER the spell is completed, 

 * but BEFORE any actual enchantments are added.

 *

 * if(!check_brittle(object weap, object caster, int brittle)) {

 *   remove();

 *   return;

 * }

 *

 * weap refers to the weapon receiveing the check.

 * brittle is the amount of 'brittle points' to be added.

 * caster is the caster of the spell (or user of skill).

 * The weapon will automatically be shattered, a message sent to

 * the player, and a 0 returned if the check is unsuccessful, 

 * otherwise, a 1 is returned.

 * NOTE: Armours are not currently supported, though if you add

 * the above code to an armour enchantment, no errors will occur.

 * In fact, this would not be such a bad idea in case we implement

 * armour brittleness in the future.

 *

 * Diewarzau 7/17/96

 * DarkeLIB 1.0

 */



int check_brittle(object weap, object from, int brittle);



int check_brittle(object weap, object from, int brit) {

  int old;



  if(!weap || !weap->is_weapon()) return 1;

  old = (int)weap->prop("brittle");

  if(old < 30) {

    old += brit;

    weap->set_property("brittle", old);

    return 1;

  }

  if(random(100) < (old-5)) {

    message("info",

	    "%^RED%^%^BOLD%^"+capitalize((string)weap->query_short())+

	    " shatters from all the magic energy inside it!",

	    from);

    message("info",

	    (string)from->query_cap_name()+ " curses as "+

	    capitalize((string)weap->query_short())+

	    " shatters into several tiny pieces!",

	    environment(from), ({ from }));

    weap->remove();

    return 0;

  }

  old += brit;

  weap->set_property("brittle", old);

  return 1;

}















