/*---------------------------------------------------------------------------
** std/living.c
**
** A simple living - 'cloned to die'.
**
** 04-Jan-1993  [Mateese]
** 19-Nov-1997  [Softbyte] OSB Stats
** 29-Noc-1997  [Softbyte] Chat calls for Talk functions
** 12-Mar-1998  [Softbyte] remove and stats::init/create calls
**
**---------------------------------------------------------------------------
*/

#include <config.h>
#include <properties.h>
#include <living.h>
#include <combat.h>
#include <health.h>
#include <classes.h>

#define THIS this_object()
#define TP   this_player()
#define ENV  environment

inherit "/std/living/stats";
inherit "/std/living/restrictions";
// has container/restrictions::create()
inherit "/std/living/heart";
// has heart::create()
#if 0
inherit "/neu/std/living/enemies";
#else
inherit "/std/living/combat";
#endif
inherit "/std/living/description";
inherit "/std/living/commands";
inherit "/std/living/chat";
inherit "/std/living/body";
inherit "/std/living/attributes";
#if 0
inherit "/neu/std/living/actions";
// has enemies::create(); has init()
#else
inherit "/std/living/moving";
#endif
inherit "/std/room/items";
inherit "/std/base";

// Indirectly inherited are:
//   combat                  : by enemies
//   hands                   : by combat
//   moving                  : by actions
//   thing/moving            : by moving
//   thing/description       : by description
//   room/description        : by description
//   container/restrictions : by restrictions

//---------------------------------------------------------------------------
public varargs void SetInitLevel (mixed level, int randHealth)

// Set all level depending things at once.

{
  int xp;

  if (pointerp(level)) {
    randHealth = level[1];
    level = level[0];
  }

  xp = ({int})RACEMASTER->XPfromLevel(level);
  xp += random(({int})RACEMASTER->XPfromLevel(level+1) - xp);
  while (XP_GAIN(xp) < 1) xp++; // Give out at least one XP to victors
  SetXP(xp);

  SetLevel(level);
  SetDex(level);
  SetStr(level);
  SetInt(level);
  SetCon(level);
  SetCha(level);
  SetWis(level);
  SetAgi(level);
  SetQui(level);

  // TODO: Adapt Stats and derived values according to P_RACE
  SetUVision(MAX_SUNBRIGHT);

// Softbyte 19nov97 ... skillusage temporaily removed
#ifdef NF
  sk = (string *)SKILLMASTER->QuerySkillNames();
  for (i = sizeof(sk); i--; )
    SetSkill(sk[i], 5*level);
#endif

  // TODO: Set Health-Rates, according to stats
  SetWeight(75000);
  SetMaxPoison(20+(STAT_SCALE*QueryCon()*80)/100);
  SetRateHP(HP_RATE);
  SetRateSP(SP_RATE);
  // Softbyte 19nov97
  SetRatePEP(PEP_RATE);
  SetRateMEP(MEP_RATE);
  SetRatePoison(POISON_RATE);

  if (!randHealth)
  {
    SetHP(QueryMaxHP());
    SetSP(QueryMaxSP());
    SetPEP(QueryMaxPEP());
    SetMEP(QueryMaxMEP());
  }
  else
  {
    SetHP(QueryMaxHP()/2+random(QueryMaxHP()/2));
    SetSP(QueryMaxSP()/2+random(QueryMaxSP()/2));
    SetPEP(QueryMaxPEP()/2+random(QueryMaxPEP()/2));
    SetMEP(QueryMaxMEP()/2+random(QueryMaxMEP()/2));
  }
  Set(P_NOGET, 1);
}

//---------------------------------------------------------------------------
public void SetDefault (mixed level)

// TODO: Make it an InitDefault (int level, string race)

// Set up a default living

{
  if (pointerp(level)) {
    level = level[0];
  }

  SetName("Nobody");
  SetShort("Nobody the featureless human");
  SetLong("Nobody is an ordinary human.\n");
  SetGender(0);
  SetWeight(75000+random(10000)-5000);
  SetRace("human");
  SetWimpy(5);

#if 0
  AddHand("right hand", HAND_WC);
  AddHand("left hand", HAND_WC);

  // Human skin gives not much defense against attacks.
  // TODO: Adapt these values to something useful.
  AddDefense(DT_BLUDGEON, 5);
  AddDefense(DT_PIERCE, 2);
  AddDefense(DT_SLASH, 2);
  AddDefense(DT_HEAT, 2);
  AddDefense(DT_COLD, 2);
  AddDefense(DT_POISON, 1);
#else
  SetHands(({
    ({"right hand",0,WEAPON_CLASS_OF_HANDS}),
    ({"left hand",0,WEAPON_CLASS_OF_HANDS}) }) );
#endif

  SetInitLevel(level, 1);
}

//---------------------------------------------------------------------------
public void create ()
{
  seteuid(getuid());
  base::create();
  heart::create();
  restrictions::create();
#if 0
  enemies::create();
#else
  combat::create();
#endif
  body::create();
  chat::create();
  stats::create();

  Set(P_HELP_MSG, "");

  if (clonep())
  {
    enable_commands();
    SetDefault(1);
    AddClassId(C_LIVING);
  }

  AddHeart(HEART_BODY);
}

public varargs void reset() {
#if 0
  ForgetEnemies();
#endif
  items::reset();
}

public void init ()
{
#if 0
  actions::init();
#else
  combat::init();
#endif
  chat::init();
  stats::init();
}
public varargs int remove(int arg) {
  stats::remove(arg); // must stand before moveing !!
  moving::remove();
  return ::remove();
}


/***************************************************************************/
