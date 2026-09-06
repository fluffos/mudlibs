
/*************************************************************

 NAME:    server.c

 PURPOSE: general purpose virtual room 
	  generator. 

 AUTHOR:  Tron

 ------------------------------------------------------------

 INFO:    Copy this file to your own directory under path 
	  /u/foo/virtual/server.c where 'foo' is your
	  name ofcourse. If directory 'virtual' does not
	  exist then create it as well as all the directories
	  you define in this file. See more help about setting
	  up your virtual world from /doc/virtual directory.

 NOTE:    rooms_home variable must contain directory under
	  your virtual directory! (u/foo/virtual)

*************************************************************/

#include <virtual_server.h>

#define VIRTUAL_HOME "/guilds/priests/gardens/virtual/world/"

void
create() {
    virtual_home = VIRTUAL_HOME;  // Home directory for virtual world

    terra_home =  VIRTUAL_HOME+"terrains/"; // Home for terrains
    maps_home  =  VIRTUAL_HOME+"maps/";     // Home for maps
    rooms_home =  VIRTUAL_HOME+"rooms/";    // Home for rooms
    descs_home =  VIRTUAL_HOME+"descs/";    // Home for descriptions

    terra_cfg  =  VIRTUAL_HOME+"terra.cfg"; // Configure terrains
    obj_cfg    =  VIRTUAL_HOME+"obj.cfg";   // Configure objects
    map_cfg    =  VIRTUAL_HOME+"map.cfg";   // Configure maps

    virtual_save = VIRTUAL_HOME+"virtual_save";  // Saved configurations
    universum    = VIRTUAL_HOME+"universum";  // Environment for rooms

    memory       = 5; // Number of maps max in memory. (swap limit)

    tdesc_x      = 1; // Width of terrain descriptor.

    start_server();  // Let's start the virtual server.
}
