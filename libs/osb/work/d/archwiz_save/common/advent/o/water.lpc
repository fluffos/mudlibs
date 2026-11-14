/* Advent - Water running through a room -- Mateese, 05-Aug-96
 *
 * This is a stream/lake/whatever of water, which is cloned and reconfigured
 * by rooms. If the property P_INVIS is set (default), the water is not listed
 * in the inventory of the room.
 * An addition to P_LONG may be stored in P_WATEREXTRA.
 * The player can drink from it and replenish bottles if P_DRINK is set.
 * A P_POISON setting is also taken care of.
 * The message given to the player upong drinking is P_FD_MSG1.
 */

#include <config.h>
#include <properties.h>
#include <search.h>
#include <moving.h>
#include <secure/wizlevels.h>
#include "advent.h"

inherit "/std/thing";

/*-----------------------------------------------------------------------*/
/* The thing is invisible in the inventory.
 */

public varargs string InvShort(string what)
{
  string sh;

  sh = ::InvShort();
  if (!Query(P_INVIS))
    return sh;
  if (IS_IMMORTAL(this_player()) && !this_player()->Query(P_NOWIZ))
    return sh+" (invisible)";
  return "";
}

/*-----------------------------------------------------------------------*/
/* The water may haven an extra P_LONG description.
 */

public string WaterExtraLong()
{
  return Query(P_WATEREXTRA) || "";
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  Set(P_SHORT, "a stream of water");
  Set(P_LONG, "A stream of cold, clear water.\n");
  SetExtraEntry("water extra long", P_LONG, #'WaterExtraLong);
  AddId(({"stream", "water" }));
  AddAdjective( ({"stream", "of", "cold", "clear" }) );
  Set(P_NOGET, "You can't take it, silly.\n");
  Set(P_DRINK, 10);
  Set(P_POISON, 0);
  Set(P_FOOD_MSGS
     , "You drink from the "+strip_article(Short())+".\n"
       "The water tastes strongly of minerals, but is not unpleasant.\n"
       "It is extremely cold.\n"
     );
  Set(P_INVIS, 1);
}

void init()
{
  ::init();
  if (Query(P_DRINK))
    add_action("fdrink", "drink");
}

public varargs int allow_enter (int method, mixed extra)
{
  if (this_player() && (M_DROP == method || M_PUT == method))
  {
    this_player()->RegisterCmdFun("dest_inv", (M_DROP == method) && extra);
    return ME_OK;
  }
  return ME_NO_ENTER;
}

public void dest_inv(int goterr, int silent)
{
  string msg, verb;
  object *ainv;
    
  ainv = all_inventory(this_object());
  if (!sizeof(ainv) || goterr)
    return;
    
  if (!silent)
  {
    verb = sizeof(ainv) < 2 ? "es" : "";
    msg = implode_list(all_inventory(this_object())
                      , "", " vanish"+verb+" in the liquid.");
    show_room(environment(), capitalize(msg));
  }
  filter_objects(deep_inventory(this_object()), "remove");
  filter(deep_inventory(this_object()), #'destruct);
}

/*-----------------------------------------------------------------------*/
public int fdrink (string arg)
{
  int dp;

  if (!arg)
  {
    notify_fail("Drink what?", NOTIFY_NOT_OBJ);
    return 0;
  }
  arg = norm_id(arg);
  if (arg[0..4] == "from ")
    arg = arg[5..];

  if (this_object() != search(this_player(), arg, SM_OBJECT|SEARCH_ENV|SM_IGNLIGHT))
  {
    notify_fail("You find no "+arg+" here to drink from.\n", NOTIFY_ILL_ARG);
    return 0;
  }

  if ((int)this_player()->Query(P_DRINK) >= (int)this_player()->Query(P_MAX_DRINK))
  {
    notify_fail("You can't drink anymore.\n", NOTIFY_NOT_VALID);
    return 0;
  }

  this_player()->AddDrink(Query(P_DRINK));
  this_player()->AddPoison(Query(P_POISON));
  write(Query(P_FOOD_MSGS));
  if (!this_player()->Query(P_INVIS))
    show(this_player()->Query(P_NAME)
	  +" drinks from the "+strip_article(Short())+".\n");
  return 1;
}

/*************************************************************************/
