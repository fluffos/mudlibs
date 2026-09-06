#ifndef _TALKCONST_H_
#define _TALKCONST_H_

// A list of "meaning" flags, which are used to give definitions to special
// nouns (pronouns, possessives, etc.)

#define NFIRSTP  0x00000001
#define NSECONDP 0x00000002
#define NTHIRDP  0x00000004
#define NPLURAL  0x00000008
#define NSUBJECT 0x00000010
#define NOBJECT  0x00000020
#define NPOSSESS 0x00000040
#define NATTRIB  0x00000080
#define NQUEST   0x00000100
#define NALL     0xFFFFFFFF

#define EYES     0x00000001
#define ENO      0x00000002

// Meaning flags for normal nouns

#define OTIME    0x00000001

// Meaning flags for verbs.

// Very common (utility verbs)
#define VBE      0x40000001
#define VHAVE    0x40000002
#define VGO      0x40000003
#define VUSE     0x40000004
#define VACT     0x40000005
#define VWANT    0x40000006
#define VGIVE    0x40000007

// Less common (physical actions, etc.)
#define VBUY     0x80000001
#define VALL     0xFFFFFFFF

#define QWHAT    0x00000001
#define QHOW     0x00000002
#define QWHERE   0x00000003
#define QWHY     0x00000004
#define QWHICH   0x00000005
#define QWHEN    0x00000006

#endif