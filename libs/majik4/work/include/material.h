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

#ifndef __MATERIAL_H__
#define __MATERIAL_H__

/* Material type definitions */

#define MTYPE_ORGANIC        0
#define MTYPE_METAL          1
#define MTYPE_STONE          2
#define MTYPE_WOOD           3
#define MTYPE_CLOTH          4
#define MTYPE_BONE           5
#define MTYPE_GLASS          6
#define MTYPE_GEM            7
#define MTYPE_PAPER          8
#define MTYPE_INORGANIC      9
#define MTYPE_MAX            10

/* Material resistance definitions */

#define MRESI_PHYSICAL       0
#define MRESI_FIRE           1
#define MRESI_COLD           2
#define MRESI_ELECTRICITY    3
#define MRESI_ACID           4
#define MRESI_DISINTEGRATION 5
#define MRESI_MAGIC          6
#define MRESI_POISON         7
#define MRESI_MAX            8

/* Material array index definitions */

#define MARR_VALUE           0 /* Value of the item, copper pieces / kg */
#define MARR_WEIGHT          1 /* Weight of the item, grams / cm^3      */
#define MARR_RARITY          2 /* Rarity of the item, 0-9               */
#define MARR_WEAPON_RARITY   3 /* How often weapons are made of the mat */
#define MARR_ARMOR_RARITY    4 /* How often armors are made of the mat  */
#define MARR_TYPE            5 /* Type of the material                  */
#define MARR_RESISTANCE      6 /* Resistances array, MRESI_X            */
#define MARR_MAX             7

#endif /* __MATERIAL_H__ */
