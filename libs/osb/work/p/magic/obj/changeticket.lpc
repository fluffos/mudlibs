// Written by Softbyte on 13.3.97
//
// This ticket will give you cheaper flights if you change a flight

#include <properties.h>

inherit "/std/thing";

string QueryLong()
{
string s;
  s=::QueryLong();
  s+="It is worth "+Query("ticketprice")+" coins.\n";
  return s;
}

void weg()
{
  write("The transfer flight ticket is now worthless.\n");
  remove();
}

int StartRemove()
{
  if (-1==find_call_out("weg")) call_out("weg",300);
  return 1;
}

create()
{
  ::create();
  if (!is_clone()) return;
  SetShort("a transfer flight ticket");
  SetLong(
"A small paper ticket which can be used as discount when changing carpet\n"
"lines.\n");
  AddId("ticket");
  AddId("transfereticket");
  AddId("changeticket");
  AddId("_changeticket");
  AddAdjective("paper");
  AddAdjective("small");
  AddAdjective("flight");
  AddAdjective("transfer");
  SetValue(0);
  Set(P_NOGET,1);
  Set(P_NODROP,1);
  Set(P_NOGIVE,1);
  Set(P_NOSELL,1);
  Set(P_NOBUY,1);
}
