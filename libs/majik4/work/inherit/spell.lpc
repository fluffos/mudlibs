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

#include <spell.h>

/* Global variable definitions */
mixed *spellarr;

/* Function prototypes */
void success(object,int,int,int);
void failure(object,int,int,int);
mixed *set_spell(mixed *);
mixed *query_spell();
int query_difficulty();
int query_casting_speed();
string query_name();
string query_short();

/* Functions */
mixed *
set_spell(mixed *map)
{
   return spellarr = map;
}

mixed *
query_spell()
{
   return spellarr;
}

int
query_difficulty()
{
   return spellarr[SPELL_DIFFICULTY];
}

int
query_casting_speed()
{
   return spellarr[SPELL_SPEED];
}

int
query_targeted()
{
   return spellarr[SPELL_TARGET];
}

string
query_name()
{
   return spellarr[SPELL_NAME];
}

string
query_short()
{
   return article(spellarr[SPELL_SHORT]);
}

string *
query_casting_symbols()
{
   return spellarr[SPELL_SYMBOLS];
}

void
create()
{
   THOB->create_spell();
}
