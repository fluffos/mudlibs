/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: weak_hp.c,v 1.1 1998/01/06 04:13:03 ceres Exp $
 * $Log: weak_hp.c,v $
 * Revision 1.1  1998/01/06 04:13:03  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "fighting.warcry".
 * <p>
 * Describe the arguments in here.
 * @classification fighting.warcry
 * @see help::effects
 */
inherit "/std/effects/basic";
/* ok, weakest healing potion */

/*
 * NB: This potion is intended to cure 20-100 hps for 'standard' coordinate
 *     and standard dose (100ml)
 */

void create() {
   set_boundaries( ({ 5, 5 }), ({ 30, 30 }) );
}

mixed *query_attrs(int *coord) {
   int total;
   total = coord[0] + coord[1];
   
   return ({ 0, 100, 
/* NAME */ ({ }),
/* COLS */ ({ ({ "light blue", total }) }),
/* SMEL */ ({ ({ "mint", total }), ({ "toothpaste", total / 2 }) }),
/* FLAV */ ({ ({ "mint", total }), ({ "toothpaste", total / 2 }) })
   });
}

void action_drunk(object ob, int *coord, int quantity){
   int total, heal;
   string desc;
   int old_hp;
   
   total = coord[0] + coord[1];
   
   heal = (20 + random(80)) * total * quantity / (30 * 100);
   old_hp = ob->query_hp();
   heal = ob->adjust_hp(heal) - old_hp;

   switch (heal) {
   case 0..35:
      desc = "ever so slightly less damaged";
      break;
   case 36..70:
      desc = "slightly less damaged";
      break;
   case 71..105:
      desc = "a touch more whole";
      break;
   case 106..140:
      desc = "ever so slightly better";
      break;
   case 141..175:
      desc = "a bit better";
      break;
   case 176..210:
      desc = "better";
      break;
   default:
/* this effect is not intended to heal > 250 hp */
      desc = "much better";
      break;
   }
   tell_object(ob, "You feel " + desc + ".\n");
}

void action_smell(object ob, int *coord, int quantity) {
   tell_object(ob, "Your nose tingles pleasantly.\n");
}
