#include <simul_efun.h>

private string regex = "( \\/\\* sizeof\\(\\) == \\d+ \\*/)";

/**
 * Returns a formatted string representation of a mapping, removing any size
 * annotations.
 *
 * @param {mapping} map - The mapping to format.
 * @returns {string} The formatted string representation of the mapping.
 */
string pretty_map(mapping map) {
  string str = sprintf("%O\n", map);

  while(pcre_match(str, regex))
    str = pcre_replace(str, regex, ({""}));

  return str;
}

/**
 * Finds the first key in a mapping that corresponds to a specific value
 * or satisfies a given condition.
 *
 * When a function is provided as the value parameter, it acts as a
 * predicate. Any trailing arguments passed to `find_key` are forwarded
 * to the predicate, so its full call signature is
 * `(val, key, map, arg...)` — `$1` is the value at the current key,
 * `$2` is the key, `$3` is the mapping, and `$4..` are the forwarded
 * extras. The predicate should return truthy when the desired key is
 * found.
 *
 * @param {mapping} map - The mapping to search.
 * @param {mixed|function} value - The value to find, or a predicate
 *                                 function.
 * @param {mixed...} [arg] - Optional trailing arguments forwarded into
 *                           the predicate call.
 * @returns {mixed} The first matching key, or 0 if no match found.
 * @example
 * // Find key for a specific value
 * mapping scores = (["Alice": 95, "Bob": 87, "Charlie": 95]);
 * string name = find_key(scores, 95); // Returns "Alice"
 *
 * // Find key using a predicate function ($1 = value at key)
 * name = find_key(scores, (: $1 > 90 :)); // First student with score > 90
 *
 * // Forwarding an extra arg lets the closure stay capture-free
 * int threshold = 90;
 * name = find_key(scores, (: $1 > $4 :), threshold);
 *
 * // Common pattern: condition-strings as keys, value as forwarded arg
 * mapping bands = ([
 *   ">=0AND<50":   ([ "size": "small"  ]),
 *   ">=50AND<80":  ([ "size": "medium" ]),
 *   ">=80AND<100": ([ "size": "large"  ]),
 * ]);
 * string key = find_key(bands, (: evaluate_number($4, $2) :), mass);
 */
varargs mixed find_key(mapping map, mixed value, mixed arg...) {
  if(valid_function(value)) {
    function f = value;

    foreach(mixed key, mixed val in map) {
      if(sizeof(arg)) {
        if(f(val,key,map,arg...))
          return key;
      } else {
        if(f(val,key,map))
          return key;
      }
    }
  } else {
    foreach(mixed key, mixed val in map) {
      if(val == value)
        return key;
    }
  }
}

/**
 * Finds all keys in a mapping that correspond to a specific value
 * or satisfy a given condition.
 *
 * When a function is provided as the value parameter, it acts as a
 * predicate. Any trailing arguments passed to `find_keys` are
 * forwarded to the predicate, so its full call signature is
 * `(val, key, map, arg...)` — `$1` is the value at the current key,
 * `$2` is the key, `$3` is the mapping, and `$4..` are the forwarded
 * extras. The predicate should return truthy for each key that
 * should be included in the result.
 *
 * @param {mapping} map - The mapping to search.
 * @param {mixed|function} value - The value to find, or a predicate
 *                                 function.
 * @param {mixed...} [arg] - Optional trailing arguments forwarded into
 *                           the predicate call.
 * @returns {mixed*} Array of all matching keys, empty array if none
 *                   found.
 * @example
 * // Find all keys for a specific value
 * mapping scores = (["Alice": 95, "Bob": 87, "Charlie": 95]);
 * string* names = find_keys(scores, 95); // Returns ({"Alice", "Charlie"})
 *
 * // Find all keys using a predicate function ($1 = value at key)
 * names = find_keys(scores, (: $1 > 90 :)); // All students with score > 90
 *
 * // Forwarding an extra arg lets the closure stay capture-free
 * int threshold = 90;
 * names = find_keys(scores, (: $1 > $4 :), threshold);
 *
 * // Using with evaluate_number for complex conditions
 * string* honor_roll = find_keys(scores, (: evaluate_number($1, ">=95OR(>=80AND%5)") :));
 * // Returns students with scores ≥95 OR (scores ≥80 AND divisible by 5)
 */
varargs mixed *find_keys(mapping map, mixed value, mixed arg...) {
  mixed *result = allocate(0);

  if(valid_function(value)) {
    function f = value;

    foreach(mixed key, mixed val in map) {
      if(sizeof(arg)) {
        if(f(val,key,map,arg...))
          push(ref result, key);
      } else {
        if(f(val,key,map))
          push(ref result, key);
      }
    }
  } else {
    foreach(mixed key, mixed val in map) {
      if(val == value)
        push(ref result, key);
    }
  }

  return result;
}

/**
 * Walks a dotted path through nested mappings and returns the value
 * at the destination, or `undefined` if any intermediate hop is
 * missing or not a mapping.
 *
 * The path is split on `.`; each segment is looked up in the
 * current mapping. The final segment's value is returned as-is
 * (it may itself be a mapping). Intermediate non-mapping values
 * abort the walk and yield `undefined`.
 *
 * @param {mapping} map - The root mapping to walk.
 * @param {string} path - Dot-separated path to follow
 *                        (e.g. `"player.stats.hp"`).
 * @returns {mixed} The value at `path`, or `undefined` if the
 *                  path can't be fully resolved.
 * @example
 * mapping data = ([
 *   "player": ([
 *     "name": "Alice",
 *     "stats": ([ "hp": 100, "mp": 40 ]),
 *   ]),
 * ]);
 *
 * dot_walk(data, "player.name");      // "Alice"
 * dot_walk(data, "player.stats.hp");  // 100
 * dot_walk(data, "player.stats");     // the nested mapping
 * dot_walk(data, "player.gear.head"); // undefined (no "gear" key)
 */
mixed dot_walk(mapping map, string path) {
  assert_arg(
    mapp(map),
    1,
    "Map must be a mapping."
  );

  assert_arg(
    stringp(path),
    2,
    "Path must be a string."
  );

  string *parts = explode(path, ".");

  if(sizeof(parts) == 0)
    return undefined;

  if(sizeof(parts) == 1)
    return map[parts[0]];

  if(mapp(map[parts[0]]))
    return dot_walk(map[parts[0]], implode(parts[1..], "."));

  return undefined;
}
