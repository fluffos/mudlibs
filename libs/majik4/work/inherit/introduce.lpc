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

#include <living.h>

mapping known;

string
query_description_beauty ()
{
   switch (THOB->query_stat(A_CHA))
	 {
	  case -1000..3:
		return "hideous";
	  case 4..7:
		return "ugly";
	  case 8..12:
		return "";
	  case 13..14:
		if (THOB->query_gender() == GENDER_MALE)
		  return "good-looking";
		else return "pretty";
	  case 15:
		return "elegant";
	  case 16..17:
		if (THOB->query_gender() == GENDER_MALE)
		  return "handsome";
		else
		  return "beautiful";
	  case 18..19:
		return "attractive";
	  case 20..21:
		return "charming";
	  case 22..28:
		if (THOB->query_gender() == GENDER_MALE)
		  return "adorable";
		else
		  return "gorgeous";
	  case 29..35:
		return "magnificent";
	  default:
		return "exquisite";
	 }
   
   return "";
}

string
query_description_age ()
{
   switch ((THOB->query_age()/100)*100/(THOB->query_max_age()/100))
	 {
	  case 0..11:
		return "very young";
	  case 12..17:
		return "teenage";
	  case 18..29:
		return "young";
	  case 30..45:
		return "middle-aged";
	  case 46..55:
		return "elderly";
	  case 56..75:
		return "old";
	  case 76..95:
		return "very old";
	  default:
		return "ancient";
	 }
   return "";
}

string
query_description_race ()
{   
   switch (THOB->query_race())
	 {
	  case "elf":
		return "elven";
	  case "half-elf":
		return "half-elven";
	  case "dwarf":
		return "dwarven";
	 }
   return THOB->query_race();
}

string
query_description_gender()
{
    switch ((THOB->query_age()/100)*100/(THOB->query_max_age()/100))
	 {
	  case 0..20:
		if (THOB->query_gender() == GENDER_MALE)
		  return "boy"; 
		else
		  return "girl";
	  default:
		if (THOB->query_gender() == GENDER_MALE)
		  return "male";
		else
		  return "female";   
	 }
   return "";
}

string
query_stranger_short()
{
   string d_beauty, d_age, d_race, d_gender;
   
   d_beauty = THOB->query_description_beauty();
   d_age = THOB->query_description_age();
   d_race = THOB->query_description_race();
   d_gender = THOB->query_description_gender();
   
   if (d_beauty == "")
	 return article(sprintf ("%s %s %s", d_age, d_race, d_gender));
   else
	 return article(sprintf ("%s %s %s %s", d_beauty, d_age, d_race, d_gender));
}

string
query_stranger_name()
{
   return article(sprintf ("%s %s",
						   THOB->query_description_race(),
						   THOB->query_description_gender()));
}

void
add_known (int uid, string str)
{
   if (!known)
	 known = ([ uid : str ]);
   else
	 known += ([ uid : str ]);
}

void
remove_known (int uid)
{
   map_delete (known, uid);
}
   
mapping
query_known ()
{
   return known;
}

mixed
test_known (int uid)
{ 
   if (!known || sizeof (keys (known)) < 1)
	 return 0;
   
   if (member_array (uid, keys (known)) > -1)
	 return known[uid];
   else
	 return 0;
}
