/*
// This one is used by the experimental map system. It defines the object
// that manages the map.
*/

#define MAP_OB "/bin/daemon/map"
#define MAP_OBJECT(file_name) (extract(file_name, 0, 10) == "/room/map/m")
