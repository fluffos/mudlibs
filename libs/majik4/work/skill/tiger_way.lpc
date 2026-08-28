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
#include <cstyle.h>

inherit COMBAT_STYLE;

void
create_combat_style()
{
   THOB->set_name("tiger way");
   THOB->set_parent("combat styles");
   THOB->set_cost_multiplier(1.5);
   THOB->set_max_train_diff(80);
   THOB->add_bonus_stat("agi", 1);
   THOB->add_bonus_stat("str", 2);
       
   THOB->add_weapon_skill("unarmed combat");
   THOB->set_speed_bonus(100);
   THOB->set_defence_bonus(40);
   THOB->set_offense_bonus(60);
   THOB->set_damage_bonus(45);
   THOB->set_fatique_bonus(15);
}

int
damage(object attacker, object defender, string loc, int percent, int damage, mixed atweapon, mixed defweapon)
{
   int *xy;
   int atx, aty;
   int dfx, dfy;
   int bonus;
   object *obs;
   
   if(defender->query_bodytype() != attacker->query_bodytype())
	 return 0;
   
   atx = attacker->query_gridx();
   aty = attacker->query_gridy();
   dfx = defender->query_gridx();
   dfy = defender->query_gridy();
   
   if(attacker->query_position() == POS_LYING)
	 {
		message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {flip} $t1 up.", MAPENV(attacker), attacker);
		attacker->set_position(POS_STANDING);
	 }
   
   switch(percent)
	 {
	  case 0..50:
		if(defender->query_position() != POS_LYING)
		  {
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {grab} $t2 by the "+loc+" and {take} $m2 down.", MAPENV(attacker), ({ attacker, defender }) );
			 defender->set_position(POS_LYING);
			 defender->add_hp(-damage);
		  }
		else
		  {
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {kick} $t2 in the flank.", MAPENV(attacker), ({ attacker, defender }) );
			 defender->add_hp(-damage);
		  }
		break;
	  case 51..100:
		if(objectp(defweapon))
		  {
			 xy = MAPENV(attacker)->get_near_location(atx, aty, 1);
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {grab} $o2 $n3 and {hurl} it to the ground.", MAPENV(attacker), ({ attacker, defender, defweapon }) );
			 defender->remove_weapon(defweapon);
			 defweapon->move(MAPENV(attacker), xy[0], xy[1]);
		  }
		else
		  {
			 if(defender->query_position() == POS_LYING)
			   {
				  message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 brutally {jump} on $t2, extending $s1 elbow.", MAPENV(attacker), ({ attacker, defender }) );
			   }
			 else
			   {
				  message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {charge} forward, landing $s1 elbow in $o2 ribcage.", MAPENV(attacker), ({ attacker, defender }) );
				  message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {are} thrown back from the force of the attack.", MAPENV(attacker), defender);
				  bonus = defender->query_stat(A_STU) / attacker->query_stat(A_STR) + 1;
				  if(atx > dfx)
					dfx -= bonus;
				  else if(atx < dfx)
					dfx += bonus;
				  if(aty > dfy)
					dfy -= bonus;
				  else if(aty < dfy)
					dfy += bonus;
				  if(!MAPENV(defender)->is_clear(dfx,dfy))
					{
					   obs = MAPENV(defender)->get_obj(dfx, dfy);
					   if(sizeof(obs) < 1)
						 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {stumble} backwards and {bump} into a wall.", MAPENV(attacker), defender);
					   else
						 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {stumble} backwards and {bump} into $n2.", MAPENV(attacker), ({ defender, obs[0] }) );
					   defender->add_hp(defender->add_hp(-10));
					}
				  else
					{
					   defender->move(MAPENV(defender), dfx, dfy);
					}
				  message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {are} stunned from the force of the attack.", MAPENV(attacker), defender);
				  defender->add_freeze(2);
			   }
			 defender->add_hp(-defender->query_hitloc_hp("chest"));
		  }
		break;
	  case 101..150:
		if(defender->query_position() != POS_LYING)
		  {
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {throw} a fancy punch at $o2 chin, rendering $m2 unconscious.", MAPENV(attacker), ({ attacker, defender }) );
			 defender->add_hp(-defender->query_hitloc_hp("head"));
			 defender->uncons();
		  }
		else
		  {
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {finish} $t2 by snapping $s2 neck with $s1 ridge hand.", MAPENV(attacker), ({ attacker, defender }) );
			 defender->die();
		  }
		break;
	  case 151..200:
		if(defender->query_position() != POS_LYING)
		  {
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 side-{kick} $t2 in the stomach, leaving $m2 gasping for air.", MAPENV(attacker), ({ attacker, defender }) );
			 defender->add_hp(-defender->query_hitloc_hp("neck") * 2);
			 defender->set_freeze(4);
		  }
		else
		  {
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 side-{kick} $t2 in the throat, crushing $s2 windpipe.", MAPENV(attacker), ({ attacker, defender }) );
			 defender->die();
		  }
		break;
	  default:
		if(defender->query_position() != POS_LYING)
		  {
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {perform} a stunning jumping sidekick and {land} it on $o2 face, killing $m2 instantly.", MAPENV(attacker), ({ attacker, defender }) );
			 defender->die();
		  }
		else
		  {
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {jump} up and cruelly land on $t2, snapping $s2 spine with a few twists of $s1 feet.", MAPENV(attacker), ({ attacker, defender }) );
			 defender->die();
			 attacker->move(MAPENV(attacker), dfx, dfy);
		  }
		break;
	 }
   return 1;
}

int
block(object attacker, object defender, mixed atweapon, mixed defweapon)
{
   int atx, aty;
   
   atx = attacker->query_gridx();
   aty = attacker->query_gridy();
   
   if(attacker->query_position() != POS_LYING)
	 {
		if(objectp(atweapon))
		  {
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {intercept} $o2 attack and counter-{attack} by claiming $o2 $n3 to $t1.", MAPENV(attacker), ({ defender, attacker, atweapon }) );
			 attacker->remove_weapon(atweapon);
			 atweapon->move(defender,-1,-1);
		  }
		else
		  {
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {intercept} $o2 attack by taking $m2 down by the "+attacker->query_natural_weapon_reqloc(atweapon)+".", MAPENV(attacker), ({ defender, attacker }) );
			 attacker->set_position(POS_LYING);
			 attacker->add_hp(-defender->query_stat(A_STR));
		  }
	 }
   else
	 {
		message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {jump} up, evading $o2 attack, and {land} a kick in $s2 ribs on $s1 way down.", MAPENV(attacker), ({ defender, attacker }) );
		attacker->add_hp(-damage);
	 }
   return 1;
}
