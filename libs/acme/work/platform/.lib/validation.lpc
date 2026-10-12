/**
 * Some common validation functions for commands.
 *
 * @author devo@eotl
 * @alias ValidationLib
 */
private inherit UserLib;

public int validate_max_length(mixed arg, mixed len);
public int validate_min_length(mixed arg, mixed len);
public int validate_not_empty(mixed arg);
public int validate_is_user(string username);

/**
 * Validate a string/array/mapping doesn't exceed a specified length.
 * 
 * @param  arg           a string/array/mapping
 * @param  len           the maximum length
 * @return 1 if valid, otherwise 0
 */
public int validate_max_length(mixed arg, mixed len) {
  return (sizeof(arg) <= to_int(len));
}

/**
 * Validate a string/array/mapping is at least a specified length.
 * 
 * @param  arg           a string/array/mapping
 * @param  len           the minimum length
 * @return 1 if valid, otherwise 0
 */
public int validate_min_length(mixed arg, mixed len) {
  return (sizeof(arg) >= to_int(len));
}

/**
 * Validate a string/array/mapping isn't empty.
 * 
 * @param  arg           a string/array/mapping
 * @return 1 if valid, otherwise 0
 */
public int validate_not_empty(mixed arg) {
  return validate_min_length(arg, 1);
}

/**
 * Validate a user exists with a given username.
 * 
 * @param  username      the username
 * @return 1 if valid, otherwise 0
 */
public int validate_is_user(string username) {
  return user_exists(username);
}

