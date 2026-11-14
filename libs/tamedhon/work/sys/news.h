// SilberLand MUDlib
//
// sys/news.h -- news master defines
//
// $Date: 1997/03/31 13:12:16 $
/* $Revision: 1.1 $
 * $Log: news.h,v $
 * Revision 1.1  1997/03/31 13:12:16  Woody
 * prepared for revision control
 *
 */

#ifndef __NEWS_H__
#define __NEWS_H__

#define G_NAME 0
#define G_OWNER 1
#define G_SAVEFILE 2
#define G_EXPIRE 3
#define G_DELETERS 4 
#define G_WRITERS 5
#define G_READERS 6
#define G_DLEVEL 7
#define G_WLEVEL 8
#define G_RLEVEL 9
#define G_MAX_MSG 10
#ifdef TESTING
#define G_MAX_NUM 11
#define G_MESSAGES 12
#else
#define G_MESSAGES 11
#endif

#define M_BOARD 0
#define M_WRITER 1
#define M_ID 2
#define M_TIME 3
#define M_TITLE 4
#define M_MESSAGE 5

#endif

