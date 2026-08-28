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

inherit BASE;

#include <mcp.h>
#include <sound.h>
#include <tile.h>
#include <hitloc.h>

#define DEBUG	message(CMD_MSG, 0, 0, 0, sprintf("%d", room_change), THOB)

/* --- -- - variables - -- --- */

string name;            /* object name */
int		 grid_x, grid_y;			/* coordinates in grid */
int		 gridchar;				/* character that is shown in the gridmap */
int		 gridcolor;				/* color of the character */
int		 gridlight;				/* the amount of light object emits */
int    physical;         /* can you bump into object */ 
nosave int invis = 0;

nosave string over;
nosave string last_description = "";
nosave string long_desc;
nosave string short_desc;
nosave mapping command;

/* --- function prototypes --- */

void	move(object, int, int); /* Move object */

/* --- -- - functions - -- --- */

string
query_true_name ()
{
   return name;
}

string
add_command (string cmd, string fnc)
{
   if (!command)
	 command = ([ ]);
   
   command[cmd] = fnc;
}

int
test_command (string cmd, string arg)
{
   string *k;
   int i;
   string fnc, ostr;
   object o;
   
   if (!command)
	 return 0;
   
   k = keys (command);
   i = member_array (cmd, k);
   
   if (i > -1)
	 {
		if (strsrch(command[k[i]], "->") > -1)
		  {
			 sscanf (command[k[i]], "%s->%s", ostr, fnc);
		  }
		else
		  fnc = command[k[i]];
		
		if (!ostr)
		  {
			 call_other (THOB, fnc, arg);
			 return 1;
		  }
		else
		  {
			 o = find_object(ostr);
			 call_other (o, fnc, arg);
			 return 1;
		  }
	 }
   
   return 0;
}

string
query_short ()
{
   if(THOB->is_living())
	 {
		if(THOB->query_name() && (THOB->query_name() != THOB->query_race()))
		  return THOB->query_name();
		else
		  return article(THOB->query_race());
	 }
   else
	 {
		if(short_desc)
		  return article(short_desc);
		else
		  return article(THOB->query_name(), THOB, THOB);
	 }
}

string
query_long ()
{
   return long_desc ? long_desc : query_short() + ".";
}

string
set_short (string str)
{
   return short_desc = str;
}

string
set_long (string str)
{
   return long_desc = str;
}

string
query_over ()
{
   return over;
}

string
set_over (string str)
{
   return over = str;
}

int
set_invis (int i)
{
   return invis = i;
}

int
query_invis ()
{
   return invis;
}

void
create()
{
   ::create();
   THOB->create_gridobject ();
}

void
raw_move (mixed target)
{
   ::move (target);
}

void
move (mixed target, int x, int y)
{
   int lx, ly;
   string desc;
   string *sups;
   object penv, env, o, *u;

   if (stringp(target) && strsrch(target, "!") > -1)
	 sscanf (target, "%s!y%dx%d", target, y, x);
   
   if (target->is_gridmap())
	 {
		x += 100*target->query_area_x();
		y += 100*target->query_area_y();
		target = ENV(target);
	 } 
   
   
   if (x == -1 && y == -1) /* We're not moving on any gridmap, so we quit */
	 {
		if (ENV(THOB))
		  {
			 if (ENV(ENV(THOB))->is_areamap())
			   ENV(ENV(THOB))->object_exit(THOB);
		  }
		::move(target);
		return;  
	 }
   
   /* Check if we ran over the borders */
   
	 if (!(env = target->get_area(x, y)))
	 {
		message(CMD_MSG, 0, 0, 0, "You can't go that way; the world ends there.", THOB);
		return;
	 }
   
   lx = x - x/100*100;  /* Local coordinates */
   ly = y - y/100*100;
   
   /* Should the following be moved somewhere else? */
   
   if (THOB->query_physical() && !env->do_special (lx, ly))
	 {		
		u = env->get_obj(lx, ly);
		
		if (u)
		  foreach (o in u)
		  {
			 if (o)
			   if (o != THOB && o->query_physical())
			   {
				  if (THOB->query_ethereal() || o->query_ethereal())
					message (CMD_SEE, 0, 0, 0, "You walk through $N1.", THOB, o);
				  else if (o->is_item())
					{
					   return;
					   message (CMD_SEE, 0,0,0, "$p1 is blocking your way.", THOB, o);
					}
				  else
					{
					   BATTLE_D->hit (THOB, o, THOB->resolve_weapon());
					   return;
					}
			   }
			 else if (o->query_gridx() == x && o->query_gridy() == y && o != THOB)
               {
				  if (o->query_over())
					message (CMD_SEE, 0,0,0, o->query_over(), THOB);
				  else if (!o->query_invis())
					message (CMD_SEE, 0,0,0, "There is $p1 lying here.", THOB, o);
               }
		  }
			
		switch (env->query_tile(lx, ly))
		  {
		   case TILE_WALL:
		   case TILE_EARTH_WALL:
		   case TILE_METAL_WALL:
		   case TILE_STONE_WALL:
		   case TILE_WOOD_WALL:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, THOB->query_gridx(), THOB->query_gridy(), VISIBLE_RADIUS, 
						   "$N1 {bang} $s1 head against the wall, ouch!", 
						   MAPENV(THOB), THOB);
				  THOB->add_hp (-random(2));
				  THOB->flush();
				  write_client (THOB, CMD_SOUND, SFX_WALL);
				  return;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You walk through the wall.", THOB);
				  break;
			   }
		   case '>':
			 message (CMD_SEE, 0,0,0, "There is a staircase leading down.", THOB);
			 break;
		   case '<':
			 message (CMD_SEE, 0,0,0, "There is a staircase leading up.", THOB);
			 break;
		   case '/':
			 message (CMD_SEE, 0,0,0, "You step through the open door.", THOB);
			 break;
		   case TILE_ROCK:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "There is a large rock blocking your way.", THOB);
				  return;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You walk through the rock.", THOB);
				  break;
			   }
		   case TILE_ACID:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "The acid beneath your feet is rapidly corroding you!", THOB);
				  sups = THOB->query_role_hitlocs(THOB->query_existing_hitlocs(), BODYPART_SUPPORTING);
				  if(sizeof(sups) > 0)
					THOB->damage_hitloc(sups[random(sizeof(sups))], "acid", d("1d50+10"));
				  else
					THOB->damage_hitloc(THOB->query_random_existing_hitloc(), "fire", d("1d50+10"));
				  break;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You float above the acid.", THOB);
				  break;
			   }
		   case TILE_LAVA:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "The molten lava beneath your feet really hurts!", THOB);
				  sups = THOB->query_role_hitlocs(THOB->query_existing_hitlocs(), BODYPART_SUPPORTING);
				  if(sizeof(sups) > 0)
					THOB->damage_hitloc(sups[random(sizeof(sups))], "fire", d("1d100+50"));
				  else
					THOB->damage_hitloc(THOB->query_random_existing_hitloc(), "fire", d("1d100+50"));
				  break;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You float above the molten lava.", THOB);
				  break;
			   }
		   case TILE_WATER:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "There is water, and you can't swim, so you suffer a bit.", THOB);
				  THOB->add_hp (-(random(10) + 10));
				  break;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You float above the water.", THOB);
				  break;
			   }
		   case TILE_D_WATER:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "You are sinking in the deep water as you can't swim.", THOB);
				  THOB->add_hp (-(random(50) + 10));
				  break;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You float above the water.", THOB);
				  break;
			   }
		   case TILE_STALAGMITE:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "A large stalagmite is blocking your path.", THOB);
				  return;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You walk through a large stalagmite.", THOB);
				  break;
			   }
		   case TILE_CRACK:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "You clumsily evade a crack in the ground.", THOB);
				  break;
			   }
			 else
			   break;
		   case TILE_CON_TREE:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "You slip past a conifer tree.", THOB);
				  if (!random(6))
					THOB->add_ep (-random(2));
				  break;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You walk through a conifer tree.", THOB);
				  break;
			   }
		   case TILE_S_CON_TREE:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "You slip past a small conifer tree.", THOB);
				  if (!random(3))
					THOB->add_ep (-random(2));
				  break;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You walk through a small conifer tree.", THOB);
				  break;
			   }
		   case TILE_L_CON_TREE:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "There is a large conifer tree blocking your way.", THOB);
				  return;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You walk through a large conifer tree.", THOB);
				  break;
			   }
		   case TILE_DEC_TREE:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "You slip past a deciduous tree.", THOB);
				  if (!random(6))
					THOB->add_ep (-random(2));
				  break;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You walk through a deciduous tree.", THOB);
				  break;
			   }
		   case TILE_S_DEC_TREE:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "You slip past a small deciduous tree.", THOB);
				  if (!random(3))
					THOB->add_ep (-random(2));
				  break;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You walk through a small deciduous tree.", THOB);
				  break;
			   }
		   case TILE_L_DEC_TREE:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "There is a large deciduous tree blocking your way.", THOB);
				  return;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You walk through a large deciduous tree.", THOB);
				  break;
			   }
		   case TILE_JUN_TREE:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "You slip past a jungle tree.", THOB);
				  if (!random(6))
					THOB->add_ep (-random(2));
				  break;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You walk through a jungle tree.", THOB);
				  break;
			   }
		   case TILE_S_JUN_TREE:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "You slip past a small jungle tree.", THOB);
				  if (!random(3))
					THOB->add_ep (-random(2));
				  break;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You walk through a small jungle tree.", THOB);
				  break;
			   }
		   case TILE_L_JUN_TREE:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "There is a large jungle tree blocking your way.", THOB);
				  return;
			   }
			 else
			   {
				  message (CMD_SEE, 0,0,0, "You walk through a large jungle tree.", THOB);
			   }
		   case TILE_L_GRASS:
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "The grass is very dense and slows you down.", THOB);
				  THOB->add_ep (-random(1));
				  break;
			   }
			 else
			   break;
		   case '+':
			 if (!THOB->query_ethereal())
			   {
				  message (CMD_SEE, 0,0,0, "The door is closed.", THOB);
				  THOB->flush();
				  write_client (THOB, CMD_SOUND, SFX_WALL);
				  return;
			   }
			 else
			   break;
		  }
	 }
   
   penv = ENV(THOB);
   
   if (ENV(THOB) != env)
	 ::move(env);
   
   target->object_move(THOB, penv, x, y);

   if (!random (4))       /* This should definitely be done in a better way */
	 THOB->add_ep (-random(2));
   
   desc = env->query_description (lx, ly, last_description);
   
   if (desc && desc != "")
	 {
		write_client(THOB, CMD_DESCRIPTION, "^cg" + desc);
		last_description = desc;
	 }   		
}

void
update_inv()
{
   object o, *a;
   int amount = 0, i;
   
   /* stack coins */
   
   a = all_inventory (THOB);
   
   foreach (o in a)
	 {
		if (arrayp(o->query_generate()))
		  {
			 if (o->query_generate()[2] == "gold coin")
			   {
				  i++;
				  amount += o->query_value();
			   }
		  }
	 }
   
   if (i > 1)
	 {
		for (int j=1;j < i;j++)
		  {
			 destruct (present (THOB, "gold coin", -1, -1));
		  }
		
		present (THOB, "gold coin", -1, -1)->set_value (amount);
	 }
   
   /* do the torches */
   
   MAPENV(THOB)->object_update(THOB);
}


string
set_name (string str)
{
   return name = str;
}

int *
set_gridpos (int x, int y)
{
	grid_x = x;
	grid_y = y;
	return ({ x,  y	});
}

int
set_gridchar (int c)
{
	return gridchar = c;
}

int
set_gridcolor (int c)
{
	return gridcolor = c;
}

int
set_gridlight (int c)
{
	return gridlight = c;
}

int
set_physical (int b)
{
	return physical = b;
}

string
query_name ()
{
	return name;
}

string
query_cap_name()
{
   return capitalize(name);
}

int
query_gridx ()
{
	return grid_x;
}

int
query_gridy ()
{
	return grid_y;
}

int
query_gridchar ()
{
	return gridchar;
}

int
query_gridcolor ()
{
	return gridcolor;
}

int
query_gridlight ()
{
   int total;
   object o, *u;
   
   u = all_inventory(THOB);
   
   if (!u || sizeof(u) == 0)
	 return gridlight;
   
   foreach (o in u)
	 {
		total += o->query_gridlight();
	 }
   
	return gridlight + total;
}
				 
int
query_physical ()
{
	return physical;
}

