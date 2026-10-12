/**
 * Utility library for manipulating closures.
 *
 * @author devo
 * @alias ClosureLib
 */

/**
 * Internal function to recurse through nested arrays of a lambda closure.
 *
 * @param  arr array to rebuild
 * @return     the rebuilt array
 */
private mixed *_reconstruct(mixed *arr) {
  int size = sizeof(arr);
  mixed *result = allocate(size + 1);
  result[0] = #'({; //'
  for (int i = 0; i < size; i++) {
    if (pointerp(arr[i])) {
      result[i + 1] = _reconstruct(arr[i]);
    } else {
      result[i + 1] = arr[i];
    }
  }
  return result;
}

/**
 * This function will return a lambda closure that, upon execution, will
 * return the array used to construct the same closure. The new closure will
 * take the specified args, which, when evaluated, will end up as constants
 * in the newly compiled closure. All other symbols found in the input array
 * will appear in the new lambda closure unquoted one level.
 *
 * Example:
 * <code><pre>
 * funcall(reconstruct_lambda(({ 'arg })),
                              ({ #'+, 'arg, ''s })), "str")</pre></code>
 * returns:
 * <code><pre>({ #'+, "str", 's})</pre></code>
 *
 * @param  args an array of arguments to the new lambda closure
 * @param  arr  the closure which is to be reconstructed
 * @return      a closure which, when executed, should return arr
 */
closure reconstruct_lambda(symbol *args, mixed *arr) {
  return lambda(args, _reconstruct(arr));
}
