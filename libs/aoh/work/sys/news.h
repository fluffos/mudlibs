#ifndef NEWS_H
#define NEWS_H 1

  /* The propertie(s) of boards */

#define P_GROUPS "Groups"

  /* The trash-directory */

#define TRASH "trash"

  /* How much notes to list per default */

#define NO_NOTES  10

  /* Cleanup of the groups-cache */

#define NEWS_TIME_TO_CLEAR 1800
#define NEWS_MIN_TOUCHED      10

  /* Delayed save on note deposit/removal */

#define NEWS_DSAVE_TIME 600

  /* Indices into grouplist */

#define GL_NAME 0
#define GL_DSC  1

  /* Indices into one group-descriptor */

#define G_NAME      0
#define G_OWNER     1
#define G_READ      2
#define G_WRITE     3
#define G_DELETE    4
#define G_SUBGROUP  5
#define G_MAXMSG    6
#define G_LOGMODE   7
#define G_LOGGER    8
#define G_ACTMSG    9
#define G_LASTID   10

#define G_SIZE     11

#define G_USAGE    11

  /* Logmodes */

#define M_NOLOG   0
#define M_LOG_NEW 1
#define M_LOG_EXP 2

  /* Indices into groups */

#define GC_NAME 0
#define GC_DATA 1

  /* Indices into the data of one group */

#define GD_MSGS    0
#define GD_TOUCHES 1

  /* Indices into one message */

#define M_WRITER 0
#define M_LEVEL  1
#define M_ID     2
#define M_TIME   3
#define M_GROUPS 4
#define M_FLAGS  5
#define M_TITLE  6
#define M_TEXT   7 // Must be last entry.

#define M_SIZE   8

  /* M_FLAG values */

#define MF_LOCKED "locked"

  /* Indices into the array of the master-interna */

#define NEWS_IVERSION   0  /* Version-string of the master */
#define NEWS_ICNTGRPS   1  /* No. of groups */
#define NEWS_ICNTCACHE  2  /* No. of cached groups */
#define NEWS_ITIMEINT   3  /* Interval of cache clears */
#define NEWS_IMINTOUCH  4  /* Min. touches for cache-hold */
#define NEWS_ILASTFLUSH 5  /* time() of last cache-flush */
#define NEWS_IDSAVEINT  6  /* Interval of _delayed_save's */
#define NEWS_IDSAVEPEND 7  /* Time to next _delayed_save or -1 if none */

#define NEWS_ISIZE     8

  /* Returnvalues of the master */

#define NEWS_OK        1  
#define NEWS_ILLPARM   0  /* Ill. Parameter */
#define NEWS_NORIGHT  -1  /* No permission */
#define NEWS_ILLGROUP -2  /* Group does/doesn't exist */
#define NEWS_ILLFILE  -3  /* Savefile does/doesn't exist */
#define NEWS_ILLNOTE  -3  /* Not that many notes */

#endif
