/*
** The Ring of Unity
** Item of the Culture Center Quest
** Author: Thragor@Nightfall, 03apr97
** Update:
** Cloned by: /d/archwiz/common/room/culture/culture
*/

#include <combat.h>
#include <properties.h>

#define SF(x) #'x //' Emacs-Hack

inherit "/std/armour";

public void create()
{
  (::create());
  SetStandard(AT_RING,0,PSIZE_GENERIC);
  SetShort("a small ring");
  SetLong("This is a small ring made of marble. It's blank except one "
	  "inscription on it.\n");
  AddId(({"ring"}));
  AddAdjective(({"marble","small"}));
  AddSubDetail("inscription",
	       "Three words are engraved: Friendship, Unity, Co-operation\n");
  AddSubReadMsg("inscription",
		"Friendship, Unity, Co-operation\n");
  SetInfo("This ring is a symbol for what you need to build and run "
	  "a Multi User Dungeon.\n");
  SetMagic("There's a strange aura of peace around this ring.\n");
}

public void NotifyWear(object pl, object ring, int flags)
{
  if (!ring || !pl || ring!=this_object())
    return;
  if (environment(pl))
    environment(pl)->CheckQuest(pl);
  return (::NotifyWear(pl,ring,flags));
}

public string CCQuest()
{
  return "ring";
}
