/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: alcohol.c,v 1.1 1998/01/06 04:21:18 ceres Exp $
 * $Log: alcohol.c,v $
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

/* It's alcohol. It gets you drunk. */

void create(){
   set_boundaries(
      ({ -7, 2 }), ({ -2, 5 }) );
}

int query_pass_through(int *coord){
   return 40;
}

int *query_coordinate(){
   return ({ -4, 3 });
}

void action_drunk( object ob, int *coord, int quantity ) {
   int total, effect;
   string desc;
   int old_vol;
   
   total = distance_within_region(coord) * 100 / 6;
   
   effect = (400 + random(300)) * total * quantity / 100 / 100;
   old_vol = ob->query_volume(0);
   ob->adjust_volume(0,effect);

   switch (effect) {
   case 0..100:
      desc = "ever so slightly dizzy";
      break;
   case 101..200:
      desc = "slightly dizzy";
      break;
   case 201..300:
      desc = "noticeably drunk";
      break;
   case 301..400:
      desc = "significantly drunk";
      break;
   case 401..600:
      desc = "very drunk";
      break;
   case 601..800:
      desc = "a great deal drunk";
      break;
   default:
/* this effect is not intended to effect > 800 drunk points */
      desc = "so drunk your brain has turned to coffee";
      break;
   }
   tell_object(ob, "You feel " + desc + ".\n");
}

void action_smell( object ob, int *coord, int quantity ) {
   tell_object(ob, "Your nose tingles pleasantly.\n");
}
