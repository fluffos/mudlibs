/* Advent - Ming Vase -- Mateese, 21-Aug-96
 *
 * The Ming Vase from the Oriental Room.
 * Dropping it onto a floor with not carpet/pillow, or filling it with
 * water breaks it.
 */

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <search.h>
#include "advent.h"

inherit ADVENT("o/treasure");

/*-----------------------------------------------------------------------*/
public object ReplaceByShards()

/* Replace the Ming Vase by shards.
 */

{
  object shards;
  
  if (!environment(this_object()))
    return 0;
    
  shards = present("shards", environment(this_object()));
  if (shards)
  {
    shards->Set(P_WEIGHT, shards->Query(P_WEIGHT)+Query(P_WEIGHT));
    return shards;
  }
    
  shards = clone_object("/std/thing");
  shards->Set(P_SHORT, "some worthless shards of pottery");
  shards->Set(P_LONG,
"They look to be the remains of what was once a beautiful vase. "
"Some oaf must have dropped it.\n"
	     );
  shards->Set(P_WEIGHT, Query(P_WEIGHT));
  shards->Set(P_VALUE, 0);
  shards->AddId(({"shards", "pottery"}));
  shards->AddAdjective(({"shards", "of", "worthless"}));
  if (ME_OK != shards->move(environment(this_object()), M_SILENT))
  {
    shards->remove();
    raise_error("Move of shards into "+to_string(environment(this_object()))
		+ "failed.\n"
	       );
  }
  show_room(environment(this_object())
	   , "The vase breaks into myriads of shards.\n"
	   );
  remove();
  return shards;
}

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  seteuid(getuid(this_object()));
    
  Set(P_SHORT, "a ming vase");
  Set(P_LONG, "It's a delicate, precious, ming vase.\n");
  Set(P_WEIGHT, 1000);
  Set(P_VALUE, 500);
  AddId("vase");
  AddAdjective(({ "delicate", "precious", "ming" }));
  Set(P_TREASURE, F_VASE);
  Set(P_XP, 1600);
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  add_action("ffill", "fill");
}

/*-----------------------------------------------------------------------*/
public int move (mixed dest, int method, mixed extra)

/* If the vase is dropped, break it.
 */

{
  int rc;
    rc = ::move(dest, method, extra);
  if (this_player() && M_DROP == method && ME_OK == rc 
   && !present("pillow", environment(this_object()))
   && !present("cushion", environment(this_object()))
     )
    this_player()->RegisterCmdFun("ReplaceByShards");
  return rc;
}

/*-----------------------------------------------------------------------*/
public int ffill (string arg)

/* If the vase is filled with a liquid, the temperature will break it.
 * Formats: 'fill vase with <...>'
 */
{
  string *args;
  string what, with;
  object obj;
  int i, volume;
    
  if (!arg)
  {
    notify_fail(capitalize(query_verb())+" what?\n", NOTIFY_NOT_CMD);
    return 0;
  }

  /* Extract the <what> and <with> from the args.
   */
  args = norm_id(arg, 1);
  i = member(args, "with");
  if (i == -1)
  {
    notify_fail(capitalize(query_verb())+" what?\n", NOTIFY_NOT_CMD);
    return 0;
  }
  what = implode(args[0..i-1], " ");
  with = implode(args[i+1..], " ");
  
  /* Is this object meant? */
  if (this_object() != wsearch_env_inv(what))
  {
    notify_fail(capitalize(query_verb())+" what?\n", NOTIFY_NOT_OBJ);
    return 0;
  }

  /* Has the player something with her to fill the vase? */
  obj = wsearch_env_inv(with);
  if (!obj)
  {
    notify_fail(capitalize(query_verb())+" the vase with what?\n"
	       , NOTIFY_ILL_ARG);
    return 0;
  }

  write("The sudden change of temperatur has delicately shattered the vase.\n");
  if (environment(this_object()) == this_player())
    move(environment(this_player()), M_SILENT);
  ReplaceByShards();

  return 1;
}

/*************************************************************************/
