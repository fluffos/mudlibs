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

/* Global variable definitions */
string *verbal_arr;
mapping somatic_map;
mapping spell_queue;
int magic_style;

/* Function prototypes */

/* Functions */
int
set_magic_style(int style)
{
   return magic_style = style;
}

int
query_magic_style()
{
   return magic_style;
}

string
add_verbal_symbol(string word)
{
   int style;
   string meaning;
   
   if(!verbal_arr)
	 verbal_arr = ({ });
   
   style = SPELL_D->query_verbal_word_style(word);
   if(style < 0)
	 return 0;
   
   meaning = SPELL_D->query_verbal_word_meaning(word);
   if(!meaning || meaning == "")
	 return 0;
   
   verbal_arr += ({ word });
   return meaning;
}

int
add_somatic_symbol(string gesture, string meaning)
{
   if(!somatic_map)
	 somatic_map = ([ gesture : meaning ]);
   else
	 somatic_map += ([ gesture : meaning ]);
   return 1;
}

string *
query_verbal_symbols()
{   
   return verbal_arr;
}

string *
query_somatic_symbols()
{
   return keys(somatic_map);
}

string *
query_verbal_meanings()
{
   int i, j;
   string *strs = ({ });
   for(i=0,j=sizeof(verbal_arr);i<j;i++)
	 strs += ({ SPELL_D->query_verbal_word_meaning(verbal_arr[i]) });
   return strs;
}

string *
query_somatic_meanings()
{
   return values(somatic_map);
}

string
query_verbal_meaning(string word)
{
   int i;
   if(!word || word == "")
	 return 0;
   else
	 {
		i = member_array(word, verbal_arr);
		if(i < 0)
		  return 0;
		else
		  return SPELL_D->query_verbal_word_meaning(word);
	 }
}

string
query_somatic_meaning(string gesture)
{
   if(!somatic_map)
	 return 0;
   else
	 return somatic_map[gesture];
}

int
add_spell_component(string component, int duration)
{
   if(!component || component == "")
	 return 0;
   if(!duration || duration < 0)
	 return 0;
   if(component == "end")
	 {
		THOB->handle_spell_queue();
		return 1;
	 }
   spell_queue[component] = duration;
   message (CMD_FEEL, 0,0,0, "You experience a slight tingling sensation.", THOB);
   return 1;
}

string *
query_spell_queue()
{
   if(!spell_queue)
	 spell_queue = ([ ]);
   return keys(spell_queue);
}

void
update_spell_queue()
{
   int i, j;
   string *strs = THOB->query_spell_queue();
   
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		if(spell_queue[strs[i]] > 1)
		  spell_queue[strs[i]]--;
		else
		  map_delete(spell_queue, strs[i]);
	 }
   
   if(i)
	 if(sizeof(THOB->query_spell_queue()) < 1)
	   message (CMD_FEEL, 0,0,0, "Your mind is clear.", THOB);
}

void
handle_spell_queue()
{
   int i, j, k, l, m, n;
   object ob;
   string str;
   string *techs = ({ }), *powers = ({ }), *forms = ({ });
   string *strs = THOB->query_spell_queue();
   
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		if(member_array(strs[i], SPELL_D->query_tech_symbols()) != -1)
		  techs += ({ strs[i] });
		else if(member_array(strs[i], SPELL_D->query_power_symbols()) != -1)
		  powers += ({ strs[i] });
		else
		  forms += ({ strs[i] });
	 }
   
   if(sizeof(techs) < 1 || sizeof(forms) < 1 || sizeof(powers) < 1)
	 return 0;
   
  for(i=0,j=sizeof(techs);i<j;i++)
	 {
		str = techs[i];
		for(k=0,l=sizeof(forms);k<l;k++)
		  {
			 str += "_"+forms[k];
			 for(m=0,n=sizeof(powers);m<n;m++)
			   {
				  str += "_"+powers[m];
				  ob = SPELL_D->find_spell(str);
				  if(ob)
					ob->success(THOB, THOB->query_gridx()+10, THOB->query_gridy(), 50);
			   }
		  }
	 }
   spell_queue = ([ ]);
   magic_style = -1;
}
