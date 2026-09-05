/**
 * A base object for rooms located by Spherical coordinates.
 * 
 * @author devo@eotl
 * @alias SphericalRoomCode
 */

inherit RoomCode;

default private variables;

int *coordinates;

default public functions;

/**
 * Return the rho, theta, and phi coordinates of this room within its 
 * containing zone.
 * 
 * @return an int array of room coordinates, or 0 if coordinates are unknown
 */
int *query_coordinates() {
  return coordinates;
}

/**
 * Set the rho, theta and phi coordinates of this room within its containing 
 * zone.
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
 * Get the rho coorindate of this room within its containing zone.
 * 
 * @return the rho coordinate
 */
int query_rho_coordinate() {
  return coordinates[RHO_COORD];
}

/**
 * Set the rho coordinate of this room within its containing zone.
 * 
 * @param  coords the rho coordinate
 * @return        0 for failure, 1 for success
 */
int set_rho_coordinate(int coord) {
  coordinates[RHO_COORD] = coord;
  return 1;
}

/**
 * Get the rho coorindate of this room within its containing zone.
 * 
 * @return the rho coordinate
 */
int query_theta_coordinate() {
  return coordinates[THETA_COORD];
}

/**
 * Set the theta coordinate of this room within its containing zone.
 * 
 * @param  coords the theta coordinate
 * @return        0 for failure, 1 for success
 */
int set_theta_coordinate(int coord) {
  coordinates[THETA_COORD] = coord;
  return 1;
}

/**
 * Get the phi coorindate of this room within its containing zone.
 * 
 * @return the phi coordinate
 */
int query_phi_coordinate() {
  return coordinates[PHI_COORD];
}

/**
 * Set the phi coordinate of this room within its containing zone.
 * 
 * @param  coords the phi coordinate
 * @return        0 for failure, 1 for success
 */
int set_phi_coordinate(int coord) {
  coordinates[PHI_COORD] = coord;
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
