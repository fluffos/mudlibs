/**
 * A base object for rooms located by Cartesian coordinates.
 * 
 * @author devo@eotl
 * @alias CartesianRoomCode
 */

inherit RoomCode;

default private variables;

int *coordinates;

default public functions;

/**
 * Return the x, y, and z coordinates of this room within its containing 
 * zone.
 * 
 * @return an int array of room coordinates, or 0 if coordinates are unknown
 */
int *query_coordinates() {
  return coordinates;
}

/**
 * Set the x, y and z coordinates of this room within its containing zone.
 * 
 * @param  coords an int array of room coordinates, or 0 of coordinates are
 *                unknown
 * @return        0 for failure, 1 for success
 */
int set_coordinates(int *coords) {
  coordinates = coords;
  return 1;
}

/**
 * Get the x coorindate of this room within its containing zone.
 * 
 * @return the x coordinate
 */
int query_x_coordinate() {
  return coordinates[X_COORD];
}

/**
 * Set the x coordinate of this room within its containing zone.
 * 
 * @param  coords the x coordinate
 * @return        0 for failure, 1 for success
 */
int set_x_coordinate(int coord) {
  coordinates[X_COORD] = coord;
  return 1;
}

/**
 * Get the y coorindate of this room within its containing zone.
 * 
 * @return the y coordinate
 */
int query_y_coordinate() {
  return coordinates[Y_COORD];
}

/**
 * Set the y coordinate of this room within its containing zone.
 * 
 * @param  coords the y coordinate
 * @return        0 for failure, 1 for success
 */
int set_y_coordinate(int coord) {
  coordinates[Y_COORD] = coord;
  return 1;
}

/**
 * Get the z coorindate of this room within its containing zone.
 * 
 * @return the z coordinate
 */
int query_z_coordinate() {
  return coordinates[Z_COORD];
}

/**
 * Set the z coordinate of this room within its containing zone.
 * 
 * @param  coords the z coordinate
 * @return        0 for failure, 1 for success
 */
int set_z_coordinate(int coord) {
  coordinates[Z_COORD] = coord;
  return 1;
}

/**
 * Return a zero-width mapping of the capabilities this program provides.
 * 
 * @return a zero-width mapping of capabilities
 */
public mapping query_capabilities() {
  return RoomCode::query_capabilities();
}
