// hair from someone to attach it to a voodoo doll
// made by magictcs - 1 jun 97
// attach is implemented in the doll itself
// cut the same

#include <properties.h>
#include <sykorath.h>

inherit "/std/thing";

string name;                          // real name of someone

//*************
// SetVHairName
//*************
string SetVoodooName(string n) {
  if (n) name=n;
  return name;
}

string QueryVoodooName() { return name; }

//********************
// short/lpng handling
//********************
string QueryShort() {
  if (name=="") return "hair";
  return "hair of "+name;
}

string QueryLong() {
  if (name=="") return "Some useless hair.\n";
  return "Some hair of "+name+". You can attach it to an empty voodoo doll.\n";
}

create() {
  ::create();
  name="";
  SetHelpMsg("You can attach it to a voodoo doll.\n");
  SetValue(0);
  SetWeight(45);
  AddId(({"hair","vhair"}));
  AddAdjective(({"some","useless"}));
}

