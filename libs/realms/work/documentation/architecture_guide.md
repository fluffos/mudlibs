# The Architecture Guide

*Understanding the Design Philosophy of the Simulation Engine*

---

# Purpose

This guide is not an API reference.

It is not a tutorial.

It explains **why** the engine is structured the way it is.

The goal is that contributors understand the architectural philosophy before they begin writing code.

Every system in the engine should reinforce these principles.

---

# Table of Contents

1. Design Goals
2. The Domain Model
3. Realizations
4. Modules
5. Services
6. Ownership
7. Dependency Rules
8. Events
9. Caching
10. Persistence
11. Declarative Design
12. Composition
13. Extension Points
14. Architectural Patterns
15. Case Studies
16. Common Mistakes

---

# Chapter 1 — Design Goals

The engine exists to simulate a living world.

Gameplay is an emergent property of that simulation.

The primary design goals are:

- Separation of responsibilities
- Composable systems
- Declarative behavior
- Reusable infrastructure
- Minimal coupling
- Extensibility
- Predictable ownership
- High runtime performance

Whenever tradeoffs occur, these goals should guide implementation.

---

# Chapter 2 — The Domain Model

The engine is divided into domains.

Each domain owns one truth.

Examples include:

| Domain | Responsibility |
|---------|----------------|
| Research | Learned capabilities |
| Combat | Combat state |
| Traits | Identity |
| Conversation | Interactions |
| Movement | Location |
| State Machine | Workflow progression |
| Experience | Historical events |
| UI | Presentation |

Domains communicate by querying one another.

Domains should never duplicate ownership.

---

# Chapter 3 — Realizations

Everything that exists in the simulation is a realization.

Examples:

- Player
- NPC
- Monster
- Companion
- Henchman
- Summoned creature

A realization is assembled from modules.

It is responsible for coordination rather than implementing business logic.

Think of a realization as the container that allows domains to work together.

---

# Chapter 4 — Modules

Modules own mutable state.

Typical responsibilities include:

- Maintaining state
- Coordinating workflows
- Publishing events
- Managing caches
- Validating transitions

Modules should know as little as possible about other modules.

Instead, they ask questions through well-defined interfaces.

---

# Chapter 5 — Services

Services encapsulate reusable business logic.

Unlike modules, services generally remain stateless.

Typical responsibilities include:

- Rule evaluation
- Calculations
- Shared algorithms
- Infrastructure
- Persistence support

Services operate on modules.

They do not own module state.

A useful rule of thumb:

> Modules own data.
>
> Services own algorithms.

---

# Chapter 6 — Ownership

Ownership is the single most important architectural concept.

Every fact should have exactly one owner.

Example:

Research owns learned techniques.

Combat asks Research.

Combat never owns Research.

Likewise:

Traits own intrinsic qualities.

Conversation asks Traits.

Conversation never stores trait information.

Duplicating ownership creates synchronization problems.

Avoid it.

---

# Chapter 7 — Dependency Rules

Dependencies should always flow toward knowledge.

Good:

Combat → Research

Conversation → Traits

Crafting → Skills

Bad:

Research → Combat

Traits → Conversation

Movement → Combat

Domains should never depend on systems that consume them.

---

# Chapter 8 — Events

Events communicate change.

Events do not own business logic.

Typical flow:

State changes.

↓

Owner updates.

↓

Caches invalidate.

↓

Event published.

↓

Interested systems react.

Events are notifications—not workflows.

---

# Chapter 9 — Caching

The engine is optimized for reads.

Derived values should be cached whenever practical.

When mutable state changes:

- invalidate caches
- recalculate
- publish notifications

Queries should generally execute in constant time.

Never sacrifice ownership simply to cache data.

Cache answers—not truth.

---

# Chapter 10 — Persistence

Persistence is infrastructure.

Domains should not become database-aware.

Persistence services should isolate storage concerns from simulation concerns.

Changing storage technology should require minimal changes to domains.

---

# Chapter 11 — Declarative Design

Whenever possible, behavior should be expressed declaratively.

Prefer data describing behavior instead of hardcoded logic.

Examples include:

Research prerequisites

Limitors

Composite definitions

State machine transitions

Dialogue structures

Quest progression

The engine interprets data.

It should not contain large numbers of feature-specific branches.

---

# Chapter 12 — Composition

Composition is one of the engine's fundamental design patterns.

Examples include:

Composite Research

Bard Songs

Spell Construction

Attack Chains

Kata

Crafting Recipes

Dialogue Trees

The engine understands composition.

Content supplies meaning.

Whenever possible, compose existing primitives rather than creating new specialized systems.

---

# Chapter 13 — Extension Points

When implementing new features, ask:

Can an existing domain represent this?

Can an existing primitive be extended?

Can composition solve the problem?

Examples:

A new guild should primarily consist of:

- Research
- State Machines
- Conversations
- Composite definitions
- Data

rather than new engine functionality.

Engine changes should introduce capabilities—not content.

---

# Chapter 14 — Architectural Patterns

Several patterns appear repeatedly throughout the engine.

## Capability Pattern

Research represents capabilities.

Guilds consume capabilities.

Books grant capabilities.

Meditation grants capabilities.

Everything uses the same abstraction.

---

## Composite Pattern

Complex behavior emerges from simpler parts.

Examples:

Songs

Spells

Kata

Combat chains

---

## Declarative Pattern

Rules are expressed as data.

The engine evaluates those rules.

---

## Reactive Cache Pattern

Caches update only when mutations occur.

Queries remain inexpensive.

---

## Query Pattern

Domains ask each other questions.

They never own each other's truth.

---

## Module / Service Pattern

Modules own mutable state.

Services own reusable behavior.

---

# Chapter 15 — Case Studies

## Why Guilds Use Research

Rather than giving every guild its own progression framework, the engine models capabilities through Research.

Guilds become one consumer of a much more general abstraction.

This same framework also supports:

- Racial abilities
- Books
- Meditation
- Martial arts
- Magical discoveries
- Crafting knowledge

The result is a single extensible capability system.

---

## Why Combat Doesn't Store Research

Combat frequently requires research information.

However:

Research owns research.

Combat queries research.

Combat caches answers.

Ownership never changes.

This eliminates synchronization problems.

---

## Why Modules and Services Are Separate

Business logic often applies to many realizations.

Rather than duplicating that logic, services encapsulate reusable algorithms.

Modules retain ownership of state.

This keeps responsibilities clear while maximizing reuse.

---

## Why Composite Systems Exist

Many gameplay systems appear different but share the same underlying structure.

Examples:

Songs

Spells

Combat combinations

Kata

Rather than implementing each independently, the engine provides a generic composition framework.

Gameplay systems become descriptions rather than implementations.

---

# Chapter 16 — Common Mistakes

## Creating a New Domain Too Early

Ask whether an existing domain can represent the concept.

Prefer extending existing abstractions.

---

## Duplicating Ownership

If another domain already owns the information, query it.

Do not duplicate it.

---

## Feature-Driven Design

Avoid creating systems specifically for one guild or feature.

Instead, identify the more general abstraction.

---

## Hardcoded Rules

Prefer declarative data.

Engine code should interpret rules.

Content should define them.

---

## Bypassing Services

Shared algorithms belong in services.

State belongs in modules.

Maintain this separation.

---

# Final Thoughts

Every new feature should strengthen the architecture rather than complicate it.

When in doubt, ask:

- Who owns this fact?
- Which domain should answer this question?
- Can this be represented declaratively?
- Can existing primitives express it?
- Does this reduce or increase coupling?

If the architecture becomes simpler after adding a feature, the design is probably moving in the right direction.
