/*
   seqaction.h

   Some constants related to how NPC executes sequences
*/

#ifndef SEQ_DEFINED
#include "/config/sys/seqaction2.h"
#endif

#ifndef SEQ_DEFINED
#define SEQ_DEFINED

#define SEQ_MAX	 10			/* Max limit of sequences / NPC */
#define SEQ_SLOW 15.0			/* The slow factor */

/* Seconds a stoppable sequence stays awake after the last meeting 
   with an interactive player
*/
#define SEQ_STAY_AWAKE 60			
    	
/* Sequence flags
*/
#define SEQ_F_NONSTOP 1

#endif
