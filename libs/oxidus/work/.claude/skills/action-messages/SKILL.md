---
name: action-messages
description: Understand and write action messages with automatic verb conjugation, pronoun handling, and perspective-based delivery. Covers all $-tokens ($N, $v, $t, $o, $p, $r, $b), all action functions, article handling, reflexives, and common pitfalls.
---

# Action Messages Skill

The action message system (derived from Lima MUD) composes messages that automatically adjust grammar based on who is reading them. A single template like `"$N $vswing $p sword."` produces "You swing your sword." for the actor and "Bob swings his sword." for everyone else.

**Core files:**
- `adm/daemons/action.lpc` — message composition engine (`ACTION_D`)
- `std/ext/action.lpc` — module wrapper inherited by living objects
- `adm/simul_efun/english.lpc` — pronoun functions (`subjective`, `objective`, `possessive`, `reflexive`)
- `adm/simul_efun/grammar.lpc` — pluralisation helpers

## Action Functions

All are called on the actor object (via `EXT_ACTION` module). The actor is always `previous_object()`.

| Function | Who Sees It | Use For |
|---|---|---|
| `simple_action(msg, obs...)` | Actor + room | Standard actions visible to everyone |
| `my_action(msg, obs...)` | Actor only | Private feedback, failure messages |
| `other_action(msg, obs...)` | Room only (not actor) | Announcements excluding the doer |
| `targetted_action(msg, target, obs...)` | Actor + target + room (3 perspectives) | Actions directed at someone |
| `target_action(msg, target, obs...)` | Target only | Private message to target |
| `my_target_action(msg, target, obs...)` | Actor only | Actor sees target-aware message |

All functions accept `mixed msg` — either a string template or an array of strings (one is chosen randomly via `element_of()`).

## Token Reference

### $N / $n — Actor Name

The doer of the action. Defaults to `who[0]`.

| Token | Actor Sees | Others See (first mention) | Others See (subsequent) |
|---|---|---|---|
| `$N` | "You" | "Bob" | "he"/"she"/"they" (subjective) |
| `$No` | "you" | "Bob" | "him"/"her"/"them" (objective) |
| `$Nd` | "Bob" | "Bob" | "Bob" (always display name) |
| `$Np` | "Bob's" | "Bob's" | "Bob's" (possessive proper noun) |

- Uppercase `$N` capitalises the result; lowercase `$n` does not
- First mention uses the name; subsequent mentions use pronouns
- Gender-based via `query_gender()`: returns `"male"`, `"female"`, `"other"`

### $V / $v — Verb Conjugation

Conjugates a verb based on perspective.

| Token | Actor Sees | Others See |
|---|---|---|
| `$vswing` | "swing" | "swings" |
| `$vgrab` | "grab" | "grabs" |
| `$vtry` | "try" | "tries" |
| `$vis` | "are" | "is" |
| `$vare` | "are" | "is" |

**Rules:**
- Actor always gets the base form: "swing", "grab"
- Others get `pluralize(verb)`: "swings", "grabs" (third-person singular)
- **"to be" special case**: `$vis`, `$vam`, `$vare` → "are" for actor, "is" for others
- Gender `"other"` also gets "are" (plural agreement)
- **Contraction hack**: `$vdon't ` works — the system detects `'t ` after the verb and appends it

**Uppercase** `$V` capitalises the conjugated result.

### $T / $t — Target Name

The target of the action. Defaults to `who[1]` with objective suffix.

| Token | Actor Sees | Target Sees | Others See |
|---|---|---|---|
| `$t` | "Bob" | "you" | "Bob" / "him" |

Same pronoun logic as `$N` but defaults to participant 1 (the target) and objective case.

### $O / $o — Object

References objects from the `obs...` arguments.

| Token | Resolves To |
|---|---|
| `$o` or `$o0` | `obs[0]` |
| `$o1` | `obs[1]` |
| `$o2` | `obs[2]` |

**Article handling**: The system detects articles in the text before `$o` and adjusts:

| You Write | Result |
|---|---|
| `"a $o"` | "a sword" (indefinite article from `a_short()`) |
| `"the $o"` | "the sword" (definite article from `the_short()`) |
| `"$o"` | "sword" (bare short description) |

- On second mention of the same object: replaced with "it"
- Arrays of objects: handled automatically with pluralisation and `simple_list()`
  - `"a $o"` with 3 swords → "3 swords"
  - Mixed arrays → "3 swords and a shield"
  - Second mention of array → "them"

### $P / $p — Possessive Pronoun

| Token | Actor Sees | Others See (first mention) | Others See (subsequent) |
|---|---|---|---|
| `$p` | "your" | "Bob's" | "his"/"her"/"their"/"its" |

### $R / $r — Reflexive Pronoun

| Token | Actor Sees | Others See |
|---|---|---|
| `$r` | "yourself" | "himself"/"herself"/"themself"/"itself" |

### $B / $b — Base Pronoun (Hybrid)

Like `$N` but uses objective pronouns on subsequent mentions.

| Token | Actor Sees | Others See (first mention) | Others See (subsequent) |
|---|---|---|---|
| `$b` | "you" | "Bob" | "him"/"her"/"them" |

## Numeric Indices

Tokens can reference specific participants by number:

- `$n0` — `who[0]` (the actor, same as `$n`)
- `$n1` — `who[1]` (the target in targetted actions)
- `$v1swing` — conjugate "swing" for `who[1]`'s perspective
- `$p1` — possessive of `who[1]`

The format is: `$[TYPE][PARTICIPANT_NUMBER][SUFFIX]`

For two-digit parsing: `$[TYPE][SUBJECT_NUMBER][PARTICIPANT_NUMBER][SUFFIX]` — subject determines reflexive detection, participant determines which person.

## Reflexive Handling

When the subject and participant are the same person and the subject has already been mentioned, reflexive pronouns are used automatically:

```
"$N $vkick $No"
// Actor: "You kick yourself."     (not "You kick you.")
// Others: "Bob kicks himself."    (not "Bob kicks Bob.")
```

This only triggers when both reference the same `who[]` entry and the subject has been previously mentioned in the message.

## Message Routing Detail

### simple_action

```
Actor ← compose_message(actor, msg, who, obs)
Actor's inventory ← compose_message(null, msg, who, obs)
Room (excluding actor) ← compose_message(null, msg, who, obs)
```

### targetted_action

```
Actor ← compose_message(actor, msg, who, obs)
Target ← compose_message(target, msg, who, obs)
Actor's inventory ← compose_message(null, msg, who, obs)
Target's inventory ← compose_message(null, msg, who, obs)
Room (excluding actor and target) ← compose_message(null, msg, who, obs)
```

When `forwhom` is `null` (the "others" perspective), no participant matches, so all names are used with third-person conjugation.

## Practical Examples

### Basic action
```lpc
tp->simple_action("$N $vdrop $p $o.", item);
// Actor: "You drop your sword."
// Others: "Bob drops his sword."
```

### Failure message (actor only)
```lpc
tp->my_action("$N $vcannot drop $p $o.", item);
// Actor: "You cannot drop your sword."
```

### Action with target
```lpc
tp->targetted_action("$N $vgive $p $o to $t.", target, item);
// Actor:  "You give your sword to Alice."
// Target: "Bob gives his sword to you."
// Others: "Bob gives his sword to Alice."
```

### Multiple objects
```lpc
tp->simple_action("$N $vtake a $o from a $o1.", item, container);
// Actor: "You take a sword from a chest."
// Others: "Bob takes a sword from a chest."
```

### To be
```lpc
tp->simple_action("$N $vis ready to fight.");
// Actor: "You are ready to fight."
// Others: "Bob is ready to fight."
```

### Contraction
```lpc
tp->simple_action("$N $vdon't see that here.");
// Actor: "You don't see that here."
// Others: "Bob doesn't see that here."
```

### Announcement to room
```lpc
tp->other_action("$N $venter from the north.");
// Actor: (nothing)
// Others: "Bob enters from the north."
```

### Reflexive
```lpc
tp->simple_action("$N $vhurt $No.");
// Actor: "You hurt yourself."
// Others: "Bob hurts himself."
```

### Random message
```lpc
tp->simple_action(({
    "$N $vswing $p sword wildly.",
    "$N $vslash at the air with $p sword.",
    "$N $vbrandish $p sword menacingly.",
}), sword);
// Randomly picks one template each time
```

## Common Pitfalls & Troubleshooting

### Wrong verb form
**Problem**: "Bob swing the sword" instead of "Bob swings the sword"
**Cause**: Missing `$v` prefix on the verb. Write `$vswing` not just `swing`.

### "you" where a name should be
**Problem**: Actor sees "you" but you wanted the name
**Fix**: Use `$Nd` (display name suffix) to force the name instead of pronoun.

### Premature pronoun
**Problem**: "he drops his sword" on first mention instead of "Bob drops his sword"
**Cause**: The `has` tracking thinks the object was already mentioned. This can happen if the same living appears in multiple token positions. The system tracks mentions per-composition — each viewer gets fresh tracking.

### "is" vs "are" wrong
**Problem**: "You is ready" or "Bob are ready"
**Fix**: Use `$vis` (not `$vare` or `$vam`). The system handles conjugation — all three forms (`is`/`am`/`are`) trigger the same "to be" logic.

### Object shows as "it" too early
**Problem**: First mention of an object shows "it" instead of the name
**Cause**: The object or its short description was already in the `has` tracking — possibly mentioned via a different token. Each `$o` use with the same object increments the tracking.

### Possessive on wrong person
**Problem**: "Bob's" shows up where "your" should
**Cause**: Check which participant `$p` refers to. By default it's participant 0 (the actor). Use `$p1` for the target's possessive.

### Articles doubling or missing
**Problem**: "a a sword" or missing article
**Cause**: The system strips and re-applies articles when `a ` or `the ` precedes `$o`. If your object's `query_short()` already includes an article ("a sword"), the system will strip and reapply. Don't include articles in both the template and the short description.

### Gender "other" and verb conjugation
**Note**: Gender `"other"` uses plural agreement — `$vis` → "are", `$vswing` → "swing" (not "swings"). This is intentional for they/them pronouns.

## Grammar Support Functions

Available as simul_efuns for manual use:

| Function | Returns |
|---|---|
| `subjective(ob)` | "he", "she", "they", "it" |
| `objective(ob)` | "him", "her", "them", "it" |
| `possessive(ob)` | "his", "her", "their", "its" |
| `possessive_proper_noun(ob)` | "Bob's", "Alice's" |
| `reflexive(ob)` | "himself", "herself", "themself", "itself" |
| `pluralize(str)` | Third-person singular: "swing" → "swings" |
| `simple_list(arr)` | "sword, shield, and mace" |
| `add_article(str, definite)` | Add "a"/"an" or "the" |
| `remove_article(str)` | Strip leading article |
