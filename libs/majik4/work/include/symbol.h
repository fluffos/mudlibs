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

#ifndef __SYMBOL_H__
#define __SYMBOL_H__

/* Gridmap symbols of creatures */

#define CS_ILLEGAL         'X' /* Default symbol if not specified          */
#define CS_AMPHIBIAN       'a' /* Amphibians: toads, frogs ...             */
#define CS_ANGEL           'A' /* Angels                                   */
#define CS_DEMON           'd' /* Demons                                   */
#define CS_DRAGON          'D' /* Dragons                                  */
#define CS_SPIRIT          'e' /* Lesser elementals and spirits            */
#define CS_ELEMENTAL       'E' /* Elementals                               */
#define CS_FLY             'f' /* Small flying creatures: birds, bats ...  */
#define CS_FISH            'F' /* Fishes                                   */
#define CS_GOLEM           'G' /* Golems and gargoyles                     */
#define CS_HUMANOID        'h' /* Small humanoids: humans, elves, orcs ... */
#define CS_LARGE_HUMANOID  'H' /* Large humanoids: giants, orgres, ...     */
#define CS_INSECT          'i' /* Giant-sized insects: beetles, ants ...   */
#define CS_MAMMAL          'm' /* Small mammals: cats, dogs, rats ...      */
#define CS_LARGE_MAMMAL    'M' /* Large mammals: elephants, bears, ...     */
#define CS_PLANT           'p' /* Plants and molds: fungi, molds ...       */
#define CS_UNUSUAL_PLANT   'P' /* Unusual plant-like creatures: treant ... */
#define CS_REPTILE         'r' /* Small reptiles: snakes, lizards ...      */
#define CS_LARGE_REPTILE   'R' /* Large reptiles: alligators, drakes ...   */
#define CS_ARACHNID        's' /* Arachnids: spiders, scorpions ...        */
#define CS_UNDEAD          'u' /* Physical undead: skeletons, zombies ...  */
#define CS_ETHEREAL_UNDEAD 'U' /* Ethereal undead: wraiths, shadows ...    */
#define CS_WORM            'w' /* Giant worms and maggots                  */

/* Gridmap symbols of items */

#define IS_ILLEGAL         '&' /* Default symbol if not specified          */
#define IS_WEAPON          '(' /* Weapons                                  */
#define IS_MISSILE_WEAPON  '}' /* Missile weapons                          */
#define IS_MISSILE         '/' /* Missiles: arrows, quarrels ...           */
#define IS_ARMOR           '[' /* Armors, shields ...                      */
#define IS_CLOTHING        ']' /* Clothes                                  */
#define IS_RING            '=' /* Rings                                    */
#define IS_AMULET          '&' /* Amulets, necklaces ...                   */
#define IS_TOOL            '&' /* Tools                                    */
#define IS_FOOD            ':' /* The items you can eat                    */
#define IS_POTION          '!' /* Potions and other drink containers       */
#define IS_SCROLL          '?' /* Scrolls, papers ...                      */
#define IS_BOOK            '"' /* Books                                    */
#define IS_WAND            '\' /* Wands                                    */
#define IS_MONEY           '$' /* Treasure                                 */
#define IS_MINERAL         '*' /* Minerals, gems, rocks ...                */

#endif /* __SYMBOL_H__ */
