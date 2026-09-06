/* std/lamp.c
**
** A standard lamp.
** Since there may be many lamps, this object must be inherited by a
** wrapper object which provides all the hooks and descriptions.
** This lamp will burn at a constant bright and then unlight.
** For a slow degradation overload BurnUp().
**
** This object is based on the /std/lightsource of Miril.
**
**   29-Aug-92 [Mateese] Creation
**   31-Aug-92 [Mateese] New property system.
**   13-Aug-92 [Mateese] New light system
**   16-Sep-92 [Mateese] Fixed the emission of messages/
**   11-Aug-94 [Mateese] Messages may now be closures, nicened it.
*/

#include <config.h>
#include <lamp.h>
#include <properties.h>
#include <search.h>
#include <classes.h>

inherit "/std/thing";

#define BURN_UP_INTERVAL 300

#define THIS    this_object()
#define TP      this_player()
#define FAIL(s)    return (notify_fail(s, NOTIFY_NOT_OBJ) && 0)
#define FAILARG(s) return (notify_fail(s, NOTIFY_NOT_VALID) && 0)

/*--------------------------------------------------------------------------*/

nosave int maxfuel, fuel, bright, burning, interval;
nosave int basevalue, fuelvalue;
nosave int baseweight, fuelweight;
nosave mixed *lamp_msg, fueltype;

/*----------------------------------------------------------------------------
** Initialize us - default is a torch
*/

void create(){
  int i;

  thing::create();
  AddClassId(C_LAMP);
  lamp_msg = allocate(PLM_MAX_MSGS);
  for (i=0; i<PLM_MAX_MSGS; lamp_msg[i++]="");
  bright = 1;
  interval = BURN_UP_INTERVAL;
}

void init() {
  thing::init();
  add_action("flight", "light");
  add_action("funlight", "unlight");
  add_action("funlight", "extinguish");
}

/*--------------------------------------------------------------------------
** Properties
*/

public int SetFuelMax (int v) { return maxfuel = v; }
public int QueryFuelMax () { return maxfuel; }

public int SetFuel (int v) {
  if (v > 0)
    AddClassAdj(CA_BURNABLE);
  else
    RemoveClassAdj(CA_BURNABLE);
  return fuel = v;
}
public int QueryFuel () { return fuel; }

public int SetFuelWeight (int v) { return fuelweight = v; }
public int QueryFuelWeight () { return fuelweight; }

public int SetFuelValue (int v) { return fuelvalue = v; }
public int QueryFuelValue () { return fuelvalue; }

public mixed SetFuelType (mixed v) { return fueltype = v; }
public mixed QueryFuelType () { return fueltype; }

public int SetLampWeight (int v) { return baseweight = v; }
public int QueryLampWeight () { return baseweight; }

public int SetLampValue (int v) { return basevalue = v; }
public int QueryLampValue () { return basevalue; }

public int SetBurnStep (int v) { return interval = v; }
public int QueryBurnStep () { return interval; }

public int SetBrightness (int v) { return bright = v; }
public int QueryBrightness () { return bright; }

public mixed * SetLampMsg (mixed * v) { return lamp_msg = v; }
public mixed * QueryLampMsg () { return lamp_msg; }

public varargs int QueryValue() { return basevalue + fuel * fuelvalue; }
public int SetValue(int v) { return QueryValue(); }
public varargs int QueryWeight() { return baseweight + fuel * fuelweight; }
public int SetWeight(int w) { return QueryWeight(); }

public int QueryBurning () { return burning; }
public int SetBurning (int v) {
  int left, i, fuel;
  object env;

  while ((i = remove_call_out("BurnUp")) >= 0)
    left = i;
  if (!burning && v) {
    call_out("BurnUp", QueryBurnStep());
    SetBright(QueryBrightness());
    AddAdjective("burning");
  }
  if (burning && !v) {
    if (left >= 0 && left * 2 < QueryBurnStep()) {
      SetFuel(fuel = QueryFuel()-1);
      if (fuel >= 0 && (env = environment(THIS)))
        env->AddWeight(-QueryFuelWeight());
    }
    SetBright(0);
    RemoveAdjective("burning");
  }
  return burning = v;
}

/*----------------------------------------------------------------------------
** Handle the lamp messages.
*/

public mixed LampMsg (int i) {
  mixed lmsg;

  lmsg = lamp_msg[i];
  if (closurep(lmsg))
    lmsg = funcall(lmsg, i);
  if (stringp(lmsg))
    lmsg = process_string(lmsg);
  return lmsg;
}

/*----------------------------------------------------------------------------
** Burn down, every interval seconds a bit.
** Return 1 if light is still on.
*/

public int BurnUp () {
  object env, pl;
  int fuel;
  mixed lmsg;

  if (!QueryBurning())
    return 0;

  if (env = environment(THIS))
    env->AddWeight(-QueryFuelWeight());

  SetFuel(fuel = QueryFuel()-1);

  if (fuel > 0 && QueryBurning()) {
    while(remove_call_out("BurnUp") >= 0);
    call_out( "BurnUp", interval);
    return 1;
  }
  if (env && interactive(env)) { /* We are carried */
    pl = env;
    if (lmsg = LampMsg(PLM_BURNED_UP))
      tell_object(pl, lmsg);
    env = environment(pl);
  }
  if (env && (lmsg = LampMsg(PLM_BURNED_UP_E)))
    show_room(env, lmsg, ({ pl }));
  SetBurning(0);
  SetFuel(0);
  return 0;
}

/*----------------------------------------------------------------------------
** Simple interface
*/

public void SetLMsg (int index, string msg) { lamp_msg[index] = msg; }

public varargs void SetWeights (int lweight, int fweight) {
  SetLampWeight(lweight);
  SetFuelWeight(fweight);
}

public varargs void SetValues (int lvalue, int fvalue) {
  SetLampValue(lvalue);
  SetFuelValue(fvalue);
}

public varargs void SetFuelAmount (int current, int max) {
  if (!max) max = current;
  SetFuelMax(max);
  SetFuel(current);
}

/*----------------------------------------------------------------------------
** Command 'light'
*/

public varargs int flight (string str, int where) {
  mixed lmsg;

  if (!str || -1 == member(({mixed})TP->Search(str, where|SEARCH_IGNLIGHT)||({}), THIS))
    FAIL(capitalize(query_verb())+" what?\n");

  if (burning)
    FAILARG(LampMsg(PLM_IS_BURNING) || "It already burns.\n");

  if (!fuel)
    FAILARG(LampMsg(PLM_NO_FUEL) || "You fail.\n");
  if (lmsg = LampMsg(PLM_LIGHT))
    write(lmsg);
  if (lmsg = LampMsg(PLM_LIGHT_E))
    show(lmsg);
  SetBurning(1);
  return 1;
}

/*----------------------------------------------------------------------------
** Command 'unlight'
*/

public varargs int funlight (string str, int where) {
  mixed lmsg;

  if (!str || -1 == member(({mixed})TP->Search(str, where|SEARCH_IGNLIGHT)||({}), THIS))
    FAIL(capitalize(query_verb())+" what?\n");

  if (!burning)
    FAILARG(LampMsg(PLM_IS_DARK) || "It doesn't burn.\n");
  if (lmsg = LampMsg(PLM_UNLIGHT))
    write(lmsg);
  if (lmsg = LampMsg(PLM_UNLIGHT_E))
    show(lmsg);
  SetBurning(0);
  return 1;
}

/*----------------------------------------------------------------------------
** For simple process_string()s, return the players name and gender_stuff
*/

string Pl_Owner() {
  object pl;
  if ((pl = environment(THIS)) && interactive(pl))
    return capitalize(({string})pl->QueryName())+"'s";
  return "a";
}
string Pl_Name() { return ({string})this_player()->QueryName(); }
string Pl_Pro() { return ({string})this_player()->QueryPronoun(); }
string Pl_Poss() { return ({string})this_player()->QueryPossessive(); }
string Pl_Obj() { return ({string})this_player()->QueryObjective(); }

/****************************************************************************/
