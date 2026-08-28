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

#ifndef __TIME_H__
#define __TIME_H__

#define SUN_RISE      0
#define SUN_LIGHT     1
#define SUN_SET       2
#define SUN_DARK      3

#define MINUTES       60
#define HOURS         24
#define DAYS          28
#define MONTHS        8

#define GAME_MIN      20     
#define GAME_HOUR     (MINUTES * GAME_MIN)
#define GAME_DAY      (HOURS * GAME_HOUR)
#define GAME_MONTH    (DAYS * GAME_DAY)
#define GAME_YEAR     (MONTHS * GAME_MONTH)

#define BIRTHDAY      868752530

#endif /* __TIME_H__ */
