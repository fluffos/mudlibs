---
title: Currency
description: Denominations, conversion, wealth storage, and transactions.
---

The currency system defines the game's denominations, converts between them, stores each living's coins, and processes purchases. Everything is built on a single rule: **all internal values are held in base units** -- the value of the lowest denomination.

## The Currency Model

Denominations are configured as an array of `[name, value]` pairs in `adm/etc/default.lpml`. The first entry is the base denomination, worth 1:

```lpml
CURRENCY: [
  ["copper",   1   ],
  ["silver",   10  ],
  ["gold",     100 ],
  ["platinum", 1000],
]
```

With this configuration copper is the base unit, so 1 gold is stored internally as 100 and 1 platinum as 1000. The currency daemon (`CURRENCY_D`) reads this through `CONFIG_D` -- see [Configuration](/systems/config/). If you change the `CURRENCY` array, run the `master` command to rehash.

Related tuning keys: `COIN_VALUE_PER_LEVEL` and `COIN_VARIANCE` control auto-valued [loot](/systems/loot/) drops, and `USE_MASS` decides whether coins carry physical weight.

## Currency Daemon

`CURRENCY_D` is the registry and conversion authority. It exposes:

| Function | Signature | Description |
|---|---|---|
| `valid_currency_type(currency)` | `int` | Whether `currency` is a known denomination |
| `convert_currency(amount, from, to)` | `int` | Convert between denominations (rounded); `-1` on invalid input |
| `fconvert_currency(amount, from, to)` | `float` | Same conversion, returned as a raw float for fractional values |
| `currency_value(currency)` | `int` | Base-unit value of a denomination |
| `currency_list()` | `string *` | Denomination names, lowest to highest |
| `lowest_currency()` / `highest_currency()` | `string` | The cheapest / most valuable denomination |
| `get_currency_map()` | `mapping` | A copy of `([ name: value, ... ])` |

```lpc
int plat = convert_currency(1000, "copper", "platinum");  // 1
```

## Wealth

Each living's coins are stored by `std/living/wealth.c` (inherited by `STD_BODY`) as a mapping of denomination to count, e.g. `([ "copper": 50, "gold": 3 ])`. Key functions:

| Function | Returns | Description |
|---|---|---|
| `query_wealth(currency)` | `int` | Count of one denomination |
| `query_all_wealth()` | `mapping` | A copy of the whole wealth mapping |
| `query_total_wealth()` | `int` | Total value in base units (1 gold + 5 copper = 105) |
| `query_total_coins()` | `int` | Total coin count, ignoring denomination |
| `adjust_wealth(currency, amount)` | `mixed` | Add or remove coins -- **returns an error string on failure** |
| `set_wealth(w)` / `wipe_wealth()` | — | Replace or clear all wealth |

`adjust_wealth()` is the one to watch: it validates the denomination, refuses to go negative, and -- when `USE_MASS` is on -- checks that the living can carry the coins. It returns an `int` on success but a `string` on any of those failures, so always check the return type before assuming the adjustment happened.

## Transactions

Purchases go through the `EXT_CURRENCY` module (`std/ext/currency.c`), which both shop types inherit. The entry point takes a cost in base units:

```lpc
mixed handle_transaction(object tp, int cost)
```

It returns either an **error string**, or a success result of `({ paid, change })` where each is an array of `({ currency, amount })` pairs. Internally it draws coins from highest to lowest denomination, makes change from any overpayment, and verifies the net coin change fits the buyer's carry capacity.

Because payment and item delivery are two steps, error recovery is mandatory. If the payment succeeds but the item cannot be delivered, you **must** reverse the payment or coins are lost:

```lpc
mixed result = handle_transaction(tp, cost);
if(stringp(result))
  return result;                      // payment failed

if(stringp(ob->move(tp))) {
  reverse_transaction(tp, result);    // undo the payment
  return "You can't carry that.";
}
```

Supporting helpers include `least_coins(total)` (break an amount into the fewest coins, without deducting anything), `can_afford(ob, cost, currency)`, and the formatters `format_currency()` and `format_return_currency_string()`.

## Coins as Objects

Physical coins in rooms and containers are `LIB_COIN` objects (`lib/coin.c`), created as `new(LIB_COIN, "gold", 5)`. When a coin object moves onto a living it destroys itself and folds its value into that living's wealth via `adjust_wealth()`; in a container, same-type coins merge into one stack. Note that `query_value()` on a coin returns `({ num, type })` -- an array, not the `int` that ordinary items return.

## Key Files

| File | Role |
|---|---|
| `adm/daemons/currency.c` | `CURRENCY_D` -- denomination registry and conversion |
| `std/living/wealth.c` | Per-living coin storage |
| `std/ext/currency.c` | `EXT_CURRENCY` -- transaction handling |
| `lib/coin.c` | `LIB_COIN` -- physical coin objects |
| `adm/etc/default.lpml` | `CURRENCY` denomination configuration |
