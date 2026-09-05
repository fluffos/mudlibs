/*
 *      File:                   /daemons/misc.c
 *      Function:               Miscellaneous functions
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2007 David Halek
 *                                      All Rights Reserved.
 *      Source:                 07/12/07
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

/* Global Variables */
string Date;     /* Date in mmddyy format */

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */


string get_date()
{
  if (!Date || !strlen(Date))
  {
    string month, day, year, ack, ugh;
    
    sscanf(ctime(), "%s %s %s %s %s", ack, month, day, ugh, year);
    
    switch(month)
    {
      case "Jan" : month = "01"; break; 
      case "Feb" : month = "02"; break;
      case "Mar" : month = "03"; break;
      case "Apr" : month = "04"; break;
      case "May" : month = "05"; break;
      case "Jun" : month = "06"; break;
      case "Jul" : month = "07"; break;
      case "Aug" : month = "08"; break;
      case "Sep" : month = "09"; break;
      case "Oct" : month = "10"; break;
      case "Nov" : month = "11"; break; 
      case "Dec" : month = "12";
    }
    
    Date = month + (day[0..0] != " " ? day : "0"+day[1..1]) + year[2..3];
  }
  
  return Date;
}

/******************************************************************************
 * Function: display_date
 *
 * Purpose: Displays the date in a user friendly format.
 * 
 * Parameters:
 *          bday - String representing date as mmddyy
 *
 * Returns: String with the date as Mon dd
 * 
 * History:
 *          08/11/2016 - Dragnar
 *            Created
 ******************************************************************************/
string display_date( string bday ) {
  string mon;

  if( !bday || !strlen(bday) )
    return 0;

  mon = bday[0..1];

  switch(mon) {
    case "01" : mon = "Jan"; break;
    case "02" : mon = "Feb"; break;
    case "03" : mon = "Mar"; break;
    case "04" : mon = "Apr"; break;
    case "05" : mon = "May"; break;
    case "06" : mon = "Jun"; break;
    case "07" : mon = "Jul"; break;
    case "08" : mon = "Aug"; break;
    case "09" : mon = "Sep"; break;
    case "10" : mon = "Oct"; break;
    case "11" : mon = "Nov"; break;
    case "12" : mon = "Dec"; break;
  }

  return mon + " " + bday[2..3];
}

/******************************************************************************
 * Function: verify_bday
 *
 * Purpose: Verifies the bday string. Some players have bad data so a double
 *          check needs to be run when they login.
 * Parameters:
 *          bday - String representing date as mmddyy
 *
 * Returns: 0 - invalid date
 *          1 - valid date
 * History:
 *          08/11/2016 - Dragnar
 *            Created
 ******************************************************************************/

int verify_bday( string bday ) {
  int i, nbr;
  string substr;
  string *digits;

  if( !bday )
    return 0;

  /** Length must be six **/
  if( strlen( bday) != 6 )
    return 0;

  /** Must contain only numbers **/
  digits = explode( bday, "" );
  for( i=0; i < sizeof(digits); i++ ) {
    if( sscanf( digits[i], "%d", nbr ) != 1 )
      return 0;
  }

  /** Validate month **/
  substr = bday[0..1];
  if( sscanf( substr, "%d", nbr ) !=1 )
    return 0;
  if( nbr < 1 || nbr > 12 )
    return 0;


  /** Validate day **/
  substr = bday[2..3];
  if( sscanf( substr, "%d", nbr ) !=1 )
    return 0;
  if( nbr < 1 || nbr > 31 )
    return 0;


  /** Validate year **/
  substr = bday[4..5];
  if( sscanf( substr, "%d", nbr ) != 1 )
    return 0;

  return 1;
}
