// a shuriken
// introduced by magictcs - 21 may 97

#include <properties.h>
#include <moving.h>
#include <living.h>
#include <skills.h>
#include "/p/guilds/madmonks/madmonks.h"

int delay;

inherit "/std/unit";
inherit "/obj/lib/skills";               // skill usage

create() {
  ::create();
  delay=0;
  SetShort("shuriken");
  SetLong(
    "A small item, but a dangerous weapon. It is made of stainless steel.\n"
    "Some sharp edges can be seen. You can throw the shuriken at your\n"
    "enemies.\n");
  SetAmount(1);
  SetPluralLong(
    "Small items but dangerous weapons. They are made of stainless steel.\n"
    "Some sharp edges can be seen. You can throw the shuriken at your\n"
    "enemies.\n");
  AddId("shuriken");
  AddPluralId("shurikens");
  AddAdjective("small");
  SetValuePerUnit(10);
  SetWeightPerUnit(105);

  SetHelpMsg("Use: throw shuriken at <monster>\n");
  SetInfo("Be careful with these shuriken - they have very sharp edges!\n");
  AddSubDetail(({"edge","edges"}),
    "The edges of the shuriken look very dangerous!\n");
}

init() {
  ::init();
  add_action("throw_me","throw");
}

// some art of combat delay
void remove_delay() {
  delay=0;
}

//***********************
// throw shuriken at whom
//***********************
// TODO: add a special guild check for the madmonks!
// TODO: add using the throw-skill
int throw_me(string str) {
  string *exp;
  int percentage,mysk;
  object whom,ob;
  notify_fail("Throw what at whom?\n");
  if (!str) return 0;
  exp=explode(str," at ");              // search for 'at'
  if (sizeof(exp) != 2) return 0;       // no 'at' found
  if (exp[1] == "") return 0;           // no 'whom' found
  if (exp[0] != "shuriken") return 0;  // no shuriken to throw?
  if (environment() != TP) {
    notify_fail("First get the shuriken before throwing!\n");
    return 0;
  }
  whom=present(exp[1],ENV(TP));        // search whom
  if (!whom || !whom->QueryIsLiving()) {
    write(CAP(exp[1])+" isn't here!\n");
    return 1;
  }
  if (whom==TP) {                       // throw at yourself? nooo
    write("Throwing the shuriken at yourself??\n");
    return 1;
  }
  if (delay) {
    write("You need a little break before you can throw a shuriken again.\n");
    return 1;
  }
  // use throw Skill!
  mysk=50+TP->QueryStr()*4+TP->QueryDex()*5;
  if (mysk>800) mysk=800;
  if (UseSkill(TP,SK_THROW,mysk,&percentage)) {
    // whom contains the object which should be hit by the shuriken
    ob=SplitOff(1);                       // it's a unit :)
    if (ob) {
      if (ob->move(whom,M_SILENT) != ME_OK) {
        ob->move(ENV(whom),M_SILENT);
      }
      write("You throw a shuriken");
      show(NAME+" throws a shuriken.\n");
      whom->Defend(10+percentage/3,DT_PIERCE);
      delay=1;
      call_out("remove_delay",1);
      return 1;
    }
  } else {
    ob=SplitOff(1);                       // it's a unit :)
    if (ob) {                 // HMMM?? not working correctly?!
      ob->move(ENV(whom),M_SILENT);
      write("You throw a shuriken at "+CAP(exp[1])+" but miss him.\n");
      show(NAME+" throws a shuriken.\n");
      delay=1;
      call_out("remove_delay",1);
      return 1;
    }
  }
  notify_fail("Throw what at whom?\n");
  return 0;
}

