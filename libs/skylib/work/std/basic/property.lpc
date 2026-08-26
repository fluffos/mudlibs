/**
 * The property handling system.  This handles all the stuff to do with
 * properties.
 * @author Pinkfish
 */

mapping map_prop;
mapping timed_properties;

void create() {
/* don't init the mapping to save memory */
} /* create() */

/**
 * Adds a property onto the object.  Allows you to add a property
 * onto the current object.  You can also set a time for the property
 * to last.
 * @param var the name of the property
 * @param val the value to give the property
 * @param tim the time before the property should time out
 * @return 1 if it succeeded, 0 if it failed.
 */
varargs int add_property( string var, mixed val, int tim ) {
    if( !stringp(var) || !val )
        return 0;
    if( !map_prop )
        map_prop = ([ ]);
    map_prop[var] = val;
    if( tim > 0 ) {
        if( !timed_properties )
            timed_properties = ([ ]);
        timed_properties[var] = tim + time();
    }
    if( var == "silenced" )
        log_file("/secure/log/SILENCED", "%s silenced on %s\n",
            TO->query_name(), ctime(time()) );
    return 1;
} /* add_property() */

/**
 * Removes a property off the object.  This removes the named property
 * from the object.
 * @param var the name of the property
 * @return always returns 1
 */
int remove_property( string var ) {
    if( map_prop )
        map_delete( map_prop, var );
    if( timed_properties )
        map_delete( timed_properties, var );
    if( var == "silenced" )
        log_file("/secure/log/SILENCED", "%s unsilenced on %s\n",
            TO->query_name(), ctime(time()) );
    return 1;
} /* remove_property() */

/**
 * Returns the value of the property.  This will return the current value
 * of the named property.
 * @param str the property to find
 * @return the value of the property
 */
mixed query_property( string str ) {
    if( !map_prop )
        return 0;

    if( timed_properties && timed_properties[str] &&
        timed_properties[str] < time() ) {
        map_delete( timed_properties, str );
        map_delete( map_prop, str );
        return map_prop[str];
    }
    return map_prop[str];
} /* query_property() */

/**
 * Is this property value timed?
 * @return 1 if it is, 0 if not
 * @param str the property to check
 */
int query_is_timed_property( string str ) {
    if( timed_properties && timed_properties[str] ) {
        if( timed_properties[str] < time() ) {
            map_delete( timed_properties, str );
            map_delete( map_prop, str );
            return 0;
        }
        return 1;
    }
    return 0;
} /* query_is_timed_property() */

/**
 * If this is a timed property it returns the amount of time left.
 * @param str the property name
 * @return the amount of time left
 */
int query_property_time_left( string str ) {
    if( timed_properties && timed_properties[str] ) {
        if( timed_properties[str] < time() ) {
            map_delete( timed_properties, str );
            map_delete( map_prop, str );
            return 0;
        }
        return timed_properties[str] - time();
    }
    return 0;
} /* query_property_time_left() */

/**
 * returns a mapping with all the properties in it.
 * @return a mapping of all the properties
 */
mapping query_properties() {
    return map_prop || ([ ]);
} /* query_properties() */

/**
 * Returns a mapping of all the timed properties.
 * @return a mapping of all the timed properties
 */
mapping query_timed_properties() {
    return timed_properties || ([ ]);
} /* query_timed_properties() */

/**
 * Adds a mapping of properties in, instead of just one.
 * @param map the mapping of properties
 */
void add_properties( mapping map ) {
    if( !map_prop )
        map_prop = map;
    else
        map_prop += map;
} /* add_properties() */

/**
 * Updates the timeouts and stuff before saving the player object.
 */
protected void save_player_properties() {
    if( timed_properties ) {
        foreach( string key in keys(timed_properties) )
          if( timed_properties[ key ] < time() ) {
              map_delete( timed_properties, key );
              map_delete( map_prop, key );
          } else
              timed_properties[ key ] -= time();
    }
} /* save_player_properties() */

/**
 * Fixes the times back up again after it has been loaded.
 */
protected void reload_player_properties() {
    if( timed_properties )
        foreach( string key in keys(timed_properties) )
          timed_properties[ key ] += time();
} /* reload_player_properties() */

/** @ignore yes */
mixed stats() {
    int time;
    mixed *res, value;
    string key;
    mapping props;

    if( !props = (mapping)TO->query_properties() )
        return ({ });

    res = ({ });

    foreach( key, value in props ) {
      time = 0;
      if( timed_properties && timed_properties[ key ] &&
          timed_properties[ key ] < time() ) {
          map_delete( timed_properties, key );
          map_delete( map_prop, key );
          continue;
      }

      if( timed_properties && timed_properties[ key ] )
          time = timed_properties[ key ] - time();

      if( !stringp( key ) || key[0..3] == "news" || key[0] == '.' )
          continue;
      if( pointerp( value ) ) {
          res += ({ ({ "(" + key + ( time ? ":" + time : "") + ")",
              array_to_string( value ) }) });
          continue;
      }
      if( mappingp( value ) ) {
          res += ({ ({ "(" + key + ( time ? ":" + time : "") + ")",
              mapping_to_string( value ) }) });
          continue;
      }
      res += ({ ({ "("+ key + ( time ? ":" + time : "" ) +")",
          value }) });
    }
    return res;
} /* stats() */
