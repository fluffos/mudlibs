# The Engine Constitution

*A Foundational Philosophy for the Simulation Engine*

---

## Introduction

This engine is not built around gameplay features.

It is built around **domains that own truth**.

Guilds, monsters, quests, spells, martial arts, conversations, crafting, and every other gameplay system are applications of a relatively small number of reusable architectural primitives.

The purpose of the engine is to create a world where complexity emerges from the interaction of simple, composable systems rather than from increasingly specialized code.

Every architectural decision should reinforce this philosophy.

---

# Article I — Ownership

## Every fact has exactly one owner.

A fact should exist in only one domain.

Examples:

| Domain | Owns |
|---------|------|
| Research | Learned capabilities |
| Combat | Current combat state |
| Traits | Intrinsic qualities |
| Movement | Position and movement |
| Conversation | Active interactions |
| Experience | Historical experiences |

If another domain requires that information, it **queries the owner**.

It never duplicates ownership.

---

# Article II — Domains

Every domain exists to answer one primary question.

| Domain | Question |
|---------|----------|
| Research | What does this realization know? |
| Combat | What is happening in combat? |
| Traits | What intrinsic qualities define this realization? |
| Movement | Where is this realization? |
| Conversation | What interaction is taking place? |
| State Machine | Where is this workflow? |
| Experience | What has this realization experienced? |

Domains should not answer questions owned by other domains.

---

# Article III — Realizations

A realization represents an entity that exists within the simulation.

Examples include:

- Players
- NPCs
- Monsters
- Companions
- Henchmen
- Summoned creatures

Realizations are assembled from modules.

A realization's primary responsibility is orchestration rather than business logic.

---

# Article IV — Modules

Modules own mutable state.

Responsibilities include:

- Maintaining state
- Validating state transitions
- Coordinating workflows
- Publishing notifications
- Maintaining caches

Modules never own another module's state.

---

# Article V — Services

Services encapsulate reusable algorithms and infrastructure.

Responsibilities include:

- Business rules
- Calculations
- Rule evaluation
- Data transformations
- Persistence support

Services generally remain stateless.

Services operate on domain objects but do not own them.

---

# Article VI — Queries

Domains communicate through queries.

Knowledge remains with its owner.

Preferred:

```text
Combat → Research

Conversation → Traits

Crafting → Skills
```

Avoid:

```text
Combat caches research ownership

Conversation stores personality

Movement stores trait information
```

Caching answers is encouraged.

Duplicating ownership is not.

---

# Article VII — Mutation

The engine optimizes for frequent reads and infrequent writes.

Whenever mutable state changes:

1. Update the owning domain.
2. Invalidate affected caches.
3. Recalculate derived values.
4. Publish notifications.

After mutation completes, queries should generally execute in constant time.

---

# Article VIII — Events

Events announce change.

Events do not own behavior.

Events are transient notifications.

Business decisions remain within the domains that own the underlying state.

---

# Article IX — Composition

Composition is preferred over specialization.

Whenever possible:

**Compose behavior.**

Avoid creating specialized subclasses.

Examples include:

- Research
- Bard songs
- Spell construction
- Combat combinations
- Kata
- Crafting recipes
- Dialogue structures

The engine understands composition.

Content provides meaning.

---

# Article X — Declarative Systems

Behavior should be described rather than hardcoded.

Prefer declarative definitions:

- Conditions
- Prerequisites
- Limitors
- Composite structures
- State transitions

Avoid feature-specific branching.

Avoid:

```c
if (isMonk())
```

Prefer:

```text
Requires:

Tiger Stance
Katana Equipped
Rank >= Disciple
Flow >= 50
```

The engine interprets data rather than executing feature-specific logic.

---

# Article XI — Infrastructure

Infrastructure remains generic.

Infrastructure should not understand:

- Guilds
- Weapons
- Monsters
- Songs
- Martial arts
- Spells

Infrastructure provides capabilities.

Content provides meaning.

---

# Article XII — User Interfaces

The UI is a consumer.

The simulation owns gameplay.

Rendering should remain completely independent from simulation logic.

The same engine should support multiple renderers without modification.

Examples include:

- Plain text
- ANSI terminals
- Unicode clients
- JSON APIs
- 2D clients
- 3D clients

---

# Article XIII — History

History is a first-class architectural concept.

Events disappear.

State changes.

History remains.

The Experience domain records what occurred.

Other domains determine what those experiences mean.

---

# Article XIV — Content

Content extends the engine.

New content should primarily consist of:

- Research
- Conditions
- Composite definitions
- Conversations
- State machines
- Data

Engine modifications should be the exception rather than the rule.

---

# Article XV — Context

Every action occurs within context.

Examples include:

- Time
- Weather
- Moon phase
- Season
- Terrain
- Area
- Region
- Equipment
- Active effects
- Stance
- Nearby entities

Domains should query context rather than reconstruct it independently.

---

# Article XVI — Emergence

The engine should encourage emergent behavior.

Interesting gameplay should arise naturally through interactions between systems.

Examples include:

- Constructed spells
- Original bard songs
- Player-created kata
- Forgotten martial arts rediscovered
- Dynamic conversations
- Context-sensitive research

Emergent systems are preferred over scripted mechanics.

---

# Article XVII — Reuse

Before creating a new framework, ask:

- Can an existing primitive express this?
- Can this be represented declaratively?
- Can composition solve this?

Only introduce new architectural primitives when multiple systems genuinely require them.

---

# Article XVIII — Knowledge

The engine distinguishes between:

- Identity
- Knowledge
- Capability
- Current State
- History

These concepts remain independent.

Learning is not mastery.

Experience is not knowledge.

Capability is not identity.

Mastery emerges from the interaction of multiple domains.

---

# Article XIX — Simulation First

The engine simulates a world.

Gameplay emerges naturally from that simulation.

Before adding mechanics, ask:

> "What would naturally happen in this world?"

The answer should guide implementation.

---

# Article XX — Architectural Integrity

When evaluating any new feature, ask:

- Who owns this fact?
- Which domain should answer this question?
- Can this be expressed declaratively?
- Can an existing primitive represent it?
- Does this duplicate ownership?
- Does this increase coupling?
- Does it encourage emergence?

If these questions cannot be answered cleanly, redesign before implementation.

---

# Closing Statement

The goal of this engine is not to create the largest collection of gameplay systems.

Its goal is to create the smallest collection of reusable architectural concepts from which an unlimited number of gameplay systems can emerge.

As the engine matures:

- Content should become richer.
- Systems should become more composable.
- The engine itself should become simpler.

Good architecture enables complexity through composition rather than specialization.

---

# Core Design Formula

The behavior of every realization emerges from the interaction of five fundamental domains:

```text
Identity
        +
Knowledge
        +
Capabilities
        +
Current State
        +
History
        ↓
     Behavior
```

Where:

- **Identity** consists of traits, personas, race, and other defining characteristics.
- **Knowledge** consists of research and learned understanding.
- **Capabilities** consist of skills, equipment, and available techniques.
- **Current State** consists of combat state, effects, movement, environment, and other transient conditions.
- **History** consists of accumulated experiences that permanently shape the realization.

No single domain defines behavior.

Behavior is the emergent result of all of them working together.

---

> **Architectural Principle**

> *The engine does not model mechanics.*
>
> *It models truths.*
>
> Mechanics emerge from the interaction of those truths.
