// This file is used by /lib/grammar via call_other. Don't clone it
// or use it elsehwere! Carador, Aug-1996

#include <money.h>
#include <limits.h>

inherit MONEY_OBJECT;

void create()
{
  if ( clonep() ||
       load_name(previous_object()) != "lib/grammar"
     ) {
    call_out(#'destruct, 0, this_object());
    return;
  }

  MONEY_OBJECT::create();
  set_amount(([
    SILVER   : DUMMY_ALL,
    COPPER   : DUMMY_ALL,
    GOLD     : DUMMY_ALL,
    PLATINUM : DUMMY_ALL,
    MITHRIL  : DUMMY_ALL,
  ]));
}
