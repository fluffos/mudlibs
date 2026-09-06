/* obj/torch
**
** A simple torch. It will burn for about 1.5 hours.
** It can't be unlit. A burning torch can't be sold to a shop.
**
**   29-Aug-92 [Mateese]
**   11-Aug-94 [Mateese] Adapted for new /std/lamp
**   13-Jan-96 [Mateese] Halfened the weight.
*/

#include <config.h>
#include <lamp.h>
#include <properties.h>
#include <nightday.h>
#include <combat.h>

inherit "/std/lamp";
inherit "/std/weapon/combat";

#define THIS this_object()
#define TP   this_player()

#define SUBID  (to_string(this_object())+":subid")

/*----------------------------------------------------------------------------
** Initialize us
*/

void create(){
  lamp::create();
  combat::create();
  AddId ("torch");
  SetShort("a torch");
  SetWeights (100, 20);          /* Base weighs 100 gr, one unit 20 gr */
  SetValues (1, 1);              /* Base is worth 1, one unit 1 */
  SetFuelAmount (15+random(6));  /* 15..20 units a 5 minutes */
  SetBrightness (ND_REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
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
  SetHelpMsg(
"A torch is a carefully selected piece of wood which radiates a bit light\n"
"when lighted. As it burns down, one can unlight it when not needed.\n"
"It also makes a handy club.\n"
	    );
  SetWeaponHands(1);
  SetWeaponType(WT_CLUB);
  SetWC(5);  /* Modified on Query according to burning status */
}

void init () {
  lamp::init();
  combat::init();
}

varargs int move(mixed dest, int method, mixed xtra) {
  int ret;
  if ((ret = lamp::move(dest, method, xtra)) == 1)
    unwield();
  return ret;
}

varargs int remove() {
  unwield();
  return lamp::remove();
}

mixed QueryNoBuy() { return QueryBurning(); }

varargs int QueryWC() {
  int wc;
  wc = ::QueryWC();
  if (QueryBurning())
    return wc;
  return (wc * QueryFuel()) / QueryFuelMax();
}

int QueryDamType () { return QueryBurning() ? DT_FIRE : DT_BLUDGEON; }

/*----------------------------------------------------------------------------
** Description, Smell, Noise
*/

varargs string QueryShort() {
  string rc;
  rc = QueryFuel() > 0 ? "" : "the remains of ";
  return rc+::QueryShort();
}

varargs string Short() {
  string sh;

  sh = ::Short();
  if (QueryBurning())
    sh = "a burning "+strip_a(sh);
  return sh;
}

varargs string InvShort (string what) {
  return ::InvShort(what)+(QueryWielded()?" (wielded)":"");
}

varargs string QueryLong() {
  if (QueryBurning())
    return "A torch, burning with a smokeless flame.\n";
  else
    return "A longish piece of wood. Being lit, it would be a good torch.\n";
}

varargs string Long(string what) {
  string rc;
  int fuel, maxfuel;

  fuel = QueryFuel();
  maxfuel = QueryFuelMax();
  rc = ::Long();
  if (!TP || !({mixed})TP->QueryCmdData(SUBID))
  {
  if (fuel == maxfuel) rc += "It is brand new.\n";
  else if (fuel * 4 > maxfuel * 3) rc += "It's only slightly burned.\n";
  else if (fuel * 2 > maxfuel) rc += "It's burned down to nearly the half.\n";
  else if (fuel * 4 > maxfuel) rc += "Only a bit wood is left.\n";
  else if (fuel) rc += "It may go out every moment.\n";
  else rc =
 "In former times, this was a torch. But it has burned down and now it's just\n"
+"a small worthless piece of wood.\n";
  }
  return rc;
}

int SetFuel (int v) {
  int rc, old;
  old = QueryFuel();
  rc = ::SetFuel(v);
  if (rc <= 0 && old > 0)
  {
    RemoveId("torch");
    AddId(({"remains", "remains of torch", "remains of a torch"}));
  }
  else if (rc > 0 && old < 0)
  {
    AddId("torch");
    RemoveId(({"remains", "remains of torch", "remains of a torch"}));
  }
  return rc;
}

varargs string QuerySmell() {
  int fuel, maxfuel;

  fuel = QueryFuel();
  maxfuel = QueryFuelMax();
  if (QueryBurning())
    return "You smell the odour of burning pine wood.\n";
  if (fuel == maxfuel) return "You smell pine wood with a touch resine.\n";
  if (!fuel) return "It smells woody.\n";
  return "You smell a mixture of pine wood and cold ashes.\n";
}

varargs string QueryNoise() {
  if (QueryBurning())
    return "You hear a faint crackling from the burning wood.\n";
  return "You hear nothing.\n";
}

/*----------------------------------------------------------------------------
** Flicker during burning
*/

int BurnUp() {
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
      default: return 1;
    }
    pl = 0;
    if ((env=environment(THIS)) && interactive(env)) { /* We are carried */
      pl = env;
      tell_object (pl, msg);
      env = environment(pl);
    }
    if (env) tell_room (env, msge, ({ pl }));
  }
  return 0;
}

/****************************************************************************/
