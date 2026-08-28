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

int uid;

void
create()
{
   if (file_size ("/data") != -2)
	 mkdir ("/data");
   
   uid = to_int(read_file("/data/UID")) + 1;
   write_file("/data/UID", uid+"", 1);
}

int
query_uid()
{
   return uid;
}

void
move (mixed dest)
{
   move_object (dest);
}

void
remove ()
{
   if (ENV(THOB))
	 {
		if (MAPENV(THOB) && ENV(THOB)->is_gridmap())
		 {
			MAPENV(THOB)->object_exit(THOB);
			
			if (!THOB->is_living())
			  message(CMD_SEE, THOB->query_gridx(), THOB->query_gridy(), 
					  VISIBLE_RADIUS, "$N1 {turn} into a pile of dust.", 
					  MAPENV(THOB), THOB);
		 }
		else
		 {
			ENV(THOB)->update_inv();
			
			if (!THOB->is_living())
			  message(CMD_SEE, 0, 0, 0, "$N1 {turn} into a pile of dust.", 
					  ENV(THOB), THOB);
		 }
	 }
   destruct(THOB);
}
