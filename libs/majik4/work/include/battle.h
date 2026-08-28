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

#ifndef __BATTLE_H__
#define __BATTLE_H__

#define HIT_FUMBLE 		1
#define HIT_CRITICAL    2
#define HIT_NORMAL		3

#define WD_WEAPON		0
#define WD_DAMTYPE		1
#define WD_DAMAGE		2
#define WD_RANGE		3
#define WD_CSTYLE		4
#define WD_SKILL		5

#define WD_MAX			6

#define HIT_UNDECIPHERED	-1
#define HIT_MISS			0
#define HIT_WBLOCK			1	
#define HIT_SBLOCK			2
#define HIT_ABLOCK			3
#define HIT_CBLOCK			4
#define HIT_SUCCESS			5

#endif /* __BATTLE_H__ */
