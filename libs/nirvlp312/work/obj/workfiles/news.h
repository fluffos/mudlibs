/******************************************************************************
 *  File:           news.h
 *  Function:       global defines for the news system
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         14/1/04
 *  Notes:          
 *  Change History:
 *****************************************************************************/
 
/* Pertinent Included Files */
#include "ansi.h"                                   /* Color Defs   */
#include "security.h"                               /* Security Defs*/

/* General Defines */
#define CREATOR     "vital"                         /* Me           */
#define VERSION     "1.9 Update"                    /* Keeping Track*/
#define ROOT        "/obj/daemons/"   /* Root Dir     */

/* News Directory Defines */
#define NEWS        "/open/NEWS/"                   /* News Dir     */
#define GROUPS      (NEWS + "groups/")                /* Groups Dir   */
#define ROOM        (ROOT + "newsroom.lpc")             /* News Room    */
#define POSTER      (ROOT + "composer.lpc")             /* News Daemon  */
#define READER      (ROOT + "newsd.lpc")            /* News Reader  */

/* Group Defines */
#define PROTECTED     ({  "inform", \
                          "guild", \
                          "misc", \
                          "area", \
                          "feedback" \
                      })
#define PLAYER_ACCESS ({  "poetry", \
                      })                /* Groups for players to post to */

/* Poster Defines */
#define NO_MESSAGE "Perhaps you will feel like posting something next time.\n"
    /* Error for posting without a message */
#define BLANK_SUBJECT "<Blank Subject Posting>"
    /* Standard header for posting without a header */
#define MAX_TITLE 32
#define MAX_SIZE  49
#define MAX_LINE  1000

/* Reader Defines */
#define SUBLIMIT  5     /* Limit to subgroup folder depth */
#define DATESTAMP 1,1   /* Datestamp Line */
#define SUBJECT   2,1   /* Subject Line */
#define AUTHOR    3,1   /* Author Line */
#define LVL       4,1   /* Author Level Line */
#define BDDY      5     /* Rest of the Message */
#define HEADER    1,3   /* Combined Header Info */
