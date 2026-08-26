/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: hp.c,v 1.1 1998/01/06 04:21:18 ceres Exp $
 * $Log: hp.c,v $
 * Revision 1.1  1998/01/06 04:21:18  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "poison.constitution".
 * <p>
 * Describe the arguments in here.
 * @classification poison.constitution
 * @see help::effects
 */
inherit "/std/effects/basic";
 
/* Hit point reducing poison */
 
void create() {
   set_boundaries( ({ 0, -60 }), ({ 30, -20 }) );
}
 
int backdrop() { return 1; }
 
mixed *query_attrs( int *coord ) {
   int total, intens;
   
   total = distance_within_region(coord);
   intens = total * 2;
   if (intens > 100) intens = 100;
   
   return ({ 5, 95, ({ }), ({ ({ "sparkling purple", intens }) }),
      ({ ({ "wax", intens / 2 }) }), 
      ({ ({ "sugar", intens }),
         ({ "wax", intens/2 }) })
   });
}
 
void action_drunk( object ob, int *coord, int quantity ) {
   int total, dam;
   string obmess, roommess;
   
   total = distance_within_region(coord);
   
   dam = ((total * quantity) * 13) / ob->query_con();
   
   switch (dam) {
    case 0..200:
      obmess = "You feel a bit sick.\n";
      roommess = ob->one_short() + " looks a little ill.\n";
      break;
    case 201..300:
      obmess = "You feel a sharp pain, and clench your teeth.\n";
      roommess=ob->one_short() +" clenches "+ob->query_possessive()+" teeth in agony.\n";
      "teeth in agony.\n";
      break;
    case 301..400:   
      obmess = "You feel like someone has punched you visciously in the stomach.\n";
      roommess = ob->one_short() + " nearly collapses.\n";
      break;
    case 401..1000:
      obmess = "You collapse and go very pale.\n";
      roommess = ob->one_short() + " collapses and goes very pale.\n";
      break;
    default:
      obmess = "You reel and collapse with all your health fleeing your body.\n";
      roommess = ob->one_short() + " collapses with a face palid as the "+
      "face death would have if death had a face.\n";
      break;
   }
   
   tell_object(ob, obmess);
   tell_room(environment(ob), roommess, ob);
   ob->adjust_hp(-dam);
   ob->reset_all();
   return;
}

void action_taste( object ob, int *coord, int quantity) {
   if (quantity >= 1) tell_object(ob, "Your tongue feels numb.\n");
}
