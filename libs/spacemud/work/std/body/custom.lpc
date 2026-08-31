/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** For your custom extensions for BODY.
*/

// Default values for where players begin the game.
private
string starsystem = "Omega";
private
int *coordinates = ({1, 1, 1});
private
string location = "Omega Terminal";
private
int planet = 0;

//: FUNCTION query_starsystem
// Returns the star system the player is currently in
// by name.
string query_starsystem()
{
   return starsystem;
}

//: FUNCTION set_starsystem
// Sets the star system the player is currently in.
// Use query_starsystem() to find out where they are.
void set_starsystem(string ss)
{
   starsystem = ss;
}

//: FUNCTION query_coordinates
// Returns the coordinates of the player on a galaxy scale
// This is not impacted by moving in rooms, but only flying
// through space.
int *query_coordinates()
{
   return coordinates;
}

//: FUNCTION set_coordinates
// Set the star coordinates for the player. This should
// only be updated when the player moves through space
// in a starship. Moving from room to room does not
// update these values.
void set_coordinates(int *c)
{
   coordinates = c;
}

//: FUNCTION query_location
// Returns the string name of the location the player is in.
// Typically planet stations or space stations or ships in
// open space.
string query_location()
{
   return location;
}

//: FUNCTION set_location
// Sets the location the player is currently in, also
// see query_location().
void set_location(string l)
{
   location = l;
}

int query_planet()
{
   return planet;
}

void set_planet(int p)
{
   planet=p;
}