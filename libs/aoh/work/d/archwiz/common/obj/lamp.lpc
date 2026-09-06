#include <config.h>
#include <lamp.h>
#include <properties.h>
#include <nightday.h>

inherit "std/lamp";

#define ME this_object()

create() {
  lamp::create();
  AddId("lamp");
  AddId("lantern");
  SetWeights(200,40);
  SetValues(1,1);
  SetFuelAmount(10+random(40));
  SetBrightness(REL_STATE(ND_DAWN,MAX_SUNBRIGHT));
  SetLampMsg(({"The lamp is already burning.\n",
  "The lamp isn't burning.\n","The lamp is burned down - you can't light it again.\n",
  "The lamp starts to burn.\n","@@Pl_Name@@ lights a lamp.\n","The lamp burnes out.\n",
  "@@Pl_Name@@ unlights @@Pl_Poss@@ lamp.\n","Your lamp flickers and goes out.\n",
  "@@Pl_Owner@@ lamp flickers and goes out.\n" }));
}

no_buy() { return burning; }

string QueryShort() {
  if (fuel) return "a "+(burning?"burning ":"")+"brass lantern";
  return "a used brass lantern";
}

string QueryLong() {
 string rc;
 if (burning) rc="A lamp burning with a smokeless flame.\n";
 else rc="A brass lantern. Maybe you can light it.\n";
 if (fuel==maxfuel) rc+="It has not been used yet.\n";
 else if (fuel*4>maxfuel*3) rc+="It's slightly burned.\n";
 else if (fuel*2>maxfuel) rc+="It's burned nearly down to the half.\n";
 else if (fuel*4>maxfuel) rc+="It's nearly empty.\n";
 else rc = "In former times this was brass lantern. But it has burned down now.\n";
 return rc;
}

string QuerySmell() {
 if (burning) return "You smell the odour of burning oil.\n";
 if (fuel==maxfuel) return "You smell oil.\n";
 if (!fuel) return "It dosn't smell.\n";
 return "You smell cold ashes.\n";
}

