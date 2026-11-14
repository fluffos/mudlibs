/*---------------------------------------------------------------------------
** obj/torch
**
** A simple torch. It will burn for about 1.5 hours.
** It can't be unlit. A burning torch can't be sold to a shop.
** As a bonus, the torch can be used as weapon.
**
**   29-Aug-92 [Mateese]
**   11-Aug-94 [Mateese] Adapted for new /std/lamp
**   25-Nov-94 [Mateese] Adapted for new /std/combat
**---------------------------------------------------------------------------
*/

#include <config.h>
#include <moving.h>
#include <lamp.h>
#include <properties.h>
#include <nightday.h>
#include "/neu/sys/combat.h"

inherit "/std/lamp";
inherit "/neu/std/combat";

#define THIS this_object()

/*----------------------------------------------------------------------------
** Initialize us
*/

create(){
  lamp::create();
  AddId ("torch");
  SetShort("a torch");
  SetWeights (200, 40);          /* Base weighs 200 gr, one unit 40 gr */
  SetValues (1, 1);              /* Base is worth 1, one unit 1 */
  SetFuelAmount (15+random(6));  /* 15..20 units a 5 minutes */
  SetBrightness (REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetLampMsg ( ({
 "The torch is already burning.\n"
,"The torch isn't burning.\n" /* Needed by unlight if it wouldnt be disabled */
,"The torch is burned down - you can't light it anymore.\n"
,"The torch lights up.\n"
,"@@Pl_Name@@ lights a torch.\n"
,"The torch goes dark.\n"             /* Not needed as well */
,"@@Pl_Name@@ unlights @@Pl_Poss@@ torch.\n"
,"Your torch flickers and goes out.\n"
,"@@Pl_Owner@@ torch flickers and goes out.\n"
           }));
  SetNumberHands(1);
  SetWeaponType(CS_CLUB);
  SetClass(5/CLASS_SCALE);  /* Modified on Query according to burning status */
}

void init () {
  lamp::init();
  weapon_init();
}

int move(mixed dest, int method, mixed extra) {
  int ret;
  if ((ret = lamp::move(dest, method, extra)) == 1)
    notify_move(dest, method, extra);
  return ret;
}

int remove() {
  notify_move(0, M_DESTRUCT);
  return lamp::remove();
}

mixed QueryNoBuy() { return QueryBurning(); }

int QueryClass() { 
  int wc;
  wc = ::QueryClass();
  if (QueryBurning())
    return wc;
  return (wc * QueryFuel()) / QueryFuelMax();
}

mapping QueryDamage () {
  int c;
  c = QueryClass();
  if (!QueryBurning())
    return ([ DT_BLUDGEON: c ]);
  return ([ DT_HEAT : c ]);
}

/*----------------------------------------------------------------------------
** Description, Smell, Noise
*/

string QueryShort() {
  string rc, sh;  
  rc = QueryFuel() > 0 ? "" : "the remains of ";
  return rc+::QueryShort();
}

string Short() {
  string sh;
  sh = ::Short();
  if (QueryBurning())
    sh = "a burning "+strip_a(sh);
  return sh;
}

string InvShort (string what) {
  return modifyInvShort(::InvShort(what));
}

string QueryLong() {
  if (QueryBurning()) 
    return "A torch, burning with a smokeless flame.\n";
  else 
    return "A longish piece of wood. Being lit, it would be a good torch.\n";
}

string Long(string what) {
  string rc;
  int fuel, maxfuel;

  fuel = QueryFuel();
  maxfuel = QueryFuelMax();
  rc = ::Long();
  if (fuel == maxfuel) rc += "It is brand new.\n";
  else if (fuel * 4 > maxfuel * 3) rc += "It's only slightly burned.\n";
  else if (fuel * 2 > maxfuel) rc += "It's burned down to nearly the half.\n";
  else if (fuel * 4 > maxfuel) rc += "Only a bit wood is left.\n";
  else if (fuel) rc += "It may go out every moment.\n";
  else rc = 
"In former times, this was a torch. But it has burned down and now it's just\n"
+"a small worthless piece of wood.\n";
  return modifyLong(rc);
}

string QuerySmell() {
  int fuel, maxfuel;

  fuel = QueryFuel();
  maxfuel = QueryFuelMax();
  if (QueryBurning()) 
    return "You smell the odour of burning pine wood.\n";
  if (fuel == maxfuel) return "You smell pine wood with a touch resine.\n";
  if (!fuel) return "It smells woody.\n";
  return "You smell a mixture of pine wood and cold ashes.\n";
}

string QueryNoise() {
  if (QueryBurning()) 
    return "You hear a faint crackling from the burning wood.\n";
  return "You hear nothing.\n";
}

public int QueryValue() { return modifyValue(::QueryValue()); }

/*----------------------------------------------------------------------------
** Flicker during burning
*/

BurnUp() {
  string msg, msge, own;
  object env, pl;

  if (::BurnUp()) {
    own = Pl_Owner();
    switch(random(10)) {
      case 0: msg  = "Your torch flickers.\n"; 
              msge = capitalize(own)+" torch flickers.\n"; 
              break;
      case 1: msg = 
"Attracted by your torch's flame, an insect dies a crackling death.\n";
              msge = 
"Attracted by "+own+" torch flame, an insect dies a crackling death.\n";
              break;
      case 2: msg = 
"A sudden wind blows a flame in your direction, nearly burning your skin.\n";
              msge = msg;
              break;
      default: return;
    }
    pl = 0;
    if ((env=environment(THIS)) && interactive(env)) { /* We are carried */
      pl = env;
      tell_object (pl, msg);
      env = environment(pl);
    }
    if (env) tell_room (env, msge, ({ pl }));
  }
}

/****************************************************************************/
