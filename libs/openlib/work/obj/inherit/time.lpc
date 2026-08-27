/*  -*- LPC -*-  */
// time.c:  Some useful time functions.  Also need to #include <time.h>
//          so you can use the #defines in there.
//
// Copyright (C) 1996 Tim McIntosh (tmcintos@dm.imaginary.com)
//
// This program is part of the OpenLib Mudlib distribution; it
// is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// If you acquired this program as part of the OpenLib Mudlib
// distribution, you should have received a copy of the GNU
// General Public License in the file /doc/GPL; if not,
// write to the Free Software Foundation, Inc., 675 Mass Ave,
// Cambridge, MA 02139, USA.
//
// Orig by Tim@Dysfunctional Mud
//
// NOTE: There are efuns to do this sort of thing...this should be phased out

#include <time.h>

string
get_date(int time, int which_part)
{
  string tmp, tmp2;

  switch(which_part) {
  case DATESTR_ALL:
    return ctime(time);

  case DATESTR_DATE:
    sscanf(ctime(time), "%*s %s %d %*s", tmp, tmp2);
    return tmp +" "+ tmp2;

  case DATESTR_TIME:
    sscanf(ctime(time), "%*s %*s %*s %s %*s", tmp);
    return "" + tmp;

  case DATESTR_YEAR:
    sscanf(ctime(time), "%*s %*s %*d %*s %d", tmp);
    return "" + tmp;

  case DATESTR_SHORT:
    sscanf(ctime(time), "%*s %s:%s:%*s %*s", tmp, tmp2);
    return tmp +":"+ tmp2;

  case DATESTR_DAY:
    sscanf(ctime(time), "%s %*s", tmp);
    switch(tmp) {
    case "Sun":
      return "Sunday";
    case "Mon":
      return "Monday";
    case "Tue":
      return "Tuesday";
    case "Wed":
      return "Wednesday";
    case "Thu":
      return "Thursday";
    case "Fri":
      return "Friday";
    case "Sat":
      return "Saturday";
    default:
      return "Someday";
    }

  case DATESTR_MONTH:
    sscanf(ctime(time), "%*s %s %*s", tmp);
    switch(tmp) {
    case "Jan":
      return "January";
    case "Feb":
      return "February";
    case "Mar":
      return "March";
    case "Apr":
      return "April";
    case "May":
      return "May";
    case "Jun":
      return "June";
    case "Jul":
      return "July";
    case "Aug":
      return "August";
    case "Sep":
      return "September";
    case "Oct":
      return "October";
    case "Nov":
      return "November";
    case "Dec":
      return "December";
    default:
      return "Janember";
    }

  default:
    return ctime(time);
  }
}
