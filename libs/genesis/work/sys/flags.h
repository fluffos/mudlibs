/*
 * /sys/flags.h
 *
 * This module contains some binary coded flags.
 */

#ifndef SYS_FLAGS_DEFINED
#define SYS_FLAGS_DEFINED

/*
 * BUSY_W  - do not hear the wizline
 * BUSY_T  - do not hear any tellalls
 * BUSY_M  - do not hear any tells from mortal players
 * BUSY_P  - do not hear any tells
 * BUSY_S  - do not hear any tells or says
 * BUSY_F  - do not hear anything
 * BUSY_C  - do not hear any communes
 * BUSY_G  - do not hear the intermud wizline
 * BUSY_I  - do not hear any intermud tells
 * BUSY_L  - do not hear the liege-line
 */
#define BUSY_W    (   1)
#define BUSY_T    (   2)
#define BUSY_M    (   4)
#define BUSY_P    (   8)
#define BUSY_S    (  16)
#define BUSY_C    (  32)
#define BUSY_F    ( 128)
#define BUSY_G    ( 256)
#define BUSY_I    ( 512)
#define BUSY_L    (1024)

/*
 * BUSY_ALL - Set this when you want to set the busy F flag, but query the F
 *            flag only with BUSY_F. This is done so that people will also
 *            catch on triggering another flag when busy F is set.
 */
#define BUSY_ALL  (2047)

/*
 * The OBFLAGS are the GD flags for objects. The 'flag' integer is available
 * to LPC objects through: flag = debug("ob_flags", ob);
 */
#define O_HEART_BEAT		0x01  /* Does it have an heart beat ? */
#define O_IS_WIZARD		0x02  /* Should we count commands for score? */
#define O_ENABLE_COMMANDS	0x04  /* Can it execute commands ? */
#define O_CLONE			0x08  /* Is it cloned from a master copy ? */
#define O_DESTRUCTED		0x10  /* Is it destructed ? */
#define O_SWAPPED		0x20  /* Is it swapped to file */
#define O_ONCE_INTERACTIVE	0x40  /* Has it ever been interactive ? */
#define O_APPROVED		0x80  /* Is std/object.c inherited ? */
#define O_RESET_STATE		0x100 /* Object in a 'reset':ed state ? */
#define O_WILL_CLEAN_UP		0x200 /* clean_up will be called next time */

/* Don't add anything below this line. */
#endif SYS_FLAGS_DEFINED
