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
#include <hitloc.h>
#include <weapon.h>
#include <armor.h>

/* Global variable definitions */
int bodytype;
mapping hitlocs;
mapping bodyparts;
int bleed;

/* Function prototypes */
void init_bodyparts();
void init_hitlocs();
mapping query_hitlocs();
mapping query_bodyparts();
mixed *query_bodypart(string);
string *query_bodypart_parts(string);
string *query_bodypart_dependants(string);
int query_bodypart_role(string);
int query_hitloc_role(string);
string *query_role_bodyparts(string *,int);
string *query_role_hitlocs(string *,int);
string query_hitloc_part_of_bodypart(string);
string *query_bodypart_lower_hitlocs(string);
string *query_parts_of_body(string *);
string *query_other_hitlocs(string *);
int query_bodytype();
int set_bodytype(int);
string *query_existing_hitlocs();
string query_random_hitloc();
string query_random_existing_hitloc();
int set_hitloc_cond(string,int);
int query_hitloc_cond(string);
int query_hitloc_hp(string);
int query_hitloc_type(string);
int query_hitloc_bleed(string);
int query_hitloc_max_bleed(string);
int query_hitloc_size(string);
string query_hitloc_armed_weapon(string);
string query_hitloc_worn_item(string);
mapping query_hitloc_protection(string);
mapping add_hitloc_protection(string,string,int);
int query_hitloc_arming_type(string);
string query_target_hitloc();
int query_bleed_value();
int add_hitloc_bleed(string,int);
string *query_bleeding_hitlocs();
void bleed();
void stop_hitloc_bleed(string);
void stop_bleed();
int heal_hitlocs();
string bodypart_short(string *);
object clone_bodypart(string *);
int disarm_limb(string);
int damage_hitloc(string,string,int);
void cripple_hitloc(string);
void remove_hitloc(string);
string *query_wield_hitlocs();
string *query_usable_wield_hitlocs();
string arm(string);
string disarm(string);
string wield(object,string *);
string remove_weapon(object);
string wear(object);
string strip(object);
object query_wielded_weapon_from_hitloc(string);
object query_worn_item_from_hitloc(string);
string *query_all_available_weapons();
string *query_armed_natural_weapons();
object *query_wielded_weapons();
object *query_shields();
object *query_worn_items();
object *query_missile_weapons();
string *query_possible_wield_hitlocs(object);
string *query_weapon_wielded_in(object);
string *query_item_worn_in(object);
mixed *query_weapon_battle_array(mixed,object);
mixed resolve_cstyle_weapon(object,string *);
mixed *resolve_weapon();
int purge_eq();

/* Functions */

/* Sets up the bodyparts-mapping which includes the relations of bodyparts
 * such as bodypart dependancies and roles */
void
init_bodyparts()
{
   bodyparts = RACE_D->query_bodytypes()[THOB->query_bodytype()];
}

/* Sets up the hitloc-mapping which includes (see /include/hitloc.h for
 * the array slot numbers):
 * HITLOC_COND(int) == overall condition (crippled, severed, ok)
 * 
 * HITLOC_HP(int) == hitloc damaging threshold, note that this does
 * not reduce from given damage, it is merely a constant number 
 * which dictates how much damage a certain hitloc can withstand
 * 
 * HITLOC_TYPE(int) == vital, nonvital, irrelevant. When a vital hitloc
 * gets crippled, the character dies, when a nonvital hitloc gets
 * crippled, it is unusable and irrelevant hitlocs naturally don't
 * have any meaning.
 * 
 * HITLOC_BLEED(int) == bleed value which is decreased from hps every
 * 20 heart beats.
 * 
 * HITLOC_MAX_BLEED(int) == maximum bleed value
 * 
 * HITLOC_SIZE(int) == the relative size of a hitloc. Unused currently
 * but should be used in the future for resolving target hitlocs in battle
 * (see query_target_hitloc()).
 * 
 * HITLOC_ARMED(string) == either the filename of a weapon object or
 * the name of a natural weapon (punch, kick etc).
 * 
 * HITLOC_WEAR(string) == the filename of a clothing/armor object which
 * is in the hitloc
 * 
 * HITLOC_PROTECTION(mapping) == the protection of the hitloc, format:
 * ([ damage_type : protection ])
 * where "damage_type" is a string value such as DT_IMPACT or DT_CUT and
 * "protection" is an int-value which is decreased from the damage of 
 * every blow of damage type "damage_type". See /daemon/battle.c lines
 * 396 -> 422 (int success()).
 * 
 * HITLOC_ARMTYPE(int) == if the hitloc can handle a hand-held weapon 
 * object or not. */
void
init_hitlocs()
{
   float percent;
   string *locs;
   mapping locmap;
   mixed *locarr;
      
   percent = to_float(THOB->query_max_hp()) / 100.0;
   bleed = 0;
   locmap = RACE_D->query_hitlocs()[THOB->query_bodytype()];
   locs = keys(locmap);
   hitlocs = ([ ]);
         
   foreach(string entry in locs)
	 {
		locarr = locmap[entry];
		hitlocs[entry] = ({ HITLOC_OK, to_int(locarr[0] * percent), locarr[1], 0, to_int(locarr[2] * percent), locarr[3], 0, 0, ([ ]), locarr[4] });
	 }
}

/* Miscellaneous functions */

mapping
query_hitlocs()
{
   return hitlocs;
}

mapping
query_bodyparts()
{
   return bodyparts;
}

mixed *
query_bodypart(string str)
{
   return bodyparts[str];
}

/* Returns the hitlocs of a certain bodypart. */
string *
query_bodypart_parts(string str)
{
   return bodyparts[str][BODYPART_PARTS];
}

/* Returns the depending bodyparts of a certain bodypart. */
string *
query_bodypart_dependants(string str)
{
   return bodyparts[str][BODYPART_DEPENDANTS];
}

/* Returns the role of a certain bodypart. This is used in
 * resolving special damage effects (stuns, falling down
 * from a blow) in battle among other things.
 * 
 * The roles are:
 * BODYPART_LIMB == limb bodypart which is not required
 * for effective movement (human arms)
 * 
 * BODYPART_HUB == the center bodypart in which all other
 * bodyparts are connected to (human torso)
 * 
 * BODYPART_CAPITAL == controlling bodypart (human head)
 * 
 * BODYPART_SUPPORTING == bodypart which is essential for
 * movement (human legs) */
int
query_bodypart_role(string str)
{
   return bodyparts[str][BODYPART_ROLE];
}

/* Returns the role of a hitloc according to the role of the
 * bodypart the hitloc is a part of */
int
query_hitloc_role(string str)
{
   return THOB->query_bodypart_role(THOB->query_hitloc_part_of_bodypart(str));
}

/* Returns a string array of bodyparts that comply to a certain 
 * role from the string array "parts" */
string *
query_role_bodyparts(string *parts, int role)
{
   int i, j;
   string *retstrs = ({ });
   
   for(i=0,j=sizeof(parts);i<j;i++)
	 {
		if(THOB->query_bodypart_role(parts[i]) == role)
		  retstrs += ({ parts[i] });
	 }
   return retstrs;
}

/* Returns a string array of the hitlocs that comply to a certain
 * role from the string array "parts" (resolved according to the
 * bodypart the hitloc is a part of) */
string *
query_role_hitlocs(string *parts, int role)
{
   int i, j;
   string *retstrs = ({ });
   
   for(i=0,j=sizeof(parts);i<j;i++)
	 {
		if(THOB->query_hitloc_role(parts[i]) == role)
		  retstrs += ({ parts[i] });
	 }
   return retstrs;
}
   
/* Returns the bodypart a certain hitloc is a part of */
string
query_hitloc_part_of_bodypart(string str)
{
   int i, j;
   string *strs = keys(bodyparts);
   
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		if(member_array(str, bodyparts[strs[i]][BODYPART_PARTS]) != -1)
		  return strs[i];
	 }
}

/* Returns an array of the hitlocs that are lower in the
 * hitloc hierarchy than hitloc "str". The returned array
 * includes the hitloc "str". */
string *
query_bodypart_lower_hitlocs(string str)
{
   int index, i, j;
   string bp;
   string *retstrs;
   string *hitstrs;
   string *deps;
            
   bp = THOB->query_hitloc_part_of_bodypart(str);
   if(!bp)
	 return ({ });
   
   deps = THOB->query_bodypart_dependants(bp);
   hitstrs = THOB->query_bodypart_parts(bp);
   index = member_array(str, hitstrs);
   if(index == -1)
	 return ({ });
   
   retstrs = ({ });
   for(i=index,j=sizeof(hitstrs);i<j;i++)
	 {
		retstrs += ({ hitstrs[i] });
	 }
   for(i=0,j=sizeof(deps);i<j;i++)
	  {
		 retstrs += THOB->query_bodypart_parts(deps[i]);
	  }
   return retstrs;
}

/* Resolves the bodyparts that are found in the hitloc string
 * array "locs". Returns "partial "+bodypart in case not all
 * of the bodyparts member hitlocs are in "locs". */
string *
query_parts_of_body(string *locs)
{
   int i, j;
   string bp;
   string *retstrs;
   string *strs;
   mapping bpmap = ([ ]);
   
   if(sizeof(locs) < 1)
	 return ({ });
   
   for(i=0,j=sizeof(locs);i<j;i++)
	 {
		bp = THOB->query_hitloc_part_of_bodypart(locs[i]);
	    bpmap += ([ bp : ({ locs[i] }) ]);
	 }
   
   strs = keys(bpmap);
   retstrs = ({ });
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		if(sizeof(bpmap[strs[i]]) == sizeof(THOB->query_bodypart_parts(strs[i])))
		  retstrs += ({ strs[i] });
		else
		  retstrs += ({ "partial "+strs[i] });
	 }
   return retstrs;
}

/* Returns all the other remaining hitlocs except the ones found
 * in the hitloc string array "strs". */
string *
query_other_hitlocs(string *strs)
{
   int i, j;
   string *locs = THOB->query_existing_hitlocs();
   string *retstrs = ({ });
   
   for(i=0,j=sizeof(locs);i<j;i++)
	 {
		if(member_array(locs[i],strs) == -1)
		  retstrs += ({ locs[i] });
	 }
   return retstrs;
}
   
/* Returns the bodytype (BT_HUMANOID, BT_INSECT) etc. The bodytype
 * is used in init_bodyparts() to resolve what bodyparts and hitlocs
 * a being has. */
int
query_bodytype()
{
   return bodytype;
}

int
set_bodytype(int i)
{
   return bodytype = i;
}

/* Returns the physically remaining hitlocs */
string *
query_existing_hitlocs()
{
   int i, j;
   string *retstrs, *strs;
      
   retstrs = ({ });
   strs = keys(hitlocs);
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		if(hitlocs[strs[i]][HITLOC_COND] != HITLOC_SEVERED)
		  retstrs += ({ strs[i] });
	 }
   return retstrs;
}

string
query_random_hitloc()
{
   string *strs;
   
   strs = keys(THOB->query_hitlocs());
   if(sizeof(strs) < 1)
   	 return 0;
   
   return strs[random(sizeof(strs))];
}

string
query_random_existing_hitloc()
{
   string *hitloc_strs;
   
   hitloc_strs = THOB->query_existing_hitlocs();
   if(sizeof(hitloc_strs) < 1)
	 return 0;
   
   return hitloc_strs[random(sizeof(hitloc_strs))];
}

int
set_hitloc_cond(string str, int i)
{
   return hitlocs[str][HITLOC_COND] = i;
}

int
query_hitloc_cond(string str)
{
   return hitlocs[str][HITLOC_COND];
}

int
query_hitloc_hp(string str)
{
   return hitlocs[str][HITLOC_HP];
}

int
query_hitloc_type(string str)
{
   return hitlocs[str][HITLOC_TYPE];
}

int
query_hitloc_bleed(string str)
{
   return hitlocs[str][HITLOC_BLEED];
}

int
query_hitloc_max_bleed(string str)
{
   return hitlocs[str][HITLOC_MAX_BLEED];
}

int
query_hitloc_size(string str)
{
   return hitlocs[str][HITLOC_SIZE];
}

string
query_hitloc_armed_weapon(string str)
{
   return hitlocs[str][HITLOC_ARMED];
}

string
query_hitloc_worn_item(string str)
{
   return hitlocs[str][HITLOC_WEAR];
}

mapping
query_hitloc_protection(string str)
{
   return hitlocs[str][HITLOC_PROTECTION];
}

mapping
add_hitloc_protection(string loc, string damtype, int prot)
{
   hitlocs[loc][HITLOC_PROTECTION][damtype] += prot;
   return hitlocs[loc][HITLOC_PROTECTION];
}

int
query_hitloc_arming_type(string str)
{
   return hitlocs[str][HITLOC_ARMTYPE];
}
						 
/* Returns a hitloc which is used as a target in battle.
 * Should use fancier formulas. The size of the hitloc
 * and the size difference between the attacker and defender
 * should affect the outcome. */
string
query_target_hitloc()
{
   return THOB->query_random_existing_hitloc();
}

/* Bleeding functions */

int
query_bleed_value()
{
   return bleed;
}

int
add_hitloc_bleed(string str, int i)
{
   hitlocs[str][HITLOC_BLEED] += i;
   if(hitlocs[str][HITLOC_BLEED] > hitlocs[str][HITLOC_MAX_BLEED])
	 {
		hitlocs[str][HITLOC_BLEED] = hitlocs[str][HITLOC_MAX_BLEED];
	 }
   bleed += hitlocs[str][HITLOC_BLEED];
   return hitlocs[str][HITLOC_BLEED];
}

string *
query_bleeding_hitlocs()
{
   int i, j;
   string *strs, *retstrs;
   strs = keys(hitlocs);
   retstrs = ({ });
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		if(hitlocs[strs[i]][HITLOC_BLEED])
		  retstrs += ({ strs[i] });
	 }
   return retstrs;
}
		   
/* Is called every 20 hbs */
void
bleed()
{
   string *arr;
   int i, sz;
   
   arr = THOB->query_bleeding_hitlocs();
   
   if (arr)
	 {
		sz = sizeof(arr);
		i = random (sz);
		
		message (CMD_FEEL, 0,0,0, "Your "+arr[i]+" is bleeding!", THOB);
		THOB->add_hp (-hitlocs[arr[i]][HITLOC_BLEED]);
		
	 }
}

void
stop_hitloc_bleed(string str)
{
   int bleedval = THOB->query_hitloc_bleed(str);
   hitlocs[str][HITLOC_BLEED] = 0;
   bleed -= bleedval;
}

void
stop_bleed()
{
   int i, j;
   string *strs = keys(THOB->query_hitlocs());
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		hitlocs[strs[i]][HITLOC_BLEED] = 0;
	 }
   bleed = 0;
}

/* Is called every 25 hbs. Reduces the bleeding of a hitloc
 * linearly. */
void
update_bleed()
{
   int i, j;
   string *strs = THOB->query_bleeding_hitlocs();
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		hitlocs[strs[i]][HITLOC_BLEED]--;
		
		if (!hitlocs[strs[i]][HITLOC_BLEED])
		  {
			 message (CMD_FEEL, 0,0,0, "Your "+strs[i]+" is no longer bleeding.", THOB);
			 
			 if (sizeof(THOB->query_bleeding_hitlocs()) == 0)
			   bleed = 0;
		  }
	 }
}

/* Sets all hitlocs in ok-status. Doesn't restore hitpoints
 * however. */
int
heal_hitlocs()
{
   int i, j;
   string *locs = keys(hitlocs);
   
   for(i=0,j=sizeof(locs);i<j;i++)
	 {
		THOB->set_hitloc_cond(locs[i], HITLOC_OK);
	 }
   return 1;
}

/* Cripple and remove functions */

/* Returns the short desc of a certain array of hitlocs. */
string
bodypart_short(string *parts)
{ 
   int i, j;
   string *states = ({ });
   int capitals, hubs, limbs, supports;
   string *actuals = ({ });
   string *bps = THOB->query_parts_of_body(parts);
   
   for(i=0,j=sizeof(parts);i<j;i++)
	 {
		if(member_array(parts[i], actuals) == -1)
		  actuals += ({ parts[i] });
	 }

   capitals = sizeof(THOB->query_role_hitlocs(actuals, BODYPART_CAPITAL));
   hubs = sizeof(THOB->query_role_hitlocs(actuals, BODYPART_HUB));
   limbs = sizeof(THOB->query_role_hitlocs(actuals, BODYPART_LIMB));
   supports = sizeof(THOB->query_role_hitlocs(actuals, BODYPART_SUPPORTING));
      
   if(hubs)
	 {
		if(sizeof(actuals) == sizeof(keys(hitlocs)))
		  states += ({ "complete" });
		
		if(hubs < sizeof(THOB->query_role_hitlocs(keys(hitlocs), BODYPART_HUB)))
		   states += ({ "partial" });
		
		if(hubs == sizeof(THOB->query_role_hitlocs(keys(hitlocs), BODYPART_HUB)))
		  {
			 if(capitals < sizeof(THOB->query_role_hitlocs(keys(hitlocs), BODYPART_CAPITAL)))
			   states += ({ "decapitated" });
		  }
		
		if(!limbs && !supports)
		  states += ({ "completely dismembered" });
		else if(!limbs || !supports)
		  states += ({ "dismembered" });
        
		if(sizeof(states))
		  return enumerize(states)+" "+THOB->query_race()+" corpse";
		else
		  return THOB->query_race()+" corpse";
	 }
   else 
	 {
		return THOB->query_race()+" "+enumerize(bps);
	 }
}
       
/* Clones a severed bodypart */
object
clone_bodypart(string *parts)
{
   object ob;

   if(sizeof(parts) < 1)
	 return 0;
   
   ob = clone_object(BODYPART);
   ob->set_name(THOB->bodypart_short(parts));
   ob->set_race(THOB->query_race());
   ob->set_parts(parts);
   ob->set_long("It consists of "+enumerize(THOB->query_parts_of_body(parts))+".");
   ob->move(MAPENV(THOB),THOB->query_gridx(),THOB->query_gridy());
   return ob;
}

/* Disarms a hitloc. In case a hand-held weapon is in the hitloc,
 * it is dropped to the ground. */
int
disarm_limb(string limb)
{
   string nw;
   string armed;
   object weapon;
   
   nw = THOB->query_natural_weapon_in_hitloc(limb);
   armed = THOB->query_hitloc_armed_weapon(limb);
   
   if(!armed)
	 return 0;
   
   if(nw)
	 {
		if(armed == nw)
		  {
			 message (CMD_SEE, THOB->query_gridx(), THOB->query_gridy(), VISIBLE_RADIUS, "$n1 {are} no longer able to use "+nw+".", MAPENV(THOB)->get_players(), THOB);
			 THOB->disarm(nw);
		  }
	 }
 
   weapon = find_object(armed);
   if(objectp(weapon))
	 {
		message (CMD_SEE, THOB->query_gridx(), THOB->query_gridy(), VISIBLE_RADIUS, "$o1 $n2 falls on the ground.", MAPENV(THOB), ({ THOB, weapon }));
		THOB->remove_weapon(weapon);
		weapon->move(MAPENV(THOB), THOB->query_gridx(), THOB->query_gridy());
		THOB->update_inv();
	 }
   return 1;
} 

/* Damages the hitloc "loc" with the damage type "damtype" and
 * the damage value "damage". Identical to the hard-coded damage
 * formulas of the battle system, however is not called from there
 * and should not be called from there. */
int
damage_hitloc(string loc, string damtype, int damage)
{
   float mult, *is;
   
   if(!loc || !damtype || damage < 1)
	 return 0;
   
   damage -= THOB->query_hitloc_protection(loc)[damtype];
   if(damage < 1)
	 return 0;
   
   if(damage >= THOB->query_hitloc_hp(loc) * 2)
	 {
		switch(damtype)
		  {
		   case DT_CUT:
		   case DT_ACID:
			 THOB->remove_hitloc(loc);
			 break;
		   case DT_IMPACT:
		   case DT_STAB:
		   case DT_FIRE:
			 THOB->cripple_hitloc(loc);
			 break;
		  }
		return THOB->query_hitloc_hp(loc) * 2;
	 }
   else 
	 {
		is = BATTLE_D->query_damage_data()[damtype];
		mult = (is[1] * to_float(damage) / 25.0) + is[0];
		return THOB->add_hp(to_int(mult * -damage));
	 }
}

/* Cripples a hitloc and all the dependant hitlocs of that
 * hitloc. */
void
cripple_hitloc(string str)
{
   int i, j;
   int dieswitch;
   string *deps;
   
   deps = THOB->query_bodypart_lower_hitlocs(str);
   for(i=0,j=sizeof(deps);i<j;i++)
	 {
		THOB->set_hitloc_cond(deps[i], HITLOC_CRIPPLED);
		if(THOB->query_hitloc_type(deps[i]) == HITLOC_VITAL)
		  dieswitch = 1;
		THOB->disarm_limb(deps[i]);
	 }
   THOB->add_hp(-THOB->query_hitloc_hp(str) * 2);
   if(dieswitch && THOB)
	 THOB->die();
}

/* Removes a hitloc and all the dependant hitlocs of that hitloc
 * and clones them. */
void
remove_hitloc(string str)
{
   int i, j;
   int dieswitch;
   string *deps;
     
   deps = THOB->query_bodypart_lower_hitlocs(str);
   THOB->clone_bodypart(deps);
   for(i=0,j=sizeof(deps);i<j;i++)
	 {
		THOB->stop_hitloc_bleed(deps[i]);
		THOB->set_hitloc_cond(deps[i], HITLOC_SEVERED);
		
		if(THOB->query_hitloc_type(deps[i]) == HITLOC_VITAL)
		  dieswitch = 1;
		THOB->disarm_limb(deps[i]);
	 }
   THOB->add_hp(-THOB->query_hitloc_hp(str) * 2);
   if(THOB)
	 {
		if(dieswitch)
		  THOB->die();
		else
		  THOB->add_hitloc_bleed(str, THOB->query_hitloc_max_bleed(str));
	 }
}

/* Weapon functions */

/* Returns a string array of all the hitlocs that can handle a hand-held
 * weapon. */
string *
query_wield_hitlocs()
{
   int i, j;
   string *strs = keys(hitlocs), *retstrs = ({ });
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		if(THOB->query_hitloc_arming_type(strs[i]) == ARMTYPE_WIELD)
		  retstrs += ({ strs[i] });
	 }
   return retstrs;
}

/* Returns a string array of all the existing hitlocs that can handle
 * a hand-held weapon. */
string *
query_usable_wield_hitlocs()
{
   int i, j;
   string *strs = THOB->query_wield_hitlocs(), *retstrs = ({ });
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		if(THOB->query_hitloc_cond(strs[i]) == HITLOC_OK)
		  retstrs += ({ strs[i] });
	 }
   return retstrs;
}

/* Arms a natural weapon */
string
arm(string weapon)
{
   object armed;
   string loc = THOB->query_natural_weapon_reqloc(weapon);
   
   armed = THOB->query_wielded_weapon_from_hitloc(loc);
   if(armed)
	 {
		THOB->remove_weapon(armed);
	 }
   return hitlocs[loc][HITLOC_ARMED] = weapon;
}

/* Disarms a natural weapon. */
string
disarm(string weapon)
{
   string loc = THOB->query_natural_weapon_reqloc(weapon);
   hitlocs[loc][HITLOC_ARMED] = 0;
   return weapon;
}

/* Wields a weapon object in "locs". */
string
wield(object weapon, string *locs)
{
   int i, j;
   string name;
   
   if(!objectp(weapon) || !arrayp(locs))
	 return 0;

   if(ENV(weapon) != THOB)
	 return 0;
   
   name = file_name(weapon);
   for(i=0,j=sizeof(locs);i<j;i++)
	 hitlocs[locs[i]][HITLOC_ARMED] = name;
   weapon->set_wielded(sizeof(locs));
   THOB->add_fatique_bonus(weapon->query_fatique_bonus());
   THOB->add_defence_bonus(weapon->query_defence_bonus());
   THOB->add_offense_bonus(weapon->query_offense_bonus());
   THOB->add_speed(-weapon->query_speed() * 5000);
   return name;
}

/* Removes a weapon object. */
string
remove_weapon(object weapon)
{
   int i, j;
   string *locs;
   string *weaps;
   
   if(!objectp(weapon))
	 return 0;
   
   if(ENV(weapon) != THOB)
	 return 0;
   
   locs = THOB->query_weapon_wielded_in(weapon);
   for(i=0,j=sizeof(locs);i<j;i++)
	 {
		hitlocs[locs[i]][HITLOC_ARMED] = 0;
	 }
   weaps = THOB->query_usable_natural_weapons();
   for(i=0,j=sizeof(weaps);i<j;i++)
	 {
		if(member_array(THOB->query_natural_weapon_reqloc(weaps[i]), locs) != -1)
		  THOB->arm(weaps[i]);
	 }
   weapon->set_wielded(0);
   THOB->add_defence_bonus(-weapon->query_defence_bonus());
   THOB->add_offense_bonus(-weapon->query_offense_bonus());
   THOB->add_fatique_bonus(-weapon->query_fatique_bonus());
   THOB->add_speed(weapon->query_speed_bonus() * 5000);
   return file_name(weapon);
}

/* Wear functions */

/* Wears an item. */
string
wear(object item)
{
   int i, j, k, l;
   string name;
   string *targ;
   string *prots;
   mapping itemprots;
   
   if(!objectp(item) || !item->is_clothing())
	 return 0;
   
   if(ENV(item) != THOB)
	 return 0;
      
   name = file_name(item);
   targ = item->query_target();
   
   itemprots = item->query_protection();
   if(mapp(itemprots))
	 prots = keys(itemprots);
   for(i=0,j=sizeof(targ);i<j;i++)
	 {
		hitlocs[targ[i]][HITLOC_WEAR] = name;
		for(k=0,l=sizeof(prots);k<l;k++)
		  THOB->add_hitloc_protection(targ[i], prots[k], itemprots[prots[k]]);
	 }
   item->set_worn(1);
   THOB->add_defence_bonus(item->query_defence_bonus());
   THOB->add_fatique_bonus(item->query_fatique_bonus());
   THOB->add_offense_bonus(item->query_offense_bonus());
   THOB->add_speed(-item->query_speed_bonus() * 5000);
   return name;
}

/* Removes a worn item. */
string
strip(object item)
{
   int i, j, k, l;
   string *targ;
   string *prots;
   mapping itemprots;
   
   if(!objectp(item) || !item->is_worn())
	 return 0;
   
   if(ENV(item) != THOB)
	 return 0;
   
   targ = item->query_target();
   itemprots = item->query_protection();
   if(mapp(itemprots))
	 prots = keys(itemprots);
   for(i=0,j=sizeof(targ);i<j;i++)
	 {
		hitlocs[targ[i]][HITLOC_WEAR] = 0;
		for(k=0,l=sizeof(prots);k<l;k++)
		  if(hitlocs[targ[i]][HITLOC_PROTECTION][prots[k]])
			THOB->add_hitloc_protection(targ[i], prots[k], -itemprots[prots[k]]);
	 }
   item->set_worn(0);
   THOB->add_defence_bonus(-item->query_defence_bonus());
   THOB->add_offense_bonus(-item->query_offense_bonus());
   THOB->add_fatique_bonuxs(-item->query_fatique_bonus());
   THOB->add_speed(item->query_speed_bonus() * 5000);
   return file_name(item);
}

/* Some stuff derived from the stuff above */

/* Returns a wielded weapon object from the hitloc "str" or 0
 * if there is no weapon wielded in it. */
object
query_wielded_weapon_from_hitloc(string str)
{
   object ob;
   string armed = THOB->query_hitloc_armed_weapon(str);
   
   if(!armed)
	 return 0;
   
   ob = find_object(armed);
   return ob;
}

/* Returns a worn item object from the hitloc "str" or 0
 * if there is no worn item in it. */
object
query_worn_item_from_hitloc(string str)
{
   object ob;
   string worn = THOB->query_hitloc_worn_item(str);
   if(!worn)
	 return 0;
	
   ob = find_object(worn);
   return ob;
}

/* Returns an array of the filenames of wielded weapon objects
 * and the names of the armed natural weapons. */
string *
query_all_available_weapons()
{
   int i, j;
   string armed;
   string *locs = THOB->query_existing_hitlocs(), *retstrs = ({ });
   for(i=0,j=sizeof(locs);i<j;i++)
	 {
		armed = THOB->query_hitloc_armed_weapon(locs[i]);
		if(armed && (member_array(armed, retstrs) == -1))
		  retstrs += ({ armed });
	 }
   return retstrs;
}

string *
query_armed_natural_weapons()
{
   int i, j;
   string armed;
   string *strs = THOB->query_all_natural_weapon_reqlocs(), *retstrs = ({ });
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		armed = THOB->query_hitloc_armed_weapon(strs[i]);
		if(THOB->query_natural_weapons()[armed])
		  retstrs += ({ armed });
	 }
   return retstrs;
}

object *
query_wielded_weapons()
{
   int i, j;
   object ob;
   object *retobs = ({ });
   string *locs = THOB->query_wield_hitlocs();
   for(i=0,j=sizeof(locs);i<j;i++)
	 {
		ob = THOB->query_wielded_weapon_from_hitloc(locs[i]);
		if(ob && (member_array(ob, retobs) == -1))
		  retobs += ({ ob });
	 }
   return retobs;
}

/* Returns an array of the equipped shield objects. */
object *
query_shields()
{
   int i, j;
   object *retobs = ({ });
   object *obs = THOB->query_wielded_weapons();
   for(i=0,j=sizeof(obs);i<j;i++)
	 {
		if(obs[i]->is_shield())
		  retobs += ({ obs[i] });
	 }
   return retobs;
}

/* Returns an array of the equipped missile weapon objects. */
object *
query_missile_weapons()
{
   int i, j;
   object *retobs = ({ });
   object *obs = THOB->query_wielded_weapons();
   for(i=0,j=sizeof(obs);i<j;i++)
	 {
		if(obs[i]->is_missile_weapon())
		  retobs += ({ obs[i] });
	 }
   return retobs;
}

/* Returns an array of the worn item objects. */
object *
query_worn_items()
{
   int i, j;
   string worn;
   object ob;
   object *retobs = ({ });
   string *locs = keys(hitlocs);
   for(i=0,j=sizeof(locs);i<j;i++)
	 {
		worn = THOB->query_hitloc_worn_item(locs[i]);
		if(worn)
		  {
			 ob = find_object(worn);
			 if(ob && (member_array(ob, retobs) == -1))
			   retobs += ({ ob });
		  }
	 }
   return retobs;
}

/* Returns the hitlocs that can be used to wield the weapon "weapon". */
string *
query_possible_wield_hitlocs(object weapon)
{
   int i, j, k, l, handed;
   string str1, str2;
   string *strs;
   string *locs = THOB->query_usable_wield_hitlocs();
   string *retstrs = ({ });
      
   handed = weapon->query_handedness();
   if(handed == 0)
	 {
		retstrs += locs;
	 }
   
   if((handed == WEAPON_1H) || (handed == WEAPON_12H))
	 {
		retstrs += locs;
	 }
   
   if((handed == WEAPON_2H) || (handed == WEAPON_12H) || (handed == 0))
	 {
		for(i=0,j=sizeof(locs);i<j;i++)
		  {
			 strs = locs - ({ locs[i] });
			 for(k=0,l=sizeof(strs);k<l;k++)
			   {
				  str1 = locs[i]+" and "+strs[k];
				  str2 = strs[k]+" and "+locs[i];
				  if((member_array(str1, retstrs) == -1) && (member_array(str2, retstrs) == -1))
					retstrs += ({ str1 });
			   }
		  }
	 }
   return retstrs;
}

/* Returns the hitlocs where a certain weapon is wielded in. */
string *
query_weapon_wielded_in(object weapon)
{
   int i, j;
   string name = file_name(weapon);
   string *locs = THOB->query_wield_hitlocs();
   string *strs = ({ });
   
   for(i=0,j=sizeof(locs);i<j;i++)
	 {
		if(THOB->query_hitloc_armed_weapon(locs[i]) == name)
		  strs += ({ locs[i] });
	 }
   return strs;
}

/* Returns the hitlocs where a certain item is worn in. */
string *
query_item_worn_in(object item)
{
   int i, j;
   string name = file_name(item);
   string *locs = THOB->query_existing_hitlocs();
   string *strs = ({ });
   
   for(i=0,j=sizeof(locs);i<j;i++)
	 {
		if(THOB->query_hitloc_worn_item(locs[i]) == name)
		  strs += ({ locs[i] });
	 }
   return strs;
}

/* Returns the battle array of a melee weapon. Is not used when
 * throwing items or using missile weapons. See /include/battle.h
 * and the last line of the function. */
mixed *
query_weapon_battle_array(mixed weapon, object cstyleob)
{
   int damage;
   string skill;
   int damtype, *damtypes;
         
   if(!weapon || (!stringp(weapon) && !objectp(weapon)))
	 return 0;
   
   if(THOB->query_natural_weapons()[weapon])
	 return THOB->query_natweapon_battle_array(weapon, cstyleob);
   
   if(!objectp(weapon))
	 weapon = find_object(weapon);
   if(!weapon)
	 return 0;
   
   damtypes = weapon->query_damage_types();
   if(sizeof(damtypes) > 0)
	 {
		damtype = damtypes[random(sizeof(damtypes))];
		if(member_array(damtype, damtypes) != -1 && weapon->is_weapon())
		  damage = weapon->query_type_damage(damtype);
		else
		  damage = 10;
	 }
   else
	 {
		damtype = DT_IMPACT;
		damage = 10;
	 }
	    
   if(weapon->is_wielded() == 2 && weapon->query_type() == WEAPON_12H)
	 damage += damage / 2;
   
   skill = weapon->query_skill();
   if(!skill || weapon->is_missile_weapon())
	 skill = "weapons";
      
   return ({ weapon, damtype, damage, RANG_CLOSE, cstyleob, skill });
}
   
/* Returns a weapon object or a natural weapon that accords to
 * the given combat style from the string array "weapons" or 
 * if none of the entries in "weapons" accord to the given
 * combat style, returns a random entry. */
mixed
resolve_cstyle_weapon(object cstyleob, string *weapons)
{
   int i, j;
   string *cstyle_weapon_skills;
   string *cstyle_skills;
   mixed *return_values = ({ });
   object ob;
   
   if(!cstyleob)
	 return 0;
   
   if(sizeof(weapons) < 1 || !weapons)
	 return 0;
   
   cstyle_weapon_skills = cstyleob->query_weapon_skills();
   cstyle_skills = ({ });
   for(i=0,j=sizeof(cstyle_weapon_skills);i<j;i++)
	 {
		ob = SKILL_D->find_skill(cstyle_weapon_skills[i]);
		if(ob->query_type() != "node")
		  {
			 if(THOB->query_skills()[ob->query_name()])
			   cstyle_skills += ({ ob->query_name() });
		  }
		else
		  cstyle_skills += THOB->query_skill_children(cstyle_weapon_skills[i]);
	 }
   if(sizeof(cstyle_skills) < 1)
	 return 0;
      
   for(i=0,j=sizeof(weapons);i<j;i++)
	 {
		if(!THOB->query_natural_weapons()[weapons[i]])
		  {
			 ob = find_object(weapons[i]);
			 if(member_array(ob->query_skill(), cstyle_skills) != -1)
			   return_values += ({ ob });
		  }
		else
		  {
			 if(member_array(THOB->query_natural_weapon_skill(weapons[i]), cstyle_skills) != -1)
			   return_values += ({ weapons[i] });
		  }
	 }
   if(sizeof(return_values) > 0)
	 return return_values[random(sizeof(return_values))];
   else
	 return 0;
}  
 
/* Resolves a random weapon from all of the armed weapons. */
mixed *
resolve_weapon()
{
   mixed weapon;
   object cstyleob;
   string *weapons;
   mixed *weapondata;
         
   weapons = THOB->query_all_available_weapons();
   if(sizeof(weapons) < 1 || !weapons)
	 return 0;
   
   cstyleob = SKILL_D->find_skill(THOB->query_active_combat_style());
   weapon = THOB->resolve_cstyle_weapon(cstyleob, weapons);
   if(!weapon)
	 weapon = weapons[random(sizeof(weapons))];
   weapondata = THOB->query_weapon_battle_array(weapon, cstyleob);
   return weapondata;
}

/* Removes all arming/wearing entries from the hitloc mapping. */
int
purge_eq()
{
   int i, j;
   string *locs = keys(hitlocs);
   
   for(i=0,j=sizeof(locs);i<j;i++)
	 {
		hitlocs[locs[i]][HITLOC_ARMED] = 0;
		hitlocs[locs[i]][HITLOC_WEAR] = 0;
	 }
   return 1;
}
