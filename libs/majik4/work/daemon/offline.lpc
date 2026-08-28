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

mapping offline;

void
create ()
{
/*   string *k;
   object o;*/
   
   load_object (base_name(THOB));

   if (!offline)
	 offline = ([ 0 : 0 ]);
   
/*   k = keys (offline);
   
   for (int i=0;i<sizeof(k);i++)
	 {
		if (file_size ("/data/player/"+k[i][0..0]+"/"+k[i]+".o") > 0)
		  {
			 log_file ("offline.log", "found "+k[i]+"\n");
			 o = new ("/secure/player");
			 o->restore_me (k[i]);
			 o->setup (k[i]);
			 o->set_offline (1);
		  }
	 }
 */
}

void
add_offline (object o)
{  
   string name;
   
   if (!ENV(o) || !MAPENV(o))
	 return;
     
   if (member_array(o->query_true_name(), keys (offline)) > -1)
	 return;
	 
   offline += ([ o->query_true_name() : ({ o->query_gridx(), o->query_gridy(), base_name(MAPENV(o)) }) ]);
   o->set_offline (1);
   o->save_me();
   name = o->query_true_name();
   o->remove();
   o = new ("/secure/player");
   o->restore_me (name);
   o->setup (name);
   o->process_input (CMD_START + ":0:-1");
   o->set_offline (1);
   
   save_object (base_name(THOB));
}

varargs void
remove_offline (string name, int flag)
{
   object o;
      
   o = find_player (name);
   
   if (flag && o)
	 {
		o->set_dead(1);
		o->save_me();
		o->set_offline(0);
	 }
   
   if (o)
	 {	
		if (!flag)
		  {
			 o->set_offline (0);
			 o->save_me();
		  }
		
		o->remove();
	 }
	 
   map_delete (offline, name);
   save_object (base_name(THOB));
}
