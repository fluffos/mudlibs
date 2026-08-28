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

#ifndef __HITLOC_H__
#define __HITLOC_H__

/* Hitloc array slot number definitions */
#define HITLOC_COND	    	0
#define HITLOC_HP	    	1
#define HITLOC_TYPE 		2
#define HITLOC_BLEED        3
#define HITLOC_MAX_BLEED    4
#define HITLOC_SIZE         5 
#define HITLOC_ARMED        6      
#define HITLOC_WEAR			7
#define HITLOC_PROTECTION   8
#define HITLOC_ARMTYPE		9

/* Hitloc arming types */
#define ARMTYPE_NONE		0
#define ARMTYPE_WIELD		1
 
/* Hitloc conditions */
#define HITLOC_OK			1
#define HITLOC_CRIPPLED 	2
#define HITLOC_SEVERED		3

/* Hitloc types */
#define HITLOC_VITAL    	1
#define HITLOC_NONVITAL 	2
#define HITLOC_IRRELEVANT	3

/* Bodypart roles */
#define BODYPART_LIMB		1
#define BODYPART_HUB		2
#define BODYPART_CAPITAL	3
#define BODYPART_SUPPORTING 4

/* Bodypart array indices */
#define BODYPART_PARTS      0
#define BODYPART_DEPENDANTS 1
#define BODYPART_ROLE		2

#endif /* __HITLOC_H__ */
