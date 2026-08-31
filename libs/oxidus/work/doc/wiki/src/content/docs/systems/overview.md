---
title: Overview
description: Overview of Systems in Oxidus
sidebar:
  order: 0
---

Oxidus includes a number of interconnected systems that handle everything from
communication to combat to world generation. Here is a brief look at some of
them.

## Channels

The channel system provides global and scoped communication for players and
staff. Channels are defined as modules, each governing its own permissions,
history, and formatting. GMCP integration means modern clients can present
channels in dedicated UI panels rather than inline with other output.

## GMCP

Oxidus supports the Generic MUD Communication Protocol for both incoming and
outgoing data. Outgoing modules push structured data to clients — character
stats, room contents, communication events — while incoming handlers let
clients send requests back to the game. New packages can be added by dropping
a module into the appropriate directory.

## Virtual Objects

Items and NPCs can be defined entirely in LPML data files rather than LPC
code. A virtual compile layer reads the data, selects the right base class,
and produces a fully functional object at load time. This makes it
straightforward to add new content without writing any code.

## Currency and Shops

A unified currency daemon tracks denominations and exchange rates. Shops come
in two flavours — inventory-based shops that sell objects from their own
stock, and menu-based shops that generate items on demand. Banks, loot tables,
and coin drops all tie back into the same currency framework.

## Signals

The signal system provides a publish-subscribe event bus. Any object can emit
a named signal, and any object can register a slot to respond. Signals drive
a wide range of behaviours — from combat events to UI updates — without
requiring tight coupling between the producer and consumer.

## Combat

Combat in Oxidus follows an attack-loop model with hit-chance calculation,
a damage pipeline, threat tracking, and a full death sequence. NPCs use a
utility-AI layer to choose actions each round, and players advance through
use-based skill improvement and experience gain.
