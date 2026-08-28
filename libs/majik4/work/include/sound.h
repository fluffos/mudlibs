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

#ifndef __SOUND_H__
#define __SOUND_H__

#define SFX_DIE        0  /* When WE die                            */
#define SFX_CLOSE_DOOR 1  /* When someone closes a door             */
#define SFX_OPEN_DOOR  2  /* When someone opens a door              */
#define SFX_HIT        3  /* When we are hit                        */
#define SFX_HIT2       4  /* When we hit monster with swords etc.   */
#define SFX_HIT3       5  /* When we hit monster by other means     */
#define SFX_KILL       6  /* When we kill a monster                 */
#define SFX_LOGOFF     7  /* When we logoff :)                      */
#define SFX_MISS       8  /* When monster misses us                 */
#define SFX_MISS2      9  /* When we miss a monster                 */
#define SFX_WALL       10 /* When we bang our head against the wall */

#endif /* __SOUND_H__ */
