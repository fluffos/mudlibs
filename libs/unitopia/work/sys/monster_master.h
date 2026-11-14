// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/monster_master.h
// Description:	Die Defines fuer den Monster-Master
// Author:	Freaky (29.10.1998)
//
// $Log: monster_master.h,v $
// Revision 1.3  2003/05/29 21:40:24  menaures
// Koerperformen "insekt" und "gegenstand" hinzugefuegt
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef MONSTER_MASTER_H
#define MONSTER_MASTER_H 1

#define MD_RASSE		 0
#define MD_KOERPERFORM	 	 1
#define MD_KOERPERGROESSE	 2
#define MD_GESCHLECHT	 	 3
#define MD_STR_MIN		 4
#define MD_STR_MAX		 5
#define MD_INT_MIN		 6
#define MD_INT_MAX		 7
#define MD_CON_MIN		 8
#define MD_CON_MAX		 9
#define MD_DEX_MIN		10
#define MD_DEX_MAX		11
#define MD_NUM_HANDS		12
#define MD_HAND_NAME		13
#define MD_WC_MIN		14
#define MD_WC_MAX		15
#define MD_AC_MIN		16
#define MD_AC_MAX		17
#define MD_HP_MIN		18
#define MD_HP_MAX		19
#define MD_SP_MIN		20
#define MD_SP_MAX		21
#define MD_ABILITIES		22
#define MD_SIZE_RASSE		23

#define MD_AB_WALK		1
#define MD_AB_SWIM		2
#define MD_AB_FLY		4

#define MD_HAND_GENDER 		0
#define MD_HAND_PLURAL 		1
#define MD_SIZE_HAND 		2

#define MD_DEF_RASSE "mensch"

#define MD_KOERPERFORMEN ({"vogel","schlange","vierbeiner","humanoid","fisch","gegenstand","insekt"})

#endif // MONSTER_MASTER_H
