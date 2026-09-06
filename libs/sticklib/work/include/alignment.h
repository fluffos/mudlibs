// Standard alignment levels. Use these if you want to consider alignment
// levels, or set them. Note that standard monster (/include/npc.h) already
// includes this file.

#ifndef _ALIGNMENT_H
#define _ALIGNMENT_H

#ifndef AL_RATIO
// Alignment ratio; one has to have at least 90% of the level to
// be of certain alignment type.
#define	AL_RATIO	90
#endif

#define	AL_ANGELIC	2000
#define	AL_SAINTLY	1200
#define AL_VERY_GOOD	800
#define	AL_GOOD		500
#define	AL_QUITE_GOOD	400
#define	AL_VERY_NICE	300
#define	AL_NICE		100
#define	AL_QUITE_NICE	50

#define	AL_NEUTRAL	0

#define	AL_QUITE_NASTY	-50
#define	AL_NASTY	-100
#define AL_VERY_NASTY	-300
#define	AL_QUITE_EVIL	-400
#define	AL_EVIL		-500
#define AL_VERY_EVIL	-800
#define	AL_DEMONIC	-1200
#define	AL_SATANIC	-2000

#endif /* ALIGNMENT_H */
