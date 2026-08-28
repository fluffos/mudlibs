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

#include <color.h>
#include <security.h>
#include <list.h>

inherit ITEM;

mapping msg;
nosave string savefile;

int
do_sort (mixed a, mixed b)
{   
   if(a > b)
	 return 1;
   else if(a == b)
	 return 0;
   else
	 return -1;
}

string
set_savefile (string str)
{   
   return savefile = str;
}

void
create_item ()
{
   THOB->create_board();
   
   if (!savefile) 
	 {
		savefile = file_name(THOB);
		sscanf (savefile, "%s#%*s", savefile);
	 }
   
   restore_object (savefile);
   
   /* defaults */
   
   THOB->set_name ("board");
   THOB->set_gridchar ('_');
   THOB->set_gridcolor (C_BROWN);
   THOB->set_physical (TRUE);
   THOB->set_no_get ("The bulletin board is firmly attached to the ground.");
   THOB->set_material ("oak");
   
   THOB->add_command ("read", file_name(THOB) + "->command_read");
   THOB->add_command ("write", file_name(THOB) + "->command_write");
   THOB->add_command ("remove", file_name(THOB) + "->command_remove");
}

int
command_remove (string str)
{
   string s1, s2, *k;
   int i;
   
   if (!str || str == "" || present(MAPENV(THIS), explode(str, " ")[0], THIS->query_gridx(), THIS->query_gridy(), 1) != THOB)
	 {	
		THIS->notify_fail ("Remove what?\n");
		return 0;
	 }
  
   if (sscanf(str, "%s %s", s1, s2) != 2)
	 {
	    message (CMD_MSG, 0,0,0, "Usage: remove board <number>", THIS);
		return 1;
	 }
   
   if (!msg)
	 msg = ([ ]);
   
   k = keys(msg);
   k = sort_array(k, "do_sort");
   
   i = to_int(s2);
   i--;
   
   if (i<0 || i>(sizeof(k)-1))
	 {
		message (CMD_MSG,0,0,0, "No such message.", THIS);
		return 1;
	 }
   else if (msg[k[i]][0] != THIS->query_true_name() && THIS->query_security() < SEC_LESSER_GOD)
	 {		
		message (CMD_MSG,0,0,0, "You can't remove that message.", THIS);
		return 1;
	 }
     else
	 {		
		map_delete (msg, k[i]);
		
		message (CMD_SEE,THIS->query_gridx(),THIS->query_gridy(),VISIBLE_RADIUS, "$N1 {remove} message number "+(i+1)+" from the board.", MAPENV(THIS), THIS);
		save_object (savefile);
	 }
   
   return 1;
}

int
command_read (string str)
{
   string s1, s2, *k, buf = "";
   int i;
   
   if (!str || str == "" || present(MAPENV(THIS), explode(str, " ")[0], THIS->query_gridx(), THIS->query_gridy(), 1) != THOB)
	 {
		THIS->notify_fail ("Read what?\n");
		return 0;
	 }
   
   if (sscanf(str, "%s %s", s1, s2) != 2)
	 {
		message (CMD_MSG,0,0,0, "Usage: read board <number>", THIS);
		return 1;
	 }
   
   if (!msg)
	 msg = ([ ]);
   
   k = keys(msg);
   k = sort_array(k, "do_sort");
   
   i = to_int(s2);
   i--;
   
   if (i<0 || i>(sizeof(k)-1))
	 {	
		message (CMD_MSG,0,0,0, "No such message.", THIS);
		return 1;
	 }
   else
	 {	
		buf += "Date: "+ctime(to_int(k[i]))+";";
		buf += "From: "+msg[k[i]][0]+";";
		buf += " ;";
		buf += "Subject: ^c1"+msg[k[i]][1]+";";
		buf += wrap(msg[k[i]][2])+";";
		
		open_window(THIS, 0,0,0,0, LTYPE_TEXT, "Board message:", "noop", buf);
		message (CMD_SEE,THIS->query_gridx(),THIS->query_gridy(),VISIBLE_RADIUS, "$N1 {read} message number "+(i+1)+" from the board.", MAPENV(THIS), THIS, THIS);
	 }
   
   return 1;
}

int
command_write (string str)
{
   string s1, s2, s3, *k;
   int t;
   
   if (!str || str == "" || present(MAPENV(THIS), explode(str, " ")[0], THIS->query_gridx(), THIS->query_gridy(), 1) != THOB)
	 {
		THIS->notify_fail ("Write on what?\n");
		return 0;
	 }
   
   if (sscanf(str, "%s (%s) %s", s1, s2, s3) != 3)
	 {
		message (CMD_MSG, 0,0,0, "Usage: write board (<subject>) <message>", THIS);
		message (CMD_MSG, 0,0,0, "Example: write board (test subject) this is a message", THIS);
		return 1;
	 }
   
   if (!msg)
	 msg = ([ ]);
   
   k = keys(msg);
   k = sort_array(k, "do_sort");
   
   if (sizeof(k) > 15)
	 map_delete (msg, k[0]);
   
   t = time();
   
   msg[t] = ({ THIS->query_true_name(), s2, wrap(s3) });
   
   message (CMD_SEE, THIS->query_gridx(), THIS->query_gridy(), VISIBLE_RADIUS, "$N1 {write} a new message on the board.", MAPENV(THIS), THIS);
   save_object (savefile);
   
   return 1;
}

string
query_short ()
{
   string *k;
   int sz;
   
   if (!msg)
	 msg = ([ ]);
   
   k = keys(msg);
   sz = sizeof(k);
   
   if (!sz)
	 return ::query_short() + " (empty)";
   else if (sz == 1)
	 return ::query_short() + " (one message)";
   else
	 return ::query_short() + " ("+sz+" messages)";
}

string
query_long ()
{
   string buf = "", *k;
   int sz;
      
   if (!msg)
	 msg = ([ ]);
   
   k = keys(msg);
   sz = sizeof(k);
   
   if (k)
	 k = sort_array(k, "do_sort");
   
   if (!sz)
	 buf += "The board is empty.\n";
   else if (sz == 1)
	 buf += "There is only one message on the board:\n";
   else
	 buf += "There are "+sz+" messages on the board:\n";
   
   for (int i=0;i<sz;i++)
	 {	
		buf += sprintf ("^c0^cc%2d^c0. %-16s (%-11s) :: ^c1%s^c0\n", i+1,
						msg[k[i]][0][0..15], ctime(to_int(k[i]))[4..15], msg[k[i]][1]);
	 }
   
   return buf;
}
