/* /std/corpse
**
** The default corpse to rot away.
**
**  16-Jan-94 [Mateese]
*/

#include <properties.h>
#include <msgclass.h>
#include <classes.h>

inherit "/std/container";
// TODO: inherit food so the corpse is eatable.

#define ENV environment

/*-------------------------------------------------------------------------*/

public void DoDecay (int justschedule);  // forward

/*-------------------------------------------------------------------------*/

nosave int pDecaytime;  // Time for one decaystep.
nosave int pDecay;      // State of decay (0 is 'fresh');
nosave int pPreserved;  // The corpse might be in preserved state
nosave string pName;    // The name of the former living
nosave string pRace;    // The race of the former living

/*-------------------------------------------------------------------------*/

public int SetDecayTime (int t)  { return pDecaytime = (t > 0) ? t : 120; }
public int QueryDecayTime ()     { return pDecaytime; }
public int SetDecay (int d)      { return pDecay = d; }
public int QueryDecay ()         { return pDecay; }
public int SetPreserved(int p) {
  pPreserved = (p != 0) ? 1 : 0;
  SetDecay(-1);
  if (pPreserved)
    while (remove_call_out("DoDecay") != -1);
  return pPreserved;
}
public int QueryPreserved ()     { return pPreserved; }

/*-------------------------------------------------------------------------*/

public string SetRace (string name)  { return pRace = name; }
public string QueryRace ()           { return pRace;}

public string SetName (string name) {
  pName = name;
  SetShort("corpse of "+name);
  SetLong("This is the dead body of "+capitalize(name)+".\n");
  AddId("corpse of "+lower_case(name));
  SetDecay(0);
  SetSmell("The corpse smells terrible!\n");
  return name;
}
public string QueryName () { return pName;}

/*-------------------------------------------------------------------------*/

public void DoDecay (int justschedule) {
  while (remove_call_out("DoDecay") != -1);
  if (!justschedule)
  {
    pDecay++;
    if (pDecay == 1) {
      SetShort("the somewhat decayed remains of "+QueryName());
      SetLong("This is the dead body of "+QueryName()+".\n"
             +"In fact, it has been dead for quite a time already.\n");
      SetSmell("The corpse smells worse now, the stench is becoming overwhelming.\n");
      if (ENV())
        show_room( ENV()
                 , ({ "The corpse of "+QueryName()+" is very rotten now.\n"
                    , "You smell something very rotten.\n" })
                 );
    }
    else if (pDecay > 1) {
      if (ENV())
        show_room( ENV()
                 , ({ "The remains of a corpse rot away.\n"
                    , "Something rotten is somehow gone.\n" })
                 );
      remove();
      return;
    }
  }
  if (pDecay >= 0)
    call_out("DoDecay", QueryDecayTime());
}

/*-------------------------------------------------------------------------*/

public void create() {
  "container"::create();
  AddId(C_CORPSE);
  AddId("remains");
  SetDecayTime(120);
  SetDecay(-1);
  SetPreserved(0);
  Set(P_HELP_MSG, "");
}

/*************************************************************************/
