// Last change : Softbyte 05apr97

#include <properties.h>
#include <moving.h>
#include <secure/wizlevels.h>

inherit "/std/thing";

#define VERSION "V 0.91"
#define TP      this_player()

create()
{
  if (::create()) return;
  Set(P_INFO,"TET - Teleport Example Tool");
  SetShort("TET "+VERSION);
  SetLong(
"You are watching at the TET - the Teleport Example Tool - of the "
"Magic Departement (TM).\n"
"The tool understands following commands:\n"
"show destinations | dests\n"
"\tShows the filenames of the destinations.\n"
"jump <number>\n"
"\tJump to the destination with the number <number>\n"
"\t0 < number < 5\n"
"\n");
  SetIds(({"tet","tool"}));
  SetAds(({"teleport","example"}));
  SetNoGive("You are not be able to give examples away.\n");
  SetNoDrop(1);
  Set(P_NOSELL, "The example has mentally values only.\n");
}

QueryLong(string str) {
  string ret;
  ret = ::QueryLong(str)+"\
Your TET reacts on the ids:\n"+
  implode(sort_array(QueryIds(),#'>),", ")+"\n"; /* '));*/
  return ret;
}  

init() {
  (::init());
  if (!IS_IMMORTAL(TP)) 
    return 0;
  add_action("show","show");
  add_action("jump","jump");
}

show(string what) {
  int i;
  
  if (!what ||
      (what != "destination" &&
       what != "dests")) {
    notify_fail("Usage: show destinations | dests\n");
    return 0;
  }
  write("Here are the stored destinations for the TET:\n");
  for (i=1;i<5;i++) {
    printf("Destination %d: /p/magic/example/rooms/teleport/t%d.c\n", i, i);
  }
  return 1;
}

jump(string where) {
  string dest;
  string OldMMsgOut;
  string OldMMsgIn;
  int move_result;
  
  if (!where &&
      to_int(where) < 1 &&
      to_int(where) > 4) {
    notify_fail("Usage: jump <number>\t0 < number < 5");
    return 0;
  }

  dest = "/p/magic/example/rooms/teleport/t"+where;

  OldMMsgOut = TP->QueryMMsgOut();
  OldMMsgIn = TP->QueryMMsgIn();

  TP->SetMMsgOut("vanishes with a teleport.");
  TP->SetMMsgIn("arrives with a teleport.");

  move_result = TP->move(dest, M_TELEPORT);

  TP->SetMMsgIn(OldMMsgIn);
  TP->SetMMsgOut(OldMMsgOut);

  switch (move_result) {
  case ME_NO_LEAVE:
    notify_fail("You can't leave this room with teleport.\n");
    return 0;
  case ME_NO_ENTER:
    notify_fail("You can't enter the destination with teleport.\n");
    return 0;
  }
  return 1;
}
