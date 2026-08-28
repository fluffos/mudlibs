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

#include <list.h>

string
query_skill_string(int pra)
{
   switch(pra)
	 {
	  case 0:
		return 0;
		break;
	  case 1..5:
		return "pitiful";
		break;
	  case 6..10:
		return "pathetic";
		break;
	  case 11..15:
		return "feeble";
		break;
	  case 16..20:
		return "deficient";
		break;
	  case 21..25:
		return "inept";
		break;
	  case 26..30:
		return "poor";
		break;
	  case 31..35:
		return "lacking";
		break;
	  case 36..40:
		return "mediocre";
		break;
	  case 41..45:
		return "moderate";
		break;
	  case 46..50:
		return "fair";
		break;
	  case 51..55:
		return "average";
		break;
	  case 56..60:
		return "satisfactory";
		break;
	  case 61..65:
		return "capable";
		break;
	  case 66..70:
		return "skillfull";
		break;
	  case 71..75:
		return "proficient";
		break;
	  case 76..80:
		return "adept";
		break;
	  case 81..85:
		return "excellent";
		break;
	  case 86..90:
		return "remarkable";
		break;
	  case 91..95:
		return "fantastic";
		break;
	  case 96..100:
		return "unequaled";
		break;
	  case 101..125:
		return "unearthly";
		break;
	  case 126..200:
		return "godly";
		break;
	 }
}

int
main()
{
   int i, j;
   object ob;
   string buf = "";
   mapping skillmap;
   string *skills, *actuals = ({ });
   
   skillmap = PREV(0)->query_skills();
   skills = keys(skillmap);
   if(sizeof(skills) < 1)
	 {
		message (CMD_MSG, 0,0,0, "You don't have any skills.", PREV(0));
		return 1;
	 }
   
   for(i=0,j=sizeof(skills);i<j;i++)
	 {
		ob = SKILL_D->find_skill(skills[i]);
		if(ob->query_type() != "node")
		  actuals += ({ skills[i]+" ("+THOB->query_skill_string(PREV(0)->query_skill_chance(skills[i]))+")" });
	 }
   
   buf = implode(actuals, ";")+";";   
   open_window(PREV(0), 0,0,0,0, LTYPE_SELECT, "Skills", "use", buf);
   return 1;
}
