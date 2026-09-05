#ifndef _sys_alignment_h
#define _sys_alignment_h

#include "living.h"

/* The values are the lower margins for the given alignments */

#define AL_SAINTLY (KILL_NEUTRAL_ALIGNMENT * 100)
#define AL_GOOD    (KILL_NEUTRAL_ALIGNMENT * 20)
#define AL_NICE    (KILL_NEUTRAL_ALIGNMENT * 4)
#define AL_NEUTRAL (KILL_NEUTRAL_ALIGNMENT * -4)
#define AL_NASTY   (KILL_NEUTRAL_ALIGNMENT * -20)
#define AL_EVIL    (KILL_NEUTRAL_ALIGNMENT * -100)
#define AL_DEMONIC (-0x80000000)

#endif /* _sys_alignment_h */
