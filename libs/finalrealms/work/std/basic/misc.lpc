/*
 * Rather large conglomeration of move/misc/values
 * - Allowing negative weights, though we'll regret it.
 * Wonderflug, 1997.
 */

#include "move_failures.h"
#include "money.h"

/* Use a hook to refer to weight all through here, unless modifying. 
 * There's a fairly good reason for this.
 */
#define WEIGHT this_object()->query_weight()

inherit "/std/basic/light";

nosave int weight=0;     /* weight of the object */
nosave int droppable=1;  /* whether the object may be dropped */
nosave int gettable=1;   /* whether the object may be picked up */

int value=0;             /* value of the object */
int resale_value=0;      /* resale value of the object */
int stolen_modifier=0;   /* devaluation when stolen */

/****** Some misc garbage */
nosave object prev;      /* last location visited by the object.. really 
                          * this isn't necessary in EVERY object, should
                          * be in player.c or creator.c
                          */
object query_prev() { return prev; }  /* this too */


/****** Initialization */

void create() 
{
}


/****** Modifiers/accessors for droppable/gettable */

void reset_get() { gettable = 0; }       /* can't be gotten */
void set_get()   { gettable = 1; }       /* can be gotten */
void reset_drop(){ droppable = 0; }      /* can't be dropped */
void set_drop()  { droppable = 1; }      /* can be dropped */  

int droppable() {
     if(TO->query_property("cursed")) return 0;
        return droppable;
}
int gettable()  { return gettable; }


/****** Weight stuff */

void adjust_weight(int w) 
{
  weight += w;

  if (environment())
  {
    environment()->adjust_contained_weight( w );
    environment()->rebalance( ({ this_object() }) );
  }
}

void set_weight(int w) { adjust_weight( w - weight ); }
int query_weight() { return weight; }

int test_adjust_weight( int w )
{
  if ( environment() )
    return environment()->test_adjust_contained_weight( w );
  else
    return 1;
}


/****** Movement stuff */

/* these get re-defined in container.c; the default, however, is that
 * an object may not add or remove objects to itself.
 */
int test_add_object( object ob ) { return MOVE_INVALID_DEST; }
int test_remove_object( object ob ) { return MOVE_INVALID_DEST; }

/* This is the nice, completely error-checking version of move.
 * Expected to be used by builders and elsewhere in mudlib.
 * Return code SHOULD be checked; see move_failures.h
 */
varargs int move(mixed dest, mixed messin, mixed messout) 
{
  int i;

  if (!objectp(dest))
  {
    if ( stringp(dest) )
      catch( dest = load_object(dest) );
    else
      return MOVE_BAD_DEST ;

    if ( !objectp(dest) )
      return MOVE_UNLOADABLE_DEST ;
  }
    
  prev = environment();
  /* dest is now guaranteed to be an object, the destination;
   * prev is now the previous environment
   */

  /* check that no weight constraints will be violated by the move 
   * Note when moving an object into/out of a container to the environment
   * of the container, we must be careful..
   * Also here, gettable/droppable checks are done, hidden in the
   * test_ calls.
   */
  if ( prev )
  {
    if ( dest == environment(prev) )
    {
      /* moving an object out of a container */
 
      if ( (i = prev->test_expell_object(this_object())) != MOVE_OK )
        return i;
    }
    else if ( prev == environment( dest ) )
    {
      /* putting an object from an env into a container in same env  */

      if ( (i = dest->test_swallow_object( this_object() )) != MOVE_OK )
        return i;
    }
    else
    {
      /* moving an object from two unrelated containers */

      if ( (i = prev->test_remove_object( this_object() )) != MOVE_OK )
        return i;

      if ( (i = dest->test_add_object( this_object() )) != MOVE_OK )
        return i;
    }
  }  /* if ( prev ) */
  else
  {
    /* only need check that the destination weight is not exceeded */
    if ( (i=dest->test_add_object( this_object() )) )
      return i;
  }

  /* now perform the actual move */

  if (prev)
  {
    event(prev, "exit", messout, dest);
    prev->adjust_contained_weight(-WEIGHT);
    /* no need to rebalance; if there were, the tests would have failed */
    prev->adjust_light(-query_light());
  }

  move_object(dest);

  event(dest, "enter", messin, prev);

  /* no need for the environment check, really.. */
  if(environment())
  {
    environment()->adjust_contained_weight( WEIGHT );
    /* no need to rebalance; if there were, the tests would have failed */
    environment()->adjust_light(query_light());
  }

  return MOVE_OK;
}

/* This is a mudlib handle; NOT to be used in ANY domain code.  */
void mudlib_move(object dest)
{
  if ( environment() )
  {
    environment()->adjust_contained_weight( -WEIGHT );
    environment()->adjust_light(-query_light());
  }
  move_object(dest);
  if ( environment() )
  {
    environment()->adjust_contained_weight( WEIGHT );
    environment()->adjust_light(query_light());
  }
}

/****** Destruction, cleanup stuff */

void dest_me() 
{
  object* obs;
  object ob;
  int i;

  // Destruct contents of this object
  obs = all_inventory(this_object());
  for(i = 0; i < sizeof(obs); i++)
    if(obs[i]) 
      obs[i]->dest_me();

  // Add weight/light to the environment, if it's there
  if (environment()) 
  {
    environment()->adjust_contained_weight(-WEIGHT);
    environment()->rebalance( ({ }) );
    set_light(0);
    event(environment(), "dest_me");
  }

  // Destruct shadows of this object, Wonderflug 96
  obs = ({ });
  ob = shadow(this_object(), 0);
  while ( ob )
  {
    obs += ({ ob });
    ob = shadow(ob, 0);
  }
  for ( i=0; i<sizeof(obs); i++ )
    if ( obs[i] )
      destruct(obs[i]);

  efun::destruct(this_object());
}

/* Do not I repeat do not mask this function.
 * is used when all else fails to dest the object...
 * If we find you masking this function... We will cut you up
 * into little bits... slowly
 */
nomask mixed dwep() 
{
  efun::destruct(this_object());
  return "Destruct With Extreme Prejuce";
}



/****** Value/money stuff */

varargs int adjust_money(mixed amt, string type) 
{

  if (pointerp(amt)) 
  {
    value += (int)MONEY_HAND->query_total_value(amt);
    if (value < 0)
      value = 0;
    return value;
  }
  amt = (int)MONEY_HAND->query_total_value( ({ type, amt }) );
  value += amt;
  if (value < 0)
    value = 0;
  return value;
}

int adjust_value(int i) { return (value += i); }

mixed* query_money_array() 
{
  return (mixed *)MONEY_HAND->create_money_array(value);
}

int query_money(string type) 
{
  int i;
  mixed* m_a;

  m_a = (mixed *)MONEY_HAND->create_money_array(value); 
  if ((i=member_array(type, m_a)) == -1)
    return 0;
  return m_a[i+1];
}

void set_value(int i) { value = i; }
int query_value() { return value; }


/* resale value functions by Hamlet, August 1995 */
/* These are the price a shop will offer for an object. */

void set_resale_value(int i) { resale_value = i; }
int adjust_resale_value(int i) { return( resale_value += i); }
int query_resale_value()
{
    if(TO->query_property("cursed")) return -1;
     return resale_value;
}

void prevent_resale() {  resale_value = -1;  }
void allow_resale() {  resale_value = 0;  }

/* These are for how much the shop will offer for the item if it has
   been stolen. -- Hamlet
*/

int set_stolen_modifier(int i) {
  if(i > 100)   i = 100;
  if(i < -1)    i = -1;

  stolen_modifier = i;
  return i;
}
int query_stolen_modifier() { return stolen_modifier; }
void no_sell_if_stolen() { stolen_modifier = -1; }


