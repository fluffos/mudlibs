/* std/npc.c
 *
 * This is a generic npc (non player character) object.
 *
 * This file is (c) Nightfall 1992, One Step Beyond 1997.
 * You may use of it whatever you
 * like, but you should put a reference in your file if you do it.
 *
 * Major authors: Deepthought (once upon a time)
 *
 * Version 4.0 first version of new player object
 * Version 4.1 Pepel fixed lots : combat and description
 *
 * [Softbyte] 19nov97 Skill usages removed
 *
 * Things that changed to previous (2.4.5) version:
 * - Properties added, most player variables are now accessible as
 *   properties
 * - New meaning of short-description. The property P_SHORT can now
 *   be used for all descriptive writes. P_SHORT of a player is now
 *   either the player's name, ghost of <player>.
 *   QueryShort() should be used to refer to an object in descriptive texts.
 *-----------------------------------------------------------------
 */

/*
 * commands are inherited!!
 */

inherit "/std/room/items";
inherit "/std/living/chat";
inherit "/std/living/description";
inherit "/std/living/heart";
inherit "/std/living/attributes";
inherit "/std/living/moving";
inherit "/std/living/restrictions";
inherit "/std/living/combat";
inherit "/std/living/commands";
inherit "/std/npc/body";
inherit "/std/npc/cmds";
inherit "/std/npc/putget";
inherit "/std/living/stats"; // Softbye 19nov97
inherit "/std/npc/view";
inherit "/std/base";

#include <config.h>
#include <properties.h>
#include <ansi.h>
#include <secure/wizlevels.h>
#include <combat.h>
#include <classes.h>
#include <living.h>

#define ME this_object()

public varargs int SetStandard(mixed level, string race, string name)
{
  int base_xp;

  if (pointerp(level))
    return apply(#'SetStandard /*'*/,level);
  SetName(name||QueryName()||"Nobody");
  if (!QueryLong() || !QueryRace())
    RACEMASTER->InitRace(ME,race||QueryRace()||"human");
  SetRace(race||QueryRace()||"human");
  // SetRace is done in InitRace, too but not for non-player-races so
  // it needs to be called once again to ensure that the race
  // got set.
  base_xp = ({int})RACEMASTER->XPfromLevel(level);
  SetXP(base_xp + random(({int})RACEMASTER->XPfromLevel(level+1)-base_xp));
  SetStr(2*level);
  SetDex(2*level);
  SetInt(2*level);
  SetCon(2*level);
  SetCha(2*level);
  SetWis(2*level);
  SetAgi(2*level);
  SetQui(2*level);
  ::SetLevel(level);
  CalculateSemiStats(0);
  SetHP(QueryMaxHP());
  SetSP(QueryMaxSP());
  SetPEP(QueryMaxPEP());
  SetMEP(QueryMaxMEP());
  SetDrink(QueryMaxDrink());
  SetFood(QueryMaxFood());
  SetAlcohol(0);
  return QueryLevel();
}

public int SetLevel(int lvl) {
  return SetStandard(lvl);
}

void create() {
  base::create();
  heart::create();
  SetIds(({}));

  /* dont mess with the blueprint too much */
  if (!clonep()) return;

  body::create();
  combat::create();
  restrictions::create();
  AddClassId(C_LIVING);
  AddClassId(C_NPC);
  Set(P_HELP_MSG, "");
  Set(P_NOGET, 1);
  SetHands(({
    ({"right hand",0,WEAPON_CLASS_OF_HANDS}),
    ({"left hand",0,WEAPON_CLASS_OF_HANDS}) }) );
  SetAC(1);	/* set the intrinsic armour class, removes all else defences */
  SetStandard(1,"human","Nobody");
  SetLong(0);
  SetGender(0);
  enable_commands();
  add_putget_cmds();
  add_view_cmds();
  add_npc_cmds();
  /* For statistics */
  // catch("/obj/npcstat"->Add(this_object()));
}

varargs void reset() {
  items::reset();
}

void init() {
  combat::init();
  chat::init();
}
