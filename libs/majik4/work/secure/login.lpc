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

#include <mcp.h>

string name, password;

void
logon ()
{
   write_client (THOB, CMD_START, "$Revision: 1.19 $");
   write_client (THOB, CMD_ASK_NAME, 0);
}

string
write_prompt ()
{
   return "";
}

string
process_input (string str)
{
   int command, datalen;
   mixed data;
   string pass, tmp;
   object o;
   int log_command, log_datalen;
   string log_data, *file, buf = "";
   
   if (sscanf (str, "%d:%d:%s", command, datalen, data) == 3)
	 { 
		switch (command)
		  {
		   case CMD_LOGIN_NAME:
			 name = strlen(data) ? lower_case(data) : data;
			 break;
		   case CMD_LOGIN_PASS:
			 pass = data;
			 break;
		   case CMD_COMMAND:
			 write_client (THOB, CMD_MSG, "CMD_COMMAND is not available until you're logged in.");
			 break;
		  }
	 }
   
   if (!name || name == "")
	 write_client (THOB, CMD_ASK_NAME, 0);
   else if (!pass || pass == "")
	 {
		if (file_size ("/data/player/" + name[0..0] + "/" + name + ".o") == -1 &&
			file_size ("/data/player/" + name[0..0] + "/" + name + ".msg") != -1)
		  {			 
			 file = explode (read_file ("/data/player/"+name[0..0]+"/"+name+".msg"), "\n");
			 
			 for (int i=0;i<sizeof(file);i++)
			   {				  
				  if (sscanf (file[i], "%d:%d:%s", log_command, log_datalen, log_data) == 3)
					{					   
					   if (log_command == CMD_MSG || log_command == CMD_FEEL || log_command == CMD_SEE ||
						   log_command == CMD_HEAR || log_command == CMD_SMELL || log_command == CMD_TASTE ||
						   log_command == CMD_SENSE || log_command == CMD_OOC || log_command == CMD_INFO ||
						   log_command == CMD_QUIT)
						 buf += log_data;
					}
			   }
			 
			 rm ("/data/player/"+name[0..0]+"/"+name+".msg");
			 write_client (THOB, CMD_QUIT, buf);
		  }
		else if (file_size ("/data/player/" + name[0..0] + "/" + name + ".o") == -1)
		  message (CMD_MSG, 0,0,0, "New character.", THOB);
		
		write_client (THOB, CMD_ASK_PASS, 0);
	 }
   else
	 {
		tmp = name;	
		o = find_player(name);
		
		if (o)
		  {           /* Player exists in game */
			 OFFLINE_D->remove_offline (name);			 
			 if (o)
			   o->remove();
		  }
		
		if (restore_object ("/data/player/" + name[0..0] + "/" + name))
		  {
			 if (password)
			   {
				  if (crypt (pass, password) != password)
					{
					   message (CMD_MSG, 0,0,0, "Login incorrect.", THOB);
					   pass = 0;
					   name = 0;
					   write_client (THOB, CMD_ASK_NAME, 0);
					   return str;
					}
			   }
		  }
		else /* this is obviously a new character */
		  {
			 name = tmp;
			 password = crypt (pass, 0);
			 
			 OFFLINE_D->remove_offline (name);
			 
			 o = new ("/secure/player");
			 
			 o->set_name (name);
			 o->set_password (password);
			 o->set_offline (0);
			 o->add_money (5 + random (10));
			 
			 // o->set_gridpos(2640,5528);  // A kludge? No.... 
			 o->save_me ();
		  }
		
		write_client (THOB, CMD_START, "$Revision: 1.19 $");
		
		OFFLINE_D->remove_offline (name);
		
		o = new ("/secure/player");
		
		o->restore_me (name);
		
		if (o->query_dead())
		  {
			 write_client (THOB, CMD_QUIT, "This character has been killed. Select another.");
			 destruct (o);
			 return "";
		  }
			 
		o->setup (name);
		o->set_offline (0);
				
		if (o)
		  {
			 exec (o, THOB); /* switch from login to player object */
			 destruct (THOB);
		  }
	 }
   
   return str;
}
