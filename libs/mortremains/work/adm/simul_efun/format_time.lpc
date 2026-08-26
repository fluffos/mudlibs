// format_time.c
// Written by Huthar@Portals
// Verbose output by Watcher@TMI  (09/26/92)
//
// Returns a time in the form of 1d 3h 7m 18s if verbose = 0
// otherwise it returns it as 1 day 3 hours 7 minutes 18 seconds

string format_time(int tm, int verbose) {
    int weeks, years;
    int days,hours,minutes,seconds;
    string str;

    str = "";

    if(!tm) 
	if(verbose)  return "0 seconds";  
	else	     return "0s";

    years = tm / 31449600;
    tm = tm % 31449600;

    weeks = tm / 604800;
    tm = tm % 604800;

    days = tm / 86400;
    tm = tm % 86400;

    hours = tm / 3600;
    tm = tm % 3600;

    minutes = tm / 60;
    seconds = tm % 60;

    if(years)
	if(!verbose)  str += years + "y ";
	else {
	if(years == 1)  str += years + " year ";
	else		str += years + " years ";  }
 
    if(weeks)
	if(!verbose)  str += weeks + "w ";
	else {
	if(weeks == 1)  str += weeks + " week ";
	else		str += weeks + " weeks ";  }
 
    if(days)
	if(!verbose)  str += days + "d ";
	else {
	if(days == 1) 	str += days + " day ";
	else		str += days + " days ";  }
 
    if(hours)
	if(!verbose)  str += hours + "h ";
	else {
	if(hours == 1)	str += hours + " hour ";
	else		str += hours + " hours ";  }
 
    if(minutes)
	if(!verbose)  str += minutes + "m ";
	else {
	if(minutes == 1) str += minutes + " minute ";
	else		 str += minutes + " minutes ";  }
 
    if(seconds)
	if(!verbose)  str += seconds + "s ";
	else {
	if(seconds == 1) str += seconds + " second";
	else		 str += seconds + " seconds";  }
 

    if(str[<1] == ' ')  str = str[0..<2];
 
return str; }
 





//	Function:	intl_date_stamp
//	Author:		Inspiral@Tabor, etc
//	Created:	930818
//	Purpose:	Parse ctime( time() ) format
//			  into international shorthand
//	Syntax:		- w/o time_flag argument, returns
//			    "930818", where 0818 is Aug 18
//			- with time_flag, returns 
//			    "930818 20:12:14"
// 
// Changed status to int type Leto 11/9/94

#define MONTHS ({ "Jan", "Feb", "Mar", "Apr", "May", \
		"Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" })

varargs string intl_date_stamp( int time_flag ) {
   int day, year;
   string tm, ret;
   mixed month;

   sscanf( ctime( time() ), "%*s %s %d %s 19%d",
	month, day, tm, year );

/*
   month = 1 + member_array( month, MONTHS );

	if( month < 10 ) month = "0" + month;
	else month += "";

	ret = sprintf( "%d-%s-%d", year, month, day );
*/

// Suggestion of Beek

   ret = sprintf( "%d-%02d-%d", year, 1 + member_array( month, MONTHS ), day );

   if( time_flag) return sprintf( "%s %s", ret, tm );
   else return ret;	   
}
