/*  mail/port_box.c
 *  Mon Nov  2 20:10:05 MET 1992 Pepel
 *  THU:27.06.92  THU=Orcgrimm@Nightfall
 */

#include <properties.h>

inherit "/mail/dpost";

varargs void create() {
  dpost::create();
  SetIds(({"mailbox", "portable mailbox"}));
  SetShort("a portable mailbox");
  SetAds(({"new","portable"}));
  SetWeight(0);
  SetNoGet(0);
  SetNoGive(1);
  SetNoDrop(1);
  Set(P_AUTOOBJECT, 1);
}
