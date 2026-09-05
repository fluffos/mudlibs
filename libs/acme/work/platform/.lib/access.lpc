/**
 * Library of functions pertaining to access control.
 *
 * @author devo@eotl
 * @alias AccessLib
 */
#pragma no_clone
#include <access.h>

/**
 * For objects loaded from a specified path, get the uid the object should be 
 * created with. This function must return a valid string.
 * 
 * @param  objectname    the path of the object being created
 * @return the uid at create time
 */
protected string get_create_uid(string objectname) {
  if (objectp(DomainTracker)) {
    return DomainTracker->query_domain_id(objectname);
  } else {
    return DEFAULT_DOMAIN; // XXX gaping security hole
  }
}

/**
 * Get the effective user of an object. This comes from the object's effective
 * uid (euid) and is of the form {username}@{uid}.
 * 
 * @param  ob            the target object
 * @return the user of the object
 */
protected string get_user(object ob) {
  string euid = geteuid(ob);
  string result;
  int pos = member(euid, '@');
  if (pos != -1) {
    result = euid[0..(pos - 1)];
  }
  return result;
}

