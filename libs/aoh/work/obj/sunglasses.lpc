/* /obj/sunglasses
**
** Generic sunglasses. Only one can be worn at a time.
** They must be worn to have effect.
**
** Use the builtin properties "DeltaUVision", "DeltaIVision" to adjust 
** the absorbtion. 'SetDelta()' sets both values at once.
** The default absorbtion is 'one half sunbright'.
** The builtin property 'Worn' also wears/removes the sunglasses.
** The glasses id as 'glasses' and 'sunglasses'. Don't change the latter.
**
**  11-Oct-92 [Mateese]
**  12-Feb-95 [Mateese] Adapted for /obj/equipment instead of /std/armour.
*/

#include <config.h>
#include <attributes.h>
#include <secure/wizlevels.h>
#include <search.h>

inherit "/obj/equipment";

#define PL this_player()
#define ME this_object()

nosave int deltaiv, deltauv;

/*--------------------------------------------------------------------------*/

void create () {
  ::create();
  SetShort("a pair of sunglasses");
  SetLong("A pair of sunglasses.\n");
  Set(P_HELP_MSG,
"Sunglasses protect sensitive eyes from too much light. "
"When worn, of course.\n"
     );
  SetWeight(100);
  SetValue(1);
  SetIds( ({ "glasses", "sunglasses" }) );
  deltaiv = deltauv = MAX_SUNBRIGHT/2;
}

/*--------------------------------------------------------------------------
** Actually (un)wear the glasses.
*/

varargs void NotifyWear (object liv, object this, int flags)
{
  if (!living(liv)) return;
  liv->ModifyAttr(A_IVISION, deltaiv);
  liv->ModifyAttr(A_UVISION, deltauv);
  // write ("You wear "+QueryShort()+".\n");
  // show ((string)owner->QueryName()+" wears "+QueryShort()+".\n");
}

varargs void NotifyUnwear (object liv, object this, int flags)
{
  if (!living(liv)) return;
  liv->ModifyAttr(A_IVISION, -deltaiv);
  liv->ModifyAttr(A_UVISION, -deltauv);
  // write ("You remove "+QueryShort()+".\n");
  // show ((string)owner->QueryName()+" removes "+QueryShort()+".\n");
}

/*--------------------------------------------------------------------------
** Set/Query the absorbtion values.
** Using the functions allows setting even when wearing the glasses.
*/

int QueryDeltaUVision () { return deltauv; }
int SetDeltaUVision (int v) { 
  int delta;
  object owner;
  if (v < 0) return deltauv;
  if (owner = QueryWorn()) {
    delta = v - deltauv;
    owner->ModifyAttr(A_UVISION, delta);
    owner->AddBonus (A_IVISION, delta);
  }
  return deltauv = v; 
}

int QueryDeltaIVision () { return deltaiv; }
int SetDeltaIVision (int v) {
  int delta;
  object owner;
  if (v < 0) return deltaiv;
  if (owner = QueryWorn()) {
    delta = v - deltaiv;
    owner->ModifyAttr(A_IVISION, delta);
    owner->AddBonus(A_IVISION, delta);
  }
  return deltaiv = v; 
}

varargs void SetDelta (int duv, int div) {
  if (!div) div = duv;
  SetDeltaUVision (duv);
  SetDeltaIVision (duv);
}

/****************************************************************************/
