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

inherit LIVING;

#include <behavior.h>

object *
add_enemy(object obj)
{
   if(obj->query_true_name() == "yorkaturr" || obj->query_true_name() == "sinister" || obj->is_horseman())
	 return 0;
   else
	 return ::add_enemy(obj);
}

void
do_come(object args)
{
   int *xy = MAPENV(args)->get_near_location(args->query_gridx(), args->query_gridy(), 3);
   THOB->move(MAPENV(args), xy[0], xy[1]);
   THOB->force_us("say What is thy bidding, my master?");
}
   
void
do_return()
{
   THOB->force_us("say I shall disappear into the abyss and return when called.");
   THOB->remove();
}
 
void
do_go(string args, object commander)
{
   int *xy;
   object plr = find_player(args);
   if(!plr)
	 {
		THOB->force_us("say I cannot seem to locate "+capitalize(args)+", master.");
        return;
	 }
   xy = MAPENV(plr)->get_near_location(plr->query_gridx(), plr->query_gridy(), 3);
   THOB->move(MAPENV(plr), xy[0], xy[1]);
   THOB->force_us("say I have been sent by "+commander->query_cap_name()+" to come to thee, "+plr->query_cap_name());
}
 
void
do_kill(string args, object commander)
{
   int *xy;
   object targ;
   
   targ = find_player(lower_case(args));
   if(!targ)
	 {
		THOB->force_us("say My liege, I cannot seem to locate "+capitalize(args)+".");
        return;
	 }
   xy = MAPENV(targ)->get_near_location(targ->query_gridx(), targ->query_gridy(), 3);
   THOB->force_us("say Thy wish is granted.");
   THOB->move(MAPENV(targ), xy[0], xy[1]);
   THOB->add_enemy(targ);
   THOB->force_us("say I have come to slay thee in the name of "+commander->query_cap_name()+"!");
}

void
do_guard()
{
   THOB->force_us("say I shall slay all intruders.");
   THOB->set_personality(P_AGGRESSIVENESS, 200);
}

void
do_calm()
{
   THOB->force_us("say I shall not attack anyone.");
   THOB->set_personality(P_AGGRESSIVENESS, -500);
   THOB->clear_enemies();
}

void
do_attack()
{
   object *obs;
   
   obs = MAPENV(THOB)->get_livings(THOB->query_gridx()-VISIBLE_RADIUS, THOB->query_gridy()-VISIBLE_RADIUS, THOB->query_gridx()+VISIBLE_RADIUS, THOB->query_gridy()+VISIBLE_RADIUS);
   foreach(object entry in obs)
	 THOB->add_enemy(entry);
   
   if(sizeof(THOB->get_enemies()) < 1 || member_array(0, THOB->get_enemies()) != -1)
	 THOB->force_us("say There is no one to slay here, my liege.");
   else
	 THOB->force_us("say Death and decay!");
}
 
void
create_living()
{
   THOB->set_race("greater demon");
   THOB->set_physical(TRUE);
   THOB->set_relation("name", "yorkaturr", 200);
   THOB->set_relation("name", "sinister", 200);
   THOB->set_speed(200000);
   THOB->create_horseman();
}

int
is_horseman()
{
   return 1;
}
