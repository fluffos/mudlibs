/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: ink.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: ink.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "mind.fluster".
 * <p>
 * Describe the arguments in here.
 * @classification mind.fluster
 * @see help::effects
 */
inherit "/std/effects/basic";
 
/* ink.  ... bit of a dummy effect really */
 
void create() {
   set_boundaries(
      ({ -10, -10 }), ({ 10, -1 }) );
}
 
int backdrop() { return 1; }        /* important due to the messages in drunk */
 
int query_ink() { return 1; }
 
mixed *query_attrs(int *coord)
{
   return ({ 20, 0,
             ({ ({ "black ink", 100 }) }),
             ({ ({ "black", 100 }) }),
             ({ }), /* no smell */
             ({ ({ "ink", 100 }) })
      });
}
 
 
void action_taste(object ob, int *coord, int quantity)
{
   tell_object(ob, "The ink tastes so bad you spit it out immediately.\n");
   tell_room(environment(ob), ob->one_short() + 
      " spits black ink out with a look of distaste.\n");
}
 
void action_drunk(object ob, int *coord, int quantity)
{
   if (quantity < 5) { /* taste amount */
      action_taste(ob, coord, quantity);
      return;
   }
   tell_object(ob, "That ink was really awful.\n");
   tell_object(ob, "You vomit.\n");
   tell_room(environment(ob),
      ob->one_short() + 
      " looks queasy and vomits black ink everywhere.\n", ob);
   ob->adjust_hp(-random(quantity));
   return;
}
