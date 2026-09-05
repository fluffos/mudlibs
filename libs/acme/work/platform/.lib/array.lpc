/**
 * Utility library for manipulating arrays.
 *
 * @author devo@eotl
 * @alias ArrayLib
 */
#pragma no_clone

protected varargs int searcha(mixed list, mixed el, int start, int step);
protected varargs int anti_searcha(mixed list, mixed el, int start, int step);
protected varargs int searcha_any(mixed list, mixed elements, int start, 
                                  int step);
protected varargs int anti_searcha_any(mixed list, mixed elements, int start,
                                       int step);
protected varargs mixed *unique_array(mixed *list, int keep_last);
protected mixed flatten_array(mixed *list);
protected mixed deep_flatten_array(mixed *list);
protected mixed *m_value(mapping map, string k);
protected varargs mixed reduce(mixed data, closure reducer, mixed initial, 
                               varargs mixed *args);
protected mapping *mapping_array(mixed *keys, mixed *data);
protected mixed random_key(mapping map);

/**
 * Return the index of the first element of an array or string which is a
 * specified value. Like member(), but provides the start/step capability.
 *
 * @param  list  an array or string to search
 * @param  el    a value to search against
 * @param  start optional starting position of the search
 * @param  step  optional step
 * @return       the index of the first member of list which is el
 */
protected varargs int searcha(mixed list, mixed el, int start, int step) {
  int size = sizeof(list);
  step ||= 1;

  if (step > 0) {
    for (; (start < size) && (list[start] != el); start += step);
    return (start < size) ? start : -1;
  } else {
    for (; (start >= 0) && (list[start] != el); start += step);
    return (start >= 0)   ? start : -1;
  }
}

/**
 * Return the index of the first element of an array or string which is not
 * a specified value.
 *
 * @param  list  an array or string to search
 * @param  el    a value to search against
 * @param  start optional starting position of the search
 * @param  step  optional step
 * @return       the index of the first member of list which is not el
 */
protected varargs int anti_searcha(mixed list, mixed el, int start, int step) {
  int size = sizeof(list);
  step ||= 1;

  if (step > 0) {
    for (; (start < size) && (list[start] == el); start += step);
    return (start < size) ? start : -1;
  } else {
    for (; (start >= 0) && (list[start] == el); start += step);
    return (start >= 0)   ? start : -1;
  }
}

/**
 * Like member(), but instead of searching for a single item, search for any
 * item of a set.
 *
 * @param  list     an array or string to search
 * @param  elements an array of potential elements, or a string or characters
 *                  to search against
 * @param  start    optional starting position of the search
 * @param  step     optional step
 * @return          the index of the first member of list which matches one
 *                  of the specified elements
 */
protected varargs int searcha_any(mixed list, mixed elements, int start, 
                                  int step) {
  int size = sizeof(list);
  step ||= 1;

  for (; (start < size); start += step) {
    if (member(elements, list[start]) != -1) {
      return start;
    }
  }

  return -1;
}

/**
 * Like anti_searcha(), but instead of searching for a single item, search
 * for any item of a set.
 *
 * @param  list     an array or string to search
 * @param  elements an array of potential elements, or a string of characters
 *                  to search against
 * @param  start    optional starting position of the search
 * @param  step     optional step
 * @return          the index of the first member of list which is not one of
 *                  the specified elements
 */
protected varargs int anti_searcha_any(mixed list, mixed elements, int start,
                                       int step) {
  int size = sizeof(list);
  step ||= 1;

  for (; (start < size); start += step) {
    if (member(elements, list[start]) == -1) {
      return start;
    }
  }

  return -1;
}

/**
 * Return a copy of an array with all duplicates removed. When an element
 * appears multiple times in the array, the first occurrence will be used for
 * its position in the new array, unless keep_last!=0, in which case the last
 * occurrence will be used.
 *
 * Note: If you don't care about preserving order, you probably want to forgo
 *       using this function in favor of the more efficient:
 *       <code>m_indices(mkmapping(list))</code>
 *
 * @param  list      the array from which to remove duplicates
 * @param  keep_last 0 to use first occurrence, otherwise use last
 * @return           a copy of the array with duplicates removed
 */
protected varargs mixed *unique_array(mixed *list, int keep_last) {
  mixed *out = ({ });
  mapping bag = ([ ]);
  if (keep_last) {
    for (int i = sizeof(list)- 1; i >= 0; i--) {
      if (!member(bag, list[i])) {
        out = ({ list[i] }) + out;
        m_add(bag, list[i]);
      }
    }
  } else {
    for (int i = 0, int j = sizeof(list); i < j; i++) {
      if (!member(bag, list[i])) {
        out += ({ list[i] });
        m_add(bag, list[i]);
      }
    }
  }
  return out;
}

/**
 * Flatten an array one level. e.g. turns:
 *   <code>({ ({ a, b }), c, ({ d, ({ e }) }) })</code>
 * into:
 *   <code>({ a, b, c, d, ({ e }) })</code>
 *
 * @param  list the array to flatten
 * @return      the flattened array
 */
protected mixed flatten_array(mixed *list) {
  if (!pointerp(list)) {
    return ({ });
  }

  mixed *newlist = ({ });
  for (int i = 0, int j = sizeof(list); i < j; i++) {
    if (pointerp(list[i])) {
      newlist += list[i];
    } else {
      newlist += ({ list[i] });
    }
  }
  return newlist;
}

/**
 * Completely flatten an array. e.g. turns:
 *   <code>({ ({ a, b }), c, ({ d, ({ e }) }) })</code>
 * into:
 *   <code>({ a, b, c, d, e, })</code>
 *
 * @param  list the array to flatten
 * @return      the flattened array
 */
protected mixed deep_flatten_array(mixed *list) {
  if (!pointerp(list)) {
    return ({ list });
  }

  mixed *newlist = ({ });
  for (int i = 0, int j = sizeof(list); i < j; i++) {
    newlist += deep_flatten_array(list[i]);
  }
  return newlist;
}

/**
 * Return all the values associated with a mapping key in the form of an
 * array. The resulting array will have the same width as the specified
 * mapping.
 *
 * @param  map the mapping to index
 * @param  key the mapping key
 * @return     an array of the mapping values for key, in order
 */
protected mixed *m_value(mapping map, string k) {
  if (!member(map, k)) {
    return 0;
  }
  int width = widthof(map);
  mixed *result = allocate(width);
  for (int i = 0; i < width; i++) {
    result[i] = map[k, i];
  }
  return result;
}

/**
 * Reduce an array or mapping.
 * 
 * @param  data          an array or mapping (reduced on keys)
 * @param  reducer       a reduction function
 * @param  initial       an initial value
 * @param  args          extra args for the reducer
 * @return a value reduced on reducer->(current_value, element)
 */
protected varargs mixed reduce(mixed data, closure reducer, mixed initial, 
                               varargs mixed *args) {
  mixed result = initial;
  foreach (mixed el : data) {
    result = apply(reducer, result, el, args);
  }
  return result;
}

/**
 * Given an array of keys, create an array of mappings such that each element
 * is a mapping with the specified keys and the correspecting values from
 * data[index].
 * 
 * @param  keys         the keys for the resultant mappings
 * @param  data         an array of corresponding values
 * @return an array of mappings of keys to values
 */
protected mapping *mapping_array(mixed *keys, mixed *data) {
  mapping *result = ({ });
  int size = sizeof(keys);
  foreach (mixed *values : data) {
    mapping map = ([ ]);
    for (int i = 0, int j = sizeof(values); i < j; i++) {
      if (i < size) {
        map[keys[i]] = values[i];
      } else {
        break;
      }
    }
    result += ({ map });
  }
  return result;
}

/**
 * Get a random key from a mapping.
 * 
 * @param  map           the mapping
 * @return a random key, or 0 if the mapping is empty
 */
protected mixed random_key(mapping map) {
  if (!mappingp(map)) {
    return 0;
  }
  string *keys = m_indices(map);
  int size = sizeof(keys);
  if (!size) {
    return 0;
  }
  return keys[random(size)];
}
