---
name: combat-system
description: Understand and work with the combat system in Oxidus. Covers the attack loop, hit-chance formula, damage pipeline, threat tracking, defense/AC, procs, vitals/regen, death sequence, XP/advancement, NPC combat behavior, and combat memory.
---

# Combat System Skill

You are helping work with the Oxidus combat system. Follow the `lpc-coding-style` skill for all LPC formatting.

## Architecture Overview

```
body.lpc
  └── combat.lpc          — attack loop, threat, hit chance, AC, defense
        └── damage.lpc     — deliver/receive damage formulas

vitals.lpc                 — HP/SP/MP, regen, condition strings
advancement.lpc            — per-living XP/level state
npc.lpc                    — NPC heartbeat, death detection, setLevel override
proc.lpc (module)          — weapon proc system
combat_memory.lpc (module) — NPC "remember and attack on sight"

advance.lpc (daemon)       — TNL formula, killXp, earnXp, advance
death.lpc (daemon)         — signal listener for SIG_PLAYER_DIED/REVIVED
```

### Inheritance Chain

```
body.lpc → combat.lpc → damage.lpc
npc.lpc  → body.lpc (STD_BODY)
```

## Combat Round Loop

`combat_round()` is called via `call_out_walltime` at intervals of `_attack_speed + random_float(1.5)` seconds (base speed default: `2.0`).

```
combat_round()
  ├── clean_up_enemies()         — remove dead/gone enemies
  ├── highest_threat() → enemy   — pick target with most accumulated threat
  ├── valid_enemy(enemy)         — must be in same room and alive
  ├── swing(1, 0)                — execute attack(s)
  ├── GMCP Char.Status update    — current_enemy, current_enemy_health, current_enemies
  └── next_round()               — schedule next combat_round
```

### Multi-Strike Logic (`swing`)

Each swing checks for a dual-wield opportunity:

```lpc
if(random(100) < 5 + query_skill("combat.melee"))
    multi = 1;  // next recursive call uses off-hand weapon
```

When `multi` is set, a random weapon from non-main-slot weapons is used. The function recurses with decremented count.

MP is checked before each swing — if `query_mp() <= 0.0`, the attacker is "too exhausted" and the swing is skipped.

## Hit Chance Formula — `can_strike()`

```lpc
float chance = mudConfig("DEFAULT_HIT_CHANCE");   // 65.0

if(enemy->query_mp() < 0.0)
    chance += 25.0;    // exhausted enemies are easier to hit

chance = chance
    + (attacker_level - defender_level)          // effective levels
    + attacker_skill_level                       // weapon skill (query_skill_level)
    - (defender_ac * 2.0)                        // armor class doubled
    - defender_defense_skill_level;              // dodge or evade skill

result = random_float(100.0);
enemy->use_skill(defense_skill);   // defender trains defense on every attempt
return result < chance;
```

**Skill routing by weapon type:**

| Weapon | Attacker Skill | Defender AC | Defender Skill |
|--------|---------------|-------------|----------------|
| Object or unarmed | `"combat.melee.<damage_type>"` | `query_ac()` | `"combat.defense.dodge"` |
| Spell (string contains `".spell."`) | spell skill name | `query_spell_ac()` | `"combat.defense.evade"` |
| Other string skill | skill name | `query_spell_ac()` | `"combat.defense.dodge"` |

## Damage Formula — `strike_enemy()`

```lpc
base     = percent_of(5.0, enemy->query_max_hp());   // 5% of enemy max HP
variance = percent_of(25.0, base);                     // 25% of that
base    -= variance;
base    += random_float(variance);                     // restore 0..variance randomly

if(enemy->query_mp() < 0.0)
    base += 4.0;    // bonus vs exhausted

dam = base
    + query_effective_level()                          // attacker level
    - enemy->query_effective_level()                   // defender level
    + skill                                            // attacker weapon skill level
    - enemy->query_defense_amount(weapon_type)         // type-specific armor reduction
    - enemy->query_skill_level("combat.defense");      // generic defense skill

if(dam < 0.0) dam = 1.0;   // minimum 1 damage
```

After calculating damage:
1. Combat messaging via `MESS_D->get_message("combat", wtype, to_int(ceil(dam)))` and `ACTION_D->action(...)`.
2. `deliver_damage(enemy, dam, wtype)` — dispatches to enemy.
3. `adjust_mp(-random_float(5.0))` — each swing costs 0-5 MP.
4. `add_threat(enemy, dam)` — threat grows by damage dealt.
5. Weapon proc check: `weapon->can_proc()` then `weapon->proc(name, self, enemy)`.

## Damage Reception — `receive_damage()`

```lpc
def = query_defense_amount(type);         // type-specific armor value
red = percent_of(def, damage);            // def% of damage is reduced

mod = mudConfig("DAMAGE_LEVEL_MODIFIER"); // 25
level_difference = attacker_level - defender_level;
mod = mod * level_difference;
red -= percent_of(mod, damage);           // level gap reduces/increases armor effectiveness

damage -= red;
if(damage < 0.0) damage = 0.0;
```

Then applies `adjust_hp(-damage)` and sets `last_damaged_by` / `killed_by` as appropriate.

**Level modifier effect:** Higher-level attackers reduce the defender's armor effectiveness. Lower-level attackers increase it.

## Threat System

Threat values start at `1.0` on `start_attack()` and grow by damage dealt.

| Function | Description |
|---|---|
| `add_threat(ob, float)` | Increments `_current_enemies[ob]` |
| `add_seen_threat(ob, float)` | Increments `_seen_enemies[ob]` (persists across rounds) |
| `highest_threat()` | Returns enemy with highest threat — combat target |
| `lowest_threat()` | Returns enemy with lowest threat |

`_current_enemies` is the active combat mapping. `_seen_enemies` tracks all-time threat.

## Defense / AC System — `adjust_protection()`

Called whenever equipment changes. Rebuilds `_defense` and `_ac` from all equipped items:

```lpc
mapping adjust_protection() {
    // iterates query_equipped() values
    // sums ob->query_defense() mappings into _defense per damage type
    // sums ob->query_ac() into _ac
}
```

| Function | Description |
|---|---|
| `query_ac()` | Returns aggregated `_ac` float |
| `query_defense_amount(string type)` | Returns `_defense[type]` for a specific damage type |
| `set_defense(mapping)` | Directly sets `_defense` |
| `add_defense(string type, float amount)` | Adds a single type entry |

## Starting and Stopping Combat

### `start_attack(object victim)`

1. Adds victim to `_current_enemies` with threat `1.0`.
2. Adds to `_seen_enemies`.
3. For NPCs: `module("combat_memory", "add_to_memory", victim)`.
4. Schedules `combat_round` via `call_out_walltime`.
5. Calls `victim->start_attack(this_object())` — mutual engagement.

### `stop_all_attacks()`

Cancels combat call out, clears `_current_enemies`, sends GMCP clear.

### `prevent_combat(object victim)`

Returns error string if:
- `victim->query_peaceful()` is set
- `victim->query_no_combat()` is set
- `environment()->query_no_combat()` is set

Returns `1` if combat is allowed.

## NPC Weapon Properties

Used when the NPC has no wielded weapon object:

| Function | Default | Description |
|---|---|---|
| `set_damage(float)` | `0.0` | Base damage. If `<= 0`, uses `random_float(queryLevel() * 2.0)` |
| `set_weapon_name(string)` | `"fist"` | Display name for combat messages |
| `set_weapon_type(string)` | `"bludgeoning"` | Damage type string |

`query_weapon_info(weapon)` transparently handles both real weapon objects and NPC defaults, returning `([ "name", "type", "skill", "base" ])`.

## Weapon Proc System — `std/modules/proc.lpc`

Weapons inherit this module to add special effects on hit.

### Proc Data Structure

```lpc
_procs[name] = ([
    "function" : string | function,   // required
    "cooldown" : int,                  // seconds, default 1
    "weight"   : int,                  // selection weight, default 100
    "chance"   : int,                  // optional per-proc chance override
])
```

### Key Functions

| Function | Description |
|---|---|
| `add_proc(string name, mixed proc)` | Register a proc (mapping, string, or function) |
| `set_procs(mixed *procs)` | Batch add: `({ ({ name, proc }), ... })` |
| `set_proc_chance(float)` | Global proc chance, 0.0-100.0 (default 15.0) |
| `can_proc()` | Called by `strike_enemy`. Filters by cooldown, selects via `element_of_weighted`. Returns proc name or false |
| `proc(string name, mixed args...)` | Executes the proc function with `(attacker, victim)` args. Records cooldown |

### Integration

```lpc
// In strike_enemy():
if(weapon && weapon->is_weapon())
    if(stringp(proc = weapon->can_proc()))
        weapon->proc(proc, this_object(), enemy);
```

## Vitals — `std/living/vitals.lpc`

### Variables

All `private nomask float`, defaults `100.0`:

| Variable | Description |
|---|---|
| `hp` / `max_hp` | Hit points |
| `sp` / `max_sp` | Spirit/mana points |
| `mp` / `max_mp` | Movement/stamina points |
| `dead` | `int`, death flag |

### Query Functions

`query_max_hp()`, `query_max_sp()`, `query_max_mp()` all add boon modifiers unless called with `raw = 1`:

```lpc
return max_hp + query_effective_boon("vital", "max_hp");
```

`hp_ratio()`, `sp_ratio()`, `mp_ratio()` return percentage floats.

### Regen — `heal_tick()`

- Fires every `regen_interval_pulses` heartbeats (default: 10 pulses).
- **Suppressed during combat** (`in_combat()` check).
- Rates come from race module: `module("race", "query_regen_rate")`.
- Human defaults: HP +2.0, SP +2.0, MP +4.0 per tick.
- No race module = no regen.

### Condition Strings

`query_condition_string()` returns `({ hp_string, sp_string, mp_string })`:

**HP:** "dead" (0) → "critical" (10) → "severely injured" (30) → "moderately injured" (45) → "injured" (60) → "hurt" (75) → "wounded" (90) → "bruised and nicked" (<100) → "healthy" (100)

**SP:** "brain dead" (5) → "depleted" (15.5) → ... → "fully charged" (100)

**MP:** "exhausted" (5) → "sluggish" (15.5) → ... → "full of stamina" (100)

## Death Sequence — `body.lpc::die()`

Death is detected in the NPC heartbeat:

```lpc
if(!is_dead() && query_hp() <= 0.0) {
    set_dead(1);
    die();
}
```

### `die()` Flow

1. `stop_all_attacks()` — clear combat state
2. SU body ejection (if a developer is possessing this body)
3. `simple_action("$N $vhave perished.")` — room message
4. `save_body()` — persist player state
5. `emit(SIG_PLAYER_DIED, this_object(), killed_by())` — signal
6. Create corpse: `new(LIB_CORPSE)` → `corpse->setup_corpse(self, killer)`
7. Loot drop: `LOOT_D->loot_drop(killed_by(), self)` if `query_loot_table` exists
8. Coin drop: `LOOT_D->coin_drop(killed_by(), self)` if `query_coin_table` exists
9. Move all inventory to corpse
10. Move all wealth to corpse (converted to coin objects)
11. Move corpse to room
12. **Player path:** `BODY_D->create_ghost(privs)`, `exec(ghost, self)`, move ghost to room
13. **NPC path:** `ADVANCE_D->killXp(killed_by(), self)` — award XP to killer
14. `remove()` — destroy this object

## XP and Advancement — `adm/daemons/advance.lpc`

### TNL Formula

```lpc
toNextLevel(level) = to_int(baseTnl * pow(tnlRate, level - 1.0))
// Default: to_int(100 * 1.25^(level-1))
```

| Level | TNL |
|---|---|
| 1 | 100 |
| 2 | 125 |
| 5 | 244 |
| 10 | 931 |
| 20 | ~8674 |

### Kill XP Formula

```lpc
xp       = toNextLevel(killed_level) / 10;    // 10% of killed NPC's TNL
variance = xp / 10;
xp       = xp - variance + random(variance);  // +/- 10% random

level_diff = killer_level - killed_level;

if(level_diff > 5)      // overlevel
    factor -= 0.05 * (level_diff - 5);    // -5% per level over threshold
else if(level_diff < 0) // underlevel
    factor += 0.05 * (-level_diff);       // +5% per level under

xp = to_int(xp * factor);
```

If `PLAYER_AUTOLEVEL` is true (default), `advance()` is called immediately after XP award.

### Config Constants

| Key | Default | Used In |
|---|---|---|
| `DEFAULT_HIT_CHANCE` | `65` | `can_strike()` |
| `DAMAGE_LEVEL_MODIFIER` | `25` | `receive_damage()` |
| `BASE_TNL` | `100` | `toNextLevel()` |
| `TNL_RATE` | `1.25` | `toNextLevel()` |
| `OVERLEVEL_THRESHOLD` | `5` | `killXp()` |
| `OVERLEVEL_XP_PUNISH` | `0.05` | `killXp()` |
| `UNDERLEVEL_THRESHOLD` | `0` | `killXp()` |
| `UNDERLEVEL_XP_BONUS` | `0.05` | `killXp()` |
| `PLAYER_AUTOLEVEL` | `true` | `earnXp()` |
| `HEART_PULSE` | `2000` | regen interval |
| `HEARTBEATS_TO_REGEN` | `5` | regen interval |
| `DEFAULT_HEART_RATE` | `10` | NPC heartbeat |

## NPC Combat Behavior — `std/living/npc.lpc`

### Heartbeat

NPCs only tick when players are present:

```lpc
void start_heart_beat() {
    if(player_check())
        set_heart_beat(mudConfig("DEFAULT_HEART_RATE"));
}

void stop_heart_beat() {
    if(!player_check() && query_hp() >= 100.0)
        set_heart_beat(0);
}
```

Heartbeat loop: `clean_up_enemies()` → `cooldown()` → death check → `heal_tick()` → `evaluate_heart_beat()` → `process_boon()`.

### Combat Memory Module

Automatically added to all NPCs. Remembers enemy names.

On init (player enters room), if target name is in memory:

```lpc
void attack_on_sight(object target) {
    if(of(name, combat_memory)) {
        query_owner()->start_attack(target);
        query_owner()->strike_enemy(target);   // immediate free strike
        query_owner()->strike_enemy(target);   // second free strike
    }
}
```

Memory is populated from `combat.lpc::start_attack()`:

```lpc
if(!userp())
    module("combat_memory", "add_to_memory", victim);
```

## GMCP Events

| Package | When | Fields |
|---|---|---|
| `Char.Status` | Every combat round | `current_enemy`, `current_enemy_health` ("%.2f" ratio), `current_enemies` |
| `Char.Status` | Combat ends | `current_enemy: ""`, `current_enemies: ({})` |
| `Char.Vitals` | Every `adjust_hp/sp/mp` | `hp`, `sp`, `mp` (as "%.2f") |
| `Char.Status` | Level/XP changes | `xp`, `tnl`, `level` |

## Signals

| Signal | When | Payload |
|---|---|---|
| `SIG_PLAYER_DIED` | `die()` after corpse creation | `(self, killed_by)` |
| `SIG_PLAYER_REVIVED` | External revival | `(self)` |
| `SIG_PLAYER_ADVANCED` | `advance()` on level-up | `(tp, new_level)` |

## Combat Skill Names

| Skill | Used In |
|---|---|
| `"combat.melee"` | Multi-strike chance in `swing()` |
| `"combat.melee.<type>"` | Hit/damage formulas (`can_strike`, `strike_enemy`) |
| `"combat.melee.unarmed"` | Unarmed fallback |
| `"combat.defense.dodge"` | Melee defense in `can_strike()` |
| `"combat.defense.evade"` | Spell defense in `can_strike()` |
| `"combat.defense"` | Generic defense reduction in `strike_enemy()` |

## Attack Speed

| Function | Description |
|---|---|
| `set_attack_speed(float)` | Directly sets base speed |
| `add_attack_speed(float)` | Adjusts, clamped to `[0.5, 10.0]` |
| `query_attack_speed()` | Returns `_attack_speed` |

Actual interval per round = `_attack_speed + random_float(1.5)` seconds.

## Gotchas

1. **Death is detected in heartbeat, not in `receive_damage`**. The `dead` flag is set in `npc.lpc::heart_beat()` when `query_hp() <= 0.0`. There can be a brief window between HP hitting zero and `die()` firing.
2. **No regen during combat.** `heal_tick()` returns immediately if `in_combat()`.
3. **NPCs stop ticking in empty rooms.** No heartbeat = no regen, no boon processing, no AI. Developers expecting continuous background behavior need to understand this.
4. **`query_skill()` vs `query_skill_level()`**: For NPCs, `query_skill()` returns `queryLevel() * 3.0` (shortcut), but `query_skill_level()` reads stored values. Combat formulas use `query_skill_level()`.
5. **`setLevel()` on NPCs wipes skills**: `npc.lpc::setLevel()` calls `adjust_skills_by_npc_level()` which resets all stored skill levels to near-zero.
6. **Proc `_proc_chance` field is maintained but not rolled against** in `can_proc()` — the actual selection uses per-proc cooldowns and `element_of_weighted`.
7. **Threat is accumulated damage**, not an abstract aggro value. `highest_threat()` targets whoever has dealt the most damage to this living.

## Timed Abilities: async_act

Abilities with a wind-up use `async_act()` on the body — the async counterpart
of `act()` in `std/living/act.lpc`. It registers an ordinary act, so
`is_acting()` reports it and `cancel_act()` / `cancel_acts()` still interrupt
it; what changes is that the outcome arrives as a promise rather than a
callback:

```lpc
private async void strike(object tp, object victim) {
  mixed err = acatch {
    if(!await tp->async_act("punch", 2.0))
      return;                                   // interrupted

    if(!same_env_check(tp, victim))
      return;

    if(tp->can_strike(victim)) {
      float damage = percent_of(25.0, tp->query_damage());

      tp->targetted_action("$N $vpunch $t!", victim);
      tp->deliver_mundane_damage(victim, damage, "bludgeoning");
      tp->use_skill("combat.melee.unarmed");
    } else {
      tp->targetted_action("$N $vtry to punch $t, but $vmiss.", victim);
      victim->use_skill("combat.defence.dodge");
    }

    victim->start_attack(tp);
  };

  if(err)
    debug_message(`punch: ${err}\n`);
}
```

The promise fulfils with **1** if the act ran to completion and **0** if it was
cancelled — which is what makes walking out of the room abandon the blow, since
`move()` calls `cancel_acts()`. Treat a `0` as "silently abandon", not as a
failure to report.

`cmds/ability/punch.lpc` is the worked example. `use()` must stay synchronous
and call the helper without awaiting — see the `command-creation` skill for why.
The older `delay_act(action, delay, assemble_call_back(...))` form still works
and several spells use it; the difference is that the async form keeps `tp` and
`victim` in lexical scope instead of threading them through the callback array.

Two interruptions exist and they are not interchangeable. `cancel_act()`
interrupts **the act**, fulfilling the promise with `0` so the awaiting body
handles it normally — that is the one the game world uses. `promise_cancel()`
interrupts **the awaiting body**, raising at its next `await`. See the
`async-promises` skill.
