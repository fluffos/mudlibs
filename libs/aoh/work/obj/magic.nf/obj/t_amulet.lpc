#include <properties.h>
#include <config.h>
#include <combat.h>

inherit "/std/armour";

int teleport;

create() {
    (::create());
    SetShort("a mysterious amulet");
    SetLong("\
This amuletis shaped like a gold coin. There is something written\n\
on it. Maybe you should read it.\n");
    SetIds(({"amulet","teleport amulet","mysterious amulet","tportamulet"}));
    SetWeight();
    SetValue(50);
    SetAC(0);
    SetNoDrop("You don't dare to drop this item\n");
    Set(P_READ_MSG,"You read:\n\
This amulet allows you to be teleported by other players.\n\
To use its special powers type\n\
- amulet on:    to give others the possibility to teleport you.\n\
- amulet off:   to forbid others to teleport you.\n\
- amulet check: tells you if the amulet is switched on or off.\n\
Use its powers wisely.\n");
    Set(P_AUTOOBJECT,1);
    SetArmourType(AT_AMULET);
    teleport=0;
    "/obj/lib/register"->RegisterCreator(this_object(),"Magic_Remove");
}

init() {
  (::init());
  add_action("amulet","amulet");
}

amulet(string str) {
  if (!str) { 
    retype();
    return 0; }
  if (str=="on") {
    teleport=1;
    write("You switched your teleport amulet on.\n\
Other players can now teleport you.\n");
    return 1; }
  if (str=="off") {
    teleport=0;
    write("You switched your teleport amulet off.\n\
Now no one can teleport you.\n");
    return 1;}
  if (str=="check") {
    if(teleport) {
      write("Your teleport amulet is switched on.\n\
Other players can teleport you.\n");
      return 1;}
    write("Your teleport amulet is switched off.\n\
No one can teleport you.\n");
    return 1;}
  retype();
  return 1;
}

int QueryTeleport() {
  return teleport;
}

/* glow can be called by the item/spell that tries to teleport
   the owner of the amulet. */
varargs glow(object me, string name, string item) {
  tell_object(me,"Your amulet starts to glow.\n\
It seems as if "+capitalize(name)+" tried to teleport you away.\n");
  if(item) {
    tell_object(me,capitalize(name)+" used a "+item+" for this try.\n");
    return 1;
  }
  return 1;
}


retype() {
  write("You tried to do something senseless with the teleport amulet.\n\
To use its special powers type\n\
- amulet on:    to give others the possibility to teleport you.\n\
- amulet off:   to forbid others to teleport you.\n\
- amulet check: tells you if the amulet is switched on or off.\n\
Use its powers wisely.\n");
  return 1;
}
