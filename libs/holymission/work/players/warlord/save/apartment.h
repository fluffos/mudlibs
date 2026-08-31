/*
	Apartments in Tear by Kriton@Emerald MUD
*/

#ifndef __APARTMENT__
#define __APARTMENT__

class apartment_rec
{
  string long;
  string short;
  int indoors, light;
  mapping sounds;
  mapping smells;
  mapping items;
  string *guests;
  mapping objects;
  mapping storage;
  int rent_due;
  string owner;
}

#define savefile(x)	sprintf("/d/tear/Apartments/save/%s/%s", x[0..0], x)
#define savedir(x)	sprintf("/d/tear/Apartments/save/%s", x[0..0])

#define ONE_MONTH	2592000
#define RENT_MONEY	5000
#define APARTMENT	"/d/tear/Apartments/apartment"
#define ROOM		"/std/room"
#define OBJECT		"/std/Object"
#define APARTMENT_D	"/d/tear/Apartments/apartment_d"
#define A_EDITOR	"/d/tear/Apartments/editor"
#define RSERVICE_FILE	"/d/tear/Apartments/room_service.db"

#endif
