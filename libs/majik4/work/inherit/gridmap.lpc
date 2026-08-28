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
#include <mudlib.h>
#include <door.h>
#include <tile.h>

/* --- -- - variables - -- --- */

nosave string *gridmap;
nosave mixed *objectmap;
nosave object *players = ({ });
nosave object *livings = ({ });
nosave mapping stair = ([ ]);
nosave mapping description = ([ ]);
nosave mapping command = ([ ]);
nosave mapping light_sources = ([ ]);
nosave mapping special = ([ ]);
nosave mapping door = ([ ]);

int light_level;
int area_x, area_y;					/* Location in areamap */
int grid_w, grid_h;						/* Gridmap size */
object area;


/* --- function prototypes --- */

void  update_client (object);				/* Refreshes objects in a client */
void  update_client_map (object);			/* Refreshes client's map */
void  refresh_all_clients ();				/* Refreshes all clients in gridmap */
void  update_tile (int, int, string);     /* Update tile on map */
void  set_light_level (int);        /* Set the global light level */
void  add_obj(int, int, object);
void  remove_obj(int, int, object);
object  *get_obj(int, int);
void    add_player(object);
void    remove_player(object);
object  *get_players();
void    add_living(object);
void    remove_living(object);
object  *get_livings();
int   *get_valid_dir(int, int);     /* Get non-blocking direction */
int   is_clear(int, int);           /* Check if not blocking */
int   is_gridmap();

/* --- -- - functions - -- --- */

/* query_weather_zone() is there for future, when our worldmap is ready we
 * have to add weather zones to it. 3,3 will be default for now, it means
 * something like center of the world.
 */

int *
query_weather_zone ()
{
   return ({ 3, 3 });
}

/* all are outdoors until this function is ready. FIXME: the integer should
 * be a define.
 */

int
query_outdoors (int x, int y)
{
   return 4;
}

void
update_client (object client)
{
   object *inv = all_inventory(ENV(client));
   object o;

   /* Clear object list */	
   write_client(client, CMD_DEL_OBJECTS, "");
   
   foreach (o in inv)
	 {
		/* Add object to list */
		write_client(client, CMD_ADD_OBJECT,
					 sprintf("%d", getoid(o))
					 );
		if (client == o)
		  write_client(client, CMD_OID_OWN, sprintf("%d", getoid(o)));
		/* And update object info */		
		write_client(client, CMD_INFO_OBJECT, 
					 sprintf("%d %d %d %d %d %d %s",
							 getoid(o),
							 o->query_gridchar(),
							 o->query_gridcolor(),
							 o->query_gridlight(),
							 o->query_physical(),
							 o->query_invis(),
							 o->query_true_name()
							 )
					 );
		write_client(client, CMD_MOVE_OBJECT,
					 sprintf("%d %d %d", 
							 getoid(o),
							 o->query_gridx(),
							 o->query_gridy()
							 )
					 );
	 }
}

void
update_clients ()
{
   object *inv = players;
   object o;
   
   if (inv)
	 foreach (o in inv)
	   update_client(o);
}

void
update_client_map (object client)
{
   if (!interactive (client))
	 return;
   
   write_client (client, CMD_MAP, implode(gridmap, ";")+";");
   write_client (client, CMD_SET_LIGHT, sprintf ("%d", light_level));
}

void
update_client_map_piece(object client, int x, int y, int side)
{
   if (!interactive (client))
	 return;
   
   x -= 25;
   y -= 25;
}

void
update_tile (int x, int y, string tile)
{
/*   object o, *u = players;
   
   if (players)
   foreach (o in u)
	   write_client (o, CMD_TILE, sprintf ("%d %d %c", x, y, tile[0]));
  */ 
   gridmap[y][x] = tile[0];
}

void
add_special (int x0, int y0, int x1, int y1, string func)
{
   special[sprintf ("x%dy%d-x%dy%d",x0,y0,x1,y1)] = func;
}					 

int
do_special (int x, int y)
{
   string *k;
   int x0, y0, x1, y1;
   
   if (!special)
	 return 0;
   
   k = keys (special);
   
   for (int i=0;i<sizeof(k);i++)
	 {
		sscanf (k[i], "x%dy%d-x%dy%d", x0, y0, x1, y1);
		
		if (x0 <= x && y0 <= y && x1 >= x && y1 >= y)
		  {
			 return call_other (THOB, special[k[i]], 0);
		  }
	 }
}
   
void
add_command (int x0, int y0, int x1, int y1, string cmd, string fnc)
{
   command[cmd] = ({ x0,y0,x1,y1, fnc });
}

int
test_command (int x, int y, string c, string a)
{
   string *k, fnc, ostr;
   int x0, y0, x1, y1;
   object o;
      
   if (!command)
	 return 0;
   
   k = keys (command);
   
   if (member_array(c, k) == -1)
	 return 0;
      
   for (int i=0;i<sizeof(k);i++)
	 {
		x0 = command[k[i]][0];
		y0 = command[k[i]][1];
		x1 = command[k[i]][2];
		y1 = command[k[i]][3];
		
		if (c == k[i] && x0 <= x && y0 <= y && x1 >= x && y1 >= y)
		  {
			 if (strsrch(command[k[i]][4], "->") > -1)
			   sscanf (command[k[i]][4], "%s->%s", ostr, fnc);
			 else
			   fnc = command[k[i]][4];
			 
			 if (!ostr)
			   {
				  call_other (THOB, fnc, a);
				  return 1;
			   }
			 else
			   {
				  o = find_object(ostr);
				  call_other (o, fnc, a);
				  return 1;
			   }
		  }
	 }
   return 0;
}

void
add_door (int x, int y, string material, int state, int lock)
{
   if (state != DOOR_NONEXIST)
	 door[({x, y})] = ({ material, state, lock });
   
   switch (state)
	 {
	  case DOOR_OPEN:
		ENV(THOB)->update_tile (area_x*100 + x, area_y*100 + y, "/");
		break;
	  case DOOR_CLOSED:
	  case DOOR_LOCKED:
		ENV(THOB)->update_tile (area_x*100 + x, area_y*100 + y, "+");
		break;
	 }
}

mixed *
query_door (int x, int y)
{
   string *k;
   int found = 0, i = 0;
   
   k = keys (door);
   
   for (i=0;i<sizeof(k);i++)
	 if (arrayp(k[i]) && sizeof(k[i]) == 2 && k[i][0] == x && k[i][1] == y)
	 {
		found = 1;
		break;
	 }
   
   if (!found)
	 return 0;
   
   return ({ door[k[i]][0], door[k[i]][1], door[k[i]][2] });
}

void
update_door (int x, int y, string material, int state, int lock)
{
   string *k;
   int found = 0, i = 0;
   
   k = keys (door);
   
   for (i=0;i<sizeof(k);i++)
	 if (arrayp(k[i]) && sizeof(k[i]) == 2 && k[i][0] == x && k[i][1] == y)
	 {
		found = 1;
		break;
	 }
   
   if (!found)
	 return;
   
   if (state == DOOR_NONEXIST)
	 {
		map_delete (door, door[k[i]]);
		return;
	 }
   
   door[k[i]] = ({ material, state, lock });
   
   switch (state)
	 {
	  case DOOR_OPEN:
		ENV(THOB)->update_tile (area_x*100 + x, area_y*100 + y, "/");
		break;
	  case DOOR_CLOSED:
	  case DOOR_LOCKED:
	    ENV(THOB)->update_tile (area_x*100 + x, area_y*100 + y, "+");
		break;
	 }
}

object
add_object (int x, int y, string s1, string s2, string s3)
{
   object o;
   
   o = GENERIC_D->generate (s1, s2, s3);
   
   if (o)
	 o->move (THOB, x, y);
   
   return o;
}

void
add_description (int x0, int y0, int x1, int y1, string sd, string ld)
{
   description[sprintf ("x%dy%d-x%dy%d",x0,y0,x1,y1)] = ({ sd,ld });
}

string
query_description (int x, int y, string last_description)
{
   string *k;
   int x0, y0, x1, y1;
   
   if (!description)
	 return "";
   
   k = keys (description);
   
   for (int i=0;i<sizeof(k);i++)
	 {
		sscanf (k[i], "x%dy%d-x%dy%d", x0, y0, x1, y1);

		if (x0 <= x && y0 <= y && x1 >= x && y1 >= y)
		  {			 
			 if (last_description != description[k[i]][1])
			   return description[k[i]][1];
			 else
			   return "";
		  }
	 }

   switch (gridmap[y][x])
	 {
	  case TILE_LADDER_UP:
		return "There is a ladder leading up.";
		break;
	  case TILE_LADDER_DOWN:
		return "There is a ladder leading down.";
		break;
	  case TILE_OPEN_DOOR:
		return "There is a open door.";
		break;
	  case TILE_CLOSED_DOOR:
		return "You are inside a closed door.";
		break;
	  case TILE_CRACK:
	    return "There is a crack in the ground.";
		break;
	  case TILE_EARTH:
		return "You are on a piece of ground.";
		break;
	  case TILE_UG_EARTH:
		return "You are on a piece of ground.";
		break;
	  case TILE_ICE:
	    return "You are on a piece of icy ground.";
		break;
	  case TILE_GRASS:
	    return "You are on grass.";
		break;
	  case TILE_L_GRASS:
		return "You are on long grass.";
		break;
	  case TILE_MARSH:
		return "You are on marsh.";
		break;
	  case TILE_SAND:
		return "You are on a piece of sand covered ground.";
		break;
	  case TILE_SNOW:
		return "You are on a piece of snow covered ground.";
		break;
	  case TILE_BURNT:
	    return "You are on burnt ground.";
		break;
	  case TILE_FLOOR:
		return "You are on a piece of floor.";
		break;
	  case TILE_STONE_FLOOR:
		return "You are on a piece of stone floor.";
		break;
	  case TILE_WOOD_FLOOR:
		return "You are on a piece of wooden floor.";
		break;
	  case TILE_CAVE_FLOOR:
	    return "You are on a piece of cave floor.";
		break;
	  case TILE_ACID:
		return "You are on a piece of acid covered ground.";
		break;
	  case TILE_WATER:
	    return "You are on water.";
		break;
	  case TILE_D_WATER:
		return "You are on deep water";
		break;
	  case TILE_UG_WATER:
		return "You are on water.";
		break;
	  case TILE_D_UG_WATER:
		return "You are on deep water.";
		break;
	  case TILE_WALL:
	    return "You are inside a solid wall.";
		break;
	  case TILE_EARTH_WALL:
		return "You are inside a solid wall.";
		break;
	  case TILE_METAL_WALL:
		return "You are inside a metal wall.";
		break;
	  case TILE_STONE_WALL:
		return "You are inside a stone wall.";
		break;
	  case TILE_WOOD_WALL:
		return "You are inside a wooden wall.";
		break;
	  case TILE_ROCK:
		return "You are inside a solid rock.";
		break;
	  case TILE_STALAGMITE:
		return "There is a stalagmite.";
		break;
	  case TILE_BUSH:
		return "There is a bush.";
		break;
	  case TILE_S_BUSH:
		return "There is a small bush.";
		break;
	  case TILE_L_BUSH:
	    return "There is a large bush.";
		break;
	  case TILE_CON_TREE:
	    return "There is a conifer tree.";
		break;
	  case TILE_S_CON_TREE:
	    return "There is a small conifer tree.";
		break;
	  case TILE_L_CON_TREE:
		return "There is a large conifer tree.";
		break;
	  case TILE_DEC_TREE:
		return "There is a decidious tree.";
		break;
	  case TILE_S_DEC_TREE:
	    return "There is a small decidious tree.";
		break;
	  case TILE_L_DEC_TREE:
		return "There is a large decicdious tree.";
		break;
	  case TILE_JUN_TREE:
	    return "There is a jungle tree.";
		break;
	  case TILE_S_JUN_TREE:
		return "There is a small jungle tree.";
		break;
	  case TILE_L_JUN_TREE:
		return "There is a large jungle tree.";
		break;
	  default:
		return "You're lost. Kill yourself.";
		break;
	 }
   
   return "You are a bug. Debug yourself.";
}

void
add_stair (int *coord, string file)
{
   stair[file] = coord;
}

string
find_stair (int x, int y)
{
   string *k = keys (stair);
   
   if (!k)
	 return "";
   
   for (int i=0;i<sizeof(k);i++)
	 {
		if (stair[k[i]][0] == y && stair[k[i]][1] == x)
		  return k[i];
	 }
   
   return "";
}

void
set_gridmap (string *arr)
{
   int i;
   
   if (gridmap)
	 {
		for (int y=0;y<sizeof(arr);y++)
		  for (int x=0;x<sizeof(arr[y]);x++)
			if (arr[y][x] != '?')
			  gridmap[y][x] = arr[y][x];
	 }
   else
	 gridmap = arr;
			
   grid_h = sizeof(arr);
   grid_w = strlen(arr[0]);
   objectmap = ({ });
   objectmap = allocate(grid_h);
   for (i = 0; i < grid_h; i++)
	 objectmap[i] = allocate(grid_w);
}

string *
query_gridmap ()
{
   return gridmap;
}

object *
get_obj(int x, int y)
{   
   if (sizeof(objectmap[y][x]))
	 return objectmap[y][x];
   else return ({ });
}

void 
add_obj(int x, int y, object o)
{
   if (!objectmap[y][x])
	 objectmap[y][x] = ({o});
   else 
	 objectmap[y][x] += ({o});
}

void 
remove_obj(int x, int y, object o)
{
   if (objectmap[y][x])
	 if (member_array(o, objectmap[y][x]) > -1)
	   objectmap[y][x] -= ({o});
}

void
add_player(object o)
{
   if (players)
	 {
		if (member_array(o, players) == -1)
		  players += ({ o });
	 }
   else
	 players = ({ o });
}

void
add_living(object o)
{
   if (livings)
	 {
		if (member_array(o, livings) == -1)
		  livings += ({ o });
	 }
   else
	 livings = ({ o });
}

void
remove_player(object o)
{
   players -= ({ o });
}

object
*get_players()
{
   return players;
}
void
remove_living(object o)
{
   livings -= ({ o });
}

object
*get_livings()
{
   return livings;
}

int
query_tile(int x, int y)
{
   return query_gridmap()[y][x];
}

int
query_gridmap_width ()
{
   return grid_w;
}

int
query_gridmap_height ()
{
   return grid_h;
}

int
query_area_x ()
{
   return area_x;
}

int
query_area_y ()
{
   return area_y;
}

void
create ()
{
/*   int *i = area->find_area_coords(file_name(THOB));
   world_x = i[0];
   world_y = i[1];
   THOB->create_gridmap ();
   move(area);    */
}

void
set_light_level(int i)
{
   object o, *u = players;
   light_level = TIME_D->query_sun_light();
   
   if (u)
	 foreach (o in u)
	 {
		write_client (o, CMD_SET_LIGHT, sprintf ("%d", light_level));
	 }
}

void set_area_coordinates(int x, int y)
{
   area_x = x;
   area_y = y;
}

int
*get_valid_dir(int x, int y)
{
   int i, j;
   int *dirs = ({0, 0});
   for (i=-1; i < 2 ;i++)
	 for (j=-1; j < 2 ;j++)
	   if (i || j)
		 if (is_clear(x+i, y+j))
		   dirs += ({ i,j });
   i = random(sizeof(dirs)/2)*2;
   return ({dirs[i], dirs[i+1]});
}

int
*get_near_location(int x, int y, int radius)
{
   int i, j, rmax = radius+1;
   int *dirs = ({0,0});
   if (radius > 10)
	 radius = 10;
   for (i=-radius; i < rmax ; i++)
	 for (j=-radius; j < rmax ; j++)
	   if (i || j)
		 if (is_clear(x+i, y+j))
		   dirs += ({ x+i, y+j});
   if (sizeof(dirs) == 2)
		return dirs;
   i = random(sizeof(dirs)/2-2)*2;
   return ({ dirs[i+2], dirs[i+3] });
}

int
*get_far_location(int x, int y, int radius)
{
   int maxcount = radius*radius;
   do 
	 {
		maxcount--;
		x = random(radius*2+1)-radius;
		y = random(radius*2+1)-radius;
	 } while (!is_clear(x, y) && maxcount > 0);
   
   if (maxcount = 0)
	 return ({0, 0});
   else
	 return ({x, y});
}

int
is_clear (int x, int y)
{
   object o, *u;
   
   if (x < 0 || x > grid_w || y < 0 || y > grid_h)
	 return FALSE;
   
   if (member_array(query_tile(x, y), blocking_terrains) != -1)
	 return FALSE;
   
   u = objectmap[y][x];
   
   if (u)
	 foreach (o in u)
	 {
		if (o->query_physical())
		  return FALSE;
	 }

   return TRUE;
}

int
is_jammed(int x, int y)
{
   int i, j;
   for (i=-1; i < 2 ;i++)
	 for (j=-1; j < 2 ;j++)
	   if (i || j)
		 if (is_clear(x+i, y+j))
		   return FALSE;
   return TRUE;
}

int
is_gridmap()
{
   return 1;
}

/*
int
clean_up(int i)
{
   debug("poks");
   if (!sizeof(all_inventory(THOB)))  
	 {
		ENV(THOB)->remove_map(THOB);
		destruct(THOB);
	 }
   return 1;
}
*/
