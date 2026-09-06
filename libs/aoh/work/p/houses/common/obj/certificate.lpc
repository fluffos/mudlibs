/* The certificate for a property */

#include <properties.h>
inherit "/std/thing";

create()
{
  ::create();
  SetIds(({"certificate","cert","property certificate"}));
  Set(P_NODROP,"You won't loose your property, want you?\n");
  Set(P_NOSELL,"You won't loose your property, want you?\n");
  Set(P_NOGIVE,"You won't loose your property, want you?\n");
}

QueryShort() { return Query(P_AUTOOBJECT)[0]; }

QueryLong() { return Query(P_AUTOOBJECT)[1]; }
