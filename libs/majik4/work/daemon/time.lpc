/* Majik 4 server
 * Copyright (C) 1998, 1999  Majik Development Team <majik@majik.netti.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* This is very simple version of time daemon and needs something, but
 * let's concentrate on base system first.
 */

#include <time.h>

/* Function prototypes */

int query_day ();
int query_hour ();
int query_minute ();
void create ();
void change_minute ();
void tell_outdoors (string);
void change_light ();
int query_sun_light ();
int quick_loop (int, int, int);
int gtime ();

/* Global variables - we don't need those! */

void
create ()
{
   call_out ("change_minute", GAME_MIN);
}

void
tell_outdoors (string str)
{
   object o, *u = users();
   
   foreach (o in u)
	 {
		/* FIXME: Insert outdoorness check here! */
		message (CMD_SEE, 0, 0, 0, str, o);
	 }
}

void
change_light ()
{
   object o, *u = users();
   
   foreach (o in u)
	 {
		write_client(o, CMD_SET_LIGHT, query_sun_light());
	 }
}

void
change_minute ()
{
   remove_call_out ("change_minute");
   
   /* FIXME: This should rely on sun's position, not on the time, but
	* as there is no system to move sun, so..
	*/
   if (query_minute() == 0)
	 {
		switch (query_hour ())
		  {
		   case 5:
			 tell_outdoors ("The sun rises in the east.");
			 change_light();
			 break;
		   case 6:
			 tell_outdoors ("The day has begun.");
			 change_light();
			 break;
		   case 9:
			 tell_outdoors ("The sun rises higher.");
			 change_light();
			 break;
		   case 11:
			 tell_outdoors ("The sun is now at its topmost position.");
			 change_light();
			 break;
		   case 16:
			 tell_outdoors ("The sun starts to descend.");
			 change_light();
			 break;
		   case 18:
			 tell_outdoors ("The shadows get longer.");
			 change_light();
			 break;
		   case 21:
			 tell_outdoors ("The sun slowly disappears in the west.");
			 change_light();
			 break;
		   case 22:
			 tell_outdoors ("The night has begun.");
			 change_light();
			 break;
		  }
		call_out ("change_minute", GAME_HOUR);
	 }
   else call_out ("change_minute", GAME_MIN);
	 
}

int
quick_loop (int val, int value, int correct)
{
   return (((time() - BIRTHDAY) / val) + correct) % value;
}
		
int
query_day ()
{
   return quick_loop (GAME_DAY, DAYS, 1);
}
   
int
query_hour ()
{
   return quick_loop (GAME_HOUR, HOURS, 0);
}

int
query_minute ()
{
   return quick_loop (GAME_MIN, MINUTES, 0);
}

/* query_sun_light() returns 3 when gridmap should be fully illuminated
 * on outdoor regions, 2 partially and 1 means moon & star light on
 * bright nights. !!Weather effects should modify this value!!
 */

int 
query_sun_light ()
{
   if (query_hour() < 5 || query_hour() > 21)
	 return 1;
   else if (query_hour() > 10 && query_hour() < 16)
	 return 5;
   else if (query_hour() > 8 && query_hour() < 18)
	 return 4;
   else if (query_hour() > 5 && query_hour() < 21)
	 return 3;
   else
	 return 2;
}

/* gtime() returns minutes since majik's birthday. It should be used
 * everywhere and thus we can have our time system to rely on game time,
 * not on rl time.
 */

int 
gtime ()
{
   return (time() - BIRTHDAY) / GAME_MIN;
}

