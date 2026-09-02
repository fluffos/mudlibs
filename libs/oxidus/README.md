# Oxidus

A genuinely modern, actively-developed FluffOS mudlib -- not a 1990s/2000s archive like most of this collection. Self-described as "an effort to create an opinionated base mudlib... a modern and feature-rich codebase for the LPMud community." Written from scratch (a distant fork of LPUniversity that has long since diverged into its own codebase), with its own real unit test suite, its own documentation site (<https://oxidus.online/>), and its own bundled agent-coding guides.

Source: `gesslar/oxidus-mudlib` on GitHub.

## Highlights

- **Account-based login**: register an account (with a password) first,
  then create or select a character under it -- the first character
  ever created on a fresh install automatically becomes the mud's
  owner/admin.
- **Real bespoke content**: the village of Olum (a square, bakery,
  tailor, financier, a manor interior with its own arcanist NPC and
  spell tree) plus forest/cavern/maze/tunnels/wastes zones -- not a
  bare skeleton.
- **Modern-feeling systems under the hood**: native `async`/`await`,
  a signal/event daemon, GMCP support (incoming and outgoing), a real
  SQLite-backed database daemon, HTTP client/server daemons, and a
  colour-code system -- documented in the lib's own `.claude/skills/`
  guides for anyone building on top of it.
- **In-game wizard tools**: a line editor (`ed`), file commands
  (`ls`/`cat`/`cp`/`mv`/etc.), and `bug`/`idea`/`todo` reporting
  commands that log locally and can optionally file a GitHub issue.

## Play

Register an account when you first connect (you'll be asked to confirm
a password), then create a character under it. Once in the game:
`look`, `score`, `inventory`, and the usual movement directions all
work as expected; `quit` saves you and disconnects cleanly, and
reconnecting with the same account brings you back to the same
character exactly where you left off.

## Status

Boots clean natively and plays correctly end-to-end -- registration,
character creation, movement through real authored rooms, and the
in-game editor were all verified live during onboarding. Not yet
packaged for the browser (WASM) gallery.

## Onboarding notes

See `NOTES.md` in this directory for the technical bring-up log: this
lib assumed a considerably newer/differently-configured driver build
than this corpus's shared one, in three independent ways (async/await
support, a bundled driver-headers directory, and the classic-vs-modern
in-game editor efun split), all diagnosed and fixed. Also fixed: a
`private`-visibility driver-callback bug in the editor, a redundant
restore call that silently stripped a promoted wizard's extra command
access on reconnect, and an unconfigured optional GitHub-issue
integration that took the whole `bug`/`idea`/`todo` commands down
instead of degrading gracefully. See `AGENTS.md` §7.161, §7.162, and
§8.21 for the two most broadly-applicable findings.
