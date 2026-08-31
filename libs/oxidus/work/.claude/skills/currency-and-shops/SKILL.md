---
name: currency-and-shops
description: Understand and work with the currency, wealth, transaction, shop, bank, coin, and loot-value systems in Oxidus. Covers the currency daemon, wealth tracking, transaction math, inventory-based shops (EXT_SHOP), menu-based shops (EXT_SHOP_MENU), the bank daemon, coin objects, and item values.
---

# Currency and Shops Skill

You are helping work with the Oxidus currency, wealth, and shop systems. Follow the `lpc-coding-style` skill for all LPC formatting.

## Architecture Overview

```
CURRENCY_D (adm/daemons/currency.lpc)     — currency registry, conversion
  |
  v
wealth.lpc (std/living/wealth.lpc)           — per-living coin storage
  |
  v
EXT_CURRENCY (std/ext/currency.lpc)        — transaction handling
  ├── EXT_SHOP (std/ext/shop.lpc)          — inventory-based shop (has storage object)
  └── EXT_SHOP_MENU (std/ext/shop_menu.lpc) — menu-based shop (clones on demand)

BANK_D (adm/daemons/bank.lpc)             — SQLite-backed bank accounts
  └── EXT_BANK (std/ext/bank.lpc)         — room commands for banking

LIB_COIN (lib/coin.lpc)                   — physical coin objects
STD_VALUE (std/object/value.lpc)           — item monetary value
LOOT_D (adm/daemons/loot.lpc)             — loot/coin drops on death
```

## Currency Configuration

From `adm/etc/default.lpml`:

```
CURRENCY: [
    ["copper",   1   ],
    ["silver",   10  ],
    ["gold",     100 ],
    ["platinum", 1000],
]
```

Each entry is `[name, value_in_base_units]`. Copper = 1 is the base denomination. **All internal values are in base (copper) units.**

Related config:

| Key | Default | Purpose |
|---|---|---|
| `USE_MASS` | `true` | Coins have physical weight |
| `COIN_VALUE_PER_LEVEL` | `15` | NPC loot coin value scaling |
| `COIN_VARIANCE` | `0.25` | 25% variance on loot values |
| `STORAGE_DATA_DIR` | `"/data/storage/"` | Persistent storage file path |

## Currency Daemon — `adm/daemons/currency.lpc`

Singleton daemon. Macro: `CURRENCY_D`.

| Function | Signature | Description |
|---|---|---|
| `valid_currency_type` | `int (string currency)` | Returns 1 if valid denomination |
| `convert_currency` | `int (int amount, string from, string to)` | Converts between denominations. Uses `amount * from_rate / to_rate`, rounded. Returns -1 on invalid. |
| `fconvert_currency` | `float (int amount, string from, string to)` | Same as above but returns raw float |
| `lowest_currency` | `string ()` | Returns `"copper"` |
| `highest_currency` | `string ()` | Returns `"platinum"` |
| `currency_list` | `string* ()` | Returns names ordered lowest to highest |
| `currency_value` | `int (string currency)` | Returns base-unit value of a denomination |
| `get_currency_map` | `mapping ()` | Returns `([ name: value, ... ])` copy |

## Wealth — `std/living/wealth.lpc`

Inherited by `STD_BODY`. Tracks coins as a mapping of `{ currency_name: count }`.

### Variable

```lpc
private nomask mapping _wealth = ([]);   // e.g., ([ "copper": 50, "gold": 3 ])
```

### Functions

| Function | Signature | Description |
|---|---|---|
| `query_total_coins` | `int ()` | Sum of all coin counts (ignores denomination) |
| `query_total_wealth` | `int ()` | Total value in base units. 1 gold + 5 copper = 105 |
| `query_all_wealth` | `mapping ()` | Safe copy of `_wealth` |
| `query_wealth` | `int (string currency)` | Count for a specific denomination |
| `adjust_wealth` | `mixed (string currency, int amount)` | **Returns int on success, string on error**. Validates currency, checks sufficient funds for negatives, checks mass capacity if `USE_MASS`. Sends GMCP. Calls `rehash_capacity()` |
| `set_wealth` | `mapping (mapping w)` | Replaces entire wealth. Wipes first, then adjusts each |
| `init_wealth` | `void ()` | Initializes to `([])` if null |
| `wipe_wealth` | `void ()` | Clears to `([])`, sends GMCP, rehashes capacity |

**Important:** `adjust_wealth` returns `mixed` — it can return an error string if the currency is invalid, funds are insufficient, or the player can't carry the weight. Always check the return type.

## Transaction Module — `std/ext/currency.lpc`

Macro: `EXT_CURRENCY`. Inherited by both shop modules.

### `handle_transaction(object tp, int cost) : mixed`

Entry point for all purchases. `cost` is in **base (copper) units**.

Returns either:
- `string` — error message
- `({ paid_array, change_array })` — success

Where each array contains `({ currency_name, amount })` pairs.

### Transaction Algorithm (`complex_transaction`)

1. Compute `total_wealth` in base units. Fail if insufficient.
2. Iterate denominations **highest to lowest**.
3. For each: take `min(available, ceil(remaining / rate))` coins.
4. If still short after first pass, retry lower denominations.
5. Compute change from overpayment, broken into fewest coins (highest to lowest).
6. Check mass capacity (net coin change vs available capacity).
7. Apply: `adjust_wealth(currency, -amount)` for each payment, `adjust_wealth(currency, amount)` for each change coin.

### `reverse_transaction(object tp, mixed result) : mixed`

**Critical for error recovery.** Reverses a completed transaction when a subsequent operation fails (e.g., item won't fit in inventory).

```lpc
// In a buy command:
mixed result = handle_transaction(tp, cost);
if(stringp(result)) return result;  // payment failed

if(stringp(ob->move(tp))) {
    reverse_transaction(tp, result);  // MUST reverse or coins are lost
    return "You can't carry that.";
}
```

### `least_coins(int total_amount) : mapping`

Breaks a base-unit amount into the minimum number of coins per denomination. Does **not** deduct anything — pure calculation.

```lpc
least_coins(125)  // → ([ "gold": 1, "silver": 2, "copper": 5 ])
```

Used by `EXT_SHOP`'s sell command to compute payout.

### Other Functions

| Function | Description |
|---|---|
| `format_return_currency_string(mixed *arr)` | Converts `({ ({"gold", 2}), ({"silver", 3}) })` to `"2 gold, 3 silver"` |
| `can_afford(object ob, int cost, string currency)` | Single-denomination check |
| `format_currency(int amount, string currency)` | Returns `"<amount> <currency>"` |

## Inventory-Based Shop — `std/ext/shop.lpc`

Macro: `EXT_SHOP`. Inherits `EXT_CURRENCY` and `CLASS_STORAGE`.

Items are stored in a persistent `STD_STORAGE_OBJECT`. Players buy items out of it and sell items into it.

### Setup Pattern

```lpc
inherit STD_ROOM;
inherit EXT_SHOP;

void setup() {
    // ... room descriptions, exits, etc. ...
    init_shop();
    add_shop_inventory(
        "/obj/weapon/piercing/rusty_sword",
        "/obj/armour/torso/leather_jerkin",
    );
}
```

### Variables

| Variable | Type | Default | Description |
|---|---|---|---|
| `shop_open` | `int` | `1` | Shop open/closed flag |
| `allow_npcs` | `int` | `0` | Whether NPCs can buy/sell |
| `sell_factor` | `float` | `0.5` | Multiplier on item value when selling |
| `store` | `object` | — | The storage object holding inventory |
| `shop_inventory` | `mixed*` | `({})` | Registered item files for restocking |

### Commands

**`buy <item>`**: Finds item in storage via `present(str, store)`. Calls `handle_transaction(tp, cost)`. Moves item to player. On move failure, calls `reverse_transaction`. Sends action messages.

**`sell <item>` / `sell all` / `sell all <item>`**: Finds items on player. For each: checks `query_cost(tp, ob, "sell")` (returns null to refuse), skips equipped items, moves to store, pays player via `least_coins(cost)` → `adjust_wealth()` per denomination.

**`list`**: Shows all items in storage with prices.

### Pricing — `query_cost()`

| Transaction | Price |
|---|---|
| `"buy"` | `ob->query_value()` |
| `"sell"` | `to_int(to_float(ob->query_value()) * sell_factor)` |
| `"list"` | `ob->query_value()` |

### Storage Object

Created via `create_storage()` using `class StorageOptions`:

```lpc
class StorageOptions {
    string storage_type;       // "public" or "private"
    mixed  storage_id;         // ID string or function
    string storage_org;        // namespace
    string storage_directory;  // filesystem path
    int    clean_on_empty;     // remove when empty
    int    restore_on_load;    // restore from saved data
}
```

The storage object has `ignore_capacity(1)` and `ignore_mass(1)` — no limits on stored items.

**Known issue:** `create_storage()` currently has a hardcoded `storage_org`. Each shop must override this or they share storage.

## Menu-Based Shop — `std/ext/shop_menu.lpc`

Macro: `EXT_SHOP_MENU`. Inherits `CLASS_MENU` and `EXT_CURRENCY`.

Items are **cloned fresh on each purchase**. No storage object. No sell command. Ideal for food, drink, and consumable vendors.

### Setup Pattern

```lpc
inherit STD_ROOM;
inherit EXT_SHOP_MENU;

void setup() {
    // ... room descriptions, exits, etc. ...
    init_shop();
    add_menu_item("food", "/obj/food/bread", 5);
    add_menu_item("drink", "/obj/drink/ale", 8);
}
```

### Menu Item Data — `class Menu`

```lpc
class Menu {
    string type;          // category (e.g., "food", "drink")
    string file;          // blueprint file path
    string short;         // display name
    string *id;           // ID array for matching
    string *adj;          // adjective array
    string description;   // long description
    int cost;             // price in base units
}
```

### Functions

| Function | Description |
|---|---|
| `add_menu_item(string type, string file, int cost)` | Loads blueprint, populates Menu class. Cost defaults to `ob->query_value()` if 0/null |
| `remove_menu_item(string file)` | Remove by file path |
| `wipe_menu()` | Clear all items |

### Commands

**`buy <item>`**: Searches `food_menu` by ID. Calls `handle_transaction`. Clones `new(item.file)`. Moves to player. Reverses on failure.

**`list` / `menu` [type]**: Shows all items or filtered by type with prices.

**`view <item>`**: Shows item short + long description.

## When to Use Which Shop

| Feature | EXT_SHOP | EXT_SHOP_MENU |
|---|---|---|
| Items persist between purchases | Yes (storage object) | No (cloned fresh) |
| Players can sell items back | Yes | No |
| Items are unique/individual | Yes | No (all identical clones) |
| Best for | Weapons, armor, gear | Food, drinks, consumables |
| Restocking | Via `reset_shop()` | Infinite (clone on demand) |

## Bank System

### Bank Daemon — `adm/daemons/bank.lpc`

SQLite-backed via `DB_D`. Stores a single balance in **base (copper) units**.

| Function | Signature | Description |
|---|---|---|
| `new_account` | `mixed (string name)` | Creates account with balance 0 |
| `query_balance` | `mixed (string name)` | Returns int balance, null if not found, or error string |
| `add_balance` | `mixed (string name, int amount)` | Adjusts balance (negative for withdrawals). Fails if result < 0 |
| `query_activity` | `mixed (string name, int limit)` | Returns activity log array. Default limit 10 |

### Bank Module — `std/ext/bank.lpc`

Macro: `EXT_BANK`. Provides room commands.

```lpc
inherit STD_ROOM;
inherit EXT_BANK;

void setup() {
    // ... room setup ...
    init_bank();
}
```

Commands: `register`, `deposit <num> <type>`, `withdraw <num> <type>`, `balance`.

**Key design:** Deposits convert denomination to copper for storage. Withdrawals convert copper back to the requested denomination. You can deposit 1 gold and withdraw 100 copper.

## Coin Objects — `lib/coin.lpc`

Physical coin items that exist in rooms and containers.

### Behavior

- **Moving to a living:** The coin object self-destructs and calls `dest->adjust_wealth(coin_type, coin_num)`. Coins dissolve into the wealth mapping.
- **Moving to a container:** Merges with existing same-type coin stacks via `adjust_coin_num()`. Different types coexist as separate objects.
- **Mass:** Each coin has mass equal to its count (`set_mass(num)`).

### Constructor

```lpc
new(LIB_COIN, "gold", 5)   // creates a stack of 5 gold coins
```

### Key Functions

| Function | Returns | Description |
|---|---|---|
| `query_coin_type()` | `string` | Denomination name |
| `query_coin_num()` | `int` | Stack size |
| `query_value()` | `({ coin_num, coin_type })` | **Returns array, NOT int** |
| `query_base_value()` | `int` | Total copper-equivalent value |
| `is_coin()` | `1` | Type identifier |
| `adjust_coin_num(int)` | `int` | Adjusts stack. Removes self if count reaches 0 |

**Critical:** `query_value()` on a coin returns `({ num, type })` — an array, not an integer. This intentionally differs from `STD_VALUE::query_value()` which returns `int`. Code handling mixed item types must account for this.

## Item Value — `std/object/value.lpc`

All items inherit this via `STD_ITEM`.

```lpc
set_value(50);       // 50 copper
query_value();       // 50
adjust_value(10);    // now 60 (but not auto-persisted!)
```

**Note:** `set_value()` calls `save_var("_value")` for persistence, but `adjust_value()` does not. Changes via `adjust_value()` are lost on reload unless `save_var` is called separately.

## Loot Value Calculation

When NPCs drop loot, `LOOT_D` can auto-value items:

```lpc
determine_value_by_level(level):
    value    = level * COIN_VALUE_PER_LEVEL (15)
    variance = COIN_VARIANCE (0.25) * value
    subtract = to_int(variance) / 2
    value   -= subtract
    value   += random(to_int(variance) + 1)
```

Level 10 NPC: base 150, range ~131-169 copper.

Triggered when a loot item has `query_loot_property("autovalue") == true`.

## GMCP Integration

Wealth changes send GMCP from `adjust_wealth()` and `wipe_wealth()`:

```
Package: "Char.Status"
Label:   "wealth"
Payload: ([ currency_name: sprintf("%d", amount) ])
```

No GMCP is sent directly by shop modules. Item movement triggers `GMCP_PKG_CHAR_ITEMS_LIST` via `STD_ITEM::move()`.

## Death and Wealth

On `die()` in `body.lpc`:

1. `query_all_wealth()` is iterated.
2. Each denomination becomes `new(LIB_COIN, type, amount)`.
3. Coin objects are moved to the corpse.
4. Player's wealth is effectively wiped (coins are now objects in the corpse).

## Gotchas

1. **All values are in base (copper) units internally.** `set_value(100)` means 100 copper = 1 gold. Shops, transactions, and bank all work in copper.
2. **`adjust_wealth()` can silently fail.** It returns a string on error (invalid currency, insufficient funds, over encumbrance). Always check the return type.
3. **`reverse_transaction()` is mandatory on buy failure.** If `handle_transaction` succeeds but the item can't be moved to the player, you must call `reverse_transaction` or coins are duplicated/lost.
4. **Two shop architectures serve different purposes.** `EXT_SHOP` for persistent inventory (gear shops). `EXT_SHOP_MENU` for clone-on-demand (food/drink vendors). Using `EXT_SHOP` for consumables causes persistent item accumulation.
5. **`query_value()` on coins returns an array, not int.** Code that handles mixed items must check for this.
6. **`adjust_value()` does not persist.** Only `set_value()` calls `save_var()`.
7. **Bank stores copper internally.** Deposit 1 gold, withdraw 100 copper — this is by design.
8. **The complex_transaction algorithm can over-draw from higher denominations**, producing non-optimal change. This is a known limitation.
