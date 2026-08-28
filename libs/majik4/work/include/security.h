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

#ifndef __SECURITY_H__
#define __SECURITY_H__

#define		SEC0			0
#define		SEC1			1
#define		SEC2			20
#define		SEC3			40
#define		SEC4			80
#define		SEC5			99
#define		SEC6 			100

#define		SEC0_NAME			"mortal"
#define		SEC1_NAME			"lesser deity"
#define		SEC2_NAME			"deity"
#define		SEC3_NAME			"greater deity"
#define		SEC4_NAME			"lesser god"
#define		SEC5_NAME			"god"
#define		SEC6_NAME			"greater god"

#define		SEC_MORTAL			SEC0
#define		SEC_LESSER_DEITY 	SEC1
#define		SEC_DEITY			SEC2
#define		SEC_GREATER_DEITY 	SEC2
#define		SEC_LESSER_GOD		SEC4
#define		SEC_GOD				SEC5
#define		SEC_GREATER_GOD		SEC6

#endif /* __SECURITY_H__ */
