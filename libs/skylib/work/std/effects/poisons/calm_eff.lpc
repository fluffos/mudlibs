/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: calm_eff.c,v 1.1 1998/01/06 04:21:18 ceres Exp $
 * $Log: calm_eff.c,v $
 * Revision 1.1  1998/01/06 04:21:18  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "poison.addictive".
 * <p>
 * Describe the arguments in here.
 * @classification poison.addictive
 * @see help::effects
 */
inherit "/std/effects/basic";
#define EFFECT "/std/spells/wizard/failure/calm"
 
/* calming poison.  This is used for the ananconda's */
 
void create() {
   set_boundaries( ({ -40, -20 }), ({ 40, 80 }) );
}

mixed *query_coordinate() { return ({ -30, 60 }); }
 
mixed *query_attrs( int *coord ) {
   int total, intens;
   
   total = distance_within_region(coord);
   intens = total * 3;
   if (intens > 100) intens = 100;
 
   return ({ 5, 95, ({ }), ({ ({ "bright blue", intens }) }),
             ({ }), 
             ({ ({ "tangy", intens }), ({ "slightly tangy", intens/2 }) })
      });
}
 
void action_drunk( object ob, int *coord, int quantity) {
   int total, condam;
   string obmess, roommess;
   
   total = distance_within_region(coord);
   
   condam = total * quantity;

   condam = condam/1000;

   obmess = "You feel really amazingly calm.\n";
   roommess = ob->one_short() + " face looks dreamy.\n"+
              ob->one_short() + " smiles dreamily.\n";
   tell_object(ob, obmess);
   tell_room(environment(ob), roommess, ob);
   ob->add_effect(EFFECT, condam);
   return;
}
 
void action_taste( object ob, int *coord, int quantity) {
   if (quantity >= 1) tell_object(ob, "You feel a sense of calmness sweep "
                                      "over your for a second.\n");
}

int query_anaconda_calmer() { return 1; }
