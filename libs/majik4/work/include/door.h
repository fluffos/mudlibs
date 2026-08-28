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

#ifndef __DOOR_H__
#define __DOOR_H__

/* Initial state for a door */

#define DOOR_NONEXIST 0 /* There is no door anymore */
#define DOOR_OPEN     1
#define DOOR_CLOSED   2
#define DOOR_LOCKED   3

/* Lock difficulty */

#define LOCK_NONEXIST 0 /* The door doesn't have a lock */
#define LOCK_EASY     1
#define LOCK_MEDIOCRE 2
#define LOCK_HARD     3

#endif /* __DOOR_H__ */
