/**
 * A mixin for setting generic properties on an object. Each property has a
 * flag setting; currently the only flags that are supported are PROP_PUBLIC
 * and PROP_NOSAVE.
 *  
 * <p>Every property may specify an optional hook to be run when the property 
 * is accessed. This allows a client object to restrict specified operations 
 * on a property (like making it read-only).</p>
 *
 * <p>Finally, every property may be "masked" by external objects, overriding
 * the normaly property value returned by the query function. A property may
 * have more than one mask on it, in which case they are executed in the 
 * order the were added.</p>
 *
 * Hooks are specified as one of the following array formats:
 * <code><pre>
 *  ({ string|object owner, string func, mixed extra, ... })
 *    // calls owner->func()
 *  ({ string func, mixed extra, ... })
 *    // same as above, but owner defaults to the calling object
 *  ({ closure cl, mixed extra, ... })
 *    // calls cl 
 *  ({ string|object owner, closure cl, mixed extra, ... }) 
 *    // calls cl, the owner element is silently ignored
 *  // the extra arguments, if provided, will be passed to the method when
 *  // it is executed.
 * </pre></code>
 *
 * @alias PropertyMixin
 */
#pragma no_clone
#include <property.h>
#include <capability.h>

private inherit FileLib;

private mapping CAPABILITIES_VAR = ([ CAP_PROPERTY ]);

private nosave mapping props;
private nosave mapping prop_values;
private mapping saved_props;
private mapping saved_prop_values;
private nosave mapping masks;

public void setup();
public void teardown();
varargs int init_prop(string prop, int flags, mixed method);
varargs int configure_prop(string prop, int flags, mixed method);
mixed query_prop(string prop);
int set_prop(string prop, mixed value);
int remove_prop(string prop);
int mask_prop(string prop, mixed method);
int unmask_prop(string prop, mixed owner);
int query_masking_prop(string prop, mixed owner);
int check_prop(string prop);
string *query_all_prop_names();
varargs string generate_unique_prop_name(string seed);
varargs int default_prop_access(string prop, int op, object source, 
                                mixed special);
private int check_vars();
private varargs int check_access(string prop, int op, object source, 
                                 mixed special);
private varargs mixed munge_method(mixed method, int extern, int mask);
private int run_mask(mixed mask, string prop, mixed value);

/**
 * Initialize PropertyMixin.
 */
public void setup() {
  check_vars();
}

/**
 * Tear down PropertyMixin.
 */
public void teardown() {
}

/**
 * Initialize a property with a specified configuration. Configuration may be
 * changed later with configure_prop(). This method is implicitly called if
 * you try to set_prop() a property that hasn't yet been inititalized.
 * 
 * @param  prop   the name of the property to initialize
 * @param  flags  a bitvector containing property flags, default 0
 * @param  method optional method that will be called later when any attempts 
 *                to access the property are made (see program description)
 * @return        1 if the property was successfully initialized, or 0 for
 *                failure
 */
varargs int init_prop(string prop, int flags, mixed method) {
  // make sure prop doesn't exist
  if (check_prop(prop)) { return 0; }

  // props are only strings
  if (!stringp(prop)) { return 0; }

  // all props are public
  flags |= PROP_PUBLIC;

  // fix up method how we like it
  method = munge_method(method, extern_call());

  // make sure prop is in correct mapping
  mapping map, value_map;
  if (flags & PROP_NOSAVE) {
    map = props;
    value_map = prop_values;
  } else {
    map = saved_props;
    value_map = saved_prop_values;
  }

  // add prop
  map += ([ prop : flags; method ]);
  value_map[prop] = 0;
  masks[prop] = allocate(0);

  return 1;
}

/**
 * Reconfigure a property that has already been initialized. This function
 * does the same thing as init_prop(), except that first a CONFIGURE_PROP
 * access check must be passed.
 * 
 * @param  prop   the name of the property to initialize
 * @param  flags  a bitvector containing property flags, default 0
 * @param  method optional method that will be called later when any attempts 
 *                to access the property are made (see program description)
 * @return        1 if the property was successfully initialized, or 0 for
 *                failure
 */
varargs int configure_prop(string prop, int flags, mixed method) {
  // make sure prop exists
  int checked = check_prop( prop );
  if (!(checked & PROP_PUBLIC)) { return 0; }

  // all props are public
  flags |= PROP_PUBLIC;
  
  // fix up method how we like it
  method = munge_method(method, extern_call());

  // make sure we're allowed to configure this prop
  if (extern_call() && 
      check_access(prop, CONFIGURE_PROP, previous_object(), flags)) {
    return 0;
  }

  // make sure prop is in correct mapping
  mapping value_map, other_value_map, prop_map;
  if (flags & PROP_NOSAVE) {
    if (member(saved_props, prop)) {
      m_delete(saved_props, prop);
    }
    prop_map = props;
    value_map = prop_values;
    other_value_map = saved_prop_values;
  } else {
    if (member(props, prop)) {
      m_delete(props, prop);
    }
    prop_map = saved_props;
    value_map = saved_prop_values;
    other_value_map = prop_values;
  }

  if (!member(value_map, prop)) {
    value_map[prop] = other_value_map[prop];
  }
  if (member(other_value_map, prop)) {
    m_delete(other_value_map, prop);
  }

  // update config
  prop_map += ([ prop : flags; method ]);

  return 1;
}

/**
 * Get the value of a property. The caller must first pass the QUERY_PROP
 * access check.
 * 
 * @param  prop the name of the property 
 * @return      if the property exists and is accessible, returns the 
 *              property value, otherwise 0
 */
mixed query_prop(string prop) {
  // make sure prop exists
  int checked = check_prop(prop);
  if (!(checked & PROP_PUBLIC)) { return 0; }
    
  // make sure we're allowed to query this prop
  if (extern_call() && 
      check_access(prop, QUERY_PROP, previous_object())) {
    return 0;
  }

  // get correct mapping
  mapping map;
  if (checked & PROP_NOSAVE)
    map = prop_values;
  else
    map = saved_prop_values;

  // overload value and remove any bad masks from array
  mixed value = map[prop];
  masks[prop] = filter(masks[prop], "run_mask", prop, &value);

  // return value
  return value;
}

/**
 * Set the value of a property. The caller must first pass the SET_PROP
 * access check.
 * 
 * @param  prop  the name of the property to set
 * @param  value the property value
 * @return       1 if the new value was assigned, or 0 for failure
 */
int set_prop(string prop, mixed value) {
  // make sure prop exists
  int checked = check_prop(prop);
  if (!(checked & PROP_PUBLIC) && !init_prop(prop)) {
    return 0;
  }

  // make sure we're allowed to set this prop
  if (extern_call() && 
      check_access(prop, SET_PROP, previous_object(), value)) {
    return 0;
  }

  // get correct mapping
  mapping map;
  if (checked & PROP_NOSAVE)
    map = prop_values;
  else
    map = saved_prop_values;

  // set it
  map[prop] = value;
  return 1;
}

/**
 * Completely remove a property from an object. The caller must first pass 
 * the REMOVE_PROP access check.
 * 
 * @param  prop the name of the property to be removed
 * @return      1 if the property was successfully removed, otherwise 0
 */
int remove_prop(string prop) {
  // make sure prop exists
  int checked = check_prop(prop);
  if (!(checked & PROP_PUBLIC)) { return 0; }
    
  // make sure we're allowed to remove this prop
  if (extern_call() && 
      check_access(prop, REMOVE_PROP, previous_object())) {
    return 0;
  }

  // get correct mapping
  mapping value_map, prop_map;
  if (checked & PROP_NOSAVE) {
    prop_map = props;
    value_map = prop_values;
  } else {
    prop_map = saved_props;
    value_map = saved_prop_values;
  }

  // delete it
  m_delete(prop_map, prop);
  m_delete(value_map, prop);
  m_delete(masks, prop);
  return 1;
}

/**
 * Masks overload the result returned by the query_prop() function. This
 * function adds a mask to a given property. The caller must first pass the
 * MASK_PROP accesscheck, and the masking object may not already have a mask
 * on the specified property.
 * 
 * @param  prop   the property to mask
 * @param  method the method to be called when query_prop() is called; the
 *                result of this method will replace the result of 
 *                query_prop()
 * @return        1 if the mask was successfully placed on the property, or 0
 *                for failure
 */
int mask_prop(string prop, mixed method) {
  // make sure prop exists
  int checked = check_prop( prop );
  if (!(checked & PROP_PUBLIC)) { return 0; }

  mixed *mask;
  if (!(mask = munge_method(method, extern_call(), 1))) { 
    return 0; 
  }

  // only one mask per object
  if (member(map(masks[prop], #'[, 0), mask[0]) != -1) {
    return 0;
  }

  // make sure we're allowed to mask this prop
  if (extern_call() && 
      check_access(prop, MASK_PROP, previous_object(), mask[0])) {
    return 0;
  }

  // add mask  
  masks[prop] += ({ mask });
  return 1;
}

/**
 * Removes a mask placed on a specified property by a specified object. The
 * caller must first pass the UNMASK_PROP access check.
 * 
 * @param  prop  the property from which the mask is to be removed
 * @param  owner a object or string representing the object that contains the
 *               code for the masking method: either an object containing an
 *               lfun or an object with a closure bound to it. defaults to
 *               the calling object is not specified/
 * @return       1 if a mask was successfully removed from the property, or 0
 *               for failure
 */
varargs int unmask_prop(string prop, mixed owner) {
  // make sure prop exists
  int checked = check_prop( prop );
  if (!(checked & PROP_PUBLIC)) { return 0; }

  // make sure owner is valid
  if (!owner) {
    owner = extern_call() ? previous_object() : this_object();
  } else if (stringp(owner)) {
    owner = find_object(owner);
    if (!owner) {
      return 0;
    }
  } else if (!objectp(owner)) {
    raise_error("Bad argument 2 to unmask_prop");
  }

  // make sure we're allowed to unmask this prop
  if (extern_call() && 
      check_access(prop, UNMASK_PROP, previous_object(), owner)) {
    return 0;
  }

  // nuke mask
  return sizeof(masks[prop]) -
         sizeof(masks[prop] = filter(masks[prop], 
                                     (: objectp($1[0]) && ($1[0] != $2) :),
                                     owner));
}

/** 
 * Test whether a specified object is currently masking a specified property.
 * 
 * @param  prop  the property to be checked
 * @param  owner a object or string representing the potential owner object 
 *               of a mask on the property
 * @return       if the object is masking the property, returns the position
 *               of that object in the property's mask array; otherwise 
 *               returns 0 to indiciate the property is not being masked by
 *               the specified object
 */
int query_masking_prop(string prop, mixed owner) {
  int checked = check_prop(prop);

  // make sure prop exists
  if (!(checked & PROP_PUBLIC)) { return 0; }

  // make sure owner is valid
  if (!owner) {
    owner = extern_call() ? previous_object() : this_object();
  } else if (stringp(owner)) {
    owner = find_object(owner);
    if (!owner) {
      return 0;
    }
  } else if (!objectp(owner)) {
    raise_error("Bad argument 2 to unmask_prop");
  }

  // return if it exists or not
  return member(map(masks[prop], #'[, 0), owner) + 1;
}

/**
 * Test whether a property has been set, and query the property's flags.
 * 
 * @param  prop the property to be checked
 * @return      if the property exists and the calling object is allowed to
 *              query it, returns that property's flag bitvector, which will
 *              always be non-zero if the property exists. otherwise, returns
 *              0.
 */
int check_prop(string prop) {
  // make sure we're allowed to check this prop
  if (extern_call() && 
      check_access(prop, QUERY_PROP, previous_object())) {
    return 0;
  }

  check_vars();
  if (member(props, prop)) {
    return props[prop, 0];
  } else {
    return saved_props[prop, 0];
  }
}

/**
 * Get a list of all the properties on the object. The result will include
 * all property names, even if the calling object isn't allowed to query 
 * them.
 * 
 * @return an array of all the names of properties
 */
string *query_all_prop_names() {
  check_vars();
  return m_indices(props) + m_indices(saved_props);
}

/**
 * Utility function guaranteed to return a property name that is not already
 * in use at the time the function is called.
 * 
 * @param  seed optional seed, a string that will be incorporated into the
 *              returned property name
 * @return      a unique property name
 */
varargs string generate_unique_prop_name(string seed) {
  check_vars();
  if (!stringp(seed)) {
    seed = "anonymous";
  }
  object owner = extern_call() ? previous_object() : this_object();
  string oname = basename(program_name(owner));

  int i = 0;
  while (i <= MAXINT) {
    i++;
    string name = sprintf("%s_%s_%d", oname, seed, i);
    if (!check_prop(name)) {
      return name;
    }
  }
  raise_error("Ran out of positive integers generating unique prop name");
}

/**
 * This function will be called for access checks against a prop that has not 
 * configured a valid access method. See check_access().
 * 
 * @param  prop    the name of the property for which to check access
 * @param  op      an integer representing the operation that is being 
 *                 checked
 * @param  source  the object that is attempting to execute the operation
 * @param  special extra information, depending on the operation
 * @return         1 if access should be denied, or 0 to allow the operation
 */
varargs status default_prop_access(string prop, int op, object source, 
                                   mixed special) {
  return 0;
}

/**
 * Makes sure all our variables are initialized and ready to use.
 * @return 1 if all the variables are good, or 0 if they couldn't be 
 *           initialized properly
 */
private int check_vars() {
  if (!mappingp(prop_values)) {
    prop_values = m_allocate(0, 1);
  }
  if (!mappingp(saved_prop_values)) {
    saved_prop_values = m_allocate(0, 1);
  }
  if (!mappingp(props)) {
    props = m_allocate(0, 2);
  }
  if (!mappingp(saved_props)) {
    saved_props = m_allocate(0, 2);
  }
  if (!mappingp(masks)) {
    masks = m_allocate(0, 1);
  }
  return 1;
}

/**
 * Verifies access when a property is operated upon by an outside object. 
 * Valid operations and their special arguments:
 * <pre>
 *   CONFIGURE_PROP  : prop flags
 *   SET_PROP        : new value
 *   QUERY_PROP      : void
 *   REMOVE_PROP     : void
 *   MASK_PROP       : mask owner
 *   UNMASK_PROP     : mask owner
 * </pre>
 * 
 * @param  prop    the name of the property for which to check access
 * @param  op      an integer representing the operation that is being 
 *                 checked
 * @param  source  the object that is attempting to execute the operation
 * @param  special extra information, depending on the operation
 * @return         1 if access should be denied, or 0 to allow the operation
 */
private varargs int check_access(string prop, int op, object source, 
                                 mixed special) {

  // make sure prop exists
  int checked = check_prop(prop);
  if (!(checked & PROP_PUBLIC)) { return 1; }

  // make sure method is good stuff
  mixed method;
  if (checked & PROP_NOSAVE) {
    method = props[prop, 1];
  } else {
    method = saved_props[prop, 1];
  }
  if (!method) {
    method = ({ THISO, symbol_function("default_prop_access", THISO) });
  }

  // create acode from method
  object owner;
  if (objectp(method[0])) {
    owner = method[0];
  } else if (stringp(method[0])) {
    call_other(method[0], "???" );
    owner = find_object(method[0]);
  } else {
    // invalid method, fall back to default
    owner = THISO;
    method = ({ owner, symbol_function("default_prop_access", owner) });
  }

  mixed args = ({ prop, op, source, special });
  closure acode;

  if (closurep(method[1])) {
    // we don't actually use the owner for closures (yet?),
    // but make sure it's bound so can call it later
    if (to_object(method[1])) {
      owner = to_object(method[1]);
    } else {
      // unbound closure?
      owner = THISO;
      method = ({ owner, symbol_function("default_prop_access", owner) });
    }
    acode = method[1];
    if (sizeof(method) > 2) {
      args += method[2..];
    }
  } else if (stringp(method[1])) {
    if (!objectp(owner)) {
      // vanished object?
      owner = THISO;
      method = ({ owner, "default_prop_access" });
    }
    if (!(acode = symbol_function(method[1], owner))) {
      // invalid function ?
      owner = THISO;
      method = ({ owner, "default_prop_access" });
      acode = symbol_function(method[1], owner);
    }
    if (sizeof(method) > 2) {
      args += method[2..];
    }
  } else {
    // invalid method
    owner = THISO;
    acode = symbol_function("default_prop_access", owner);
    method = ({ owner, acode });
  }

  // if this errors, it's up to the owner to fix it
  return apply(acode, args);
}

/**
 * Returns a method definition in a standardized format. See the program
 * description for valid method formats. The result of this function will
 * be a method of the format:
 *
 * <code><pre>
 *   // For methods: 
 *   ({ string|object owner, string|closure routine, mixed extra, ... })
 *   // For masks:
 *   ({ object owner, closure routine, mixed extra, ... })
 * </pre></code>
 * 
 * @param  method the method to normalize
 * @param  extern 1 if the method is being executed via an external call,
 *                otherwise 0
 * @param  mask   1 if this method is for a mask, otherwise 0
 * @return        an array containing a method definition in its cannonical
 *                form, or 0 if the method could not be normalized correctly
 */
private varargs mixed munge_method(mixed method, int extern, int mask) {
  if (!pointerp(method) || !sizeof(method)) {
    return 0;
  }

  mixed result = 0;
  if (closurep(method[0])) {
    object owner;
    if (!objectp(owner = to_object(method[0]))) {
      return 0;
    }

    mixed mcode = method[0];
    mixed *extra = ({ });
    if (sizeof(method) > 1) {
      extra = method[1..];
    }

    result = ({ owner, mcode }) + extra;

  } else {

    object owner;
    if (objectp(method[0])) {
      owner = method[0];
    } else if (stringp(method[0])) {
      if (owner = find_object(method[0])) {
        if (sizeof(method) < 2) {
          return 0;
        } else {
          method = method[1..];
        }
      }
    }
    if (!owner) {
      owner = extern ? previous_object() : this_object();
    }
   
    mixed mcode;
    if (mask) {
      if(!(mcode = symbol_function(method[0], owner))) {
        return 0;
      }
    } else {
      mcode = method[0];
    }
    mixed *extra = ({ });
    if (sizeof(method) > 1) {
      extra = method[1..];
    }

    if (mask) {
      result = ({ owner, mcode }) + extra;
    } else {
      result = ({ object_name(owner), mcode }) + extra;
    }

  } 

  return result;
}

/**
 * Execute a mask method.
 * 
 * @param  mask  the mask method
 * @param  prop  the property being masked
 * @param  value the value of the property, passed by reference through this
 *               function to the mask method
 * @return       1 if the mask was successfully executed, 0 for failure
 */
private int run_mask(mixed mask, string prop, mixed value) {
  if (!pointerp(mask)) { return 0; }

  int size = sizeof(mask);
  if (size < 2) { return 0; }

  if (!objectp(mask[0])) { return 0; }
  if (!closurep(mask[1])) { return 0; }

  mixed *args = ({ });
  if (size > 2) {
    args = mask[2..];
  }

  value = apply(mask[1], prop, &value, args);
  return 1;
}
