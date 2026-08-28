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

#define NONSENSE 1+random(3)

mapping truename_map;

string query_magical_true_meaning(string);

string
create_syllable()
{
   string *vowel, *cons, w1, w2, c1, c2;
      
   vowel = ({
	  "a","e","i","o","u","y"
   });
   cons = ({
	  "b","c","d","f","g","h","j","k","l","m",
	  "n","p","q","r","s","t","v","w","x","z"
   });
   
   w1 = vowel[random(sizeof(vowel))];
   w2 = vowel[random(sizeof(vowel))];
   c1 = cons[random(sizeof(cons))];
   c2 = cons[random(sizeof(cons))];
   switch (d("1d6"))
	 {
	  case 1:
		return c1+w1;
	  case 2:
		return w1+c1;
	  case 3:
		return w1+c1+w2;
	  case 4:
		return c1+w1+c2;
	  case 5:
		return c1+w1+w1;
	  case 6:
		return w1+w1+c1;
	 }
}

void
initialize_magical_true_names()
{   
   truename_map = ([ ]);
}

int
add_magical_true_name(string true_name, string meaning)
{
   truename_map[true_name] = meaning;
   return 1;
}

string *
query_known_true_names()
{   
   return keys(truename_map);
}

string *
query_known_true_meanings()
{   
   return values(truename_map);
}

string
list_true_names()
{
   int i, j;
   string msg, *truenames;
      
   truenames = keys(truename_map);
   truenames = sort_array(truenames,1);
   msg="";
   
   for (i=0,j=sizeof(truenames);i<j;i++)
	 msg += truenames[i] + "\n";
   
   return msg;
}

string
query_magical_true_meaning(string true_name)
{
   return truename_map[true_name];
}

string
query_magical_true_name(string meaning)
{   
   int i;
   string *truenames, *meanings;
   
   truenames = keys(truename_map);
   meanings = values(truename_map);
   if(member_array(meaning, meanings) != -1)
	 return truenames[i];
   
   return "";
}

string
create_magical_true_name(string meaning)
{
   string new_true_name, *truenames, *meanings;
   
   if(!SKILL_D->find_skill("name of "+meaning))
	 return "";
   
   truenames = keys(truename_map);
   meanings = values(truename_map);
   
   if(member_array(meaning, meanings) != -1)
	 return "";
   
   new_true_name = THOB->create_syllable() + THOB->create_syllable();
   
   while (member_array(new_true_name, truenames) != -1)
	 new_true_name += THOB->create_syllable();
   
   THOB->add_magical_true_name(new_true_name, meaning);
   THOB->add_skill("name of "+meaning, 0, 0);
   return new_true_name;
}

string
handle_true_names(string divine_chant)
{
   int i, j, nonsense;
   string *tech, *form, *power, *all, *words, *meanings;
   string *tmp_tech, *tmp_form, *tmp_power, true_chant;
      
   tech = TRUENAME_D->query_tech_names();
   form = TRUENAME_D->query_form_names();
   power = TRUENAME_D->query_power_names();
   all = TRUENAME_D->query_all_names();
   
   words = explode(divine_chant, "-");
   
   tmp_tech = ({ });
   tmp_form = ({ });
   tmp_power = ({ });
   meanings = ({ });
   
   meanings = allocate(sizeof(words));
   for (i=0,j=sizeof(meanings);i<j;i++)
	 {
		meanings[i] = THOB->query_magical_true_meaning(words[i]);
		if(meanings[i])
		  {
			 if(member_array(meanings[i], tech) != -1)
			   tmp_tech += ({ meanings[i] });
			 else if(member_array(meanings[i], form) != -1)
			   tmp_form += ({ meanings[i] });
			 else if(member_array(meanings[i], power) != -1)
			   tmp_power += ({ meanings[i] });
			 else
			   nonsense++;
		  }
		else
		  nonsense += strlen(words[i]);
	 }
   
   if(nonsense)
	 {
		message (CMD_FEEL, 0,0,0, "Using nonsense with true names really hurts!", THOB);
		THOB->add_hp(-nonsense*NONSENSE);
		THOB->add_sp(-nonsense*NONSENSE);
		THOB->add_ep(-nonsense*NONSENSE);
	 }
   
   if(sizeof(tmp_tech) < 1 || sizeof(tmp_form) < 1 || sizeof(tmp_power) < 1)
	 return "incomplete";
   
   tmp_tech = sort_array(tmp_tech, 1);
   tmp_form = sort_array(tmp_form, 1);
   tmp_power = sort_array(tmp_power, 1);
   true_chant = implode(tmp_tech,"-")+"-"+implode(tmp_form,"-")+"-"+implode(tmp_power,"-");
   return true_chant;
}

int
recite_true_name(object spellob, string chant, int x, int y)
{
   string *words;
   int i, j, res, suc, fai;
        
   message (CMD_HEAR, THOB->query_gridx(), THOB->query_gridy(), VISIBLE_RADIUS, "$N1 {divine}, '^c1" + chant + "!^c0'", MAPENV(THOB), THOB);
   message (CMD_FEEL, 0,0,0, "Reality ripples from the power of your words!", THOB);
   words = explode(chant, "-");
   for(i=0,j=sizeof(words);i<j;i++)
	 {	
		res = THOB->use_skill("name of "+THIS->query_magical_true_meaning(words[i]), 100, 0, 0);
		if(res > spellob->query_difficulty("truename"))
		  suc++;
		else
		  fai++;
	 }
   
   spellob->set_type("truename");
   if(suc >= fai)
	 spellob->success("truename", THOB, x, y, 50);
   else
	 spellob->failure("truename", THOB, x, y, 50);
   return 1;
}
