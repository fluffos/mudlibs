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
#include <living.h>
#include <list.h>

inherit ITEM;

void
create_item()
{
   THOB->set_name("true name sphere");
   THOB->set_physical(TRUE);
   THOB->set_gridchar('*');
   THOB->set_gridcolor(C_DARK_GRAY);
   THOB->set_material("obsidian");
   THOB->set_dimension(200,200,200,0);
}

string
query_long()
{
   int xdist, ydist, dist;
   xdist = abs(THIS->query_gridx() - THOB->query_gridx());
   ydist = abs(THIS->query_gridy() - THOB->query_gridy());
   xdist > ydist ? dist = ydist : dist = xdist;
   
   if(dist > 2)
	 return ::query_long();
   
   if(member_array("creation", THIS->query_known_true_meanings()) == -1)
	 {
		THIS->set_position(POS_LYING);
		THIS->create_magical_true_name("creation");
		THIS->uncons();
		return "As you gaze at the crudely spherical obsidian shape, the cold, brutal "
		  "majesty which reeks from it's dead black surface makes you feel utterly "+
		  "powerless. You have a distinct feeling that the sphere is gazing back at "+
		  "you, investigating you, seeking the deepest cavities of your soul, yet you "+
		  "cannot perceive anything to support your feeling with mere mortal senses. "+
		  "The image of the sphere, etched in your confused mind, assumes a hypnotic "+
		  "pulsating dance that you cannot resist.\n \n"+
		  "You fall on your knees and drowsiness overcomes...\n \n"+
		  "You start to dream.\n \n"+
		  "You are on a light-bound path, floating in obscure nothingness. The way back "+
		  "is blocked by an impenetrable wall of imagination. You desperately pound "+
		  "your fists on the invisible wall, fear adding to your strength, but the "+
		  "effort is useless. The only way is forward.\n \n"+
		  "You take a reluctant step after reluctant step towards a blinding halo "+
		  "of light in the end of the path, constantly afraid that the gaping darkness "+
		  "under your feet will devour you, until the light is but an auspiciously "+
		  "short step away. Time stops as you admire the light in illogical, childish "+
		  "fascination, lacking all understanding. As you reach out a trembling hand, a "+
		  "surge of coldness runs down your spine. The light feels like frost on a "+
		  "glass window and gently ripples around your tingling fingertips. You start "+
		  "as an ancient voice suddenly fills the air with a single resounding word of "+
		  "arcane wisdom: '"+THIS->query_magical_true_name("creation")+"'.\n \n"+
		  "You awake, gasping, in a sudden burst of mundane realization and, after a "+
		  "moment of tremulous groping, find yourself back on solid ground.";
	 }
   else
	 return ::query_long();
}
