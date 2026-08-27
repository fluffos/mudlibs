/*
 * /sys/alignment.h
 *
 * This module contains the alignment values that have been pre-defined
 * by the state-descriptions. For the good alignment, if your value is
 * higher than the definition you are considered to be of that alignment
 * and for evil alignments, you are considered to be of a certain alignment
 * when your level is below the defined value.
 */

#ifndef SYS_ALIGNMENT_DEFINITIONS
#define SYS_ALIGNMENT_DEFINITIONS

#define	ALIGN_MAX		( 1000)
#define	ALIGN_HOLY		(  910)
#define	ALIGN_SAINTLY		(  820)
#define	ALIGN_BLESSED		(  730)
#define	ALIGN_DEVOUT		(  640)
#define	ALIGN_GOOD		(  550)
#define	ALIGN_SWEET		(  460)
#define	ALIGN_NICE		(  370)
#define	ALIGN_SYMPATHETIC	(  280)
#define	ALIGN_TRUSTWORTHY	(  190)
#define	ALIGN_AGREEABLE		(  100)
#define	ALIGN_NEUTRAL		(    0)
#define	ALIGN_DISAGREEABLE	(  -80)
#define	ALIGN_UNTRUSTWORTHY	( -160)
#define	ALIGN_UNSYMPATHETIC	( -240)
#define	ALIGN_SINISTER		( -310)
#define	ALIGN_WICKED		( -390)
#define	ALIGN_NASTY		( -470)
#define	ALIGN_FOUL		( -540)
#define	ALIGN_EVIL		( -620)
#define	ALIGN_MALEVOLENT	( -700)
#define	ALIGN_BEASTLY		( -770)
#define	ALIGN_DEMONIC		( -850)
#define	ALIGN_DAMNED		( -930)
#define	ALIGN_MIN		(-1000)

/* No definitions beyond this line. */
#endif SYS_ALIGNMENT_DEFINITIONS
