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

int elspell_castspeed, elspell_minus;
object elspell_ob, elspell_target;
string elspell_category;

int
resolve_elemental_spell()
{
   float elun;
   int tk, uo, result;
  
   tk = THOB->use_skill("true knowledge of "+elspell_category, 100, 0, 0);
   uo = THOB->use_skill("utilization of "+elspell_category, 100, 0, 0);
   elun = THOB->use_skill("elemental unity", 100, 0, 0) / 100.0;
   result = tk - elspell_ob->query_difficulty("elemental");
   if(result > 0)
	 return to_int(to_float(uo) * elun);
   else
	 return result;
}

void
evoke_elemental_spell(int x, int y)
{
   int level;
   elspell_castspeed -= elspell_minus + random(25);
   THOB->add_sp(-random(12));
   THOB->add_ep(-random(3));
   if(THOB->query_sp() < 1 || THOB->query_ep() < 1)
	 {
		remove_call_out("evoke_elemental_spell");
		message(CMD_SEE, THOB->query_gridx(), THOB->query_gridy(), VISIBLE_RADIUS, "$n1 {lose} $s1 concentration on the evocation.", MAPENV(THOB), THOB);
		THOB->set_casting(0);
		elspell_ob->failure("elemental", THOB, x, y, -random(100 - THOB->query_skill_chance("true knowledge of "+elspell_category))); 
		return;
	 }
   
   if(elspell_castspeed > 0)
	 {
		call_out("evoke_elemental_spell", 2, x, y);
		message (CMD_FEEL, 0,0,0, "You proceed in your evocation.", THOB);
	 }
   else 
	 {
		remove_call_out("evoke_elemental_spell");
		level = resolve_elemental_spell();
		elspell_ob->set_type("elemental");
		if(level > 0)
		  {
			 if(elspell_target)
			   {
				  x = elspell_target->query_gridx();
				  y = elspell_target->query_gridy();
			   }
			 elspell_ob->success("elemental", THOB, x, y, level);
		  }
		else
		  {
			 elspell_ob->failure("elemental", THOB, x, y, level);
		  }
		THOB->set_casting(0);
	 }
}

void
start_elemental_spell(object ob, int x, int y)
{
   object *obs = MAPENV(THOB)->get_livings(x, y, x, y);
   
   elspell_ob = ob;
   elspell_target = 0;
   if(sizeof(obs) > 0)
	 elspell_target = obs[random(sizeof(obs))]; 
	
   elspell_category = elspell_ob->query_spell()["elemental"][SPELL_EXTRA];
   if(THOB->query_casting())
	 {
		message (CMD_SEE, THOB->query_gridx(), THOB->query_gridy(), VISIBLE_RADIUS, "$n1 {lose} $s1 concentration on $s1 evocation.", MAPENV(THOB), THOB);
	    remove_call_out("evoke_elemental_spell");
	 }
   elspell_minus = THOB->use_skill(elspell_category+" channeling", 100, 0, 0);
   elspell_castspeed = elspell_ob->query_casting_speed("elemental");
   THOB->set_casting(1);
   message(CMD_SEE, THOB->query_gridx(), THOB->query_gridy(), VISIBLE_RADIUS, "$n1 {start} concentrating on an elemental evocation.", MAPENV(THOB), THOB);
   evoke_elemental_spell(x, y);
}
