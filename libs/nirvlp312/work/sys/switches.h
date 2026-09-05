/*
 * sys/switches.h
 *
 * In this file global switches can be set (#define). Other files auto-
 * matically include this file (the master takes care of this with its
 * auto-include string) and may test the switches (#ifdef) to decide
 * which code part is to be taken.
 * If you add switches, please document them properly.
 */

#ifndef _sys_switches_h
#define _sys_switches_h

/* We use Nirvana's mudlib, some objects want to know this (the robe)
 * the define NIRVANA shall be used for code that only shall run in 
 * real Nirvana.
 * The following define, NIRVLIB, shall be used for all code that shall
 * run on nirvlib-distributions, e.g. on homemuds that don't want
 * a NIRVANA-define.
 */

#ifndef NIRVLIB
#define NIRVLIB
#endif


/*
 * This defines that the combat skills are active
 */

#if 0
#ifndef COMBAT_SKILLS
#define COMBAT_SKILLS
#endif
#endif


/*
 * This switch defines whether sponsoring wizard apprentices to full wizards
 * is restricted to members of a domain "Sponsors" or not.
 */
#ifdef NIRVANA
#ifndef RESTRICTED_SPONSORING
#define RESTRICTED_SPONSORING
#endif
#endif


/*
 * This switch activates the new level system, including levels 21 to
 * 40 for players, first-time-experience based advancing and much more.
 * Note that you cannot simply deactivate this. Existing player files
 * will bug. Of course you can try to set up a new mud with the old
 * level system.
 */

#if 0
#ifndef NEW_LEVELS
#define NEW_LEVELS
#endif
#endif


/*
 * This switch activates usage of InterMud-3 together with the loading
 * of the InterMud3 main program from /room/init_file.
 * To use the Intermud 3, you have to install the new ERQ demon.
 *
 * Defaults to be enabled only for Nirvana itself and not for testmuds.
 * Loading /etc/intermud3 without setting this flag is safe, InterMud won't
 * be active then.
 */

#ifdef NIRVANA
#ifndef TESTMUD
#ifndef INTERMUD3
#define INTERMUD3
#endif
#endif
#endif


/*
 * This switch activates the new light module system
 */
#if 0
#ifndef NEW_LIGHT
#define NEW_LIGHT
#endif
#endif


/*
 * This switch replaces the old skill system by the new one.
 */

#ifndef NEW_SKILLS
#define NEW_SKILLS
#endif

#endif
