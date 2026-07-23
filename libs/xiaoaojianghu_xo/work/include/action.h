// action.h

#ifndef __ACTION__
#define __ACTION__

// AGENTS.md §15g/§8g: `class Action` was declared as a return/parameter
// TYPE in add_action.lpc/lcommand.lpc/localcmds.lpc but never actually
// DEFINED anywhere in this archive -- ported verbatim from the sibling
// xo(#28)/TMI-2-ES2 lineage lib's own include/action.h (same lineage,
// confirmed via master.lpc/securityd.lpc header credits), which has the
// real struct definition matching this file's own verb/ob/func usage.
class Action {
    string verb;
    string ob;
    string func;
}

varargs void start_busy(mixed busy, mixed interrupt);

#endif
