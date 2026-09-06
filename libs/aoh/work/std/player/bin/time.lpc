/*--------------------------------------------------------------------------
 * /std/player/bin/time.c  --  The OSB time command
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * [Tune]    25-Apr-98 creation
 * [Mateese] 02-Jug-98 Added Usenet time to the 'time all' display.
 *    An explanation: Around 1990 a lot of the American colleges provided
 *    their students with computers in their dorms. So every September there
 *    was a flood of freshmen discovering Internet und Usenet, and, not
 *    knowing the rules, causing a lot of noise and trouble. This never
 *    lasted long - towards the end of September the rules were taught and
 *    the noise subsided. In typical Usenet style this period was named
 *    the "Usenet September", begin and end defined by the increase and
 *    decrease of noise produced by unknowing newbies. Then in September
 *    1993 AOL connected to the Internet, and the resulting Usenet September
 *    hasn't ended yet.
 */

#include <properties.h>
#include <daemons.h>
#include <nightday.h>

// prototypes
private string get_rl_time();
private string get_aol_time();
private string get_osb_time();


public int main( string arg ) 
{
  string s;
  mixed * uptime;
  int flag;
  
  s = "";
  
  if( !arg )
     arg = ({string})this_player()->Query(P_TIME_OPTIONS);
  else
     flag = 1;
  
  switch( arg )
  {
     case TIME_OSB:
       s += get_osb_time();
       break;
     case TIME_RL:
       s += get_rl_time();
       break;
     case TIME_ALL:
       s += get_osb_time();
       s += get_rl_time();
       s += get_aol_time();
   }
  
  if (!flag)
  {
     uptime = ({mixed *})GAMECLOCK->QueryUptime();
     s += "[ Time since genesis: ";
     if (!pointerp(uptime))
       s += "unknown";
     else
       s += implode(map(uptime, #'to_string /*'*/), " ");
     s += " ]\n";

  }

  object shut = find_object(SHUTDEMON);
  if (shut && ({int})shut->query_progress())
  {
    int tleft = ({int})shut->query_time_left();
    int hours = tleft / 3600;
    int min = (tleft / 60) % 60;
    s += sprintf("\n" MUDNAME " will reboot in %d:%02d hours (%s)\n"
                , hours, min, ({string})shut->query_reason());
  }
  
  write(s);
  return 1;
}

private string get_rl_time()
{
  string cdate;
   
  cdate = ctime(time());
  return  "Real World time is: "+cdate[0..2]+" "+cdate[8..9]+"-"+cdate[4..6]+
          "-"+cdate[22..23]+" "+cdate[11..18]+" CT\n";

}

private string get_aol_time()
{
  string cdate;
  int dt;
#define FIRST_SEP 746834400 /* 1.Sep 93: The month AOL got onto the Internet */

  cdate = ctime(time());
  if (time() < FIRST_SEP)
    return  "Real World time is: "+cdate[0..2]+" "+cdate[8..9]+"-"+cdate[4..6]+
            "-"+cdate[22..23]+" "+cdate[11..18]+" CT\n";
  dt = (time()-FIRST_SEP) / (24*3600) + 1;
  return "Usenet time is: "+cdate[0..2]+" "+sprintf("%4d", dt)+"-Sep-93 "
         +cdate[11..18]+" CT\n"; 
}

private string get_osb_time()
{
   mixed *date;
   
   date = ({mixed *})NIGHTDAY->QueryDate();
  
   return "Today is the " + otoa(date[0], 1) + " day of " + date[1] 
           + " " + date[2] + ". It is currently " 
           + ({string})NIGHTDAY->QueryTimeString() + ".\n";
}

  
