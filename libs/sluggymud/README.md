# SluggyMUD

A tiny, bare-bones LPC mudlib skeleton, explicitly built to run on the
[FluffOS](https://github.com/fluffos/fluffos) driver -- per the
archive's own two-line README: "A component-based mudlib designed to
run on the FluffOS LPC driver."

There's no world here to explore: no rooms, no NPCs, no combat, no
account/login system. This is a from-scratch engine's earliest
scaffolding -- a real `master.lpc`, a real `simul_efun.lpc`, and a
handful of developer commands -- left at exactly the stage its author
stopped at in 2013, complete with a comment in the login code
admitting "needs fixed to handle passwords." What *is* real and
working: connect anonymously and try out `who`, `say`, `eval <lpc
expression>`, `ed <file>`, and a genuinely substantial (once repaired)
~113-file self-test suite covering the driver's own compiler and efun
behavior.

Source: `Sluggy/SluggyMUD` on GitHub.

## Highlights

- A clean, permissive MudOS/FluffOS-style `master.lpc`/`valid.lpc` pair
  -- a good minimal reference for what a from-scratch mudlib's driver
  glue looks like with nothing else built on top yet.
- `eval <expr>` compiles and runs an arbitrary LPC expression on the
  fly and prints its result; the hidden `codefor <expr>` sibling prints
  the real compiled bytecode disassembly instead.
- A hidden `tests` command walks and runs the archive's own
  compiler/efun self-test suite live against whatever driver is
  running it -- a neat way to see a real compiler-behavior difference
  surface on the spot (one "should fail to compile" fixture actually
  compiles fine on this build, and the suite catches it).

## Play online

https://mudlibs.fluffos.info/sluggymud/

## Local run

```
cd libs/sluggymud
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40250**.

No accounts, so nothing to register -- just connect and try `who`,
`say hello`, or `eval return 6*7;`.
