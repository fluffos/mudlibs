/*--------------------------------------------------------------------------
 * /p/daemons/gameclock  --  A Game uptime clock.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * The object offers a few functions to compute and describe the uptime
 * and the current daystate. Additionally, it implements the Clocktower
 * functionality. It cannot be cloned or moved.
 * The functions available to call from outside are:
 *
 *   string   QueryDaytime() : returns the descr of the current daytime.
 *   mixed  * QueryUptime()  : returns an array describing the uptime.
 *
 * The Clocktower feature is implemented by Bing() (called from create()).
 * To make sure the Clocktower is running, every /std/player attempts to
 * load this object upon login of a player.
 * TODO: The Clocktower should stop if nobody is there.
 * TODO: QueryDaytime() should to into nightday
 * TODO: QueryUptime() should be made sefun, breaking up seconds into YMDhms.
 *--------------------------------------------------------------------------
 * Changes: 22-Jun-97 [tune] Moved text strings in QueryDaytime() to inside
 *                           of DAEMONS(nightday.c). QueryDaytime() now
 *                           queries NIGHTDAY->QueryTimeString().
 *          25-Jul-97 [mica] changed tell_object to msg_object
 */

#include <config.h>
#include <nightday.h>
#include <msgclass.h>

public void StartBing(); // forward

//--------------------------------------------------------------------------
public void create ()
{
  if (member(object_name(this_object()), '#') != -1)
  {
    raise_error(object_name(this_object())+" should not be cloned.\n");
    destruct(this_object());
    return;
  }

  StartBing();
}

public int clean_up (int ref)
{
  if (ref <= 1)
    destruct(this_object());
  return this_object() && 1;
}

//--------------------------------------------------------------------------
public string QueryDaytime ()

// Return a description of the current daytime.
// If 0 is returned, either the NIGHTDAY cannot be found, or it returned
// something strange.

{
  string tmp;

  if (!find_object(NIGHTDAY))
    return 0;
  if(!tmp = ({string})NIGHTDAY->QueryTimeString())
    return 0;
  return tmp;
}

//--------------------------------------------------------------------------
public mixed * QueryUptime ()

// Determine the uptime and put it into a decent format. If the uptime
// cannot be determined, 0 is returned. The normal return is an array
// of this format:
//   ({ <number of days>   , "days"
//    , <number of hours>  , "hours"
//    , <number of minutes>, "minutes"
//    , <number of seconds>, "seconds"
//    })
//  but with two deviations: if one entry is just one unit (e.g. one minute),
//  the string uses the singular form, and leading zero entries are omitted.
// The 'seconds' entry is always present.
// Examples:
//   ({ 1, "day", 10, "hours", 3, "minutes", 2, "seconds" })
//   ({            3, "hours", 0, "minutes", 1, "second"  })
//   ({                                      0, "seconds" })

{
  mixed rc;
  int uptime, j;
  int firstset, boottime;

  boottime = query_boot_time();
  if (boottime < 1 || boottime > time())
    return 0;
  uptime = time() - boottime;

  rc = allocate(8);
  firstset = -1;

  j = uptime / 60 / 60 / 24;
  rc[0] = j;
  rc[1] = j == 1 ? "day" : "days";
  uptime -= j * 60 * 60 * 24;
  if (firstset < 0 && j != 0)
    firstset = 0;

  j = uptime / 60 / 60;
  rc[2] = j;
  rc[3] = j == 1 ? "hour" : "hours";
  uptime -= j * 60 * 60;
  if (firstset < 0 && j != 0)
    firstset = 2;

  j = uptime / 60;
  rc[4] = j;
  rc[5] = j == 1 ? "minute" : "minutes";
  uptime -= j * 60;
  if (firstset < 0 && j != 0)
    firstset = 4;

  rc[6] = uptime;
  rc[7] = uptime == 1 ? "second" : "seconds";
  if (firstset < 0)
    firstset = 6;

  return rc[firstset..];
}

//--------------------------------------------------------------------------
public void StartBing()

// Start the Clocktower call_out to Bing().

{
  int now, when;

  if (find_call_out("Bing") == -1)
  {
    now = time();
    when = (now/3600 + 1)*3600;
    call_out("Bing", when - now, when);
  }
}

//--------------------------------------------------------------------------
public void Bing (int when)

// Function implementing the Clocktower functionality. It calls itself
// in a call_out(), passing the nominal time of the scheduled call (to
// detect if the call happens too early).
// Upon call, the function converts the current time into a nice string
// and prints it to all players, then it schedules a call to itself
// for the next full hour.

{
  object *u;
  int i, now, h;
  string ampm, dayt;

  while (remove_call_out("Bing") != -1) /* nop */ ;

  if (!sizeof(users())) // No use running when nobody's here.
    return;

  now = time();
  if (time() < when)
  {
    call_out("Bing", when - now, when);
    return;
  }
  when = (now/3600+1)*3600;
  call_out("Bing", when - now, when);

//  sscanf(ctime(now), "%~s %~s %~d %d:%~d:%~d %~s", dow, mon, d, h, m, s, y);
  sscanf(ctime(now), "%~s %~s %~d %d:%~d:%~d %~s", h);

  if (h > 12) { h -= 12; ampm = "pm"; }
  else ampm = "am";
  if (dayt = QueryDaytime())
    dayt = " and "+dayt;
  else
    dayt = "";
  u = users();
  for ( ; i < sizeof(u); i++)
    msg_object( u[i], CMSG_ROOM,
"Another hour has passed. You hear the Silvere clocktower in the distance.\n"
+"It's now "+h+ /* " o'clock "+ */ ampm+dayt+".\n");
}

