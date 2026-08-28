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
#include <material.h>

inherit GRIDOBJECT;

nosave int xdim, ydim, zdim;
nosave int hollow;
string material;
nosave mixed no_get;

nosave int is_wielded;
int hp;          /* hit points of the item                             */
mixed generate;  /* array used to generate item                        */
mapping command;
nosave string default_apply;

void
set_default (string str)
{
   default_apply = str;
}

string
query_default (string str)
{
   return default_apply;
}

int
query_value ()
{
   return (THOB->query_weight() / 1000.0 * MATERIAL_D->query_material(THOB->query_material())[MARR_VALUE] / 100.0) + 1 + random(10);
}

int
set_no_get (mixed str)
{
   return no_get = str;
}

mixed
query_no_get ()
{
   return no_get;
}

int
is_item ()
{
   return 1;
}

int
is_unique ()
{
   return generate ? 0 : 1;
}

int
set_wielded (int i)
{
   if(i)
	 THOB->set_default ("remove");
   else
	 THOB->set_default ("wield");
   return is_wielded = i;
}

int
is_wielded ()
{
   return is_wielded;
}

string
set_material (string str)
{
   return material = str;
}

string
query_material ()
{
   return material;
}

mixed
set_generate (mixed s1, mixed s2, mixed s3)
{
   return generate = ({ s1, s2, s3 });
}

mixed
query_generate ()
{
   return generate;
}

void
set_dimension (int x, int y, int z, int h)
{
   xdim = x;
   ydim = y;
   zdim = z;
   hollow = h;
}

int
query_weight()
{
   object *all, o;
   int hol, ret, dm3;
      
   if (hollow)
	 hol = (xdim*ydim*zdim)*hollow/100;
   
   dm3 = (xdim*ydim*zdim)-hol;
   
   if(MATERIAL_D->query_material(THOB->query_material()))
	 ret += 100 * MATERIAL_D->query_material(THOB->query_material())[MARR_WEIGHT] * dm3 / 100;
      
   all = all_inventory(THOB);
   
   if (all)
	 {
		foreach (o in all)   
		  ret += o->query_weight();
	 }
   
   return ret;
}

void
create_gridobject ()
{
   THOB->create_item();
}

int
save_me (string file)
{
   return save_object (file);
}

int
restore_me (string file)
{
   return restore_me (file);
}

mapping
save_map ()
{
   mixed *all;
   mapping m = ([ ]);
   
   all = variables (THOB, 1);
   
   for (int i = 0; i < sizeof (all); i++)
	 {
		if (strsrch (all[i][1], "nosave") > -1)
		  continue;
		
		m[all[i][0]] = save_variable (fetch_variable (all[i][0]));
	 }
   
   return m;
}

int
restore_map (mapping m)
{
   string *k, *v = ({ });
   mixed *all;
   int i;
   
   if (m)
	 {
		k = keys (m);
		all = variables (THOB, 1);
		
		for (i = 0; i < sizeof (all); i++)
		  {
			 if (strsrch (all[i][1], "nosave") > -1)
			   continue;
			 else
			   {
				  if (!v)
					v = ({ all[i][0] });
				  else
					v += ({ all[i][0] });
			   }
		  }
		
		for (i = 0; i < sizeof (k); i++)
		  {
			 if (member_array (k[i], v) > -1)
			   store_variable (k[i], restore_variable (m[k[i]]));
		  }
	 }
   return i;
}
