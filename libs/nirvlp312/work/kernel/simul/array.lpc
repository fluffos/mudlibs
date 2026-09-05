/*
 * /kernel/simul/array.c
 * Some functions for simul_efun concerning arrays
 * Rumplemintz
 */

#include <closures.h>

/*
 * Function name: exclude_array
 * Description:   Deletes a section of an array
 * Arguments:     arr: The array
 *                from: Index from which to delete elements
 *                to: Last index to be deleted
 * Returns:
 */
mixed *exclude_array(mixed *arr, int from, int to) {
  arr[from..to] = ({ });
  return arr;
}

/*
 * Function name: exclude_element
 * Description:   deletes an element from an array
 * Arguments:     arr: the array
 *                from: index of the element to remove from the array
 * Returns:       first element of the array, or -1 if failed.
 * Warning:       elements in the array will have been reshuffled somewhat
 */
mixed *exclude_element(mixed *arr, int index) {
  arr[index..index] = ({ });
  return arr;
}

mixed *merge_array(mixed *arr) {
  mixed *new;
  int i, j, p;

  p = sizeof(arr[0]) * sizeof(arr);
  new = allocate(p);
  for (i=sizeof(arr[0]); i--; )
    for (j=sizeof(arr); j-- && p--; )
      new[p] = arr[j][i];
  return new;
}

mixed *split_array(mixed *arr, int mod) {
  mixed *new;
  int i, j, p;

  new = map(allocate(mod), lambda(0, ({ #'allocate, (p=sizeof(arr))/mod })));
  for (i=sizeof(arr)/mod; i--; )
    for (j=mod; j-- && p--; )
      new[j][i] = arr[p];
  return new;
}

varargs mixed *flatten_array(mixed *arr, status recursive) {
  int i;

  for (i=sizeof(arr); i--; )
    if (pointerp(arr[i]))
      arr[i..i] = recursive ? flatten_array(arr[i],1) : arr[i];
  return arr;
}

mixed turn_array(mixed m) {
  int i;
  mixed h;

  for (i=(stringp(m) ? strlen(m) : sizeof(m)) >> 1; i--; )
    h = m[i], m[i] = m[<i+1], m[<i+1] = h;
  return m;
}

mixed shuffle_array(mixed m) {
  int i, j;
  mixed h;

  for (i=(stringp(m) ? strlen(m) : sizeof(m)); i--; )
    j=random(i+1), h=m[i], m[i]=m[j], m[j]=h;
  return m;
}

varargs mixed find_extreme(mixed *m, closure c, mixed extra) {
  mixed max;
  int i;

  i = sizeof(m);
  max = m[--i];
  while (i--)
    if (apply(c,m[i], max, extra || ({})))
      max = m[i];
  return max;
}

varargs mixed find_map_extreme(mixed *m, closure map, closure c, mixed extra) {
  mixed h, max, applied_max;
  int i;

  i = sizeof(m);
  max = m[--i];
  applied_max = apply(map, max, extra || ({}));
  while (i--) {
    h = apply(map, m[i], extra || ({}));
    if (funcall(c, h, applied_max)) {
      max = m[i];
      applied_max = h;
    }
  }
  return max;
}

varargs int find_element(mixed m, closure c, int i, mixed extra) {
  for (; i<(pointerp(m) ? sizeof(m) : strlen(m)); i++)
    if (apply(c, m[i], extra || ({})))
      return i;
  return -1;
}

varargs int find_last_element(mixed m, closure c, int i, mixed extra) {
  for (i=i || (pointerp(m) ? sizeof(m) : strlen(m)); i--; )
    if (apply(c, m[i], extra || ({})))
      return i;
  return -1;
}

varargs mixed *sort_map_array(mixed *arr, mixed a, mixed b, mixed c, mixed d,
                              mixed extra) {
  // a: map closure | map lfun-string
  // b: map object | sort closure | sort lfun-string
  // c: sort lfun-string | sort object | sort closure | extra arguments
  // d: sort object | extra arguments
  // extra: extra arguments
  // c, d, and extra can be omitted.
  // extra should always be given as array. if it is not give it defaults to
  // an empty array for practical reasons. give ({ 0 }) if you really want to
  // pass a 0 to the closure
  mixed h;
  closure map, sort;

  if (closurep(a)) { // map as closure?
    map = a;
    if (closurep(b)) { // sort as closure?
      sort = b;
      extra = c;
    }
    else { // map as closure, sort as lfun and object
      sort = symbol_function(b,c);
      extra = d;
    }
  }
  else { // map give as lfun and object
    map = symbol_function(a,b);
    if (closurep(c)) { // sort as closure?
      sort = c;
      extra = d;
    }
    else // map as lfun and object, sort as lfun and object
      sort = symbol_function(c,d);
  }
  if (!sizeof(arr))
    return arr;
  h = apply(#'map, arr, map, extra || ({}));
  h = transpose_array(({ h, arr }));
  h = sort_array(h, lambda(({ 'x, 'y }),
                           ({ sort,
                              ({ CL_INDEX, 'x, 0 }),
                              ({ CL_INDEX, 'y, 0 }) })));
  return transpose_array(h)[1];
}

varargs object *sort_objects(object *os, string lfun, closure sortfun,
                             mixed extra) {
  mixed h;

  if (!sizeof(os))
    return os;
  h = map_objects(os, lfun, extra);
  h = transpose_array(({ h, os }));
  h = sort_array(h, lambda(({ 'x, 'y }),
                           ({ sortfun,
                              ({ CL_INDEX, 'x, 0 }),
                              ({ CL_INDEX, 'y, 0 }) })));
  return transpose_array(h)[1];
}

mapping count_elements(mixed *arr) {
  int i;
  mapping result;

  result = ([]);
  for (i = sizeof(arr); i--; )
    result[arr[i]]++;
  return result;
}

