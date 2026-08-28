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

inherit ITEM;

int fuel;
int lit;
int maxlight;

void out_of_fuel();

void
create_light ()
{
   ::create();
   
   fuel = 5000;
   lit = 0;
}

void
set_fuel (int i)
{
   if (i < -1)
	 i = -1;
   
   fuel = i;
   lit = 0;
   
   remove_call_out ("do_update");
}

int
set_lit(int i)
{
   return lit = i;
}

int
query_lit()
{
   return lit;
}

void
set_maxlight (int i)
{
   maxlight = i;
}

void
do_update ()
{
   switch (fuel)
	 {
	  case 1201..2400:
		THOB->set_gridlight (maxlight);
		fuel = 1200;
		call_out ("do_update", 600);
		break;
	  case 601..1200:
		fuel = 600;
		THOB->set_gridlight (maxlight > 2 ? maxlight - 1 : maxlight);
		call_out ("do_update", fuel);
		break;
	  case 1..600:
		THOB->set_gridlight (maxlight > 2 ? maxlight - 2 : maxlight);
		fuel = 0;
		out_of_fuel ();
		break;
	  default:
		THOB->set_gridlight (maxlight);
		fuel = 2400;
		call_out ("do_update", 1200);
		break;
	 }

   if (THIS)
	 THIS->update_inv();
}

void
out_of_fuel ()
{
   lit = 0;
   fuel = 0;
   
   if (THIS)
	 message (CMD_SEE, THIS->query_gridx(),THIS->query_gridy(),VISIBLE_RADIUS, "$O1's $p2 goes dark.", MAPENV(THIS), ({ THIS, THOB }));
   else
	 message (CMD_SEE, THOB->query_gridx(),THOB->query_girdy(),VISIBLE_RADIUS, "$P1 goes dark.", MAPENV(THOB), THOB);
   
   remove_call_out ("do_update");
   THOB->set_gridlight(0);

   if (THIS)
	 THIS->update_inv();
}

int
query_fuel ()
{
   return fuel;
}

int
command_light (string str)
{
   if (!str)
	 return 0;
   
   if (present(THIS, str, -1, -1) != THOB)
	 return 0;
   
   if (lit)
	 {
		if (THIS)
		  THIS->force_us ("extinguish "+str);
		return 1;
	 }
   
   if (!fuel)
	 {
		message (CMD_MSG, 0,0,0, "$P1 can no longer give light!", THIS, THOB);
		return 1;
	 }
   
   message (CMD_SEE, THIS->query_gridx(), THIS->query_gridy(), VISIBLE_RADIUS, "$N1 {light} $p2.", MAPENV(THIS), ({ THIS, THOB }));
   lit = 1;
   
   switch (fuel)
	 {
	  case 1201..2400:
		THOB->set_gridlight (maxlight);
		call_out ("do_update", fuel-1200);
		break;
	  case 601..1200:
		THOB->set_gridlight (maxlight);
		call_out ("do_update", fuel-600);
		break;
	  case 1..600:
		THOB->set_gridlight (maxlight > 2 ? maxlight - 1 : maxlight);
		call_out ("do_update", fuel);
		break;
	  default:
		THOB->set_gridlight (maxlight);
		call_out ("do_update", fuel-2400);
		break;
	 }
   
   THIS->update_inv();
   return 1;
}

int
command_extinguish (string str)
{
   int i;
   
   if (!str)
	 return 0;
   
   if (present(THIS, str, -1, -1) != THOB)
	 return 0;
   
   if (fuel == -1)
	 {
		message (CMD_MSG, 0,0,0, "$P1 cannot be extinguished!", THIS, THOB);
		return 1;
	 }
   
   if (!lit)
	 {
		message (CMD_MSG, 0,0,0, "$P1 is not lit!", THIS, THOB);
		return 1;
	 }
   
   message (CMD_SEE, THIS->query_gridx(), THIS->query_gridy(), VISIBLE_RADIUS, "$N1 {extinguish} $p2.", MAPENV(THIS), ({ THIS, THOB }));
   lit = 0;
   i = remove_call_out ("do_update");
   
   if (i == -1)
	 i = 0;
   
   switch (fuel)
	 {
	  case 1201..2400:
		fuel = 1200 + i;
		break;
	  case 601..1200:
		fuel = 600 + i;
		break;
	  case 1..600:
		fuel = i;
		break;
	  default:
		fuel = 2400 + i;
		break;
	 }
   
   THOB->set_gridlight (0);
   THIS->update_inv();
   return 1;
}

string
query_long ()
{
   string buf = "";
   
   switch (fuel)
	 {
	  case -1:
		buf += "It will give light until the end of time.";
		break;
	  case 0:
		buf += "It can no longer give light.";
		break;
	  case 1..600:
		buf += "It will not give light much longer.";
		break;
	  case 601..1200:
		buf += "It will give light for a while yet.";
		break;
	  case 1201..2400:
		buf += "It will give light for a long time.";
		break;
	  default:
		buf += "It will give light for a very long time.";
		break;
	 }
   
   return "" + ::query_long() + " " + buf;
}

string
query_short ()
{
   string ext = "";
   
   if (lit)
	 ext += " (lit)";
   else if (!fuel)
	 ext += " (useless)";
   
   return "" + ::query_short() + ext;
}

int
is_light() 
{
   return 1;
}
