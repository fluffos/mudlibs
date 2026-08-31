// /std/user/wealth.c
// Wealth management for livings
//
// Created:     2024/02/19: Gesslar
// Last Change: 2024/02/19: Gesslar
//
// 2024/02/19: Gesslar - Created

#include <wealth.h>
#include <daemons.h>
#include <gmcp_defines.h>
#include "/std/object/include/contents.h"

private nomask mapping __wealth = ([]);

int query_total_coins() {
  return sum(values(__wealth));
}

int query_total_wealth() {
  int total = 0;
  mixed *config = mud_config("CURRENCY");

  foreach(mixed *c in config)
    total += __wealth[c[0]] * c[1];

  return total;
}

mapping query_all_wealth() {
  return copy(__wealth);
}

int query_wealth(string currency) {
  return __wealth[currency];
}

mixed adjust_wealth(string currency, int amount) {
  int mass;

  if(nullp(__wealth))
    __wealth = ([]);

  if(!CURRENCY_D->valid_currency_type(currency))
    return "That is not a valid currency type.\n";

  if(amount < 0)
    if(__wealth[currency] - amount < 0)
      return "You don't have that many coins.\n";

  if(mud_config("USE_MASS")) {
    mass = amount;
    if(!can_hold_mass(mass))
      return "You are overburdened and cannot carry the coins.\n";
  }

  __wealth[currency] += amount;

  GMCP_D->send_gmcp(this_object(), GMCP_PKG_CHAR_STATUS, ([
    GMCP_LBL_CHAR_STATUS_WEALTH : ([ currency : sprintf("%d", __wealth[currency]) ])
  ]));

  rehash_capacity();

  return __wealth[currency];
}

mapping set_wealth(mapping w) {
  mixed *config = mud_config("CURRENCY");

  wipe_wealth();

  foreach(mixed *c in config) {
    if(!w[c[0]]) {
      w[c[0]] = 0;
      continue;
    }

    if(!adjust_wealth(c[0], w[c[0]]))
      w[c[0]] = 0;
  }

  rehash_capacity();

  return __wealth = w;
}

void init_wealth() {
  if(nullp(__wealth))
    __wealth = ([]);
}

void wipe_wealth() {
  __wealth = ([]);

  GMCP_D->send_gmcp(this_object(), GMCP_PKG_CHAR_STATUS, ([
    GMCP_LBL_CHAR_STATUS_WEALTH : ([ ])
  ]));

  rehash_capacity();
}
