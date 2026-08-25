/*
 * /sys/exec.h
 *
 * This is the default include file with some prefedefined macros for the
 * command exec. It is included in your exec_obj.c by default _after_ the
 * exec.h from your home directory has been included. Provisions are made
 * so that definitions from this file, generic as they are, are only
 * created if they are not defined before to guard against redefinition
 * errors.
 *
 * The following definitions are included:
 *
 * ME      Always returns the objectpointer to you, the person executing
 *         the exec command, even if you switched this_player().
 * TP      this_player() [may have been altered using set_this_player(o)]
 * TI      this_interactive() [probably always the same as ME]
 * TO      this_object()
 *
 * FP(s)   find_player(s)
 * FL(s)   find_living(s)
 * FO(s)   find_object(s)
 * ENV(o)  environment(o)
 * INV(o)  all_inventory(o)
 * CAP(s)  capitalize(s)
 * LOW(s)  lower_case(s)
 * HERE    The room you are in.
 */

#ifndef DEFAULT_EXEC_INCLUDE
#define DEFAULT_EXEC_INCLUDE

#ifndef ME
#define ME     (find_player(getuid(this_object())))
#endif  ME

#ifndef TP
#define TP     (this_player())
#endif  TP

#ifndef TI
#define TI     (this_interactive())
#endif  TI

#ifndef TO
#define TO     (this_object())
#endif  TO

#ifndef FP
#define FP(s)  (find_player(s))
#endif  FP

#ifndef FL
#define FL(s)  (find_living(s))
#endif  FL

#ifndef FO
#define FO(s)  (find_object(s))
#endif  FO

#ifndef ENV
#define ENV(o) (environment(o))
#endif  ENV

#ifndef INV
#define INV(o) (all_inventory(o))
#endif  INV

#ifndef CAP
#define CAP(s) (capitalize(s))
#endif  CAP

#ifndef LOW
#define LOW(s) (lower_case(s))
#endif  LOW

#ifndef HERE
#define HERE (environment(this_interactive()))
#endif  HERE

/* No definitions beyond this line. */
#endif DEFAULT_EXEC_INCLUDE
