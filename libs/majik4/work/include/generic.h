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

#ifndef __GENERIC_H__
#define __GENERIC_H__

/* Definitions for array indexes in generic object definition mapping */

#define GARR_XDIM   0 /* X-dimension of the item        */
#define GARR_YDIM   1 /* Y-dimension of the item        */
#define GARR_ZDIM   2 /* Z-dimension of the item        */
#define GARR_HOLLOW 3 /* Hollowness of the item         */
#define GARR_TYPE   4 /* Type of the material used      */
#define GARR_ITEM   5 /* Type of the item               */
#define GARR_SYMBOL 6 /* Gridmap symbol of the item     */
#define GARR_COLOR  7 /* Gridmap color of the item, C_X */
#define GARR_EXT    8 /* Extensions array               */

#define GARR_MAX    9

/* Item type definitions */

#define ITEM_UNDEFINED   0
#define ITEM_LIGHT       1

#define ITEM_WEAPON      2
#define ITEM_SHIELD		 3
#define ITEM_MISSILE_WEAPON 4
#define ITEM_MISSILE	 5

#define ITEM_CLOTHING    6
#define ITEM_ARMOR       7
#define ITEM_CONTAINER   8
#define ITEM_DRINKCON    9 /* Liquid container */
#define ITEM_TOOL        10 /* Misc tool */
#define ITEM_FOOD        11
#define ITEM_MONEY       12

#define ITEM_MAX         13

#endif /* __GENERIC_H__ */
