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
#include <behavior.h>
#include <event.h>

/*  -- Variables --  */

nosave string *dir_cycle =
({
      ({  0, -1 }),
      ({  1, -1 }),
      ({  1, 0  }),
      ({  1, 1  }),
      ({  0, 1  }),
      ({ -1, 1  }),
      ({ -1, 0  }),
      ({ -1, 1  })
});

nosave int wander;
nosave int wander_delay;
nosave int wander_counter;
nosave int *wander_center = ({ });
nosave int wander_dist;

nosave string *talk = ({ });
nosave int talk_delay;
nosave int talk_count;

nosave int speed_count;

nosave int no_attack_counter;

nosave mapping chat_subjects = ([ ]);
nosave mapping events = ([ ]);
nosave object *enemies = ({ }); 
nosave object enemy;

nosave object *friends = ({ });

mixed relations = ([ ]);
int wimpy;
int wimpy_chance;
int *personality = ({ });

/*  -- Function prototypes --  */

int set_talk_delay(int);
object *add_enemy(object);
object *remove_enemy(object);
void clear_enemies();
object *get_enemies();


/*  -- Functions --  */


varargs void
set_wander(int type, int delay, mixed *dirs)
{
   wander = type;
   if (!delay)
	 delay = 10;
   wander_delay = delay;
   wander_counter = delay + random(delay);
   switch (type)
	 {
	  case NO_WANDER:
	  case RAND_WANDER:
		break;
	  case DIST_WANDER:
		wander_dist = to_int(dirs[2]);
		wander_center = ({ to_int(dirs[0]), to_int(dirs[1]) });
		if (wander_dist <= 1)
		  wander_dist = 2;
		break;
	  case PATH_WANDER:
	  case AREA_WANDER:
		break;
	 }
}

int
set_wimpy(int chance)
{
   return wimpy_chance = chance;
}

int
query_wimpy()
{
   return wimpy_chance;
}

void
set_talk(string *str)
{
   if (arrayp(str))
	 talk = str;
   else
	 talk = ({ str });
   if (!talk_delay)
	 set_talk_delay(500);
}

int
set_talk_delay(int delay)
{
   if (!delay)
	 delay = 500;
   if (delay < 0)
	 {
		talk_delay = -1;
		return talk_count = -1;
	 }
   talk_delay = delay;
   return talk_count = talk_delay + random(talk_delay);
}

object
*add_enemy(object obj)
{
   if (member_array(obj, enemies) == -1)
	 return enemies += ({ obj });
   else
	 return 0;
}

object
*remove_enemy(object obj)
{
   if (member_array(obj, enemies) > -1)
	 return enemies -= ({ obj });
   else
	 return 0;
}

object
get_nearest_enemy()
{
   int x, y, temp, dist = 100000, count = 50;
   object obj, nearest;
   
   x = THOB->query_gridx();
   y = THOB->query_gridy();
   
   foreach (obj in enemies)
	 {
		if ((count-- < 0) && nearest)
		  break;
		
		if (!obj)
		  {
			 enemies - ({ obj });
			 continue;
		  }
		
		if (member_array(obj, THOB->query_near_objects()) == -1)
		  {
			 enemies -= ({ obj  });
			 continue;
		  }
		if ((temp = distance(x, y, obj->query_gridx(), obj->query_gridy())) < dist)
		  {
			 dist = temp;
			 nearest = obj;
		  }
	 }
   return nearest;
}
   
void   
clear_enemies()
{
   enemies = ({ });
   enemy = 0;
}

object*
get_enemies()
{
   return enemies;
}

object
set_primary_enemy(object obj)
{
   enemy = obj;
}

mapping
add_event_handler(int event, string fun)
{
   return events += ([ event : fun ]);
}

varargs void
receive_event(int type, mixed *args)
{
   if (interactive(THOB))
	 return;
   
   if (functionp(events[type]))
	 evaluate(events[type], args);
   else
	 switch (type)
	 {
	  case E_ATTACKED:
		THOB->attacked_by(args);
		break;
	  case E_OBJECT_ENTER:
		THOB->object_enter(args);
		break;
	  case E_BATTLE_IN_SIGHT:
		if ((THOB->query_relation(args[0]) > 49) && (THOB->query_relation(args[1]) < 50))
		  add_enemy(args[1]);
		break;
	  default:
		break;
	 }
}

mapping
query_chat_subjects()
{
   return chat_subjects;
}

mapping
set_chat_subjects(mapping map)
{
   return chat_subjects = map;
}

mapping
add_chat_subject(mixed subject, string fun)
{
   if(arrayp(subject))
	 {
		foreach(string entry in subject)
		  chat_subjects += ([ entry : fun ]);
		return chat_subjects;
	 }
   else
	 return chat_subjects += ([ subject : fun ]);
}

void
catch_message(string str)
{
   string subject, args;
   
   if (interactive(THOB))
	 return;
   
   if(sscanf(str, "%s %s", subject, args) != 2)
	 subject = str;
   
   if(!chat_subjects[subject])
	 {
		if(subject == "bye")
		  {
			 THOB->force_us("say Bye.");
			 THIS->set_chat_target(0);
		  }
		else if(!chat_subjects["default"])
		  {
			 THOB->force_us("say "+({"Eh?","Umm?","What?","Pardon?","Uh, right.","Yeah, yeah..."})[random(6)]);
		  }
		else
		  {
			 if(functionp(chat_subjects["default"]))
			   evaluate(chat_subjects["default"], args);
			 else
			   THOB->force_us("say "+chat_subjects["default"]);
		  }
	 }
   else
	 {
		if(functionp(chat_subjects[subject]))
		  evaluate(chat_subjects[subject], args);
		else
		  THOB->force_us("say "+chat_subjects[subject]);
	 }
}

void
attacked_by(object obj)
{
   int *xy;
   
   if (interactive(THOB))
	 return;
   
/*   if (enemy == obj)
	 return;
  
*/
   
   if (add_enemy(obj))
	 {
		THOB->force_us("say GRRR!!");
		if (!enemy)
		  enemy = obj;
		MAPENV(THOB)->get_targets(THOB->query_gridx(), THOB->query_gridy(), 25)
		  ->receive_event(E_BATTLE_IN_SIGHT, ({ THOB, obj }));
	 }
   else if (no_attack_counter > 2)
	 {
		enemy = obj;
		no_attack_counter = 0;
	 }
		
   if ((to_float(THOB->query_hp())/to_float(THOB->query_max_hp()))*100 < wimpy_chance)
	 {
		THOB->force_us("say Eep!");
		xy = MAPENV(THOB)->get_far_location(THOB->query_gridx(), THOB->query_gridy(), 10);
		THOB->set_wander(DIST_WANDER, 100, ({ xy[0], xy[1], 2 }));
		wimpy = 1;
	 }

}

int
set_personality(int type, int value)
{
   return personality[type] = value;
}

int
query_personality(int type)
{
   return personality[type];
}

int
set_relation(string type, string subtype, int value)
{
   if (!relations[type])
	 relations[type] = ([ ]);
	 
   return relations[type][subtype] = value;
}
   
int
query_relation(object obj)
{
   int value;
   
   if (sizeof(keys(relations)))
	 foreach (string entry in keys(relations))
	 {
		foreach (string entry2 in keys(relations[entry]))
		  {
			 if (call_other(obj, "query_"+entry) == entry2)
			   value += relations[entry][entry2];
		  }
	 }

   
   return value;
}

void
object_enter(object obj)
{
   if (obj->is_living() && (THOB->query_relation(obj) 
							- THOB->query_personality(P_AGGRESSIVENESS) < -50))
	 {
		if (!sizeof(enemies))
		  THOB->force_us("say I smell an enemy.");
		THOB->add_enemy(obj);
	 }
}

int *      /* Returns target coords */
move_step(int sx, int sy)
{
   int x, y, dx, dy, tx, ty;
   int count, i;
   
   x = THOB->query_gridx();
   y = THOB->query_gridy();
   
   dx = sx - x;
   dy = sy - y;
   
   if (dx != 0)    dx = dx / abs(dx);
   if (dy != 0)    dy = dy / abs(dy);
   tx = x+dx;
   ty = y+dy;
   
   if (!MAPENV(THOB)->is_clear(tx, ty))
	 {
		if (sx == tx && sy == ty)
		  return ({ -1, -1  });
		  
		if (MAPENV(THOB)->query_tile(tx, ty) == '+')
		  {
			 THOB->force_us("open");
		  }
		else
		  {
			 for (i = 0; i < 8; i++)
			   if (dx == dir_cycle[i][0] &&
				   dy == dir_cycle[i][1])
				 break;
			 
			 while (MAPENV(THOB)->query_tile(tx,ty) != '+' &&
					!MAPENV(THOB)->is_clear(tx,ty) && count < 8)
			   {
				  i++;
				  if (i >= 8)
					i = 0;
				  count++;
				  dx = dir_cycle[i][0];
				  dy = dir_cycle[i][1];
				  tx = x+dx;
				  ty = y+dy;
			   }
			 
			 if (count == 8)
			   {
				  dx = 0;
				  dy = 0;
				  THOB->force_us("say Darn, I'm stuck.");
				  tx = x+dx;
				  ty = y+dy;
			   }
			 
			 else if (MAPENV(THOB)->query_tile(tx, ty) == '+')
			   THOB->force_us("open");
		  }
	 }
   return ({ tx, ty });
}

void
heart_beat()
{
   int x, y, tx, ty, *txy, i, *xy;
   int test = 0, move = 1;
   string spell;
   
   if (interactive(THOB) || THOB->query_uncons())
	 return;
   
   speed_count += 100000;
   
   if (speed_count <= THOB->query_speed())
	 return;
   
   // THOB->force_us ("say *** "+THOB->query_speed()+" "+THOB->query_were_in_battle()+"");
   
   speed_count = 0;
   
   x = THOB->query_gridx();
   y = THOB->query_gridy();
		
   txy = ({ x, y });
   
   no_attack_counter++;
   
   if (talk_delay > -1)
	 talk_count--;
   
   if (!talk_count && sizeof(talk))
	 {
		talk_count = talk_delay + random(talk_delay);
		THOB->force_us("say "+talk[random(sizeof(talk))]);
	 }
   
   if ((!enemy && sizeof(enemies)) || (no_attack_counter > 6))
	 {
		enemy = THOB->get_nearest_enemy();
		no_attack_counter = 0;
	 }

   /*
	* while (sizeof(enemies))
	*   {
	*     i = random(sizeof(enemies));
	*     if (member_array(enemies[i], THOB->query_near_objects()) == -1)
	*	    {
	*		  enemies -=  ({ enemies[i] });
	*		  continue;
	*	    }
	*     enemy = enemies[i];
	*     break;
	*   }
	*/
   
   THOB->set_were_in_battle (0);
   
   if (enemy && !wimpy)
	 {             /* Isvisible() ... */
		if (member_array(enemy, THOB->query_near_objects()) > -1)
		  {
			 if(THOB->query_position() != POS_STANDING)
			   {
				  THOB->force_us("pos stand");
				  return;
			   }
			 tx = enemy->query_gridx();
			 ty = enemy->query_gridy();
			 
			 if (!THOB->query_casting())
			   txy = THOB->move_step(tx, ty);
			 
			 if (txy[0] == -1 && !THOB->query_ethereal())
			   {
				  i = BATTLE_D->hit(THOB, enemy, THOB->resolve_weapon());
				  
				  if (enemy && enemy->query_ethereal() && i == 5)
					{
					   THOB->force_us ("say A ghost!");
					   xy = MAPENV(THOB)->get_far_location(THOB->query_gridx(), THOB->query_gridy(), 10);
					   THOB->set_wander(DIST_WANDER, 100, ({ xy[0], xy[1], 2 }));
					   wimpy = 1;
					}
				  
				  move = 0;
				  no_attack_counter = 0;
			   }
			 else
			   {
				  if (THOB->query_spells() && !THOB->query_casting() && THOB->query_sp()*100/THOB->query_max_sp() > 49)
					{	 
					   if (sizeof(keys(THOB->query_spells())))
						 if (spell = THOB->query_spells()[keys(THOB->query_spells())[0]][random (sizeof (THOB->query_spells()[keys(THOB->query_spells())[0]]))])
						 {
							move = 0;
							no_attack_counter = 0;
							THOB->force_us ("evoke "+spell+" to "+enemy->query_gridx()+" "+enemy->query_gridy()+"");
						 }
					}
				  
				  if (txy[0] == -1)
					{
					   move = 0;
					   no_attack_counter = 0;
					}
			   }
		  }
		else
		  {
			 enemy = 0;
		  }
	 }
   
   // If no enemies then wander around
   else if (wander)
	 {
		wander_counter--;
		if (wander_counter <= 0 || (test = ((wander == DIST_WANDER) &&
											(abs(x - wander_center[0]) > wander_dist ||
											 abs(y - wander_center[1]) > wander_dist))))
		  {
			 wander_counter = wander_delay + random(wander_delay);
			 switch (wander)
			   {
				case NO_WANDER :
				  break;
				case RAND_WANDER:
				  txy = MAPENV(THIS)->get_valid_dir(x, y);
				  if (txy == ({ x, y }))
					move = 0;
				  break;
				case DIST_WANDER :
				  if (test)
					{
					   txy = THOB->move_step(wander_center[0], wander_center[1]);
					   if(txy[0] == -1)
						 {
							THOB->force_us("say Out of my way!");
							move = 0;
						 }
					}
				  else
					{
					   txy = MAPENV(THIS)->get_valid_dir(x, y);
					   if (txy == ({ x, y }))
						 move = 0;
					}
				  break;
				case PATH_WANDER :
				case AREA_WANDER :
				  break;
				default :
				  break;
			   }
		  }
	 }
   if (((txy[0] != x) || (txy[1] != y)) && move)
	 THOB->move(MAPENV(THOB), txy[0], txy[1]);
}
