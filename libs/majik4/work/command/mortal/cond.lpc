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

#include <list.h>
#include <hitloc.h>

int
main(string str)
{
   int i, j, k, l;
   string *bps, *locs;
   int crips, sevs;
   string buf = "";
   
   bps = keys(PREV(0)->query_bodyparts());
   for(i=0,j=sizeof(bps);i<j;i++)
	 {
		crips = 0; 
		sevs = 0;
		locs = PREV(0)->query_bodypart_parts(bps[i]);
		for(k=0,l=sizeof(locs);k<l;k++)
		  {
			 if(PREV(0)->query_hitloc_cond(locs[k]) == HITLOC_CRIPPLED)
			   crips++;
			 else if(PREV(0)->query_hitloc_cond(locs[k]) == HITLOC_SEVERED)
			   sevs++;
		  }
		
		if(!crips && !sevs)
		  buf += "^cg"+bps[i]+";";
		else if(sevs == sizeof(locs))
		  buf += "^cL"+bps[i]+";";
		else if(crips == sizeof(locs))
		  buf += "^cr"+bps[i]+";";
		else if(sevs && !crips)
		  buf += bps[i]+";";
		else if(!sevs && crips)
		  buf += "^cY"+bps[i]+";";
		else if(sevs && crips)
		  buf += "^cb"+bps[i]+";";
	 }
   buf += " ;";
   buf += "Explanation:;";
   buf += "^cg#^c0 - Bodypart is ok;";
   buf += "^cY#^c0 - Bodypart is partially crippled;";
   buf += "# - Bodypart is partially severed;";
   buf += "^cb#^c0 - Bodypart is partially crippled and severed;";
   buf += "^cr#^c0 - Bodypart is completely crippled;";
   buf += "^cL#^c0 - Bodypart is completely severed;";
   open_window(PREV(0), 0,0,0,0, LTYPE_TEXT, "Condition:", "noop", buf);
   return 1;
}
