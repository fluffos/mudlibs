/*
** /basic/room/map.c
**
** Author: Tamarindo
**   Date: August 2018
**
** Purpose:
**
**	The map.c component provides the Compass Daemon insight into
**	the identity of the area and the type of environment claimed
**	by the room object.
**
**	Example:
**		set_map_environment(MAP_ENVIRONMENT_CITY);
**		set_map_area(MAP_AREA_CITY_OF_TRISTEZA);
**
**		OR for a room at the center of the map (option 1)
**		with X, Y, Z coordinates ({0, 0, 0})
**
**		set_map_environment(MAP_ENVIRONMENT_CITY);
**		set_map_area(MAP_AREA_CITY_OF_TRISTEZA, MAP_CENTER);
**
**		OR for a room at the center of the map (option 2)
**		with X, Y, Z coordinates ({0, 0, 0})
**
**		set_map_environment(MAP_ENVIRONMENT_CITY);
**		set_map_area(MAP_AREA_CITY_OF_TRISTEZA);
**		set_map_center(MAP_CENTER);
**
**	The #define values for the standard environments and areas
**	are included into the standard rooms because they should be
**	used almost everywhere, although that does not mean that
**	every area should be mapped for visibility to players.
**
**	These values are registered with the Compass Daemon during
**	the first time that init() is called when in the presence
**	of a player object if and only if an area and environment
**	are already setup in the room.  For several reasons, there
**	were challenges to performing the registration at the
**	create() of the room or upon init() of the room by objects
**	other than the player object.
**
**	The Compass Daemon will request the area and environment
**	for the room if available and assign and store a unique
**	number for the room that will be saved indefinitely by the
**	Compass Daemon.  The room's number will be used to identify
**	the room through GMCP (Generic Mud Communication Protocol)
**	and sent to clients that could process it.  The room number
**	gets used with GMCP to also identify it as an exit for other
**	rooms.
**
**	The Compass Daemon generates a standard XML file in the MMP
**	(MUD Mapping Protocol) that may be downloaded from the game's
**	website and if supported by the client scripts this may be
**	automatically downloaded to the client as the map file is
**	updated, such as when a new area is added to the game.
**
**	As the Compass Daemon tracks rooms based on their file name
**	accessed through the object_name() of the room, for virtual
**	rooms there was a challenge.  Virtual rooms are first cloned
**	by the virtual server and then renamed.  For this purpose,
**	the Master Object calls a set_map_private_key(string path)
**	immediately after it compiles the cloned room object, passing
**	it the intended path of the virtual file name.  This value
**	is used during registration with the Compass Daemon so that
**	the room does not get registered with the object_name of the
**	clone, because those would only be consistent until the
**	room was destructed.  The map_private_key does not have any
**	intended use thereafter.
**
**	The identifying room id is set to the room after registration
**	and may also be queryied thereafter.  It is also possible to
**	query the map coordinates with the query_map_coords() method
**	which returns an array of positive or negative integers
**	representing ({
**		X or west-to-east,
**		Y or south-to-north,
**		Z or down-to-up
**	})
**
**	It is intended that the ({0, 0, 0}) coordinates are in the
**	exact center of the area.  For example, the well in the City
**	of Tristeza should be ({0, 0, 0}).
**
** See Also:
**
**	/bin/daemons/compass_d.c
**	/include/map_environment_defs.h
**	/include/map_area_defs.h
*/

#ifndef ROOM_C
#include <daemons.h>
#endif /* ROOM_C */

#ifndef MAP_AREA_DEFS_H
#include <map_area_defs.h>
#endif /* MAP_AREA_DEFS_H */

private nosave int map_environment;
private nosave int map_area;
private nosave int map_center = MAP_NOT_CENTER;
private nosave int map_public_key;
private nosave string map_private_key;

// Prototype
public int *query_map_coords();
public int set_map_center(int arg);

/*
** Function: query_map_environment
**
**  Returns: int, the environment also in /include/map_environment_defs.h
**
*/
public int query_map_environment() {
    return map_environment;
}

/*
** Function: query_map_area
**
**  Returns: int, the area also in /include/map_area_defs.h
**
*/
public int query_map_area() {
    return map_area;
}

/*
** Function: query_map_center
**
**  Returns: int, 1 if this room is allowed to have coordinates of ({ 0, 0, 0})
**           and -1 if this room is not allowed to have coordinates of ({ 0, 0, 0 })
**
*/
public int query_map_center() {
    return map_center;
}

/*
** Function: query_map_key
**
**  Returns: int, the room number of this room created by the Compass Daemon
**
*/
public int query_map_key() {
    return map_public_key;
}

/*
** Function: query_map_private_key
**
**  Returns: string, the file path registered with the Compass Daemon
**
**    Notes: Set as private for now.  No one should need to use this anyways.
*/
private string query_map_private_key() {
    return map_private_key;
}

/*
** Function: query_map_coords
**
**  Returns: int *, the X, Y, Z coordinates of the room we are in.
**
*/
public int *query_map_coords() {
    return MAPPER_D->query_map_coords(map_private_key ? map_private_key : this_object());
}

/*
**   Function: set_map_environment
**
** Parameters: int arg, the environment to set upon the room
**
**    Returns: int, 0 for fail, such as an invalid environment, and 1 for success
**
*/
public int set_map_environment(int arg) {
    if (member(MAPPER_D->query_map_environments(), arg) < 1)
	return 0;

    map_environment = arg;
    return 1;
}

/*
**   Function: set_map_area
**
** Parameters: int arg1, the area to set upon the room
**
**             int arg2, arg2 != 0 will allow the coordinates of the room to be
**             set to ({ 0, 0, 0 })
**
**    Returns: int, 0 for fail, such as an invalid area, and 1 for success
**
*/
public varargs int set_map_area(int arg1, int arg2) {
    if (member(MAPPER_D->query_map_areas(), arg1) < 1)
	return 0;

    map_area = arg1;

    if (arg2) set_map_center(arg2);

    return 1;
}

/*
**   Function: set_map_center
**
** Parameters: int arg, arg != 0 will set the X, Y, Z coordinates of the room to ({ 0, 0, 0 })
**
**    Returns: int, 1 for success
**
*/
public int set_map_center(int arg) {
    if (!arg)
	map_center = MAP_NOT_CENTER;
    else
	map_center = MAP_CENTER;

    return 1;
}

/*
**   Function: set_map_key
**
** Parameters: int arg, the room number to set upon the room per the Compass Daemon
**
**    Returns: int, 1 for success (should we just make it void? *shrug*)
**
*/
public int set_map_key(int arg) {
    map_public_key = arg;
    return 1;
}

/*
**   Function: set_map_private_key
**
** Parameters: string arg, the file path to set upon the room used by the Compass Daemon
**
**    Returns: arg, 1 for success
**
**	Notes: Probably only the Master object should call this with compile_object()
**
*/
public int set_map_private_key(string arg) {
    map_private_key = arg;
    return 1;
}
