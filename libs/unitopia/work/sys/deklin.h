// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/deklin.h
// Description: Defines fuer die Grammatik-Funktionen
// Author:      Garthan (1994)
//
// $Log: deklin.h,v $
// Revision 1.9  2009-01-15 09:32:38  gnomi
// ADJ_NICHT_DEKLIN definiert.
//
// Revision 1.8  2002/03/30 19:03:13  gnomi
// Anderer Name fuers neue Define.
//
// Revision 1.7  2002/03/29 06:16:16  gnomi
// Ein paar neue Defines fuer query_dekliniert.
//
// Revision 1.6  2001/03/29 16:50:39  gnomi
// ART_NUR_JENER/MANCHER/WELCHER eingefuehrt.
//
// Revision 1.5  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

/* Defines zur Grammatik in /secure/deklin.c */

#ifndef DEKLIN_H
#define DEKLIN_H 1

/* Basic */
#define ART_EIN           1
#define ART_DER           2
#define ART_DIESER        3 
#define ART_MEIN          4
#define ART_DEIN          5
#define ART_SEIN          6
#define ART_ICH           7
#define ART_DU            8
#define ART_ER            9
#define ART_KEIN         10
#define ART_JENER        11
#define ART_MANCHER      12
#define ART_WELCHER      13
#define ART_BLANK        20

#define ART_MASK         0x00FF

#define ART_NO_PRONOM    0x0100
#define ART_NO_ADJEKTIV  0x0200
#define ART_NO_NOMEN     0x0400 
#define ART_GROUP        0x0800    /* unused, but reserved */
#define ART_VIS          0x1000
#define ART_INVIS        0x2000
#define ART_AUTO         0x4000
#define ART_CAPITALIZE   0x8000

/* Composed */
#define ART_NUR_PRONOM   ( ART_NO_ADJEKTIV | ART_NO_NOMEN )
#define ART_NUR_ADJEKTIV ( ART_NO_PRONOM | ART_NO_NOMEN )
#define ART_NUR_NOMEN    ( ART_NO_PRONOM | ART_NO_ADJEKTIV )

#define ART_AAA          ( ART_DER    | ART_AUTO )
#define ART_NUR_AAA      ( ART_DER    | ART_AUTO | \
			   ART_NO_ADJEKTIV | ART_NO_NOMEN )
#define ART_NUR_EIN      ( ART_EIN    | ART_NO_ADJEKTIV | ART_NO_NOMEN )
#define ART_NUR_DER      ( ART_DER    | ART_NO_ADJEKTIV | ART_NO_NOMEN )
#define ART_NUR_DIESER   ( ART_DIESER | ART_NO_ADJEKTIV | ART_NO_NOMEN )
#define ART_NUR_MEIN     ( ART_MEIN   | ART_NO_ADJEKTIV | ART_NO_NOMEN )
#define ART_NUR_DEIN     ( ART_DEIN   | ART_NO_ADJEKTIV | ART_NO_NOMEN )
#define ART_NUR_SEIN     ( ART_SEIN   | ART_NO_ADJEKTIV | ART_NO_NOMEN )
#define ART_NUR_KEIN     ( ART_SEIN   | ART_NO_ADJEKTIV | ART_NO_NOMEN )
#define ART_NUR_JENER    ( ART_JENER  | ART_NO_ADJEKTIV | ART_NO_NOMEN )
#define ART_NUR_MANCHER  ( ART_MANCHER | ART_NO_ADJEKTIV | ART_NO_NOMEN )
#define ART_NUR_WELCHER  ( ART_WELCHER | ART_NO_ADJEKTIV | ART_NO_NOMEN )

#define ART_KEINS_BEST   ( ART_DER   | ART_NO_PRONOM )
#define ART_KEINS_UNBEST ( ART_EIN   | ART_NO_PRONOM )
#define ART_KEINS        ( ART_BLANK | ART_NO_PRONOM )

#define FALL_NOM        1
#define FALL_GEN        2
#define FALL_DAT        3
#define FALL_AKK        4
#define FALL_DEF        0

#define OBJ_TO          0
#define OBJ_PO          1
#define OBJ_TP          2
#define OBJ_OW          3
#define OBJ_TI          4

#define DEKLIN_ERR_UNKNOWN_ERROR              0
#define DEKLIN_ERR_ILLEGAL_WHO                1
#define DEKLIN_ERR_MISSING_NAME               2
#define DEKLIN_ERR_1_AUTO_OWNER_WITH_VIRT_OBJ 3
#define DEKLIN_ERR_2_AUTO_OWNER_WITH_VIRT_OBJ 4
#define DEKLIN_ERR_ILLEGAL_ADJ		      5
#define DEKLIN_ERR_ILLEGAL_ART                6

// Fuer die Pronomen von Mengenangaben, siehe set/query_menge
#define PRON_NICHT_DEKLIN    1
#define PRON_NICHT_NACH_BEST 2

// Fuer die Adjektive
#define ADJ_NICHT_DEKLIN     1

// Flags und Makros fuer query_dekliniert (siehe dortige Doku)
#define DEKL_BESTIMMT		0
#define DEKL_UNBESTIMMT		1
#define DEKL_BLANK		2

#define DEKL_ART_MASK		3

#define DEKL_2_ADJ_ART(flags)	(ART_NUR_ADJEKTIV | ( ({ART_DER, ART_EIN, ART_BLANK})[(flags)&DEKL_ART_MASK] ) )

#endif // DEKLIN_H
