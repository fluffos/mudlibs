#include <config.h>
#include <lamp.h>
#include <properties.h>
#include <nightday.h>

inherit "std/lamp";

#define ME this_object()

create() {
  lamp::create();
  AddId("stick");
  SetWeights(200,40);
  SetValues(1,1);
  SetFuelAmount(10+random(20));
  SetBrightness(REL_STATE(ND_DAWN,MAX_SUNBRIGHT));
  SetLampMsg(({"The stick is already burning.\n",
  "The stick isn't burning.\n","The stick is burned down - you can't light it again.\n",
  "The stick starts to burn.\n","@@Pl_Name@@ lights a stick.\n","The stick burnes out.\n",
  "@@Pl_Name@@ unlights @@Pl_Poss@@ torch.\n","Your stick flickers and goes out.\n",
  "@@Pl_Owner@@ stick flickers and goes out.\n" }));
}

no_buy() { return burning; }

QueryValue() {
   return 0;
}

string QueryShort() {
  if (fuel) return "a "+(burning?"burning ":"")+"stick";
  return "the remains of a stick";
}

string QueryLong() {
 string rc;
 if (burning) rc="A stick burning with a smokeless flame.\n";
 else rc="A longish piece of wood. Being lit, it would be a good torch.\n";
 if (fuel==maxfuel) rc+="It has not been used yet.\n";
 else if (fuel*4>maxfuel*3) rc+="It's slightly burned.\n";
 else if (fuel*2>maxfuel) rc+="It's burned nearly down to the half.\n";
 else if (fuel*4>maxfuel) rc+="Only a small pice of wood is left.\n";
 else rc = "In former times this was a stick. But it has burned down now.\n";
 return rc;
}

string QuerySmell() {
 if (burning) return "You smell the odour of burning oak wood.\n";
 if (fuel==maxfuel) return "You smell dried oak wood.\n";
 if (!fuel) return "It smells woody.\n";
 return "You smell cold ashes.\n";
}

