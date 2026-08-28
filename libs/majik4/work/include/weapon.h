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

#ifndef __WEAPON_H__
#define __WEAPON_H__

/* Generic weapon array slot number definitions */
#define WEAPON_DAMAGE	    8
#define WEAPON_RANGE		9
#define WEAPON_HANDEDNESS   10
#define WEAPON_SKILL		11

/* Weapon handedness definitions */
#define WEAPON_1H	1
#define WEAPON_12H	2
#define WEAPON_2H	3

/* Weapon damage type definitions */
#define DT_STAB     1
#define DT_CUT      2
#define DT_IMPACT   3
#define DT_FIRE     4
#define DT_ACID		5

/* Weapon range definitions */ 
#define RANG_CLOSE		0x0001
#define RANG_THROWN		0x0010
#define RANG_MISSILE	0x0100

#endif /* __WEAPON_H__ */
