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

mapping numbers = ([
1 : "N",
2 : "B",
3 : "M",
4 : "C"
]);

string
main(string str)
{
   int i;
   int number = to_int(str);
   string result = "";
   
   if(!number)
	 return "R";
   
   if(number > 19)
	 {
		i = number / 80000;
		if(i)
		  {
			 if(i > 1)
			   result += numbers[i];
			 result += "A";
		  }
		number -= 80000 * i;
		
		i = number / 40000;
		result += repeat_string("E", i);
		number -= 40000 * i;
		
		i = number / 8000;
		if(i)
		  {
			 if(i > 1)
			   result += numbers[i];
			 result += "O";
		  }
		number -= 8000 * i;
		
		i = number / 4000;
		result += repeat_string("U", i);
		number -= 4000 * i;
		
		i = number / 800;
		if(i)
		  {
			 if(i > 1)
			   result += numbers[i];
			 result += "K";
		  }
		number -= 800 * i;
		
		i = number / 400;
		result += repeat_string("T", i);
		number -= 400 * i;
		
		i = number / 80;
		if(i)
		  {
			 if(i > 1)
			   result += numbers[i];
			 result += "G";
		  }
		number -= 80 * i;
		
		i = number / 40;
		result += repeat_string("H", i);
		number -= 40 * i;
		
		if(number)
		  {
			 i = number / 20;
			 result += sprintf("%s%s", number % 20 ? "" : "R", repeat_string("R", i));
			 number -= 20 * i;
		  }
	 }
   i = number / 4;
   result += i ? numbers[i] : "";
   number -= 4 * i;
   if(number)
	 result += "-"+numbers[number];
   return result;
}
