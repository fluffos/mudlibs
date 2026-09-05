/**
 * Support for items which can be seen with the "look" command.
 * 
 * @author devo@eotl
 * @alias VisibleMixin
 */

#include <look.h>
#include <capabilities.h>

default private variables;

string short, long;

default public functions;

/**
 * Return a short description of the room. This name will be shown to the 
 * user everytime they enter the room so it should be short and recognizable.
 * 
 * @return the short description
 */
string query_short() { 
  return short;
}

/**
 * Set the short description of the room.
 * 
 * @param str the short to set
 * @return    0 for failure, 1 for success
 * @see       query_short()
 */
int set_short(string str) {
  short = str;
  return 1;
}

/**
 * Return a long description of the room. This will be displayed to the 
 * player when they explicitly look inside a room. It can be as long as is
 * needed, but probably shouldn't take up more than a page of a user's 
 * screen.
 * 
 * @return the long description of the room
 */
string query_long() { 
  return long;
}

/**
 * Set the room's long description. 
 * 
 * @param str the description to set
 * @return    0 for failure, 1 for success
 * @see       query_description()
 */
int set_long(string str) {
  long = str;
  return 1;
}

/**
 * Initialize VisibleMixin.
 */
protected void setup_visible() {
  if (THISO->is_room()) {
    short = DEFAULT_ROOM_SHORT;
    long = DEFAULT_ROOM_LONG;
  } else {
    short = DEFAULT_SHORT;
    long = DEFAULT_LONG;
  }
}

/**
 * Return the capabilities this mixin provides.
 * 
 * @return the 'visible' capability
 */
public mapping query_capabilities() {
  return ([ CAP_VISIBLE ]);
}
