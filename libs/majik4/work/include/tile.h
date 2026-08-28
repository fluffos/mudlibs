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

#ifndef __TILE_H__
#define __TILE_H__

#define TILE_PLAYER      '@' /* the player itself */
#define TILE_LADDER_UP   '>' /* ladder/stair up */
#define TILE_LADDER_DOWN '<' /* ladder/stair down */
#define TILE_OPEN_DOOR   '/' /* open door */
#define TILE_CLOSED_DOOR '+' /* closed door */

#define TILE_CRACK       'c' /* crack in the ground */
#define TILE_EARTH       '.' /* ground */
#define TILE_BURNT       'b' /* burnt ground */
#define TILE_UG_EARTH    'e' /* underground ground */
#define TILE_ICE         'i' /* icy floor */
#define TILE_GRASS       'g' /* grass */
#define TILE_L_GRASS     'G' /* long grass */
#define TILE_MARSH       'm' /* marsh */
#define TILE_SAND        's' /* sand */
#define TILE_SNOW        'n' /* snow-covered floor */
#define TILE_FLOOR       'f' /* ordinary house floor */
#define TILE_STONE_FLOOR 't' /* stone floor */
#define TILE_WOOD_FLOOR  'w' /* wooden floor */
#define TILE_CAVE_FLOOR  '0' /* cave floor */

#define TILE_ACID        'a' /* acidic ground */
#define TILE_LAVA        'L' /* molten lava */
#define TILE_WATER       '~' /* water */
#define TILE_D_WATER     'd' /* deep water */
#define TILE_UG_WATER    'u' /* underground water */
#define TILE_D_UG_WATER  'U' /* deep underground water */

#define TILE_WALL        '#' /* just a wall (obsolete?) */
#define TILE_EARTH_WALL  'E' /* earth wall */
#define TILE_METAL_WALL  'M' /* metal wall */
#define TILE_STONE_WALL  'S' /* stone wall */
#define TILE_WOOD_WALL   'W' /* wooden wall */
#define TILE_ROCK        '^' /* rock */
#define TILE_STALAGMITE  'T' /* stalagmite */

#define TILE_BUSH        'B' /* bush */
#define TILE_S_BUSH      '1' /* small bush */
#define TILE_L_BUSH      '2' /* large bush */
#define TILE_CON_TREE    '%' /* conifer tree */
#define TILE_S_CON_TREE  '3' /* small conifer tree */
#define TILE_L_CON_TREE  '4' /* large conifer tree */
#define TILE_DEC_TREE    'D' /* deciduous tree */
#define TILE_S_DEC_TREE  '5' /* small deciduous tree */
#define TILE_L_DEC_TREE  '6' /* large deciduous tree */
#define TILE_JUN_TREE    'J' /* jungle tree */
#define TILE_S_JUN_TREE  '7' /* small jungle tree */
#define TILE_L_JUN_TREE  '8' /* large jungle tree */

nosave string 
*blocking_terrains = ({
   TILE_CLOSED_DOOR,
   TILE_WALL,
   TILE_EARTH_WALL,
   TILE_METAL_WALL,
   TILE_STONE_WALL,
   TILE_WOOD_WALL,
   TILE_ROCK,
   TILE_STALAGMITE,
   TILE_L_CON_TREE,
   TILE_L_DEC_TREE,
   TILE_L_JUN_TREE
});

#endif /* __TILE_H__ */
