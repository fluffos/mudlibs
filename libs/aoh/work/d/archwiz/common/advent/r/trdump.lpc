/* Advent - Treasure Dump Site -- Mateese, 03-Aug-96
 *
 * Being a niche to the Yellow C.A.R.T. tunnel, the Treasure Dump Site
 * is located here.
 * By touching the floor, the players may enter the old pregame (and get
 * one Explorer Point for it).
 * If ADV_QUESTNAME is defined, the drop of the last treasure will award
 * the player with the mini-quest.
 * If not, he'll get a special message anyway.
 * All solvers are logged in l/SPELUNKERS which is displayed in
 * the Hall Of Fame.
 * Properties:
 *   "NumTreasures": Number of Treasures present in the room.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include <secure/wizlevels.h>
#include "advent.h"

inherit ADVENT("i/stdroom");
inherit "/obj/lib/string";

/*-----------------------------------------------------------------------*/
int UpdateTreasures()

/* Recompute the number of treasures in this room and update the lighting.
 */

{
  int newcount, oldcount;
  object cartroom, springroom;
  
  cartroom = find_object(CART("yellow3"));
  springroom = find_object(ADVENT("r/subtwell"));
  oldcount = Query("NumTreasures");
  newcount = sizeof(filter_objects(deep_inventory(this_object()), "IsTreasure")
		   );
  if (newcount != oldcount)
  {
    if (newcount < oldcount)
      show_room(this_object(), "The glow of the sign fades.\n");
    else
      show_room(this_object(), "The glow of the sign increases.\n");
    Set("NumTreasures", newcount);
    Set(P_BRIGHT, 10+10*newcount);
    if (cartroom)
      cartroom->Set(P_BRIGHT, cartroom->Query(P_BRIGHT));
    if (springroom)
      springroom->Set(P_BRIGHT, springroom->Query(P_BRIGHT));
      // This will cause the cart/springroom to recompute its internal lighting.
  }
}

/*-----------------------------------------------------------------------*/
public string DetailSign()
{
  string msg;
  int    numtreasure;
    
  numtreasure = Query("NumTreasures");
  msg = 
"  +----------------------+\n"
"  | Treasure!            |\n"
"  |   Dump    -------+   |\n"
"  |     Site         |   |\n"
"  |                 \\|/  |\n"
"  |                  V   |\n"
"  +----------------------+\n";
  if (numtreasure < 2)
    msg += "It is glowing faintly.\n";
  else
    switch (numtreasure)
    {
      case 0..5:
        msg += "It emits a steady glow.\n";
	break;
      case 6..7:
        msg += "It emits a brilliant glow.\n";
	break;
      default:
        msg += "It shines brightly.\n";
	break;
    }
  return msg;
}

/*-----------------------------------------------------------------------*/
void create()
{
  ::create();

  // Main description
  Set(P_INT_SHORT, "Treasure Dump Site");
  Set(P_INT_LONG,
"A small niche carved into the south wall of an old C.A.R.T. tunnel.\n"
"A sign has been attached to one wall.\n"
     );
  Set(P_INT_SMELL, "The air smells stale and earthy.\n");
  Set(P_INT_NOISE, "It is silent, except for the quiet sound of flowing water.\n");
  Set(P_BRIGHT, 10);
  Set(P_NODWARF, 1);
  Set(P_NOORIG, 1);

  // Exits
  AddExit("north", CART("yellow3"));
  AddExit("south", ADVENT("r/subtwell"));
    
  // Details
  AddDetail("cart tunnel",
"The tunnel is a bit to the north, running from east to west.\n"
           );
  AddDetail("tunnel",
"The C.A.R.T. tunnel is a bit to the north, running from east to west. "
"The second tunnel leads southwards into darkness.\n"
           );
  AddNoise(({ "tunnel","water" })
          , "The sounds of flowing water emerge from the tunnel.\n"
	  );
  AddDetail(({ "niche", "dumpsite", "dump site"
             , "treasure dumpsite", "treasure dump site" })
           ,
"The niche has been carefully carved into the stone. Its floor "
"is unnaturely flat, and a sign has been attached to the back of the niche.\n"
"From the back of the niche, a tunnel leads south.\n"
           );
  AddDetail("floor",
"The floor in the niche is flat as if it's liquid, though it looks like "
"ordinary earth.\n"
           );
  AddDetail("sign", #'DetailSign);
  AddReadMsg("sign", #'DetailSign);

  AddRoomCmd("dump", "fdump");
  AddRoomCmd("touch", "ftouch");
}

/*-----------------------------------------------------------------------*/
public void reset()
{
  ::reset();
  UpdateTreasures(); // To be on the safe side
}

/*-----------------------------------------------------------------------*/
/* Touching the floor sucks the player into the old pregame :-)
 */
public int ftouch(string arg)
{
  if (!arg 
   || -1 == member(({"earth", "the earth", "floor", "the floor"})
		  , norm_id(arg))
     )
  {
    notify_fail("Touch what?");
    return 0;
  }

  if (ME_OK != this_player()->move(ADVENT("r/building"), M_SPECIAL
				  , ({
"vanishes", "is here"
,"touch ordinary earth. Well, it makes you feel a bit dizzy"
				    }))
     )
    raise_error("Move to "+ADVENT("r/building")+" failed.\n");
  return 1;
}

/*-----------------------------------------------------------------------*/
public int fdump(string arg)
{
  if (!arg)
    arg = "drop";
  else
    arg = "drop "+arg;
  this_player()->command_me(arg);
  return 1;
}

/*-----------------------------------------------------------------------*/
/* Whenever a treasure is dropped here, it must be removed and the
 * receival noted in the player.
 */

int allow_enter(int method, mixed extra)
{
  int rc;
  rc = ::allow_enter(method, extra);
  if (!this_player() || !rc || method != M_DROP
   || !previous_object()->IsTreasure(this_player()))
  {
    previous_object()->Set("LastOwner", 0);
    return rc;
  }
  previous_object()->Set("LastOwner", previous_object()->QueryOwner());
  this_player()->RegisterCmdFun("DumpedTreasures");
  return rc;
}
 
void DumpedTreasures(int arg, int goterror)
{
  object *inv;
  int i;
  string msg;

  /* Of all the inventory, filter out the possible treasures. */
  inv = filter_objects(all_inventory(this_object()), "Query", P_TREASURE);

  /* Clean up in case of an error */
  if (goterror || !this_player())
  {
    map_objects(inv, "Set", "LastOwner", 0);
    return;
  }
    
  /* Filter out the true treasures */
  for (i = 0; i < sizeof(inv); i++)
    if (inv[i]->Query("LastOwner") != this_player()
     || !inv[i]->IsTreasure(this_player(), 1)
       )
      inv[i] = 0;
  inv -= ({ 0 });
  
  if (!sizeof(inv))
  {
    write("Nothing happens.\n");
    return;
  }
    
  /* Remove the treasures and count them in with their droppers */
  for (i = 0; i < sizeof(inv); i++)
  {
    SetFlag(inv[i]->Query(P_TREASURE), this_player());
    this_player()->AddXP(inv[i]->Query(P_XP));
  }
  msg = implode_list(map_objects(inv, "Short")
		    , "The earth stirs up and sucks "
		    , " underground. Then everything is still again."
		    , " and"
		    );
  map_objects(inv, "remove");
  show_room(this_object(), msg);
    
  /* Check if the player dropped all treasures and thus completed the
   * task. If ADV_QUESTNAME is defined, this is counted as completion
   * of the mini-quest.
   */
  for (i = 1; i <= F_NUM_TREASURES; i++)
    if (!QueryFlag(i, this_player()))
      break;
  if (i > F_NUM_TREASURES)
  {
    SetFlag(F_SOLVED, this_player());
    write("You really proved yourself being a true spelunker.\n");
    write("Your performance will be remembered.\n");
    write_file(ADVENT("l/SPELUNKERS"), stime(time())+" : "+capitalize(this_player()->QueryRealName())+"\n");
#ifdef ADV_QUESTNAME
    QUESTMASTER->SetPlayerQuest(ADV_QUESTNAME, this_player());
    QUESTMASTER->qshout(capitalize(this_player()->QueryRealName())
	  +" really proved "+this_player()->QueryPronoun()+"self "
	  +" being a true spelunker.\n");
#endif
  }
}

/*-----------------------------------------------------------------------*/
/* The grunt stuff of updating the numtreasure whenever the content
 * of the room is changed.
 */

void notify_enter(mixed oldenv, int method, mixed extra)
{
  ::notify_enter(oldenv, method, extra);
  UpdateTreasures();
}

void notify_leave(mixed dest, int method, mixed extra)
{
  ::notify_leave(dest, method, extra);
  UpdateTreasures();
}

/*************************************************************************/
