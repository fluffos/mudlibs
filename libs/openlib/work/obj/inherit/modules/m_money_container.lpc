//  -*- LPC -*-
// m_money_container:  Functions for objects which contain money
//
// Copyright (C) 1996 Tim McIntosh (tmcintos@dm.imaginary.com)
//
// This program is part of the OpenLib Mudlib distribution; it
// is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// If you acquired this program as part of the OpenLib Mudlib
// distribution, you should have received a copy of the GNU
// General Public License in the file /doc/GPL; if not,
// write to the Free Software Foundation, Inc., 675 Mass Ave,
// Cambridge, MA 02139, USA.
//
// Orig by Tim 24 Apr 96
//

#include "m_money_container.h"

//
// Global Variables
//
private int* coins;                    // our money -- saves

void
initialize()
{
  coins = allocate(COIN_TYPES);
  for(int i = 0; i < COIN_TYPES; i++)
    coins[i] = 0;
}

/*
 * returns 1 if the money was received successfully
 */
nomask int
add_money(int *money)
{
  int weight;

  if( sizeof(money) < COIN_TYPES )
    return 0;

  weight += money[SILVER] / 18;
  weight += money[GOLD] / 6;

  if( weight + query_weight_contained() > query_weight_capacity() )
    return 0;

  for(int i = 0; i < COIN_TYPES; i++)
    coins[i] += money[i];

  return 1;
}

/*
 * makes change, returns 1 on success
 */
nomask int
remove_money(int *money)
{
  int remove_silver, remove_gold;

  if(sizeof(money) < COIN_TYPES)
    return 0;

  if( coins[SILVER] >= money[SILVER] ) {
    remove_silver = money[SILVER];
  } else {
    int gold_required, left_over;

    money[SILVER] -= coins[SILVER];

    gold_required = 1 + (money[SILVER] - 1) / ONE_GOLD_IN_SILVER;
    left_over = money[SILVER] % ONE_GOLD_IN_SILVER;

    if(coins[GOLD] >= gold_required + money[GOLD]) {
      coins[GOLD] -= gold_required + money[GOLD];
      coins[SILVER] = ONE_GOLD_IN_SILVER - left_over;
      return 1;
    } else {
      return 0;
    }
  }

  if( coins[GOLD] >= money[GOLD] ) {
    remove_gold = money[GOLD];
  } else {
    int silver_required;

    money[GOLD] -= coins[GOLD];

    silver_required = money[GOLD] * ONE_GOLD_IN_SILVER;

    if(coins[SILVER] >= silver_required) {
      coins[SILVER] -= silver_required + money[SILVER];
      coins[GOLD] = 0;
      return 1;
    } else {
      return 0;
    }
  }

  coins[GOLD] -= remove_gold;
  coins[SILVER] -= remove_silver;

  return 1;
}

nomask int*
query_money()
{
  return copy(coins);
}

/*
 * returns weight of coins contained
 */
int
query_weight_contained()
{
  int weight;

  // weight of coins
  weight += coins[SILVER] / 18;
  weight += coins[GOLD] / 6;

  return weight;
}
