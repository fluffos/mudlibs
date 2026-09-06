// a voodoo doll
// made by magictcs - 29 may 97
// configureable by some settings

// TODO: prick doll with needle into xxx
//       check for the into xxx !! (eyes,mouth,leg,...)
// reduce some amount HP if it is a player/npc near ?
// TODO: break needle after some tries!

#include <properties.h>
#include <search.h>
#include <moving.h>
#include <sykorath.h>

inherit "/std/container";

string name;
int num_needles;

//***************************************************
// set the name of the player/npc for the voodoo doll
//***************************************************
string SetVoodooName(string n) {
  if (n) name=n;
  return name;
}

string QueryVoodooName() { return name; }

//***********************
// special short and long
//***********************
string QueryShort() {
  if (name=="") return "a voodoo doll";
  return "a voodoo doll of "+name;
}

string QueryLong() {
  string ret;
  ret="It is a special doll - a voodoo doll.\n"
  "You can prick the doll with a special needle. Normally the magic works\n"
  "only if you are near the man for whom the doll is made.\n";
  if (name!="") ret+="It is a doll of "+name+".\n";
  else ret+=
    "You have to attach something of the man to the doll (for example some\n"
    "hair of the man?).\n"
    "You can cut some hair of a living to attach it to the doll.\n";
  if (num_needles==1)
    ret+="There is one needle pricking the doll.\n";
  if (num_needles>1)
    ret+="There are "+num_needles+" needles pricking the doll.\n";
  return ret;
}

//**************
// prick command
//**************
// prick doll with needle
int cmd_prick(string str) {
  string *exp;
  object needle,doll;
  notify_fail("Prick what with what?\n");
  if (!str) return 0;
  exp=explode(str," with ");              // search for 'with'
  if (sizeof(exp)!=2) return 0;
  // check for the needle:
  needle=TP->Search(exp[1],SEARCH_INV|SM_OBJECT);
  if (!needle) return 0;
  if (!(needle->id("vneedle"))) { 
    notify_fail("You need a special needle to do this.\n");
    return 0;
  }
  // okay needle is okay - but the doll?
  doll=TP->Search(exp[0],SEARCH_INV|SM_OBJECT);
  if (!doll) return 0;
  if (doll!=TO) return 0;       // maybe another doll?
  if (!(doll->id("vdoll"))) {
    notify_fail("You need a special voodoo doll to do this.\n");
    return 0;
  }
  // check for the name of the doll
  if (name=="") {
    write(
    "You prick the doll with the needle. Nothing happens, because this doll "
    "has nothing attached to it.\n");
    return 1;
  }
  if (!find_living(lower_case(name))) {
    write("You prick the doll with the needle, but nothing happens.\n"
      "Maybe "+CAP(name)+" is netdead? or not alive?\n");
    return 1;
  }
  write("You prick the "+exp[0]+" of "+name+" with the "+exp[1]+".\n"+
        name+" cries in pain.\n");
  shout(name+" cries in pain as "+NAME+
        " pricks the voodoo doll with a needle.\n");
  needle->move(TO,M_SILENT);
// reduce HP if it is a player/npc near???
  return 1;
}

//***************
// attach command
//***************
// attach hair|nail to doll
int cmd_attach(string str) {
  string *exp;
  object hair,doll;
  notify_fail("Attach what to what?\n");
  if (!str) return 0;
  exp=explode(str," to ");              // search for 'to'
  if (sizeof(exp)!=2) return 0;
  // check for the doll:
  doll=TP->Search(exp[1],SEARCH_INV|SM_OBJECT);
  if (!doll) return 0;
  if (doll!=TO) return 0;             // maybe another doll?
  if (!(doll->id("vdoll"))) { 
    notify_fail("You need a special voodoo doll to do this.\n");
    return 0;
  }
  // okay doll is okay - but the hair/nail ?
  hair=TP->Search(exp[0],SEARCH_INV|SM_OBJECT);
  if (!hair) return 0;
  if (!(hair->id("vhair") || hair->id("vnail"))) {
    notify_fail("You need something from a player/monster to do this.\n");
    return 0;
  }
  // check for the name of the doll
  if (name!="") {
    write(
    "This doll has already something attached to it. Buy a new clear doll!\n");
    return 1;
  }
  name=hair->QueryVoodooName();
  write("You attach "+exp[0]+" to the doll. It looks like a doll of "+name+
        " yet.\n");
  hair->remove();
  return 1;
}

//*************************
// cut hair from player/npc
//*************************
int cmd_cut(string str) {
  string *exp,hname;
  object who,hair;
  notify_fail("Cut what from whom?\n");
  if (!str) return 0;
  exp=explode(str," from ");              // search for 'from'
  if (sizeof(exp)!=2) return 0;
  if (exp[0]!="hair") {
    notify_fail("You can't cut "+exp[0]+" from "+exp[1]+".\n");
    return 0;
  }
  who=TP->Search(exp[1],SEARCH_ENV|SM_OBJECT);
  if (!who) return 0;
  if (!interactive(who)) {                 // players are allowed (ever)
    if (!who) {
      notify_fail(CAP(exp[1])+" isn't here!\n");
      return 0;
    }
    if (!(who->QueryIsLiving())) {
      write(CAP(exp[1])+" is not alive!\n");
      return 1;
    }
    if (who->QueryIsFollower() || who->QueryIsPet()) {
      write("You can't cut hair from "+who->QueryShort()+".\n");
      return 1;
    }
  }
  hname=CAP(who->QueryRealName());
  hair=clone_object(OBJ("vhair"));
  hair->SetVoodooName(hname);
  hair->move(TP,M_SILENT);                    // move without check!
  write("You cut some hair from "+hname+".\n");
  show(NAME+" cuts some hair from "+hname+".\n");
  return 1;
}


//****************
// create the doll
//****************
create() {
  ::create();
  name="";
  num_needles=0;
  SetHelpMsg("You can prick the doll with a special needle.\n");
  AddId(({"doll","vdoll"}));
  SetAds(({"voodoo","special"}));
  SetValue(random(34)+420);
  SetTransparency(0);     // not transparent !!
}

init() {
  ::init();
  add_action("cmd_prick","prick");
  add_action("cmd_attach","attach");
  add_action("cmd_cut","cut");
}

//***************************************
// enter/leave - only vneedles can enter!
//***************************************
int allow_enter(int method,mixed extra) {
  if (!PO) return 0;
  if (PO->id("vneedle")) { num_needles++; return ME_OK; }
  return 0;
}

notify_leave(object dest,int method,mixed extra) {
  if (!PO) return;
  if (PO->id("vneedle")) num_needles--;
}

