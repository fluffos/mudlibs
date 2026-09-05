/*
 *      File:                   filename.c
 *      Function:               
 *      Author(s):              YourName@Nirvana
 *      Copyright:              Copyright (c) 2004 YourName
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

string pwd; 

/* ======================================================================
 * 
 * ======================================================================
 */

 
 
 
/* ======================================================================
 * 
 * ======================================================================
 */





/* ======================================================================
 * query/set pwd 
 * ======================================================================
 */
 
status set_pwd(string str) {
  private;
  
  if (object_name(previous_object())[0..6] != "bin/wiz")
    return 0;

  pwd = (str[<1] == '/' ? str : sprintf("%s/", str));
}

string query_pwd() 
{
  int plev;
  
  plev = (int)this_player()->query_level();
  
  if ( this_player() && this_player() != this_object()
  && (plev < ELDER || (int)this_object()()->query_level() >= plev) )
    return "";
  return pwd;
}

string get_path() { return query_pwd(); }
