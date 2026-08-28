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

#include <security.h>
#include <log.h>

/* The purpose of this daemon is to provide system-wide logging services.
 * Once the logging functions are in this file, write access to the /log/
 * directory can be explicitly allowed to this daemon. */

nosave mapping logfiles = ([

/*              log file     minimum security to listen for log file */
LOG_SYSTEM  : ({ "syslog", SEC_GOD }),
LOG_RUNTIME : ({ "runtime", SEC_LESSER_DEITY }),

LOG_BUG		: ({ "bugs", SEC_LESSER_DEITY }),
LOG_IDEA	: ({ "ideas", SEC_LESSER_DEITY })
]);

/* Log into system-wide logfiles (see mapping above) */

nomask int syslog(int file, string msg)
{
   object o, all;
   string d;
   
   if (!arrayp(logfiles[file]) ||
	   logfiles[file][0] == "")
	 return 0;
   
   d = "[" + ctime(time())[4..15] + "] ";
   
   return write_file("/log/" + logfiles[file][0], d + msg + "\n");
}

/* Log errors caused by wizards, that were previously in /log/<name> */

nomask int errorlog(string who, string msg)
{
   string d;
   d = "[" + ctime(time())[4..15] + "] ";
   
   if (file_size("/log/error") != -2)
	 mkdir("/log/error");
   
   return write_file("/log/error/" + lower_case(who), d + msg + "\n");
}

/* Wizards' .rep files */

nomask int replog(string who, string msg)
{
   string d; 
   d = "[" + ctime(time())[4..15] + "] ";
   
   if (file_size("/log/rep") != -2)
	 mkdir("/log/rep");
   
   return write_file("/log/rep/" + lower_case(who), d + msg + "\n");
}

nomask create()
{
   
}

