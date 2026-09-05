/**
 * Support for creatures which have proper names.
 * 
 * @author devo@eotl
 * @alias NameMixin
 */

#include <capabilities.h>

default private variables;

string first_name, last_name, nickname;

default public functions;

/**
 * Return the first name of this character, or 0 if unnamed.
 * 
 * @return the character's first name, or 0
 */
string query_first_name() {
  return first_name;
}

/**
 * Set the first name of the character. 
 * 
 * @param str the first name to set
 * @see       query_first_name()
 */
void set_first_name(string str) {
  first_name = str;
}

/**
 * Return the last name of this character, or 0 if unnamed.
 * 
 * @return the character's last name, or 0
 */
string query_last_name() {
  return last_name;
}

/**
 * Set the last name of the character. 
 * 
 * @param str the last name to set
 * @see       query_last_name()
 */
void set_last_name(string str) {
  last_name = str;
}

/**
 * Return the nickname of this character, or 0 if unnamed.
 * 
 * @return the character's nickname, or 0
 */
string query_nickname() {
  return nickname;
}

/**
 * Set the nickname of the character. 
 * 
 * @param str the nickname to set
 * @see       query_nickname()
 */
void set_nickname(string str) {
  nickname = str;
}

/**
 * Return the full name of this character, generally first name plus last 
 * name.
 * 
 * @return the full name of the character, or 0 if no first or last name
 */
string query_full_name() {
  string result;
  if (first_name) {
    result = first_name;
  }
  if (last_name) {
    if (result) {
      result += " ";
    } else {
      result = "";
    }
    result += last_name;
  }  
  return result;
}

/**
 * Return the display name based on user preferences.
 * @return display name
 */
string query_name() {
  // TODO make this work
  return nickname;
}

/**
 * Initialize NameMixin. If this function is overloaded, be advised that the
 * mixin's private variables are initialized in the parent implementation.
 */
protected void setup_name() {
  first_name = 0;
  last_name = 0;
  nickname = 0;
}

/**
 * Return a zero-width mapping of the capabilities this program provides.
 * 
 * @return a zero-width mapping of capabilities
 */
public mapping query_capabilities() {
  return ([ CAP_NAME ]);
}

