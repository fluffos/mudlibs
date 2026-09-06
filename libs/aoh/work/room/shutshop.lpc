/* The final shop for armageddon */
/* TODO: With full autoloading, this should no longer be necessary.
 * TODO:: If removed, update /obj/armageddon and /sys/stdrooms.h
 */

#include <stdrooms.h>

inherit "/std/shop";

varargs void create() {
  ::create();

  SetIntShort("Armageddon's Final Shop");
  SetIntLong(
    "You're in Armageddon's Final Shop near the end of the universe.\n"
    "A small corridor leads west into The Restaurant.\n");
  SetList(0);
  SetIdentify(0);
  SetAppraise(0);
  SetBuy(0);
  ForbidShopkeeper();
  SetLivingTrade(1);
  AddExit("west", RESTROOM);
  AddExit("east", STARTROOM);
}
