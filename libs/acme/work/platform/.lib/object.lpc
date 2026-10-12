/**
 * Utility library for dealing with objects of all types.
 *
 * @author devo@eotl
 * @alias ObjectLib
 */
#include <sys/files.h>
#include <sys/inherit_list.h>
#include <sys/functionlist.h>
#include <access.h>
#include <object.h>
#include <zone.h>

private inherit AccessLib;

protected varargs int is_reachable(object ob, object who);
protected mixed *get_path_info(mixed ob);
protected varargs object reload_object(mixed ob, int flags);  

/**
 * Test whether an object is reachable from another object.
 *
 * TODO This doesn't belong here, the name sucks. Maybe is_present(), and we
 * expand the definition of "present" (i.e. reimplement present()) to include 
 * any of these three conditions. I think it would be fine most of the time to 
 * search from the inside out, but probably provide multiple algorithms. What
 * really matters is what needs to happen in ObjectExpansionLib.
 * 
 * @param  ob  the object trying to be accessed
 * @param  who the object doing the accessing, defaults to THISP
 * @return     1 if the object is reachable, otherwise 0
 */
protected varargs int is_reachable(object ob, object who) {
  if (!who) {
    who = THISP;
  }
  return (ob == who) || (ob == ENV(who)) || (ENV(ob) == who);
}

/**
 * Get various info about an object based on its path.
 * 
 * @param  ob            a target object, or the object name of an object (or
 *                       potential object)
 * @return object name, uid, user, domain, zone, category, filename, clone 
 *         number
 */
protected mixed *get_path_info(mixed ob) {
  string oname, uid, user;
  int tmp;
  if (objectp(ob)) {
    oname = object_name(ob);
    uid = getuid(ob);
    user = get_user(ob);
  } else if (stringp(ob)) {
    oname = ob;
    uid = get_create_uid(ob);
  }
  tmp = strlen(oname);
  if ((tmp >= 2) && (oname[<2..<1] == LPC_EXTENSION)) {
    if (tmp) {
      oname = oname[0..<3];
    } else {
      oname = "";
    }
  }

  string zone, category, file;
  int clone;

  string *parts = explode(oname, "/");
  int len = sizeof(parts);
  int i = 0;
  while (i < (len - 1)) {
    if (strlen(parts[i]) && (parts[i][0] == CATEGORY_DELIM[0])) {
      if (i == 0) {
        zone = "";
        category = implode(parts[i..<2], CATEGORY_DELIM);
      } else {
        zone = implode(parts[0..(i - 1)], ZONE_DELIM);
        category = implode(parts[i..<2], CATEGORY_DELIM)[1..];
      }
      break;
    }
    i++;
  }
  if (!zone) {
    zone = implode(parts[0..<2], ZONE_DELIM);
    category = "";
  }

  parts = explode(parts[<1], CLONE_DELIM);
  file = parts[0];
  if (sizeof(parts) >= 2) {
    clone = to_int(parts[<1]);
  }

  string domain = DEFAULT_DOMAIN; // XXX gaping security hole
  if (objectp(DomainTracker)) {
    domain = DomainTracker->query_domain_id(oname);
  }

  return ({ oname, uid, user, domain, zone, category, file, clone });
}

/**
 * Reload an object. Depending on the flags being used, this function will 
 * destruct an object and then recreate, attempting to restore as much of the
 * original object's state as possible. 
 * 
 * @param  ob            the object to reload
 * @param  flags         reload flags
 * @return the newly loaded object
 */
protected varargs object reload_object(mixed ob, int flags) {  
  // TODO move/restore inventory
  // TODO move/restore shadows

  string name;
  if (stringp(ob)) {
    name = ob;
    ob = 0;
  } else if (objectp(ob)) {
    name = load_name(ob);
  } else {
    return 0;
  }

  // save variable values
  mixed *vars;
  if (ob) {
    vars = variable_list(ob, RETURN_FUNCTION_NAME|RETURN_VARIABLE_VALUE);
  }

  // TODO reload inherited programs
  // reload the blueprint, and clone if necessary
  object result;
  if (ob) {
    if (clonep(ob)) {
      if (flags & RELOAD_RELOAD_BLUEPRINT) {
        object blueprint = blueprint(ob);
        if (blueprint && (blueprint != ob)) {
          blueprint = reload_object(blueprint, flags);
          if (!blueprint) {
            return 0;
          }
        }
      }
      if (ob) {
        destruct(ob);
      }
      result = clone_object(name);
    } else {
      destruct(ob);
      result = load_object(name);
    }
  } else {
    result = load_object(name);
  }
  
  // restore variables
  if (vars) {
    for (int i = 0, int j = sizeof(vars); i < j; i += 2) {
      closure var = funcall(bind_lambda(#'symbol_variable, result), vars[i]);
      closure setter = bind_lambda(unbound_lambda(({ 'val }),
        ({ #'=, var, 'val })
      ), result);
      funcall(setter, vars[i + 1]);
    }    
  }

  return result;
}
