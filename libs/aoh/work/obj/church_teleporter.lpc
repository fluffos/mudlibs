/*
** Church-Teleporter
** This teleporter might be placed anywhere. It should be placed
** at the entry-points of races or near to it, so that it's easy
** for players to get in contact.
**
** Author: Thragor@Nightfall, 24nov95
** Update:
*/

#include <stdrooms.h>
#include <config.h>
#include <search.h>
#include <moving.h>

#define P_CAME_FROM "ChurchTravel/CameFrom"
#define TP this_player()
#define ME this_object()

private nosave string Pteleport_to;

inherit "/std/thing";

public varargs string SetTeleportTo(string file)
{
  file = resolve_file(file);
  Pteleport_to=file||CHURCH;
}

public string QueryTeleportTo()
{
  return Pteleport_to||CHURCH;
}

private string QueryHole()
{
  if (!environment()||QueryTeleportTo()==object_name(environment()))
    return "dark";
  return "bright";
}

public string QueryShort()
{
  return "a big column with a "+QueryHole()+" hole inside";
}

public void create()
{
  (::create());
  SetLong(
    "This column looks strange somehow. It doesn't fit into its environment.\n"
    "It seems as if it is taken from another world. You're even not sure,\n"
    "if it's really here, existing, so that you can touch it.\n"
    "The hole is nothing. Not nothing important, or anything like that.\n"
    "Really nothing. It hurts looking into it.\n");
  SetNoGet("You feel that you get contact to the column but as you\n"
           "want to grab it, your hand suddenly moves through it as if\n"
           "it's not there.\n");
  SetIds(({"column"}));
  SetAds(({"big","strange","foreign","alien"}));
}

public void init()
{
  (::init());
  add_action("cmd_touch","touch");
}

public int cmd_touch(string str)
{
  string efile,dest;
  object env;
  
  if (!str||!TP||search(TP,str,SEARCH_ENV|SM_IGNLIGHT|SM_OBJECT)!=ME)
    return notify_fail("What do you want to touch?\n",
		       NOTIFY_NOT_OBJ),0;
  if ((env = environment())!=environment(TP))
    return notify_fail("You need to be here.\n",NOTIFY_NOT_VALID),0;
  // As the players should be able to return but can't return to a
  // cloned environment (most of the time), it's forbidden to leave
  // such places.
  if (is_clone(env))
    return notify_fail("Your environment isn't fixed in the structures\n"
                       "of the world. You can't leave.\n",
		       NOTIFY_NOT_VALID),0;
  if ((efile = object_name(env))==QueryTeleportTo())
    {
      if (!efile = TP->Query(P_CAME_FROM))
        return notify_fail("Nothing happens.\n",NOTIFY_NOT_VALID),0;
      TP->Set(P_CAME_FROM,0);
      dest = efile;
    }
  else
    {
      TP->Set(P_CAME_FROM,efile);
      dest = QueryTeleportTo();
    }
  if (TP->move(dest,M_SILENT)!=ME_OK)
    return notify_fail("You're puzzled. Nothing happens.\n",
		       NOTIFY_NOT_VALID),0;
  write("You touch the column and suddenly the dark hole becomes very wide -\n"
        "it just opens like a mouth. Your feet lose contact and you are\n"
        "sucked into the black nothingness of the hole.\n"
        "You fall and fall and fall and fall and ...\n"
        "Then you have a feeling as if you turn while falling. There's a\n"
        "light in this nothingness.\n"
        "After this strange trip you're again in front of the column. Hm.\n"
        "But something seems to be different here.\n");
  // The player won't see where he is without looking around.
  // It's a small gag. Please don't change that.
  // Thragor
  if (!TP->QueryInvis())
    {
      show_room(env,
        capitalize(TP->QueryName())+" touches the column. Suddenly "+
        TP->QueryPronoun()+" shrinks, loses contact to the ground and is\n"
        "sucked away into the dark hole in the column.\n");
      show_room(environment(),
        "Suddenly something very small appears out of the hole in the\n"
        "column. Looks like something living. It becomes bigger and bigger\n"
        "and after some seconds, "+TP->QueryName()+" is standing in front\n"
        "of you.\n",({TP}));
    }
  return 1;
}

