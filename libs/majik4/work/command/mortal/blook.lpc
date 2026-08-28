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
#include <tile.h>

int
main (string str)
{
   object *o;
   string buf = "";
   int x, y;
   
   if (x > MAPENV(PREV(0))->query_area_w() || 
	   y > MAPENV(PREV(0))->query_area_h() || 
	   x < 0 || y < 0)
	 {
		prompt_client (PREV(0), 1, "noop", "You can't see that far!");
		return 1;
	 }		
   
   if (sscanf (str, "%d %d", x, y) == 2)
	 {
		o = MAPENV(PREV(0))->get_obj(x, y);
   
		if (!o || sizeof(o) == 0)
		  {
			 switch (MAPENV(PREV(0))->query_tile(x, y))
			   {
				case TILE_LADDER_UP:
				  buf = "A ladder leading up";
				  break;
				case TILE_LADDER_DOWN:
				  buf = "A ladder leading down";
				  break;
				case TILE_OPEN_DOOR:
				  buf = "A open door";
				  break;
				case TILE_CLOSED_DOOR:
				  buf = "A closed door";
				  break;
				case TILE_CRACK:
				  buf = "A crack";
				  break;
				case TILE_EARTH:
				  buf = "A piece of ground";
				  break;
				case TILE_UG_EARTH:
				  buf = "A piece of ground";
				  break;
				case TILE_ICE:
				  buf = "A piece of icy ground";
				  break;
				case TILE_GRASS:
				  buf = "Grass";
				  break;
				case TILE_L_GRASS:
				  buf = "Long grass";
				  break;
				case TILE_MARSH:
				  buf = "Marsh";
				  break;
				case TILE_SAND:
				  buf = "A piece of sand covered ground";
				  break;
				case TILE_SNOW:
				  buf = "A piece of snow covered ground";
				  break;
				case TILE_BURNT:
				  buf = "A piece of burnt ground";
				  break;
				case TILE_BURNT:
				  buf = "Burnt ground";
				  break;
				case TILE_FLOOR:
				  buf = "A piece of floor";
				  break;
				case TILE_STONE_FLOOR:
				  buf = "A piece of stone floor";
				  break;
				case TILE_WOOD_FLOOR:
				  buf = "A piece of wooden floor";
				  break;
				case TILE_CAVE_FLOOR:
				  buf = "A piece of cave floor";
				  break;
				case TILE_ACID:
				  buf = "A piece of acid covered ground";
				  break;
				case TILE_WATER:
				  buf = "Water";
				  break;
				case TILE_D_WATER:
				  buf = "Deep water";
				  break;
				case TILE_UG_WATER:
				  buf = "Water";
				  break;
				case TILE_D_UG_WATER:
				  buf = "Deep water";
				  break;
				case TILE_WALL:
				  buf = "A solid wall";
				  break;
				case TILE_EARTH_WALL:
				  buf = "An earth wall";
				  break;
				case TILE_METAL_WALL:
				  buf = "A metal wall";
				  break;
				case TILE_STONE_WALL:
				  buf = "A stone wall";
				  break;
				case TILE_WOOD_WALL:
				  buf = "A wooden wall";
				  break;
				case TILE_ROCK:
				  buf = "Solid rock";
				  break;
				case TILE_STALAGMITE:
				  buf = "A stalagmite";
				  break;
				case TILE_BUSH:
				  buf = "A bush";
				  break;
				case TILE_S_BUSH:
				  buf = "A small bush";
				  break;
				case TILE_L_BUSH:
				  buf = "A large bush";
				  break;
				case TILE_CON_TREE:
				  buf = "A conifer tree";
				  break;
				case TILE_S_CON_TREE:
				  buf = "A small conifer tree";
				  break;
				case TILE_L_CON_TREE:
				  buf = "A large conifer tree";
				  break;
				case TILE_DEC_TREE:
				  buf = "A decidious tree";
				  break;
				case TILE_S_DEC_TREE:
				  buf = "A small decidious tree";
				  break;
				case TILE_L_DEC_TREE:
				  buf = "A large decicdious tree";
				  break;
				case TILE_JUN_TREE:
				  buf = "A jungle tree";
				  break;
				case TILE_S_JUN_TREE:
					buf = "A small jungle tree";
				  break;
				case TILE_L_JUN_TREE:
				  buf = "A large jungle tree";
				  break;
			   }
			 
			 prompt_client (PREV(0), 1, "noop", buf + ".");
			 return 1;
		  }
		
		if (sizeof(o) == 1)
		  {
			 prompt_client (PREV(0), 1, "vlook", capitalize(wrap(o[0]->query_short(PREV(0)))) + ". [S]elect");
			 return 1;
		  }
		else
		  {
			 prompt_client (PREV(0), 1, "vlook", "There are "+sizeof(o)+" items lying here. [S]elect");
			 return 1;
		  }   
	 }
}
