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

#pragma optimize

#include <living.h>
#include <hitloc.h>
#include <battle.h>
#include <weapon.h>
#include <sound.h>
#include <event.h>

/* Global variable definitions */
mixed *locdata;
mixed *atweapondata, *defweapondata;
int atx, aty;
object attacker, defender;
string loc;
int percent, damage;
int defweightpen, atweightpen;

mapping damagedata = ([
/* dt      init   step */
DT_CUT 	  : ({ 0.4, 0.275 }),
DT_STAB   : ({ 0.7, 0.15 }),
DT_IMPACT : ({ 0.5, 0.225 }),
DT_FIRE   : ({ 0.8, 0.3 }),
]);

/* Function prototypes */
int percentage(int,int,int);
int how_many_percent(int,int);
int resolve_hit_type(int);
void resolve_hitloc_damaging();
void resolve_special_influences();
int calculate_hit_chance();
int calculate_weapon_block_chance(int);
int calculate_dodge_chance(int);
int calculate_shield_chance();
float calculate_damage_bonus();
int success();
int block(int,int,int,int);
int miss();
int hit(object,object,mixed *);

/* Functions */
void
DEBUG(string str, object ob)
{
   message (CMD_MSG, 0,0,0, "^cG"+str+"^c0", ob);
}

mapping
query_damage_data()
{
   return damagedata;
}

int
percentage(int number, int percent, int maxpercentage)
{
   if(percent > maxpercentage)
	 percent = maxpercentage;
   if(number < 0)
	 return to_int(number + ((-number * percent) / 100));
   else
	 return to_int((number * percent) / 100);
}

int
how_many_percent(int value, int max)
{
   return (100 * value) / max;
}

int
resolve_hit_type (int i)
{
   if(i == 1)
	 return HIT_FUMBLE; 
   else if(i == 100)
	 return HIT_CRITICAL;
   else
	 return HIT_NORMAL;
}

void
resolve_hitloc_damaging ()
{
   int check;
   object *obs = MAPENV(attacker)->get_message_targets(atx, aty, VISIBLE_RADIUS);
   
   /* This is here to ensure that the message goes to the defender
	* if the attacker is using ranged weapons (the defender might
	* not be within the attacker's VISIBLE_RADIUS) */
   if(member_array(defender, obs) == -1)
	 obs += ({ defender });
     
   if(objectp(atweapondata[WD_WEAPON]))
	 if(atweapondata[WD_WEAPON]->damage(attacker, defender, loc, percent, damage, atweapondata[WD_WEAPON], defweapondata[WD_WEAPON]))
	   check = 1;
   
   if(objectp(atweapondata[WD_CSTYLE]))
	 if(atweapondata[WD_CSTYLE]->damage(attacker, defender, loc, percent, damage, atweapondata[WD_WEAPON], defweapondata[WD_WEAPON]))
	   check = 1;
       
   if(check)
	 return;
      
   switch(atweapondata[WD_DAMTYPE])
	 {
	  case DT_STAB:
		switch(percent)
		  {
		   case 0..50:
			 if(atweapondata[WD_RANGE] == RANG_CLOSE)
			   message (CMD_MSG, 0,0,0, "$n1 {punch} a small hole into $o2 "+loc+".", obs, ({ attacker, defender }) );
			 else
			   message (CMD_MSG, 0,0,0, "$n1 soars through the air and punches a small hole into $o2 "+loc+".", obs, ({ atweapondata[WD_WEAPON], defender }) );
			 break;
		   case 51..100:
			 if(atweapondata[WD_RANGE] == RANG_CLOSE)
			   message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$o1 thrust {open} up a gaping hole on $o2 "+loc+".", obs, ({ attacker, defender }) );
			 else
			   message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 soars through the air and opens up a gaping hole on $o2 "+loc+".", obs, ({ atweapondata[WD_WEAPON], defender }) );
			 defender->add_hitloc_bleed(loc, locdata[HITLOC_HP] / 12);
			 break;
		   case 101..150:
			 if(atweapondata[WD_RANGE] == RANG_CLOSE)
			   message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {puncture} $o2 "+loc+", spilling blood everywhere.", obs, ({ attacker, defender }) );
			 else
			   message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 soars through the air and punctures $o2 "+loc+".", obs, ({ atweapondata[WD_WEAPON], defender }) );
			 defender->add_hitloc_bleed(loc, locdata[HITLOC_HP] / 8);
			 break;
		   case 151..200:
			 if(atweapondata[WD_RANGE] == RANG_CLOSE)
			   {
				  if(objectp(atweapondata[WD_WEAPON]))
					message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {drive} $s1 $n2 into $o3 "+loc+".", obs, ({ attacker, atweapondata[WD_WEAPON], defender }) );
				  else
					message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {drive} $s1 "+atweapondata[WD_WEAPON]+" into $o2 "+loc+".", obs, ({ attacker, defender }) );
			   }
			 else
			   {
				  message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 soars through the air and sinks into $o2 "+loc+".", obs, ({ atweapondata[WD_WEAPON], defender }) );
			   }
			 defender->add_hitloc_bleed(loc, locdata[HITLOC_HP] / 5);
			 break;
		   default:
			 if(atweapondata[WD_RANGE] == RANG_CLOSE)
			   message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {impale} $o2 "+loc+"!", obs, ({ attacker, defender }) );
			 else
			   message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 soars through the air and impales $o2 "+loc+"!", obs, ({ atweapondata[WD_WEAPON], defender }) );
			 defender->add_hitloc_bleed(loc, locdata[HITLOC_MAX_BLEED]);
			 defender->cripple_hitloc(loc);
			 break;
		  }
		break;
	  case DT_CUT:
		switch(percent)
		  {
		   case 0..50:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {cut} a small wound on $o2 "+loc+".", obs, ({ attacker, defender }) );
			 break;
		   case 51..100:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$o1 attack {open} up a gaping wound on $o2 "+loc+".", obs, ({ attacker, defender }) );
			 defender->add_hitloc_bleed(loc, locdata[HITLOC_HP] / 10);
			 break;
		   case 101..150:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "Blood pours out of $o2 "+loc+" as $n1 {slash} $m2.", obs, ({ attacker, defender }) );
			 defender->add_hitloc_bleed(loc, locdata[HITLOC_HP] / 5);
		     break;
		   case 151..200:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$o1 brutal attack shreds $o2 "+loc+", revealing bone and flesh.", obs, ({ attacker, defender }) );
		     defender->add_hitloc_bleed(loc, locdata[HITLOC_HP] / 2);
			 break;
		   default:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {chop} through $o2 "+loc+"!", obs, ({ attacker, defender }) );
			 defender->remove_hitloc(loc);
			 break;
		  }
		break;
	  case DT_IMPACT:
		switch(percent)
		  {
		   case 0..50:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {hit} $o2 "+loc+" causing a minor bruise.", obs, ({ attacker, defender }) );
			 break;
		   case 51..100:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {club} $t2 in the "+loc+" crushing some tissue.", obs, ({ attacker, defender }) );
			 break;
		   case 101..150: 
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {bash} $o2 "+loc+" causing a minor fracture.", obs, ({ attacker, defender }) );
	    	 break;
		   case 151..200:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {smash} $o2 "+loc+" causing a major fracture.", obs, ({ attacker, defender }) );
			 break;
		   default:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {crush} $o2 "+loc+"!", obs, ({ attacker, defender }) );
			 defender->cripple_hitloc(loc);
			 break;
		  }
		break;
	  case DT_FIRE:
		switch(percent)
		  {
		   case 0..50:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 slightly {scorch} $o2 "+loc+".", obs, ({ attacker, defender }) );
			 break;
		   case 51..100:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {burn} $o2 "+loc+".", obs, ({ attacker, defender }) );
			 break;
		   case 101..150:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {torch} $o2 "+loc+", causing severe burns.", obs, ({ attacker, defender }) );
			 break;
		   case 151..200:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {fry} $o2 "+loc+".", obs, ({ attacker, defender }) );
			 break;
		   default:
			 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {incinerate} $o2 "+loc+".", obs, ({ attacker, defender }) );
			 defender->remove_hitloc(loc);
			 if(defender)
			   defender->stop_hitloc_bleed(loc);
			 break;
		  }
		break;
	  default:
		message (CMD_MSG, 0,0,0, "BUG! INVALID DAMAGE TYPE!", attacker);
		break;
	 }
  
   write_client (attacker, CMD_SOUND, SFX_HIT2);
   if(defender)
	 {
		write_client (defender, CMD_SOUND, SFX_HIT);
		defender->add_hp(-damage);
	 }
}

void
resolve_special_influences ()
{
   int bonus;
   switch(defender->query_hitloc_role(loc))
	 {
	  case BODYPART_SUPPORTING:
		if(defender->query_position() != POS_LYING)
		  {
			 bonus = (defender->query_stat(A_AGI) * 2) + defender->query_stat(A_STU);
			 if(damage > bonus)
			   {
				  message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {lose} $s1 balance and {fall} down.", MAPENV(defender), defender);
				  defender->set_position(POS_LYING);
			   }
		  }
		break;
	  case BODYPART_CAPITAL:
		bonus = defender->query_max_hp() / 5;
		if(damage > bonus)
		  {
			 bonus = damage - bonus;
			 if(!defender->query_uncons() && !defender->query_dead())
			   {
				  if(bonus > defender->query_max_hp() / 10)
					{
					   defender->uncons();
					}
				  else
					{
					   message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {are} stunned from the force of the attack.", MAPENV(defender), defender);
					   defender->add_freeze(bonus);
					}
			   }
		  }
		break;
	  default:
		break;
	 }
}

int
calculate_hit_chance ()
{
   int skill, bonus;
   
   if(defender->query_position() == POS_LYING)
	 bonus = 25;
   else if(defender->query_freeze() > 0)
	 bonus = defender->query_freeze() * 2;
   else if(defender->query_uncons())
	 bonus = 100;
   
   bonus -= atweightpen;
   skill = attacker->use_skill(atweapondata[WD_SKILL], 100, bonus, 0);
   if(atweapondata[WD_RANGE] == RANG_CLOSE)
	 {
		if(objectp(atweapondata[WD_CSTYLE]))
		  skill += percentage(atweapondata[WD_CSTYLE]->query_offense_bonus(), attacker->use_skill(atweapondata[WD_CSTYLE]->query_name(), 0, 0, 0), 100);
	 }
   skill += attacker->query_offense_bonus();
   skill += random(attacker->query_aggressiveness());
   return skill;
}

int
calculate_dodge_chance(int hc)
{
   int dodge;
   
   if(defender->query_uncons())
	 return 0;
  
   dodge = defender->use_skill("dodge", 100, -defweightpen, 0);
   if(objectp(defweapondata[WD_CSTYLE]))
	 dodge += percentage(defweapondata[WD_CSTYLE]->query_defence_bonus(), defender->use_skill(defweapondata[WD_CSTYLE]->query_name(), 0, 0, 0), 100);
   dodge += defender->query_defence_bonus();
   dodge += random(defender->query_defensiveness());
   /* If the attacker is not attacking in melee, he must be using
	* a thrown/missile weapon, which are much harder to dodge */
   if(atweapondata[WD_RANGE] != RANG_CLOSE)
	 dodge /= 2;
   if(dodge < 0)
	 dodge = 0;
   return dodge;
}

int
calculate_weapon_block_chance(int hc)
{
   int skill;
   string blockloc, natblock, *blocks;
   
   if(defender->query_uncons() || defender->query_ethereal())
	 return 0;
   
   /* If the defender does not wield a hand-held weapon, he is
	* using one of his blocking hitlocs (humanoids use arms)
	* to block an attack */
   if(!objectp(defweapondata[WD_WEAPON]))
	 {
		blocks = defender->query_blocking_natural_weapons();
		if(sizeof(blocks) < 1)
		  return 0;
		
		natblock = blocks[random(sizeof(blocks))];
		blockloc = defender->query_natural_weapon_reqloc(natblock);
		skill = defender->use_skill(defender->query_natural_weapon_skill(natblock), 100, -defweightpen, 0);
		if(skill < 0)
		  skill = 0;
		return skill;
	 }

   if(defweapondata[WD_WEAPON]->is_shield())
	 return 0;
   
   skill = defender->use_skill(defweapondata[WD_SKILL], 100, -defweightpen, 0);
   if(objectp(defweapondata[WD_CSTYLE]))
	 skill += percentage(defweapondata[WD_CSTYLE]->query_defence_bonus(), defender->use_skill(defweapondata[WD_CSTYLE]->query_name(), 0, 0, 0), 100);
   if(skill < 0)
	 skill = 0;
   return skill;
}

int
calculate_shield_chance()
{
   if(objectp(defweapondata[WD_WEAPON]))
	 return defweapondata[WD_WEAPON]->query_shielding();
   else
	 return 0;
}

float
calculate_damage_bonus()
{
   int str, stu;
   float bonus;
   str = attacker->query_stat(A_STR) - 12;
   stu = attacker->query_stat(A_STU) - 12;
   bonus = str + stu;
   return (bonus / 50.0) + 1.0;
}

int
success()
{
   if(damage < 1)
	 {
		message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$o1 attack is ineffective and doesn't cause damage.", MAPENV(defender), ({ attacker, defender }) );
		return HIT_ABLOCK;
	 }
   
   damage -= locdata[HITLOC_PROTECTION][atweapondata[WD_DAMTYPE]];
   if(damage < 1)
	 {
		message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$o1 armor stops $o2 attack.", MAPENV(defender), ({ defender, attacker }) );
		return HIT_ABLOCK;
	 }
   
   if (defender->query_ethereal())
	 {
		message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {punch} through the ethereal form of $n2.", MAPENV(defender), ({ attacker, defender }) );
		return HIT_SUCCESS;
	 }
   
   resolve_hitloc_damaging();
   if(defender)
	 {
		if(!defender->query_uncons())
		  resolve_special_influences();
		if(objectp(atweapondata[WD_WEAPON]))
		  atweapondata[WD_WEAPON]->attacked (attacker, defender, loc, percent, damage, atweapondata[WD_WEAPON], defweapondata[WD_WEAPON]);
		if(objectp(atweapondata[WD_CSTYLE]))
		  atweapondata[WD_CSTYLE]->attacked (attacker, defender, loc, percent, damage, atweapondata[WD_WEAPON], defweapondata[WD_WEAPON]);
	 }
   return HIT_SUCCESS;
}

int
block(int hit_chance, int defence, int s_block, int w_block)
{
   string blockloc, natblock, *blocks;
   
   if(objectp(defweapondata[WD_CSTYLE]))
	 if(defweapondata[WD_CSTYLE]->block (attacker, defender, atweapondata[WD_WEAPON], defweapondata[WD_WEAPON]))
	   return HIT_CBLOCK;
		
   defence -= s_block;
   if(hit_chance > defence)
	 {
		message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {block} $o2 attack with $s1 shield.", MAPENV(defender), ({ defender, attacker }) );
		return HIT_SBLOCK;
	 }
   
   if(objectp(defweapondata[WD_WEAPON]))
	 {
		if(defweapondata[WD_WEAPON]->block (attacker, defender, atweapondata[WD_WEAPON], defweapondata[WD_WEAPON]))
		  return HIT_WBLOCK;
		
		message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {block} $o2 attack with $s1 $n3.", MAPENV(defender), ({ defender, attacker, defweapondata[WD_WEAPON] }) );
		return HIT_WBLOCK;
	 }
   
   blocks = defender->query_blocking_natural_weapons();
   if(sizeof(blocks) < 1)
	 {
		message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {try} to block $o2 attack but is physically unable to do so.", MAPENV(defender), ({ defender, attacker }) );
		return success();
	 }
   
   natblock = blocks[random(sizeof(blocks))];
   blockloc = defender->query_natural_weapon_reqloc(natblock);
   blocks = defender->query_bodypart_parts(defender->query_hitloc_part_of_bodypart(blockloc));
   blockloc = blocks[random(sizeof(blocks))];
   message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {block} $o2 attack with $s1 "+blockloc+".", MAPENV(defender), ({ defender, attacker }) );
   if(defender->damage_hitloc(blockloc, atweapondata[WD_DAMTYPE], damage))
	 message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$o1 "+blockloc+" is damaged due to the block.", MAPENV(defender), defender);
   return HIT_WBLOCK;
}

int
miss()
{
   if(objectp(atweapondata[WD_CSTYLE]))
	 if(atweapondata[WD_CSTYLE]->miss (attacker, defender, atweapondata[WD_WEAPON], defweapondata[WD_WEAPON]))
	   return HIT_MISS;
   
   if(objectp(atweapondata[WD_WEAPON]))
	 if(atweapondata[WD_WEAPON]->miss (attacker, defender, atweapondata[WD_WEAPON], defweapondata[WD_WEAPON]))
	   return HIT_MISS;
   
   message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {miss} $n2.", MAPENV(defender), ({ attacker, defender }) );
   return HIT_MISS;
}
    
/* Return values:
 * -1 No attack
 *  0 Dodged
 *  1 Blocked by weapon
 *  2 Blocked by shield
 *  3 Blocked by armor
 *  4 Blocked by combat style 
 *  5 Succesfull hit
 */
int
hit (object att, object def, mixed *hitdata)
{
   int hit_chance, hit_mag, hit_type;
   int s_block, w_block, dodge, defence;
   int returnval = HIT_UNDECIPHERED;
   int minusep;
   float mult, *is;
   string *tmps, *targs;
   
   if(!att || !def)
	 return returnval;
   
   att->set_were_in_battle (1);
   def->set_were_in_battle (1);
   
   if(att->query_dead())
	 {
		message (CMD_MSG, 0,0,0, "Fighting in hell is prohibited.", att);
		return returnval;
	 }
   
   attacker = att;
   defender = def;
   
   atweapondata = hitdata;
   if(!atweapondata)
	 {
		message (CMD_MSG, 0,0,0, "You haven't armed any weapons.", attacker);
	   	return returnval;
	 }
   defweapondata = defender->resolve_weapon();
   if(!defweapondata)
	 defweapondata = allocate(WD_MAX);
   
   /* Resolve attacker's coordinates for battle messages */
   atx = attacker->query_gridx();
   aty = attacker->query_gridy();
   
   /* Resolve the defender/attacker weight penalties */
   atweightpen = attacker->query_weight_penalty();
   defweightpen = defender->query_weight_penalty();
   
   /* Calculate hit bonus */
   hit_chance = calculate_hit_chance();
   hit_type = resolve_hit_type(d("1d100"));
   if(hit_type == HIT_CRITICAL)
	 {
		message (CMD_SEE, atx, aty, VISIBLE_RADIUS, "$n1 {score} a ^crcritical^c0 hit.", MAPENV(attacker), attacker);
		hit_chance += 50;
	 }
   
   /* Calculate dodge bonus */
   dodge = calculate_dodge_chance(hit_chance);
     
   /* Calculate weapon block bonus */
   w_block = calculate_weapon_block_chance(hit_chance);
      
   /* Calculate shield block bonus */
   s_block = calculate_shield_chance();
      
   /* Calculate defence bonus */
   if(atweapondata[WD_RANGE] != RANG_CLOSE)
	 {
		defence = s_block;
	 }
   else
	 {
		defence = s_block + w_block;
		defence += defender->query_defence_bonus();
		defence += random(defender->query_defensiveness());
	 }
    
   /* Resolve hitloc and calculate damage and hit magnitude */
   if(defender->query_uncons())
	 {
		/* If the defender is unconscious, it is assumed that the 
		 * attacker is trying to kill him, and thus he is aiming 
		 * for the most vulnerable parts */
		targs = ({ });
		tmps = defender->query_existing_hitlocs();
		targs += defender->query_role_hitlocs(tmps, BODYPART_CAPITAL);
        targs += defender->query_role_hitlocs(tmps, BODYPART_HUB);
		loc = targs[random(sizeof(targs))];
		damage = atweapondata[WD_DAMAGE] * 2;
		if(atweapondata[WD_RANGE] != RANG_MISSILE)
		  damage = to_int(damage * calculate_damage_bonus());
	 }
   else
	 {
		loc = defender->query_target_hitloc();
		hit_mag = hit_chance - ((dodge / 2) + (defence / 5));
		if(hit_mag < 0)
		  hit_mag = 0;
		/* The attacker hardly gains any extra bonus to the efficiency of 
		 * his attack from his size and strength if he is using a missile 
		 * weapon */
		if(atweapondata[WD_RANGE] != RANG_MISSILE)
		  {
			 hit_mag = to_int(hit_mag * calculate_damage_bonus());
			 if(objectp(atweapondata[WD_CSTYLE]))
			   hit_mag += percentage(atweapondata[WD_CSTYLE]->query_damage_bonus(), attacker->use_skill(atweapondata[WD_CSTYLE]->query_name(), 0,0,0), 100);
			 hit_mag += attacker->query_damage_bonus();
			 damage = percentage(atweapondata[WD_DAMAGE], hit_mag, to_int(calculate_damage_bonus() * 200.0));
		  }
		else
		  damage = percentage(atweapondata[WD_DAMAGE], hit_mag, 200);
	 }
   locdata = defender->query_hitlocs()[loc];
   /* The following code applies the damage type specific damage
	* modifiers (fire damage is much more painful than impact
	* damage and thus should cause a bigger hp loss) */
   is = damagedata[atweapondata[WD_DAMTYPE]];
   mult = (is[1] * (to_float(damage) / 25.0)) + is[0];
   damage = to_int(mult * damage);
   percent = how_many_percent(damage, locdata[HITLOC_HP]);
   if(damage > locdata[HITLOC_HP] * 2)
	 damage = locdata[HITLOC_HP] * 2;
     
   /*
   DEBUG("Dodge chance: "+dodge, defender);
   DEBUG("Block chance: "+w_block, defender);
   DEBUG("Defence chance: "+defence, defender);
   DEBUG("Shield chance: "+s_block, defender);
   if(objectp(defweapondata[WD_CSTYLE]))
	 DEBUG("Combat style: "+defweapondata[WD_CSTYLE]->query_name(), defender);  
   
   DEBUG("Hit chance: "+hit_chance, attacker);
   DEBUG("Hit magnitude: "+hit_mag, attacker);
   DEBUG("Damage: "+damage, attacker);
   DEBUG("Damage percentage: "+percent, attacker);
   DEBUG("Damage bonus: "+calculate_damage_bonus(), attacker);
   if(objectp(atweapondata[WD_CSTYLE]))
	DEBUG("Combat style: "+atweapondata[WD_CSTYLE]->query_name(), attacker);
   */
   
   if(hit_chance < dodge)
	 {
		returnval = miss();
	 }
   else
	 {
		if (hit_chance > defence)
		  {
			 returnval = success();
		  }
		else
		  {
			 returnval = block(hit_chance, defence, s_block, w_block);
		  }
	 }
   minusep = d("1d3");
   if(defender)
	 {
		defender->receive_event(E_ATTACKED, attacker);
		
		if (!defender->query_ethereal())
		  defender->add_ep(-minusep);
	 }
   minusep += random(attacker->query_fatique_bonus() + 1);
   attacker->add_ep(-minusep);
   
   if (attacker)
	 attacker->flush();
   
   if (defender)
	 defender->flush();
   
   return returnval;
} 
