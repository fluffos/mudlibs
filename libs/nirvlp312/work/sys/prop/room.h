/*
 *  <prop/room.h>
 */

#ifndef _sys_prop_room_h
#define _sys_prop_room_h

#include <terrain.h>                            // for terrain defines

#define P_AREA                  "area"          // for defining of areas, e.g.
                                                // set_prop(P_AREA,"myarea");
#define P_ROOM                  "room"          // to be defined by rooms

#define P_OUTSIDE               "outside"
#define P_INSIDE                "inside"
#define P_DAYLIGHT              "daylight"      // An inside room may or
                                                // may not have daylight

#define P_MOUNTAIN              "mountain"      // mountains, hills
#define P_OPEN_ROOM             "plains"        // open rooms of every kind
                                                // without trees
#define P_UNDERGROUND           "underground"   // mine, dungeon, catacombs,
                                                // cave, cellar
#define P_VILLAGE               "village"       // in a village, city
#define P_FOREST                "forest"        // P_FOREST,TE_LIGHT: light f.
                                                // P_FOREST,TE_NORMAL: normal f.
                                                // P_FOREST,TE_DENSE: dense f.,
                                                // e.g. jungle
#define P_WATER                 "water"         // in/on/diving in a lake, sea
                                                // or river
#define P_SWAMP                 "swamp"         // swamp, fen
#define P_DESERT                "desert"        // desert of every kind (ice,
                                                // snow, sand, stone desert)
#define P_VEHICLE               "vehicle"       // in a boat, on horse/dragon
#define P_MAGIC                 "magic"         // magic room or a magic item
                                                // attached to the room
#define P_ON_TREE               "on_tree"       // For the substance-server

#define P_NO_TELEPORT           "no_teleport"
#define P_NO_TELEPORT_TO        "no_teleport_to"
#define P_NO_TELEPORT_FROM      "no_teleport_from"

#define P_NO_INVISIBILITY       "no_invisibility"

#define P_NO_TOOL_MESSAGES      "no_tool_messages"
#define P_NO_CLEANUP            "no_cleanup"     // don't selfdestruct
                                                 // on cleanup (complex/room)
#define P_NO_FIGHT              "no_fight"
#define P_NO_HERMES             "no_hermes"
#define P_HERMES                "hermes"  // for teleport proof rooms, where
                                          // Hermes should help
#define P_PLAIN_ROOM            "replace_program"   // use replace_program
                                                    // after initial configure
#define P_UNDER_WATER           "under_water"

#define P_NO_GROUND             "no_ground"    // have it contain a room path
#define P_LIQUID_GROUND         "liquid_ground"

#define P_LOCATION              "location"      // Reserved for the new
                                                // map/location system
#define P_TEMPERATURE           "temperature"   // the temperature of this
                                                // room given by values
                                                // from <temperature.h>
                                                // (int values in kelvin)

/* set this property if you don't want the exits to be shown in brief mode */
#define P_NO_EXITS_IN_BRIEF     "no_exits_in_brief"


/* set the following property to a preposition that will be prepended
   the room's short when the player walks in brief mode. 
   The short itself shall only be a subject describing the player's
   environment, see 'man set_short' for details
*/

#define P_LOCAL_PREPOSITION     "local_preposition"


/* set the following property if you want to have logged when somebody
   tries to look at 'missing fakeitems' in your rooms.
*/
   
#define P_LOG_ITEMS             "log_items"

/* set property P_SAVE_ROOM (with a save-file-name, if you don't want to use
   load_name(this_object()) as default) if you want your room-data
   saved every room-reset and on destruct() and reloaded upon creation),
   Also, autoloading objects in the room will be saved and cloned and
   initialized properly during creation */

#define P_SAVE_ROOM             "save_room"

/* The following property forbids the display of the little map in the room */

#define P_NO_MAP                "no_map"

/* Do _NOT_ use P_NOTIFY_LOAD any longer. If you want to be informed upon
   the reset or loading of certain rooms, use the notifier-server. Read
   'man notifier' for details.
*/

#define P_NOTIFY_LOAD           "notify_load" 

/* this room is an air room (part of the air space) and can be inhabited
   only by flying livings and objects.
*/

#define P_AIR_ROOM              "air_room"

#endif /* _sys_prop_room_h */
