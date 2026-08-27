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

/* Don't add anything below this line. */
#endif SYS_FLAGS_DEFINED
