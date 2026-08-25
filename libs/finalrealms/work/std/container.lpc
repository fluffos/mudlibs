/*
 * Wonderflug, 1997.
 * - Fixed weight once and for all.  We have the invariant that
 *   contents_weight is ALWAYS correct, so we need not recalculate it
 *   constantly, we only need update it constantly.  Also, max_weight
 *   may never be negative.
 */

#include "move_failures.h"

inherit "std/object";
inherit "std/basic/cute_look";

int max_weight;              /* maximum allowable weight, 0 = no limit */
nosave int contents_weight;  /* current contained weight */

void create() 
{
  max_weight = 0;
  contents_weight = 0;
  object::create();
} /* create() */

int query_max_weight() { return max_weight; }
int query_contents_weight() { return contents_weight; }
int query_empty_weight() { return ::query_weight(); }
int query_weight() 
{ 
  return contents_weight + ::query_weight();
}


/****** The following functions may, in effect, have force_ preceding their
 ****** names.  They adjust things no matter what, and then remove any
 ****** inconsistencies afterward.
 ******/

void set_max_weight( int newmax ) 
{ 
  if ( newmax < 0 )
    newmax = 1;
  else
    max_weight = newmax; 
  this_object()->rebalance( ({ }) );
}

void adjust_max_weight( int amount )
{
  /* if it's adjusting, and hitting 0, we have it be 1, in fact, since
   * 0 is a reserved value for max_weight.  It's not likely someone is
   * setting the object to have unlimited weight by using adjust_max_weight
   */
  if ( max_weight + amount == 0 )
    return set_max_weight( 1 );
  return set_max_weight( max_weight + amount );
}

/* NOT to be used in any domain code */
void adjust_contained_weight(int n) 
{
  contents_weight += n;
  /* propogate the change to the environment */
  if ( environment() )
    environment()->adjust_contained_weight( n );
}

/* NOT to be used in any domain code */
void mudlib_adjust_contained_weight(int n)
{
  contents_weight += n;
}

/****** This function is only to be used rarely, it is expensive, but
 ****** rebalances things completely.  Excess objects get expelled to
 ****** the environment, and then the environment gets rebalanced.
 ****** Preferred are objects already expelled somewhere or
 ****** suspected to be causing the inconsistency (eg, they've just
 ****** changed weight).  However they must already have been moved
 ****** into this_object().  Note cursed objects (in use and unable
 ****** to remove from use) will never be expelled, regardless of
 ****** preferred status.
 ******/
void rebalance( object* preferred ) 
{
  object* stuff;
  int i;
  int curr_weight = contents_weight;

  if ( !max_weight || max_weight >= contents_weight )
    return ;

  if ( !preferred )
    preferred = ({ });

  /* first check if throwing out some preferred stuff rebalances things */
  preferred = filter_array( preferred, "check_rebalanceable", this_object() );
  for ( i=0; i<sizeof( preferred ); i++ )
  {
    curr_weight -= preferred[i]->query_weight();
    if ( max_weight >= curr_weight )
    {
      /* we can let everything else stay */
      this_object()->rebalance_move( preferred[0..i] );
      return ;
    }
  }

  /* preferred didn't cut it, we must throw out some additional stuff now.
   */
  stuff = all_inventory(this_object()) - preferred;
  stuff = filter_array( stuff, "check_rebalanceable", this_object() );

  for(i=0;i<sizeof(stuff);i++)
  {
    curr_weight -= stuff[i]->query_weight();
    if ( max_weight >= curr_weight )
    {
      this_object()->rebalance_move( preferred + stuff[0..i] );
      return ;
    }
  }

  /* if we reach here.. we're throwing out everything and still not good
   * enough.  This is probably a bad sign, but may just mean they're
   * overloaded with cursed items.  In any case, we'll let them keep on.
   */
  this_object()->rebalance_move( preferred + stuff );
}  

int check_rebalanceable( object ob )
{
  if ( !ob->droppable() ||
       (ob->query_in_use() && !ob->set_in_use(0)) )
    return 0;
  return 1;
}
  

/* Dumps all the objects to the environment, or crushes them
 * if there's no environment 
 */
void rebalance_move( object* obs )
{
  if ( environment() )
  {
    obs->mudlib_move( environment() );
    environment()->rebalance( obs + ({ this_object() }) );
  }
  else
    this_object()->rebalance_crush( obs );
}

/* Destroys all the objects; this happens when there isn't enough
 * contents space for all the contents, and there is no environment
 * to expell the objects to. 
 */
void rebalance_crush( object* obs )
{
  int i;

  tell_room( this_object(), query_multiple_short(obs)+" are crushed!\n");
  for( i=0; i<sizeof(obs); i++ )
    if ( living(obs[i]) )
      obs[i]->do_death(this_object());
    else
      obs[i]->dest_me();
}



/****** The permission functions.  Determine whether the proposed action
 ****** would cause inconsistency.
 ******/

/*
 * test_add/remove_object; these perform all the necessary checks as to
 * whether an object may be added/removed from the container.  Return
 * a move_failures.h return code
 *
 * NOTE the default here, is that non-droppable items may
 * be removed, and non-gettable items may be added.  
 * This gets overridden in living objects.  (see /std/living/living.c)
 */
int test_remove_object(object ob) 
{ 
  if ( !max_weight )
    return MOVE_OK;

  if ( contents_weight - ob->query_weight() > max_weight )
  {
    /* it might be cursed objects that are the real cause of the
     * overbalance; in that case, we allow objects to be removed
     */
    if ( contents_weight < max_weight )
      /* the object has negative weight and would overbalance us */
      return MOVE_TOO_HEAVY_FOR_SOURCE;
  }

  if ( environment() &&
       !environment()->test_adjust_contained_weight( -ob->query_weight() ) )
    return MOVE_TOO_HEAVY_FOR_SOURCE;
  else
    return MOVE_OK;
}

int test_add_object(object ob)
{

  if ( !max_weight )
    return MOVE_OK;

  if ( contents_weight + ob->query_weight() > max_weight )
    return MOVE_TOO_HEAVY_FOR_DEST;

  if ( environment() &&
       !environment()->test_adjust_contained_weight( ob->query_weight() ) )
    return MOVE_TOO_HEAVY_FOR_DEST;
  else
    return MOVE_OK;
}

/*
 * test_swallow/expell_object; these work much as add/remove, but imply
 * that the object is being received/moved from/to the immediate environment,
 * so the weight constraints aren't the same; ie, if we asked the environment
 * if adding the additional weight was ok, we would (faultily) require
 * extra free space in the environment to perform the move; but in effect, the
 * environment sees no change of weight.  Note this is different, if there
 * is a weight reduction applied.  See /obj/container.c
 */
int test_swallow_object( object ob )
{
  if ( !max_weight )
    return MOVE_OK;

  if ( contents_weight + ob->query_weight() > max_weight )
    return MOVE_TOO_HEAVY_FOR_DEST;

  return MOVE_OK;
}

int test_expell_object( object ob )
{
  if ( !max_weight )
    return MOVE_OK;

  if ( contents_weight - ob->query_weight() > max_weight 
       && contents_weight <= max_weight )
    return MOVE_TOO_HEAVY_FOR_SOURCE;

  return MOVE_OK;
}

/*
 * test_adjust_contained_weight; test if the given change to the contained
 * weight would cause an inconsistency. 1=no, ie allowable, 0=yes
 */
int test_adjust_contained_weight( int n )
{
  if ( contents_weight + n > max_weight )
    return 0;

  if ( environment() )
    return environment()->test_adjust_contained_weight( n );
  else
    return 1;
}



/****** Miscellaneous stuff */

object *find_inv_match(string str) 
{
  return all_inventory(this_object());
} /* find_inv_match() */

mixed stats() 
{
  return ::stats() + 
  ({
    ({ "contents_weight", query_contents_weight(), }),
    ({ "max_weight", query_max_weight(), }),
  });
} /* stats() */

int transfer_all_to(object dest) 
{
  object *ob;
  int i;
 
  ob = all_inventory(this_object());
  ob -= ({ dest });
  for (i=0;i<sizeof(ob);i++)
    ob[i]->move(dest);

  if (first_inventory(this_object())) 
    return 0;
  return 1;
} /* transfer_all_to() */

string long(string str, int dark) 
{
  string ret;

  ret = ::long(str, dark);
  ret += calc_extra_look();
  /* this is stupid.  corpse.c should redefine long() itself. 
   *if(this_object()->query_corpse())
   *  ret += (string)this_object()->query_living_contents(0);
   *
   * else
   */
  ret += query_contents(short(dark)+" contains:\n", all_inventory() - 
                        query_labels());
  return ret;
} /* long() */


/****** Autoload stuff */

/*
 * Derived can be:
 *   -1 = unknown, check
 *    0 = not derived
 *    1 = derived
 */
mapping query_auto_load_attributes( int derived )
{
  mapping tmp;

  if ( derived < 0 )
  {
    if (file_name(this_object())[0..13] == "/std/container")
      derived = 0;
    else
      derived = 1;
  }

  tmp = ::query_auto_load_attributes( derived );

  if ( !derived )
    return 
      ([
        "::" : tmp,
        "max weight" : max_weight,
        "inv" : "/global/auto_load"->create_auto_load(
                    all_inventory(this_object()) - labels ),
      ]);
  else
    return
      ([
        "::" : tmp,
        "inv" : "/global/auto_load"->create_auto_load(
                    all_inventory(this_object()) - labels ),
      ]);
}

void init_auto_load_attributes( mapping attribute_map )
{
  if (attribute_map["::"])
    ::init_auto_load_attributes(attribute_map["::"]);
  if (!undefinedp(attribute_map["max weight"]))
    max_weight = attribute_map["max weight"];

  if (attribute_map["inv"])
    "/global/mortal"->load_auto_load(attribute_map["inv"], this_object());
} /* init_dynamic_arg() */
