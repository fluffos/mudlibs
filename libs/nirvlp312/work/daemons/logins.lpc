/*
 *      File:                   /daemons/logins.c
 *      Function:               Tracks recent logins
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2007 David Halek
 *                                      All Rights Reserved.
 *      Source:                 08/28/07
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

#define LIST_LENGTH 20

/* Global Variables */
string *AllInfo;

void add_entry(string name, string level)
{
  string temp;
  
  temp = ctime()+": "+ralign(level+" ", 7)+capitalize(name)+"\n";
  
  if (!AllInfo) 
    AllInfo = ({ temp });  
  else if (sizeof(AllInfo) < LIST_LENGTH)
    AllInfo += ({ temp });
  else
#ifndef __LDMUD__ /* Rumplemintz */
    AllInfo = AllInfo[1..-2] + ({ temp });
#else
    AllInfo = AllInfo[1..<2] + ({ temp });
#endif
}

string *query_logins() { return AllInfo+({ }); }



/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
