---
name: skills-and-advancement
description: Understand and work with the skill tree and advancement systems in Oxidus. Covers the nested skill tree, dot-path addressing, use-based improvement, the query_skill / query_raw_skill / query_skill_level / query_raw_skill_level API grid, has_skill existence checks, boon integration, XP, TNL formula, leveling, attributes, and how skills interact with combat and NPCs.
---

# Skills and Advancement Skill

You are helping work with the Oxidus skill and advancement systems. Follow the `lpc-coding-style` skill for all LPC formatting.

## Architecture Overview

```
skills.lpc (std/living/skills.lpc)           — nested skill tree, use-based improvement
advancement.lpc (std/living/advancement.lpc) — per-living XP/level state
advance.lpc (adm/daemons/advance.lpc)        — TNL formula, kill_xp, earn_xp
attributes.lpc (std/living/attributes.lpc)   — STR/DEX/CON/INT/WIS/CHA
boon.lpc (std/living/boon.lpc)               — buff/debuff modifiers on skills and vitals
```

All of these are inherited by `STD_BODY` and apply to both players and NPCs.

## Skill System — `std/living/skills.lpc`

### Storage Structure

Skills are a **nested tree**, not a flat mapping:

```lpc
skills = ([
    "combat": ([
        "level": 3.47,
        "subskills": ([
            "melee": ([
                "level": 2.15,
                "subskills": ([
                    "slashing": ([ "level": 4.82, "subskills": ([]) ]),
                    "piercing": ([ "level": 1.03, "subskills": ([]) ]),
                    "bludgeoning": ([ "level": 2.60, "subskills": ([]) ]),
                    "unarmed": ([ "level": 1.55, "subskills": ([]) ]),
                ]),
            ]),
            "defense": ([
                "level": 1.90,
                "subskills": ([
                    "dodge": ([ "level": 3.21, "subskills": ([]) ]),
                    "parry": ([ "level": 1.10, "subskills": ([]) ]),
                ]),
            ]),
        ]),
    ]),
])
```

Dot notation addresses nodes: `"combat.melee.slashing"` navigates the tree.

The **integer part** of the level is the effective skill level. The **fractional part** is progress toward the next level (0-99%).

A private `find_skill_node(string skill)` helper walks the dot-path and returns the live node mapping (or 0). Every read/leaf-mutate function delegates to it — `add_skill` and `remove_skill` keep their own walks because they need creation / parent-ref semantics.

### Default Skill Tree (from config)

```
combat
  defense: dodge, parry
  melee: attack, bludgeoning, piercing, slashing, unarmed
social: barter, charm, intimidate, persuade
general: appraise, hide, jump, listen, search, spot, swim
```

Full dot-path examples: `"combat.melee.slashing"`, `"combat.defense.dodge"`, `"social.barter"`, `"general.swim"`.

### Key Functions

| Function | Signature | Description |
|---|---|---|
| `add_skill` | `int (string skill, float level)` | Creates skill at dot-path. Intermediates created at level 1.0. **Does not overwrite existing nodes.** Returns 1 on success |
| `remove_skill` | `int (string skill)` | Removes leaf node |
| `has_skill` | `int (string skill)` | Returns 1 if the node exists, 0 otherwise. Use this for existence checks instead of `nullp(query_raw_skill(...))` |
| `query_raw_skill` | `float (string skill)` | Raw float level — no flooring, no boon |
| `query_skill` | `float (string skill)` | Raw float level + boon modifier |
| `query_raw_skill_level` | `float (string skill)` | `floor(level)` — no boon |
| `query_skill_level` | `float (string skill)` | `floor(level)` + `query_effective_boon("skill", skill)`. The function combat math uses |
| `set_skill_level` | `int (string skill, float level)` | Sets exact float level. Requires intermediates to already exist; will not create them |
| `query_skills` | `mapping ()` | Returns a copy of the entire tree |
| `set_skills` | `void (mapping s)` | Replaces the tree wholesale (no-op if `s` is not a mapping) |
| `use_skill` | `int (string skill, mixed mod_adjust)` | 20% chance per call to call `improve_skill(skill, mod_adjust)`. `mod_adjust` raises the per-call progress cap for low-frequency callers. Auto-creates the skill if missing |
| `improve_skill` | `float (string skill, mixed potential_progress)` | Default cap `0.01` via `(: 0.01 :)` syntax. See improvement algorithm below |
| `query_skill_progress` | `int (string skill)` | Fractional part of the level as a 0-99 integer |
| `modify_skill_level` | `int (string skill, int level)` | Replace level with an int. Like `set_skill_level` but accepts int and doesn't enforce a minimum |
| `assure_skill` | `int (string skill)` | Creates at level 1.0 if missing, tells the player they gained a new skill |
| `wipe_skills` | `void ()` | Resets to empty mapping |
| `initialize_missing_skills` | `void (mapping, string)` | Creates any missing skills from a config-shaped tree |
| `adjust_skills_by_npc_level` | `int (float level)` | NPC-only: seeds every skill in the tree to `level * 3.0` so `query_skill_level()` is honest for combat math. Errors if called on a user |

### Use-Based Improvement

Players improve skills transparently by using them — no skill points or manual allocation.

```lpc
varargs int use_skill(string skill, mixed mod_adjust) {
    if(has_skill(skill)) {
        if(random_float(100.0) < 20.0)          // 20% chance per use
            improve_skill(skill, mod_adjust);
    } else {
        assure_skill(skill);                     // auto-create at level 1.0
    }
}
```

`use_skill()` is called throughout the codebase:
- Combat: attacker trains weapon skill after each swing, defender trains defense skill on every hit attempt.
- Any system can call `use_skill("general.swim")` etc. to trigger organic improvement.

**`mod_adjust`** raises the per-call progress cap above the 0.01 default. Use it for low-frequency call sites (specific spells, niche abilities) where the default would feel painfully slow. Pattern: `tp->use_skill("combat.spell.light", 0.15);`. Hot paths (combat swings, defense checks) should omit it. **All nodes on the path share the same cap** — the bubble-up doesn't tighten it, so pick `mod_adjust` values that are reasonable for parents too.

### Improvement Algorithm

`improve_skill(string skill, mixed potential_progress)`:

1. Coerces `potential_progress` to a float — accepts omitted/null (defaults to 0.01 via FluffOS's `(: 0.01 :)` default-functional syntax, resolved at the call boundary), `float` (as-is), `int` (promoted), or a functional (evaluated against `this_object()`).
2. Builds the dot-path's `chances` mapping: each node's weight is `(depth+1)*3`. For a 3-segment path: leaf 50%, middle 33%, root 17%.
3. Picks one node via `element_of_weighted(chances)`.
4. Applies `random_float(progress)` to that node's level.
5. If the floored level rises, notifies the player: `"You have improved your X skill."`

This means using `"combat.melee.slashing"` can also improve `"combat.melee"` or `"combat"` — but with lower probability. **Parent skills grow organically as their children are used, but more slowly because they are picked less often.** Every node on the path uses the same cap; bubble-up balance lives entirely in the pick weights — that's the lever to tune if balance ever feels off.

### Query API Grid

Four query functions form an orthogonal grid over two axes: floored vs raw float, and with-boon vs without-boon.

|         | Raw float                      | Floored (combat math)                |
|---------|--------------------------------|--------------------------------------|
| No boon | `query_raw_skill(s)` → 3.47    | `query_raw_skill_level(s)` → 3.0     |
| + boon  | `query_skill(s)` → 3.47 + boon | `query_skill_level(s)` → 3.0 + boon  |

Pick by what the call site actually wants:

- **Hit/damage formulas** → `query_skill_level()`. Combat math.
- **Proc rolls / scaling on fractional progress** → `query_raw_skill()` (e.g. multi-strike in `swing()`) or `query_skill()` if buffs should help.
- **Existence check** → `has_skill(s)` — returns 1 or 0. Do not use `nullp(query_raw_skill(...))` for this.

All four functions return `null` if the skill is not found. NPCs and players read the same storage — there is no NPC shortcut. NPCs are seeded at `level * 3.0` at setup time so the storage is honest for both through the same code path.

### Boon Integration

The `query_skill` and `query_skill_level` variants add the effective boon modifier:

```lpc
// query_skill_level
return floor(level) + query_effective_boon("skill", skill);
// query_skill
return level + query_effective_boon("skill", skill);
```

Where `query_effective_boon("skill", "combat.melee.slashing")` = sum of boons minus sum of curses for that skill class+type. See the `buff-system` skill for details on applying boons. Use the `query_raw_*` variants when you explicitly want to bypass boons (e.g. introspection commands, raw progression UI).

### Skills Used by the Combat System

| Skill | Where Used |
|---|---|
| `"combat.melee"` | Multi-strike chance in `swing()` (uses `query_skill_level` — floored level + boons) |
| `"combat.melee.<type>"` | Hit chance and damage formulas |
| `"combat.melee.unarmed"` | Unarmed combat fallback |
| `"combat.defense.dodge"` | Melee defense in hit chance |
| `"combat.defense.evade"` | Spell defense in hit chance |
| `"combat.defense"` | Generic defense reduction in damage formula |

## XP and Advancement

### Per-Living State — `std/living/advancement.lpc`

| Variable | Type | Default | Description |
|---|---|---|---|
| `__level` | `float` | `1.0` | Current level |
| `__level_mod` | `float` | `0.0` | Temporary level modifier (boons / curses) |
| `__xp` | `int` | `0` | Accumulated experience points |

### Functions

| Function | Signature | Description |
|---|---|---|
| `query_xp` | `int ()` | Returns `__xp` |
| `query_level` | `float ()` | Returns `__level` |
| `query_effective_level` | `float ()` | Returns `__level + __level_mod`. Used throughout combat math |
| `query_tnl` | `float ()` | Returns `ADVANCE_D->to_next_level(__level)` |
| `set_level` | `float (float l)` | Sets `__level`. Sends GMCP `Char.Status` if user |
| `adjust_level` | `float (float l)` | Adds delta to `__level`. Sends GMCP if user |
| `query_level_mod` | `float ()` | Returns the temporary modifier |
| `set_level_mod` | `float (float l)` | Sets the temporary modifier (routes through `adjust_level_mod`) |
| `adjust_level_mod` | `float (float l)` | Adjusts modifier by delta |
| `adjust_xp` | `int (int amount)` | Adds delta to `__xp`. Sends GMCP if user |
| `set_xp` | `int (int amount)` | Sets `__xp` to `amount` via `adjust_xp(amount - __xp)` |
| `on_advance` | `void (object tp, float l)` | Slot for `SIG_PLAYER_ADVANCED`. Tells the player they have advanced |

### Advancement Daemon — `adm/daemons/advance.lpc`

Config constants:

| Key | Default | Description |
|---|---|---|
| `BASE_TNL` | `100` | XP for level 1 to 2 |
| `TNL_RATE` | `1.25` | Geometric multiplier per level |
| `PLAYER_AUTOLEVEL` | `true` | Auto-advance on XP gain |
| `OVERLEVEL_THRESHOLD` | `5` | Levels above target before XP penalty |
| `OVERLEVEL_XP_PUNISH` | `0.05` | -5% per level over threshold |
| `UNDERLEVEL_THRESHOLD` | `0` | Levels below target for XP bonus |
| `UNDERLEVEL_XP_BONUS` | `0.05` | +5% per level under threshold |

### TNL Formula

```lpc
to_next_level(level) = to_int(baseTnl * pow(tnlRate, level - 1.0))
// Default: to_int(100 * 1.25^(level-1))
```

| Level | TNL | Level | TNL |
|---|---|---|---|
| 1 | 100 | 10 | 931 |
| 2 | 125 | 15 | 2842 |
| 5 | 244 | 20 | ~8674 |

### `advance(object tp)`

1. Checks `can_advance(xp, level)` — is XP >= TNL?
2. Deducts TNL from XP.
3. Increments level by 1.0.
4. Emits `SIG_PLAYER_ADVANCED` signal with `(tp, new_level)`.
5. Returns 1.

### Kill XP Formula — `kill_xp(object killer, object killed)`

```lpc
xp       = to_next_level(killed_level) / 10;  // 10% of killed NPC's TNL
variance = xp / 10;
xp       = xp - variance + random(variance);  // ±10% random

level_diff = killer_level - killed_level;

if(level_diff > 5)      // overlevel
    factor -= 0.05 * (level_diff - 5);    // -5% per level over threshold
else if(level_diff < 0) // underlevel
    factor += 0.05 * (-level_diff);       // +5% per level under

xp = to_int(xp * factor);
```

Called from `body.lpc::die()` for NPC deaths only. If `PLAYER_AUTOLEVEL` is true, `advance()` is called immediately after XP award.

### `earn_xp(object tp, int amount)`

Calls `tp->adjust_xp(amount)`. If `PLAYER_AUTOLEVEL`, calls `advance(tp)`. The general-purpose XP award function.

## Attributes — `std/living/attributes.lpc`

Default attributes (from config): `"strength"`, `"dexterity"`, `"constitution"`, `"intelligence"`, `"wisdom"`, `"charisma"`. All initialized to `5`.

| Function | Signature | Description |
|---|---|---|
| `set_attribute` | `int (string key, int value)` | Set directly. Returns new value or null if invalid key |
| `get_attribute` | `int (string key, int raw)` | Returns `value + query_effective_boon("attribute", key)`. If `raw=1`, raw only |
| `modify_attribute` | `int (string key, int value)` | Adjust by delta |
| `get_attributes` | `mapping ()` | Returns copy of all attributes |
| `init_attributes` | `void ()` | Loads from config, initializes missing to 5 |

Like skills, attributes support boon/curse modifiers via `query_effective_boon("attribute", key)`.

## GMCP Events

| Package | When | Fields |
|---|---|---|
| `Char.Status` | `set_level`, `adjust_level` | `level`, `xp`, `tnl` |
| `Char.Status` | `adjust_xp` | `xp`, `tnl`, `level` |

## Signals

| Signal | When | Payload |
|---|---|---|
| `SIG_PLAYER_ADVANCED` | `advance()` on level-up | `(tp, new_level)` |

## NPC Skill Behaviour

NPCs interact with the skill system through the same code paths as players — no shortcuts, no special-case branching in `query_*` functions:

1. **`npc.lpc::set_level()` calls `adjust_skills_by_npc_level()`**, which seeds every skill in the tree to `level * 3.0`. After this, `query_skill_level()` returns meaningful values (e.g. a level-5 NPC has skill 15 for every known skill) without any branching.
2. **Combat formulas use `query_skill_level()`** — NPCs and players read through the same path; the storage is the truth.
3. **Use-based improvement still fires** for NPCs (defenders train defense skill on hit attempts), but `set_level()` reseeding overwrites any accumulated progress, so improvements are transient.

## Gotchas

1. **Skills are a nested tree, not flat.** Using `"combat.melee.slashing"` requires the full path to exist. `add_skill` creates intermediates automatically but does NOT overwrite existing nodes.
2. **Pick the right query.** Four-way grid: `query_raw_skill` / `query_skill` / `query_raw_skill_level` / `query_skill_level`. Combat math uses `query_skill_level()`. For existence checks use `has_skill()` — not `nullp(query_raw_skill(...))`.
3. **`set_level()` on NPCs reseeds stored skills.** Always call `set_level()` before adding custom NPC skills.
4. **Improvement bubbles up.** Using a leaf skill has a chance to improve parent skills too, via the weighted pick — the pick is the only bubble-up mechanic.
5. **Progress is tiny by default.** Each successful `use_skill` roll grants up to `random_float(0.01)` — roughly 0-1% of a level. For low-frequency callers (specific spells, niche abilities), pass a `mod_adjust` (e.g. `0.15`) to raise the cap.
6. **`mod_adjust` is shared by every node on the path.** Bubble-up doesn't tighten the cap; the weighted pick alone biases toward leaves. Pick caps that are fine for parents too.
7. **Boons apply to `query_skill` / `query_skill_level`, not the `_raw_` variants.** A boon on `"combat.melee.slashing"` changes what `query_skill_level` and `query_skill` return but never mutates the stored value.
8. **Attributes are currently independent of skills.** They have their own boon class (`"attribute"`) and don't directly modify skill checks — they're tracked but not yet wired into formulas.
9. **`(: 0.01 :)` default-arg functional is resolved at the call boundary.** When `improve_skill` is invoked without the second arg, the body sees `potential_progress = 0.01` (a float), not a functional. The `valid_function()` branch only fires when a caller explicitly passes a functional.
